#include <iostream>

int main(void)
{
	std::string brain = "HI THIS IS BRAIN";
	std::string *brainPTR = &brain;
    std::string &brainREF = brain;

    std::cout << "The memory address of the string 'brain' = " << &brain << std::endl;
    std::cout << "The memory address held by brainPTR = " << &brainPTR << std::endl;
	std::cout << "The memory address held by brainREF = " << &brainREF << std::endl;

    std::cout << std::endl;
    
    std::cout << "Value of string 'brain' = " << brain << std::endl;
	std::cout << "Value pointed to brain by brainPTR = " << *brainPTR << std::endl;
	std::cout << "Value pointed to brain by brainREF = " << brainREF << std::endl;
}