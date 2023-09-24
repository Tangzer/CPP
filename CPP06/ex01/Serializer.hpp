#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>
#include <iostream>

struct Data {
	int			nb;
	char		c;
	float		flt;
};

class Serializer {
public:
	uintptr_t	serialize(Data *ptr);
	Data* 		deserialize(uintptr_t raw);
};

std::ostream &operator<<(std::ostream &os, Data myData);

#endif