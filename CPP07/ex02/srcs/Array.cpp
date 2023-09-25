#include "Array.hpp"

template <typename T>
Array<T>::Array() : _tab(NULL), _size(0) {
	std::cout << "Default Array Constructor called\n";
}

template <typename T>
Array<T>::Array(const unsigned int n): _tab(new T[n]), _size(n) {
	std::cout << "Array Constructor w/ uInt param\n";
}

template <typename T>
Array<T>::Array(const Array<T> &copy): _tab(NULL), _size(0) {
	std::cout << "Array Copy Constructor\n";
	*this = copy;
}

template <typename T>
Array<T>& Array<T>::operator=(const  Array<T> &copy) {
	std::cout << "Array Assignment Operator\n";
	if (this != &copy)
	{
		if (_size > 0)
			delete [] _tab;
		_size = copy._size;
		_tab = new T[copy._size];
		for (unsigned int i = 0; i < _size; i++)
			_tab[i] = copy._tab[i];
	}
}