#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap:  virtual public ClapTrap
{
	
public:
	FragTrap(void);
	FragTrap(const FragTrap& copy);
	FragTrap(std::string name);
	~FragTrap(void);
	FragTrap &operator=(const FragTrap& FragTrap);

	void	highFivesGuys(void);
};

#endif