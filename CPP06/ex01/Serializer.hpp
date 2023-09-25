#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>
#include <iostream>

struct Data {
	int			nb;
	float 		flt;
	char 		c;
};

class Serializer {
public:
	uintptr_t	serialize(Data *ptr);
	Data* 		deserialize(uintptr_t raw);
};

std::ostream &operator<<(std::ostream &os,const Data myData);

#endif