#include "easyfind.hpp"
#include <iostream>

template<typename T>
typename T::iterator	easyfind(T & data, int n) {
	if (std::find(data.begin(), data.end(), n) == data.end())
		throw NotFoundException();
	return (std::find(data.begin(), data.end(), n));
}