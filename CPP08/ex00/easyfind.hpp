#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>

class NotFoundException : public std::exception {
	virtual const char *what() const throw() {
		return ("Value not found.");
	}
};

template<typename T>
typename T::iterator	easyfind(T & data, int n);

static std::ostream &operator<<(std::ostream &os, std::vector<int> const &v) {
	os << "[ ";
	for ( std::vector<int>::const_iterator it = v.begin(); it != v.end();
		  it++ ) {
		if ( it != v.begin() ) { os << ", "; }
		os << *it;
	}
	os << " ]";
	return (os);
}

#include "easyfind.tpp"

#endif