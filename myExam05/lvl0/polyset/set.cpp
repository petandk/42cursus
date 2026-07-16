#include "set.hpp"

bool set::has(int value) const
{
	return (_bag.has(value));
}

void set::insert(int value)
{
	if (!has(value))
		_bag.insert(value);
}

void set::insert(int *arr, int size)
{
	for (int i = 0; i < size; i++)
		insert(arr[i]);
}

void set::print() const
{
	_bag.print();
}

void set::clear()
{
	_bag.clear();
}

const searchable_bag &set::get_bag() const
{
	return (_bag);
}
