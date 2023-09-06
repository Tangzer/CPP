#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
private:
	bool	_guardMode;
public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &other);
	ScavTrap& operator=(const ScavTrap &other);
	~ScavTrap();

	void	attack(const std::string &target);
	void 	guardGate();
};