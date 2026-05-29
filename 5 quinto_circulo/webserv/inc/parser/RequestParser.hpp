#ifndef REQUESTPARSER_HPP
#define REQUESTPARSER_HPP

# include <string>
# include <cstddef>
# include "HTTPRequest.hpp"

class RequestParser
{
	private:
			enum ParseState
			{
				PARSING_REQUEST_LINE,
				PARSING_HEADERS,
				PARSING_BODY,
				PARSING_CHUNK_SIZE,
				PARSING_CHUNK_DATA,
				PARSING_CHUNK_TRAILER,
				COMPLETE,
				ERROR
			};
			// State
			ParseState		_state;
			std::string		_buffer;
			HTTPRequest		_request;

	// Body parsing
			size_t			_contentLength;
			size_t			_bodyBytesRead;
			bool			_isChunked;
			size_t			_maxBodySize;
			size_t			_currentChunkSize;
			size_t			_chunkBytesRead;

	// Header tracking
			size_t			_totalHeaderSize;
			int				_headerCount;

	// Limits (enum for C++98 compatibility)
			enum Limits
			{
				MAX_REQUEST_LINE	= 8192,
				MAX_HEADER_LINE		= 8192,
				MAX_TOTAL_HEADERS	= 32768,
				MAX_HEADER_COUNT	= 100,
				MAX_CHUNK_SIZE_LINE	= 64,
				DEFAULT_MAX_BODY	= 1048576  // 1MB
			};

			// Parsing methods
			void	_parseRequestLine();
			void	_parseHeaders();
			void	_parseBodyFixed();
			void	_parseChunkSize();
			void	_parseChunkData();
			void	_parseChunkTrailer();
			void	_determineBodyStrategy();

			// Utils
			bool		_findLine(std::string& line);
			void		_setError(int code);
			static std::string	_toLower(const std::string& str);
			static std::string	_trim(const std::string& str);
			static std::string	_percentDecode(const std::string& input, bool& error);
			static std::string	_normalizePath(const std::string& path);
			static bool			_isValidMethod(const std::string& method);
			static bool			_isValidVersion(const std::string& version);
	public:
			
			RequestParser();
			RequestParser(const RequestParser& other);
			RequestParser& operator=(const RequestParser& other);
			~RequestParser();

			
			//void			feed(Client client);
			void					feed(const std::string& data);
			bool					isComplete() const;
			ParseState				getState() const;
			const HTTPRequest&		getRequest() const;
			void					reset();
			void					setMaxBodySize(size_t size);


};

#endif
