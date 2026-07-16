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

bigint &bigint::operator+=(const bigint &other)
{
	int carry = 0;
	int i = _big.size() - 1;
	int j = other._big.size() - 1;
	
	std::string result;

	while (i >= 0 || j >= 0 || carry)
	{
		int thisval = (i >= 0) ? _big[i] - '0' : 0;
		int otherval = (j >=0) ? other._big[j] - '0' : 0;

		int res = thisval + otherval + carry;

		carry = res / 10;

		result.push_back((res % 10) +'0');
		--i;
		--j;
	}
	std::string rev;
	int siz = result.size() -1;
	for (; siz >= 0; siz--)
		rev.push_back(result[siz]);
	_big = rev;
	return (*this);
}

bigint bigint::operator+(const bigint &other) const
{
	bigint copy(*this);
	copy += other;
	return (copy);
}

bigint &bigint::operator++()
{
	bigint dummy(1);
	*this += dummy;
	return (*this);
}

bigint bigint::operator++(int)
{
	bigint copy(*this);
	bigint dummy(1);
	*this += dummy;
	return (copy);
}

bigint bigint::operator<<(unsigned int amount)
{
	bigint copy(*this);
	copy._big.append(amount, '0');
	return (copy);
}

bigint bigint::operator>>(unsigned int amount)
{
	bigint copy(*this);
	if(amount > _big.size())
		copy._big = "0";
	else
		copy._big.resize(copy._big.size() - amount);
	return (copy);
}

bigint &bigint::operator<<=(unsigned int amount)
{
	*this = *this << amount;
	return (*this);
}

bigint &bigint::operator>>=(unsigned int amount)
{
	*this = *this >> amount;
	return (*this);
}

unsigned int strtouint(const std::string &val)
{
	std::stringstream ss(val);
	unsigned int num;
	ss >> num;
	return num;
}

bigint bigint::operator<<(const bigint &other)
{
	bigint copy(*this);
	copy <<= strtouint(other._big);
	return (copy);
}

bigint bigint::operator>>(const bigint &other)
{
	bigint copy(*this);
	copy >>= strtouint(other._big);
	return (copy);
}

bigint &bigint::operator<<=(const bigint &other)
{
	*this <<= strtouint(other._big);
	return (*this);
}

bigint &bigint::operator>>=(const bigint &other)
{
	*this >>= strtouint(other._big);
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
	return ( other < *this );
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
	return(_big == other._big);
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
