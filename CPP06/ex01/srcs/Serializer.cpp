#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data *ptr) {
	std::cout << "Serializing Data\n";
	uintptr_t ret = reinterpret_cast<uintptr_t>(ptr);
	std::cout << "uintptr_t value : " << ret << std::endl;
	return (ret);
}

Data* Serializer::deserialize(uintptr_t raw) {
	std::cout << "Deserializing Data\n";
	return (reinterpret_cast<Data *>(raw));
}

std::ostream &operator<<(std::ostream &os, Data myData) {
	os << myData.nb << std::endl;
	os << myData.c << std::endl;
	os << myData.flt << std::endl;
	return (os);
}