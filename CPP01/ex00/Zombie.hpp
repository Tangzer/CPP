#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>

class Zombie 
{
private:
	std::string	_name;
public:
	Zombie();
	~Zombie();

	void		set_name(std::string zombieName);
	void		announce();
};

Zombie			*newZombie(std::string name);
void			randomChump(std::string name);

#endif