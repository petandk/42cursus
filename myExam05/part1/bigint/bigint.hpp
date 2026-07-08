#pragma once

# include <iostream>
# include <algorithm>
# include <sstream>

class bigint
{
	public:
		bigint(unsigned int nbr = 0);
		bigint(const bigint &other):_big(other._big){};

		std::string getBig() const { return (_big); };

		bigint operator+(const bigint &other) const;
		bigint &operator+=(const bigint &other);

		bigint &operator++();
		bigint operator++(int);

		bigint operator<<(const bigint &other) const;
		bigint &operator<<=(const bigint &other);
		bigint &operator>>=(const bigint &other);

		bool operator<(const bigint &other) const;
		bool operator>(const bigint &other) const;
		bool operator<=(const bigint &other) const;
		bool operator>=(const bigint &other) const;
		bool operator==(const bigint &other) const;
		bool operator!=(const bigint &other) const;

	private:
		std::string _big;
};

std::ostream &operator<<(std::ostream &out, const bigint &other);
