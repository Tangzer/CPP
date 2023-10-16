#include "PmergeMe.hpp"

template<typename T>
void	printContainer(T &container) {
	for (typename T::iterator it = container.begin(); it != container.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

template<typename Iterator>
void	printSpan(Iterator begin, Iterator end) {
	std::cout << "[";
	for (Iterator it = begin; it != end; it++)
		std::cout << *it << " ";
	std::cout << "]" << std::endl;

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
	typename T::iterator it = container.begin();
	typename T::iterator ite = container.end();

	for (; it != ite; it++) {
		if (std::distance(container.begin(), it) % 2 == 0)
			main.push_back(*it);
		else
			pend.push_back(*it);
	}
}

template<typename T>
T		getNumber(T nb) {
	if (nb == 0)
		return (0);
	else if (nb == 1)
		return (1);
	return (getNumber(nb - 1) + 2 * getNumber(nb - 2));
}

template<typename T, typename Iterator>
void	merge(Iterator begin, Iterator mid, Iterator end) {
	T 			lhs(begin, mid);
	T 			rhs(mid, end);
	Iterator 	insertPos = begin;
	Iterator 	leftIt = lhs.begin();
	Iterator 	rightIt = rhs.begin();

	while (leftIt != lhs.end() && rightIt != rhs.end())
	{
		if (*leftIt < *rightIt)
		{
			*insertPos = *rightIt;
			rightIt++;
			insertPos++;
			*insertPos = *rightIt;
			rightIt++;
		}
		else
		{
			*insertPos = *leftIt;
			leftIt++;
			insertPos++;
			*insertPos = *leftIt;
			leftIt++;
		}
		insertPos++;
	}
	while (leftIt != lhs.end())
	{
		*insertPos = *leftIt;
		leftIt++;
		insertPos++;
	}
	while (rightIt != rhs.end())
	{
		*insertPos = *rightIt;
		rightIt++;
		insertPos++;
	}
}

template<typename T, typename Iterator>
void	mergeSort(Iterator begin, Iterator end) {
	int			distance;
	Iterator	mid;

	if (std::distance(begin, end) <= 2)
		return ;
	distance = std::distance(begin, end) / 2;
	if (distance % 2 == 1)
		distance += 1;
	mid = std::next(begin, distance);
	mergeSort<T>(begin, mid);
	mergeSort<T>(mid, end);
	merge<T>(begin, mid, end);
}

template<typename T>
void	insert(T &main, T &pend) {
	std::size_t		maxSize = pend.size();
	std::size_t		indexJ = 2;
	std::size_t		jn = getNumber(indexJ);
	std::size_t		jn_1 = getNumber(indexJ - 1);
	std::size_t		jn_2 = getNumber(indexJ - 2);

	typename T::iterator itPendStart = pend.begin();
	typename T::iterator itPendEnd = pend.begin();
	typename T::iterator itInsertPos = main.begin();

	unsigned int insertedAmount = 0;

	while (jn <= maxSize)
	{
		if (jn == 1)
		{
			main.insert(main.begin(), *itPendStart);
			insertedAmount++;
		}
		else
		{
			std::advance(itPendEnd, jn_1 - jn_2);
			std::advance(itPendStart, jn - jn_1);
			typename T::iterator tmpIt = itPendStart;
			while (tmpIt != itPendEnd)
			{
				std::size_t	toAdvance = jn + insertedAmount + 1;
				//Really not optimal for lists as it goes through the whole list all the time.
				typename T::iterator itMainEnd = main.begin();
				if (toAdvance > main.size())
					itMainEnd = main.end();
				else
					std::advance(itMainEnd, toAdvance);
				itInsertPos = std::lower_bound(main.begin(), itMainEnd, *tmpIt);
				main.insert(itInsertPos, *tmpIt);
				insertedAmount++;
				tmpIt--;
			}
		}
		indexJ++;
		jn_2 = jn_1;
		jn_1 = jn;
		jn = getNumber(indexJ);
	}
	if (++itPendStart != pend.end())
	{
		while (itPendStart != pend.end())
		{
			itInsertPos = std::lower_bound(main.begin(), main.end(), *itPendStart);
			main.insert(itInsertPos, *itPendStart);
			itPendStart++;
		}
	}
}

template<typename T>
T		mergeInsert(T &container) {
	bool	trailing = false;
	int		trailingVal = 0;
	T		main;
	T		pend;

	if (container.size() % 2 == 1) {
		trailing = true;
		trailingVal = container.back();
		container.pop_back();
	}
	paireUp(container.begin(), container.end());
	mergeSort<T>(container.begin(), container.end());
	splitContainer(container, main, pend);
	if (trailing == true)
		pend.push_back(trailingVal);
	insert(main, pend);
	return (main);
}