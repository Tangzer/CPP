#include "Span.hpp"

Span::Span() : _maxSize(0) {};

Span::Span(const unsigned int N) : _maxSize(N) {};

Span::Span(const Span & copy) {
	*this = copy;
};

Span &Span::operator=(const Span & copy) {
	if (this != &copy)
	{
		_maxSize = copy._maxSize;
		_tab = copy._tab;
	}
	return (*this);
};

Span::~Span() {};

/****************************/
/* --- MEMBER FUNCTIONS --- */
/****************************/

void	Span::addNumber(int n) {
	if (_tab.size() < _maxSize)
		_tab.push_back(n);
	else
		throw AddNumberException();
}

unsigned int	Span::shortestSpan() {
	long				ret;
	std::vector<int>	tmp;

	if (_tab.size() < 2) {
		throw NoSpanException();
	}
	ret = std::numeric_limits<long>::max();
	tmp = _tab;
	std::sort(tmp.begin(), tmp.end());
	for (unsigned int i = 0; i + 1 < _maxSize ; i++)
		ret = (std::min(ret, static_cast<long>((tmp[i + 1] - tmp[i]))));
	return (ret);
}

unsigned int	Span::longestSpan() {
	std::vector<int> tmp;

	if (_tab.size() < 2)
		throw NoSpanException();
	tmp = _tab;
	std::sort(tmp.begin(), tmp.end());
	return (tmp.back() - tmp.front());
}

/*********************************/
/* --- XTRA MEMBER FUNCTIONS --- */
/*********************************/

int		generateRandomNumber() {
	return (std::rand() % 100);
}

void	Span::randomFill() {
	int	(*f)() = generateRandomNumber;

	_tab.resize(_maxSize);
	generate(_tab.begin(), _tab.end(), f);
}

void	display(int n) {
	std::cout << n << ", ";
}

void	Span::displayTab() {
	void (*d)(int) = display;
	for_each(_tab.begin(), _tab.end(), d);
	std::cout << std::endl;
}