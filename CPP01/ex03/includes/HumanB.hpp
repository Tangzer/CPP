#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include <string>

class HumanB {
private:
	Weapon      *_weaponPtr;
	std::string	_name;
public:
	HumanB(std::string name);
	~HumanB(void);

	void	setWeapon(Weapon& weaponName);
	void	attack(void);
};

#endif