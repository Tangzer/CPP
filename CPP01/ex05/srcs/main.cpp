#include "../Harl.hpp"

int main(int ac, char **av) {
    if (ac == 2)
    {
        Harl    Karen;

        Karen.complain(av[1]);
        return (0);
    }
    std::cerr << "The program needs 2 arguments" << std::endl;
    return (1);
}