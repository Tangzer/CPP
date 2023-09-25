#include "Serializer.hpp"

int main() {
	Data 				myData;
	static Serializer	serializer;
	uintptr_t 			tmp = 0;

	myData.nb = 5;
	myData.c = 'H';
	myData.flt = 10.15;
	std::cout << "MyData :" << std::endl << myData << &myData << std::endl << std::endl;

	tmp = serializer.serialize(&myData);
	std::cout << "tmp = " << tmp << std::endl << std::endl;

	serializer.deserialize(tmp);
	std::cout << "MyData :" << std::endl << myData << &myData;

	return (0);
}