#include "PmergeMe.hpp"

int	main(int argc, char **argv) {
	if (argc == 1) {
		std::cerr << "Error: usage: ./pmerge <numbers>" << std::endl;
		return 1;
	}

	argv++;

	std::deque<int>		dequeContainer;
	std::vector<int>	vectorContainer;
	try {
		parseArgs(dequeContainer, argv);
		parseArgs(vectorContainer, argv);
	} catch (const std::invalid_argument& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}

	PmergeMe	algorithm = PmergeMe();

	clock_t	startDeque = clock();
	algorithm.fordJohnsonSort(dequeContainer);
	clock_t	endDeque = clock();

	printContainerStatement(argc, argv, dequeContainer);

	clock_t	startVector = clock();
	algorithm.fordJohnsonSort(vectorContainer);
	clock_t	endVector = clock();

	printMsg(DEQUE, startDeque, endDeque, argc);
	printMsg(VECTOR, startVector, endVector, argc);
	return 0;
}
