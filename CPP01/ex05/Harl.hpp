#ifndef HARL_HPP
# define HARL_HPP

#include <string>
# include <iostream>

class Harl {
    private:
        void	(Harl::*_fPtr[4])(void);
        void    debug();
        void    info();
        void    warning();
        void    error();
    public:
        Harl();
        void    complain(std::string level);
        ~Harl();
};

#endif