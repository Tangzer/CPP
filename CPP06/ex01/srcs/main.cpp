#include "Serializer.hpp"

int main() {
	Data 		myData;
	Serializer	serializer;

	myData.nb = 5;
	myData.c = 'H';
	myData.flt = 10.15;
	std::cout << myData;

	serializer.deserialize(serializer.serialize(&myData));

	std::cout << myData;
	return (0);
}