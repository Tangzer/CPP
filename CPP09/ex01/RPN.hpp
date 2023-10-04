#ifndef CPP_RPN_HPP
#define CPP_RPN_HPP

#include <iostream>
#include <string>
#include <stack>

class RPN {
private:
	std::stack<long int>	_stack;
	std::string 			_arg;
	bool					_argStatus;
public:
	RPN();
	RPN(const std::string &arg);
	RPN(const RPN &copy);
	RPN &operator=(const RPN &copy);
	~RPN();

	std::stack<long int>	getStack() const {return (_stack);}
	std::string 			getArg() const {return (_arg);}
	bool		 			getArgStatus() const {return (_argStatus);}
	int						printError(const std::string str);

	int						reversePolishNotation();
	bool					parseReversePolishNotation();
};

#endif