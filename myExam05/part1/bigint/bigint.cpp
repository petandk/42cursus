#include "bigint.hpp"

bigint::bigint(unsigned int nbr)
{
	std::stringstream ss;
	ss << nbr;
	_big = ss.str();
}
bigint &bigint::operator=(const bigint &other)
{
	if (this != &other)
		_big = other._big;
	return (*this);
}

std::string bigint::getBig() const
{
	return _big;
}

bigint &bigint::operator++()
{
	bigint dummy(1);
	*this += dummy;
	return (*this);
}

bigint bigint::operator++(int)
{
	bigint dummy(1);
	bigint copy(*this);
	*this += dummy;
	return (copy); 
}

bigint &bigint::operator+=(const bigint &other)
{
	int carry = 0;
	int i = _big.size() - 1;
	int j = other._big.size() - 1;

	std::string result;

	while (i >= 0 || j >= 0 || carry)
	{
		int currentDigit = i >= 0 ? _big[i] - '0' : 0;
		int otherDigit = j >= 0 ? other._big[j] - '0' : 0;

		int sum = currentDigit + otherDigit + carry;

		carry = sum / 10;
		result.push_back((sum%10) + '0');
		--i;
		--j;
	}
	int siz = result.size();
	std::string rev;
	for (int s = siz -1; s >= 0; s--)
		rev.push_back(result[s]);
	_big = rev;
	return (*this);
}

bigint bigint::operator+(const bigint &other) const
{
	bigint copy(*this);
	copy += other;
	return (copy);
}

bigint bigint::operator<<(unsigned int n)
{
	bigint copy(*this);
	copy._big.insert(copy._big.end(), n, '0');
	return (copy);
}

bigint bigint::operator>>(unsigned int n)
{
	bigint copy(*this);
	if (n < copy._big.size())
		copy._big.erase(copy._big.size()  - n, n);
	else
		copy._big = "0";
	return (copy);
}

bigint &bigint::operator<<=(unsigned int n)
{
	*this = *this << n;
	return *this;
}

bigint &bigint::operator>>=(unsigned int n)
{
	*this = *this >> n;
	return *this;
}

unsigned int stringToUnInt(const std::string &val)
{
	std::stringstream ss(val);
	unsigned int num;
	ss>>num;
	return num;
}

bigint bigint::operator<<(const bigint &other)
{
	bigint tmp(*this);
	tmp = tmp << stringToUnInt(other._big);
	return tmp;
}

bigint bigint::operator>>(const bigint &other)
{
	bigint tmp(*this);
	tmp = tmp >> stringToUnInt(other._big);
	return tmp;
}

bigint &bigint::operator<<=(const bigint &other)
{
	*this = *this << stringToUnInt(other._big);
	return (*this);
}

bigint &bigint::operator>>=(const bigint &other)
{
	*this = *this >> stringToUnInt(other._big);
	return (*this);
}

bool bigint::operator<(const bigint &other) const
{
	return (_big.size() != other._big.size())
			? _big.size() < other._big.size()
			: _big < other._big;
}

bool bigint::operator>(const bigint &other) const
{
	return (other < *this);
}

bool bigint::operator<=(const bigint &other) const
{
	return !(*this > other);
}

bool bigint::operator>=(const bigint &other) const
{
	return !(*this < other);
}

bool bigint::operator==(const bigint &other) const
{
	return (_big == other._big);
}

bool bigint::operator!=(const bigint &other) const
{
	return (_big != other._big);
}

std::ostream &operator<<(std::ostream &out, const bigint &other)
{
	out << other.getBig();
	return (out);
}
