#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "./Weapon.hpp"

class HumanA {
private:
    const Weapon&       _weaponRef;
    std::string         _name;
public:
    HumanA(std::string name, const Weapon& weaponRef);
    ~HumanA();

	void	attack();
};

#endif