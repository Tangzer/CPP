#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>

class Zombie 
{
	private:
		std::string	_name;
	public:
		Zombie();
		void		set_name(std::string zombieName);
		void		announce();
		~Zombie();
};

Zombie			*newZombie(std::string name);
void			randomChump(std::string name);

#endif