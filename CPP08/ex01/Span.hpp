#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

class Span {
private:
	unsigned int		_maxSize;
	std::vector<int>	_tab;
public:
	Span();
	Span(unsigned int N);
	Span(const Span & copy);
	Span & operator=(const Span & copy);
	~Span();

	void			addNumber(int n);
	unsigned int	shortestSpan();
	unsigned int	longestSpan();
	void			displayTab();
	void			randomFill();
	unsigned int	getSize() {return (_maxSize);}
	unsigned int	tabSize() {return (_tab.size());}

	class AddNumberException : public std::exception {
		public:
			virtual const char* what() const throw() {
				return ("Error : can't add number.");
			}
	};
	class NoSpanException : public std::exception {
		public:
			virtual const char* what() const throw() {
				return ("Error : no span can be found (array is empty or has only 1 number stored).");
			}
	};
	class WrongSizeException : public std::exception {
		public:
			virtual const char* what() const throw() {
				return ("Size must be a positive number!");
			}
};
};

#endif