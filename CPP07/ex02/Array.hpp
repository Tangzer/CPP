#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array {
private:
	T* 			_tab;
	unsigned int _size;
public:
	Array() : _tab(NULL), _size(0) {
		std::cout << "Default Array Constructor called\n";
	}

	Array(const unsigned int n) : _tab(new T[n]), _size(n) {
		std::cout << "Array Constructor w/ uInt parameter called\n";
	}

	Array(const Array<T> &copy) : _tab(NULL), _size(0) {
		std::cout << "Array Copy Constructor called\n";
		*this = copy;
	}

	Array<T> &operator=(const Array<T> &copy) {
		std::cout << "Array Assignment Operator called\n";
		if (this != &copy) {
			if (_size > 0)
				delete[] _tab;
			_size = copy._size;
			_tab = new T[copy._size];
			for (unsigned int i = 0; i < _size; i++)
				_tab[i] = copy._tab[i];
		}
		return *this;
	}

	T &operator[](const int i) const {
		if (i < 0 || static_cast<unsigned int>(i) >= _size)
			throw InvalidIndexException();
		return (_tab[i]);
	}

	unsigned int size() const {
		return _size;
	};

	class InvalidIndexException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return ("Invalid index.");
		}
	};
};

#endif
