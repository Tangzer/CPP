#include "./Zombie.hpp"

int main(void)
{
	Zombie *z;

	randomChump("SlowZombie");
	z = newZombie("FastZombie");
	z->announce();
	delete(z);
	return (0);
}