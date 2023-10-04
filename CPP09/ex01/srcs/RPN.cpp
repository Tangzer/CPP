#include "../RPN.hpp"

RPN::RPN()
	: _stack(),
	_arg(""),
	_argStatus(false) {}

RPN::RPN(const std::string &arg)
	: _stack(),
	_arg(arg),
	_argStatus(parseReversePolishNotation()) {}

RPN::RPN(const RPN &copy) {
	if (this != &copy)
		*this = copy;
}

RPN & RPN::operator=(const RPN &copy) {
	if (this != &copy) {
		_stack = copy.getStack();
		_arg = copy.getArg();
		_argStatus = copy.getArgStatus();
	}
	return (*this);
}

RPN::~RPN() {}

/****************************/
/* --- MEMBER FUNCTIONS --- */
/****************************/

int RPN::reversePolishNotation() {
	long int		nbr = 0;
	long int		nbr1 = 0;
	long int		nbr2 = 0;
	long int		res = 0;
	long int		count = 0;
	std::string 	arg = getArg();

	for (std::string::const_iterator it = arg.begin(); it != arg.end(); ++it) {
		if (*it == ' ')
			continue ;
		if (*it >= '0' && *it <= '9') {
			nbr = nbr*10 + *it - '0';
			if (*(it + 1) == ' ' || (it + 1) == arg.end()) {
				_stack.push(nbr);
				nbr = 0;
				count++;
			}
		}
		else if (*it == '+' || *it == '-' || *it == '/' || *it == '*') {
			if (_stack.size() < 2)
				return (printError("not enough numbers to perform operation."));
			nbr1 = _stack.top();
			_stack.pop();
			nbr2 = _stack.top();
			_stack.pop();
			count--;
			switch (*it) {
				case '+' :
					res = nbr2 + nbr1;
					break ;
				case '-' :
					res = nbr2 - nbr1;
					break ;
				case '*' :
					res = nbr2 * nbr1;
					break ;
				case '/' :
					if (nbr1 == 0)
						return (printError("divide by zero is impossible."));
					res = nbr2 / nbr1;
					break ;
				default:
					break ;
			}
			_stack.push(res);
		}
		else
			return (printError("bad input."));
	}
	if (count == 0)
		return (printError("bad input."));
	if (count > 1)
		std::cout << "Error: too many operations." << std::endl;
	else
		std::cout << _stack.top() << std::endl;
	return (0);
}

bool RPN::parseReversePolishNotation() {
	std::string		arg;

	arg = getArg();
	for (std::string::iterator it = arg.begin(); it != arg.end(); ++it) {
		if (*it == ' ')
			continue ;
		if (*it >= '0' && *it <= '9') {
			if (*(it + 1) != ' ' && (it + 1) != arg.end())
				return (false);
			}
		else if (*it == '+' || *it == '-' || *it == '/' || *it == '*') {
			if (*(it + 1) != ' ' && (it + 1) != arg.end())
				return (false);
		}
		else
			return (false);
	}
	return (true);
}