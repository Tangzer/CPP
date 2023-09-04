#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include <string>

class HumanA {
private:
    const Weapon&   _weaponRef;
    std::string     _name;
public:
    HumanA(std::string name, const Weapon& weaponRef);
    ~HumanA(void);

	void    attack(void);
};

#endif