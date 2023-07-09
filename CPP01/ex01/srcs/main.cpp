#include "./Zombie.hpp"

int	main() {
	Zombie	*z;

	z = zombieHorde(4, "Bert");
	delete[] z;
	return (0);
}