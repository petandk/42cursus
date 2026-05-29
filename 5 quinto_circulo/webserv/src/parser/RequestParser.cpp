#include "../../inc/parser/RequestParser.hpp"
#include <cctype>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iostream>


// ─── Constructor / Destructor ────────────────────────────────────────────────

RequestParser::RequestParser()
	: _state(PARSING_REQUEST_LINE), _contentLength(0), _bodyBytesRead(0),
	  _isChunked(false), _maxBodySize(DEFAULT_MAX_BODY), _currentChunkSize(0),
	  _chunkBytesRead(0), _totalHeaderSize(0), _headerCount(0)
{

}

RequestParser::~RequestParser()
{

}

RequestParser::RequestParser(const RequestParser& other)
	: _state(other._state), _buffer(other._buffer), _request(other._request),
	  _contentLength(other._contentLength), _bodyBytesRead(other._bodyBytesRead),
	  _isChunked(other._isChunked), _maxBodySize(other._maxBodySize),
	  _currentChunkSize(other._currentChunkSize), _chunkBytesRead(other._chunkBytesRead),
	  _totalHeaderSize(other._totalHeaderSize), _headerCount(other._headerCount)
{
	
}

RequestParser& RequestParser::operator=(const RequestParser& other)
{
	if (this != &other)
	{
		_state = other._state;
		_buffer = other._buffer;
		_request = other._request;
		_contentLength = other._contentLength;
		_bodyBytesRead = other._bodyBytesRead;
		_isChunked = other._isChunked;
		_maxBodySize = other._maxBodySize;
		_currentChunkSize = other._currentChunkSize;
		_chunkBytesRead = other._chunkBytesRead;
		_totalHeaderSize = other._totalHeaderSize;
		_headerCount = other._headerCount;
	}
	return *this;
}

// ─── Public Interface ────────────────────────────────────────────────────────
void RequestParser::feed(const std::string& data)
{
	if (_state == COMPLETE || _state == ERROR)
		return;

	_buffer.append(data);

	while (_state != COMPLETE && _state != ERROR)
	{
		ParseState prevState = _state;
		size_t prevBufferSize = _buffer.size();

		if (_state == PARSING_REQUEST_LINE)
			_parseRequestLine();
		else if (_state == PARSING_HEADERS)
			_parseHeaders();
		else if (_state == PARSING_BODY)
			_parseBodyFixed();
		else if (_state == PARSING_CHUNK_SIZE)
			_parseChunkSize();
		else if (_state == PARSING_CHUNK_DATA)
			_parseChunkData();
		else if (_state == PARSING_CHUNK_TRAILER)
			_parseChunkTrailer();

		if (_state == COMPLETE)
			_request.setIsComplete(true);

		// Break if no progress was made (need more data)
		if (_state == prevState && _buffer.size() == prevBufferSize)
			break;
	}
}

bool RequestParser::isComplete() const
{
	return _state == COMPLETE || _state == ERROR;
}

RequestParser::ParseState RequestParser::getState() const
{
	return _state;
}

const HTTPRequest& RequestParser::getRequest() const
{
	return _request;
}

void RequestParser::reset()
{
	// Preserve leftover buffer data (pipelining)
	_state = PARSING_REQUEST_LINE;
	_request.clear();
	_contentLength = 0;
	_bodyBytesRead = 0;
	_isChunked = false;
	_currentChunkSize = 0;
	_chunkBytesRead = 0;
	_totalHeaderSize = 0;
	_headerCount = 0;
}

void RequestParser::setMaxBodySize(size_t size)
{
	_maxBodySize = size;
}

// ─── Request Line Parsing ────────────────────────────────────────────────────
void RequestParser::_parseRequestLine()
{
	std::string line;
	if (!_findLine(line))
		return; // Need more data

	if (line.size() > MAX_REQUEST_LINE)
		return _setError(414);

	// Split: METHOD SP URI SP HTTP-VERSION
	std::string::size_type firstSpace = line.find(' ');
	if (firstSpace == std::string::npos)
		return _setError(400);

	std::string::size_type secondSpace = line.find(' ', firstSpace + 1);
	if (secondSpace == std::string::npos)
		return _setError(400);

	// Check no extra spaces
	if (line.find(' ', secondSpace + 1) != std::string::npos)
		return _setError(400);

	std::string method = line.substr(0, firstSpace);
	std::string uri = line.substr(firstSpace + 1, secondSpace - firstSpace - 1);
	std::string version = line.substr(secondSpace + 1);

	// Validate method
	if (!_isValidMethod(method))
		return _setError(405);

	// Validate version
	if (!_isValidVersion(version))
		return _setError(505);

	// Validate URI starts with /
	if (uri.empty() || uri[0] != '/')
		return _setError(400);

	if (uri.size() > MAX_REQUEST_LINE)
		return _setError(414);

	// Split URI into path and query string
	std::string path;
	std::string queryString;
	std::string::size_type queryPos = uri.find('?');
	if (queryPos != std::string::npos)
	{
		path = uri.substr(0, queryPos);
		queryString = uri.substr(queryPos + 1);
	}
	else
	{
		path = uri;
	}

	// Percent-decode the path
	bool decodeError = false;
	path = _percentDecode(path, decodeError);
	if (decodeError)
		return _setError(400);

	// Normalize path (resolve . and ..)
	path = _normalizePath(path);

	_request.setMethod(method);
	_request.setUri(uri);
	_request.setPath(path);
	_request.setQueryString(queryString);
	_request.setHttpVersion(version);

	_state = PARSING_HEADERS;
}

