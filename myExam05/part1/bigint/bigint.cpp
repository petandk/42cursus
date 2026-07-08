#include "bigint.hpp"

bigint::bigint(unsigned int nbr)
{
	std::stringstream ss;
	ss << nbr;
	_big = ss.str();
}

bigint &bigint::operator+=(const bigint &other)
{
	int carry = 0;
	int i = _big.size() - 1;
	int j = other._big.size() - 1;

	std::string result;

	while(i >= 0 || j >= 0 || carry)
	{
		int currentDigit = i >= 0 ? _big[i] - '0' : 0;
		int otherDigit = j >= 0 ? other._big[j] - '0' : 0;

		int sum = currentDigit + otherDigit + carry;

		carry = sum /10;
		result.push_back((sum%10) + '0');
		--i;
		--j;
	}
	std::reverse(result.begin(), result.end());
	_big = result;

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
	bigint dummy(1);
	bigint copy(*this);
	*this += dummy;
	return (copy);
}

bigint &bigint::operator<<=(const bigint &other)
{
	if (_big != "0")
	{
		const unsigned long amount = std::atol(other._big.c_str());
		_big.append(amount, '0');
	}
	return (*this);
}

bigint bigint::operator<<(const bigint &other) const
{
	bigint copy(*this);
	copy <<= other;
	return (copy);
}

bigint &bigint::operator>>=(const bigint &other)
{
	const unsigned int size = _big.size();
	const unsigned long amount = std::atol(other._big.c_str());
	size > amount
		? _big.erase(size - amount)
		:_big = "0";

	return (*this);
}

bool bigint::operator<(const bigint &other) const
{
	return (_big.size() != other._big.size())
		? _big.size() < other._big.size()
		: _big < other._big;
}

bool bigint::operator>(const bigint &other) const
{ return (other < *this); }

bool bigint::operator<=(const bigint &other) const
{ return !(*this > other); }

bool bigint::operator>=(const bigint &other) const
{ return !(*this < other); }

bool bigint::operator==(const bigint &other) const
{ return (_big == other._big); }

bool bigint::operator!=(const bigint &other) const
{ return(_big != other._big); }

std::ostream &operator<<(std::ostream &out, const bigint &other)
{
	out << other.getBig();
	return (out);
}
