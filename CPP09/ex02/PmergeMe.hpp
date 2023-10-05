#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <list>
#include <vector>
#include <deque>
#include <sys/time.h>

void	parseInput(char **av, std::vector<int> &vector, std::deque<int> &deque);
double	timing(struct timeval begin, struct timeval end);

class	InvalidValueError : public std::exception {
	public:
		const char* what() const throw() {
			return ("Invalid input.");
		}
};

template<typename T>
void	printContainer(T &container);

template<typename Iterator>
void	printSpan(Iterator begin, Iterator end);

template<typename T, typename Iterator>
void	merge(Iterator begin, Iterator mid, Iterator end);

template<typename T, typename Iterator>
void	mergeSort(Iterator begin, Iterator end);

template<typename Iterator>
void	paireUp(Iterator begin, Iterator end);

template<typename T>
void	splitContainer(T &container, T &main, T &pend);

template<typename T>
T		getNumber(T nb);

template<typename T>
void	insert(T &main, T &pend);

template<typename T>
T 		mergeInsert(T &container);

#include "PmergeMe.tpp"

#endif