// ─── Header Parsing ──────────────────────────────────────────────────────────
void RequestParser::_parseHeaders()
{
	std::string line;
	while (_findLine(line))
	{
		// Empty line marks end of headers
		if (line.empty())
		{
			// Validate mandatory headers
			if (_request.getHttpVersion() == "HTTP/1.1" && !_request.hasHeader("host"))
				return _setError(400);

			_determineBodyStrategy();
			return;
		}

		// Check limits
		if (line.size() > MAX_HEADER_LINE)
			return _setError(400);

		_totalHeaderSize += line.size();
		if (_totalHeaderSize > MAX_TOTAL_HEADERS)
			return _setError(431);

		_headerCount++;
		if (_headerCount > MAX_HEADER_COUNT)
			return _setError(431);

		// Reject obsolete line folding (starts with space/tab)
		if (line[0] == ' ' || line[0] == '\t')
			return _setError(400);

		// Find colon separator
		std::string::size_type colonPos = line.find(':');
		if (colonPos == std::string::npos || colonPos == 0)
			return _setError(400);

		// No space before colon
		if (line[colonPos - 1] == ' ')
			return _setError(400);

		std::string name = _toLower(line.substr(0, colonPos));
		std::string value = _trim(line.substr(colonPos + 1));

		// Handle duplicate headers
		if (_request.hasHeader(name))
		{
			// Multiple Host headers = 400
			if (name == "host")
				return _setError(400);
			// Multiple different Content-Length = 400
			if (name == "content-length")
			{
				if (_request.getHeader(name) != value)
					return _setError(400);
				continue; // same value, skip
			}
			// Other headers: append with comma (RFC 7230 3.2.2)
			std::string existing = _request.getHeader(name);
			_request.setHeader(name, existing + ", " + value);
		}
		else
		{
			_request.setHeader(name, value);
		}
	}
}

// ─── Body Strategy ───────────────────────────────────────────────────────────
void RequestParser::_determineBodyStrategy()
{
	std::string transferEncoding = _request.getHeader("transfer-encoding");
	std::string contentLengthStr = _request.getHeader("content-length");

	// Check Transfer-Encoding (takes precedence over Content-Length per RFC 7230 3.3.3)
	if (!transferEncoding.empty())
	{
		if (_toLower(transferEncoding) != "chunked")
			return _setError(501);
		// Remove Content-Length if present (RFC 7230 3.3.3)
		if (_request.hasHeader("content-length"))
			_request.setHeader("content-length", "");

		_isChunked = true;
		_state = PARSING_CHUNK_SIZE;
		return;
	}

	// Check Content-Length
	if (!contentLengthStr.empty())
	{
		char* endptr;
		long cl = std::strtol(contentLengthStr.c_str(), &endptr, 10);
		if (*endptr != '\0' || cl < 0)
			return _setError(400);

		_contentLength = static_cast<size_t>(cl);

		if (_contentLength > _maxBodySize)
			return _setError(413);

		if (_contentLength == 0)
		{
			_state = COMPLETE;
			return;
		}
		_state = PARSING_BODY;
		return;
	}

	// No body indicators
	if (_request.getMethod() == "POST")
		return _setError(411); // Length Required

	_state = COMPLETE;
}

// ─── Fixed-Length Body ───────────────────────────────────────────────────────
void RequestParser::_parseBodyFixed()
{
	size_t remaining = _contentLength - _bodyBytesRead;
	size_t available = _buffer.size();
	size_t toRead = (available < remaining) ? available : remaining;

	if (toRead > 0)
	{
		_request.appendBody(_buffer.substr(0, toRead));
		_buffer.erase(0, toRead);
		_bodyBytesRead += toRead;
	}

	if (_bodyBytesRead >= _contentLength)
		_state = COMPLETE;
}

// ─── Chunked Body ────────────────────────────────────────────────────────────

