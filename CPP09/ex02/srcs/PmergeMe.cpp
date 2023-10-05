#include "../PmergeMe.hpp"

void	parseInput(char **av, std::vector<int> &vector, std::deque<int> &deque) {
	int val;

	for(unsigned int i = 1; av[i]; i++)
	{
		for (unsigned int j = 0; av[i][j]; j++) {
			if (!isdigit(av[i][j]))
				throw (InvalidValueError());
		}
		std::stringstream	ss(av[i]);
		ss >> val;
		if (ss.fail() || val < 0)
			throw (InvalidValueError());
		vector.push_back(val);
		deque.push_back(val);
	}
}

double	timing(struct timeval begin, struct timeval end) {
	long 	seconds = end.tv_sec - begin.tv_sec;
	long 	microseconds = end.tv_usec - begin.tv_usec;
	double	elapsed = seconds*1e6 + microseconds;

	return (elapsed);
}