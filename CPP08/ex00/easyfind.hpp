#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <list>

class NotFoundException : public std::exception {
	virtual const char *what() const throw() {
		return ("Value not found.");
	}
};

template<typename T>
typename T::iterator	easyfind(T & data, int n);

static std::ostream &operator<<(std::ostream &os, std::list<int> const &v) {
	os << "[ ";
	for ( std::list<int>::const_iterator it = v.begin(); it != v.end();
		  it++ ) {
		if ( it != v.begin() ) { os << ", "; }
		os << *it;
	}
	os << " ]";
	return (os);
}

#include "easyfind.tpp"

#endif