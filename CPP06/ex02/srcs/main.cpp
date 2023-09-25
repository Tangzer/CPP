#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void) {
	Base* ret;

	srand(time(NULL));
	int nb = rand() % 3;
	if (nb == 0)
		ret = new A();
	else if (nb == 1)
		ret = new B();
	else
		ret = new C();
	return (ret);
}

void identify(Base *p) {
	std::cout << "Identifying pointer type...\n";
	if (dynamic_cast<A *>(p))
		std::cout << "Type A detected\n";
	if (dynamic_cast<B *>(p))
		std::cout << "Type B detected\n";
	if (dynamic_cast<C *>(p))
		std::cout << "Type C detected\n";
}

void identify(Base &p) {
	std::cout << "Identifying reference type...\n";
	try {
		p = dynamic_cast<A &>(p);
		std::cout << "Type A detected\n";
	} catch (std::exception &e) {}

	try {
		p = dynamic_cast<B &>(p);
		std::cout << "Type B detected\n";
	} catch (std::exception &e) {}

	try {
		p = dynamic_cast<C &>(p);
		std::cout << "Type C detected\n";
	} catch (std::exception &e) {}
}

int main()
{
	static Base* base = generate();
	std::cout << std::endl;

	identify(base);
	std::cout << std::endl;
	identify(*base);
	std::cout << std::endl;

	delete base;
	return (0);
}