#include "PmergeMe.hpp"

template<typename T>
void	printContainer(T &container) {
	for (typename T::iterator it = cont.begin(); it != cont.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

//template<typename Iterator>
//void	printSpan(Iterator begin, Iterator end) {
//	std::cout << "[";
//	for (Iterator it = begin; it != end; it++)
//		std::cout << *it << " ";
//	std::cout << "]" << std::endl;
//
//}

template<typename T, typename Iterator>
void	merge(T &container, Iterator begin, Iterator mid, Iterator end) {

}

template<typename T, typename Iterator>
void	merge(T &container, Iterator begin, Iterator end) {

}

template<typename Iterator>
void	paireUp(Iterator begin, Iterator end) {
	Iterator	it;

	it = begin;
	while (it != end) {
		if (*it < *(std::next(it, 1)))
			std::swap(*it, *(std::next(it, 1)));
		it = std::next(it, 2);
	}
}

template<typename T>
void	splitContainer(T &container, T &main, T &pend) {

}

template<typename T>
T		getNumber(T nb) {
	if (nb == 0)
		return (0);
	else if (nb == 1)
		return (1);
	return (getNumber(nb - 1) + 2 * getNumber(nb - 2));
}

template<typename T>
void	insert(T &main, T &pend) {

}

template<typename T>
T mergeInsert(T &cont) {

}