#ifndef SPAN_HPP
#define SPAN_HPP


class Span {
private:
	unsigned int	N;
public:
	Span();
	Span(const unsigned int N);
	Span(const Span & copy);
	Span & operator=(const Span & copy);
	~Span();

	void			addNumber(int n);
	unsigned int	shortestSpan();
	unsigned int	longestSpan();
};

#endif