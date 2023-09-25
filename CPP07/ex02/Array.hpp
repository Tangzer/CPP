#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array {
private:
	T*				_tab;
	unsigned int	_size;
public:
	Array();
	Array(const unsigned int n);
	Array(const Array<T> &copy);
	Array<T> &operator=(const Array<T> &copy);
	~Array();

	unsigned int 	size() const {return(_size);};
};

#endif