void RequestParser::_parseChunkSize()
{
	std::string line;
	if (!_findLine(line))
		return;

	if (line.size() > MAX_CHUNK_SIZE_LINE)
		return _setError(400);

	// Strip chunk extensions (everything after ;)
	std::string::size_type semiPos = line.find(';');
	std::string sizeStr = (semiPos != std::string::npos) ? line.substr(0, semiPos) : line;
	sizeStr = _trim(sizeStr);

	if (sizeStr.empty())
		return _setError(400);

	// Parse hex
	char* endptr;
	unsigned long chunkSize = std::strtoul(sizeStr.c_str(), &endptr, 16);
	if (*endptr != '\0')
		return _setError(400);

	_currentChunkSize = static_cast<size_t>(chunkSize);
	_chunkBytesRead = 0;

	// Terminal chunk
	if (_currentChunkSize == 0)
	{
		_state = PARSING_CHUNK_TRAILER;
		return;
	}

	// Check total body size
	if (_request.getBody().size() + _currentChunkSize > _maxBodySize)
		return _setError(413);

	_state = PARSING_CHUNK_DATA;
}

void RequestParser::_parseChunkData()
{
	size_t remaining = _currentChunkSize - _chunkBytesRead;
	size_t available = _buffer.size();
	size_t toRead = (available < remaining) ? available : remaining;

	if (toRead > 0)
	{
		_request.appendBody(_buffer.substr(0, toRead));
		_buffer.erase(0, toRead);
		_chunkBytesRead += toRead;
	}

	if (_chunkBytesRead < _currentChunkSize)
		return;

	// Chunk data is complete, expect \r\n after it
	if (_buffer.size() < 2)
		return;

	if (_buffer[0] != '\r' || _buffer[1] != '\n')
		return _setError(400);

	_buffer.erase(0, 2);
	_state = PARSING_CHUNK_SIZE;
}

void RequestParser::_parseChunkTrailer()
{
	// After the 0-size chunk, consume trailer headers until empty line
	std::string line;
	while (_findLine(line))
	{
		if (line.empty())
		{
			_state = COMPLETE;
			return;
		}
	}
}

// ─── Utility Functions ───────────────────────────────────────────────────────
bool RequestParser::_findLine(std::string& line)
{
	std::string::size_type pos = _buffer.find("\r\n");
	if (pos == std::string::npos)
	{
		// Also accept bare \n for lenient parsing
		pos = _buffer.find('\n');
		if (pos == std::string::npos)
			return false;
		line = _buffer.substr(0, pos);
		if (!line.empty() && line[line.size() - 1] == '\r')
			line.erase(line.size() - 1);
		_buffer.erase(0, pos + 1);
		return true;
	}
	line = _buffer.substr(0, pos);
	_buffer.erase(0, pos + 2);
	return true;
}

void RequestParser::_setError(int code)
{
	_state = ERROR;
	_request.setErrorCode(code);
	_request.setIsComplete(true);
}

std::string RequestParser::_toLower(const std::string& str)
{
	std::string result = str;
	for (size_t i = 0; i < result.size(); ++i)
		result[i] = static_cast<char>(std::tolower(static_cast<unsigned char>(result[i])));
	return result;
}

std::string RequestParser::_trim(const std::string& str)
{
	std::string::size_type start = 0;
	while (start < str.size() && (str[start] == ' ' || str[start] == '\t'))
		++start;
	std::string::size_type end = str.size();
	while (end > start && (str[end - 1] == ' ' || str[end - 1] == '\t'))
		--end;
	return str.substr(start, end - start);
}

std::string RequestParser::_percentDecode(const std::string& input, bool& error)
{
	std::string result;
	error = false;

	for (size_t i = 0; i < input.size(); ++i)
	{
		if (input[i] == '%')
		{
			if (i + 2 >= input.size())
			{
				error = true;
				return "";
			}
			char hi = input[i + 1];
			char lo = input[i + 2];
			if (!std::isxdigit(static_cast<unsigned char>(hi)) ||
				!std::isxdigit(static_cast<unsigned char>(lo)))
			{
				error = true;
				return "";
			}
			char decoded[3] = { hi, lo, '\0' };
			char c = static_cast<char>(std::strtol(decoded, NULL, 16));
			// Reject null bytes (security)
			if (c == '\0')
			{
				error = true;
				return "";
			}
			result += c;
			i += 2;
		}
		else
		{
			result += input[i];
		}
	}
	return result;
}

std::string RequestParser::_normalizePath(const std::string& path)
{
	// Split path by /
	std::vector<std::string> segments;
	std::string segment;
	std::istringstream stream(path);

	while (std::getline(stream, segment, '/'))
	{
		if (segment.empty() || segment == ".")
			continue;
		if (segment == "..")
		{
			if (!segments.empty())
				segments.pop_back();
		}
		else
		{
			segments.push_back(segment);
		}
	}

	// Rebuild path
	std::string result = "/";
	for (size_t i = 0; i < segments.size(); ++i)
	{
		result += segments[i];
		if (i + 1 < segments.size())
			result += "/";
	}

	// Preserve trailing slash if original had one
	if (path.size() > 1 && path[path.size() - 1] == '/' && result[result.size() - 1] != '/')
		result += "/";

	return result;
}

bool RequestParser::_isValidMethod(const std::string& method)
{
	return method == "GET" || method == "POST" || method == "DELETE";
}

bool RequestParser::_isValidVersion(const std::string& version)
{
	return version == "HTTP/1.1" || version == "HTTP/1.0";
}
