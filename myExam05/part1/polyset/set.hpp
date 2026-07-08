#pragma once

# include "searchable_bag.hpp"
class set
{
	public:
		set(searchable_bag &bag):_bag(bag){};
		set(const set &other):_bag(other._bag){};
		~set(){};

		bool has(int vaue) const;
		void insert(int value);
		void insert(int *arr, int size);
		void print() const;
		void clear();
		const searchable_bag &get_bag() const;

	private:
		searchable_bag &_bag;
};
