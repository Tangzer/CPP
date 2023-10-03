#include "../RPN.hpp"

RPN::RPN() : _stack(), _arg(""), _argStatus(false) {}

RPN::RPN(onst std::string &arg) : _stack(), _arg(arg), _argStatus(Parse_Reverse_Polish_Notation()) {}

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

bool RPN::Parse_Reverse_Polish_Notation() {

}

int RPN::Reverse_Polish_Notation() {

}