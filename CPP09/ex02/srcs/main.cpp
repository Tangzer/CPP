#include "PmergeMe.hpp"

int	main(int ac, char **av) {
	std::vector<int> vec, vecSorted;
	std::deque<int> deq, deqSorted;
	struct timeval vecBegin, vecEnd, deqBegin, deqEnd;
	struct timeval dataBegin, dataEnd;
	int nbrElements = 0;

	gettimeofday(&dataBegin, 0);
	try
	{
		if (ac < 2)
			throw InvalidValueError();
		parseInput(av, vec, deq);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}
	gettimeofday(&dataEnd, 0);

	std::cout << "Before: ";
	printContainer(vec);
	gettimeofday(&deqBegin, 0);
	std::cout << "2 \n";
	deqSorted =  mergeInsert(deq);
	std::cout << "3 \n";
	gettimeofday(&deqEnd, 0);

	gettimeofday(&vecBegin, 0);
	vecSorted = mergeInsert(vec);
	gettimeofday(&vecEnd, 0);

	for (unsigned int i = 1; av[i]; i++)
		nbrElements++;
	// std::cout << "========================================================================================================================================================================" << std::endl;
	std::cout << "After: ";
	printContainer(vecSorted);
	std::cout << std::endl << "Time to process Data " << timing(dataBegin, dataEnd) << " us" << std::endl << std::endl;
	// std::cout << "---DEQ---" << std::endl;
	std::cout << "Time to process a range of "<< nbrElements <<" elements with std::deque : " << timing(deqBegin, deqEnd) << " us" << std::endl;
	std::cout << "Time to process a range of " << nbrElements <<" elements with std::vector : " << timing(vecBegin, vecEnd) << " us" << std::endl;
	std::cout << std::endl;

	// std::cout << "---VEC---" << std::endl;
	std::cout << "Is deque sorted : " <<  std::is_sorted(deqSorted.begin(), deqSorted.end()) << std::endl;
	std::cout << "Is vector sorted : " <<  std::is_sorted(vecSorted.begin(), vecSorted.end()) << std::endl;

	return (0);
}