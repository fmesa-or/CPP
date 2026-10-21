#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <deque>
#include <vector>
#include <set>
#include <sstream>
#include <ctime>
// #include <cstdlib>
// #include <cctype>
// #include <stdexcept>

class PmergeMe {
	private:
		std::deque<int>	_bigDequeContainer;
		std::deque<int>	_smallDequeContainer;
		std::deque<int>	_finalDequeContainer;

		std::vector<int>	_bigVectorContainer;
		std::vector<int>	_smallVectorContainer;
		std::vector<int>	_finalVectorContainer;

		// Jacobsthal
		void	generateJacobsthalSequence(std::vector<size_t>& sequence, size_t limit);
		void	generateInsertionOrder(std::vector<size_t>& insertionIndexes, size_t elementsToInsert);

	public:
		PmergeMe(void);
		PmergeMe(const PmergeMe& other);
		PmergeMe&	operator=(const PmergeMe& other);
		~PmergeMe(void);

		// DEQUE
		void	splitPairs(const std::deque<int>& container, std::deque<int>& smallContainer, std::deque<int>& bigContainer);
		void	fordJohnsonSort(std::deque<int>& container);
		void	binaryInsertWithJacobsthal(std::deque<int>& src, std::deque<int>& dst);

		// VECTOR
		void	splitPairs(const std::vector<int>& container, std::vector<int>& smallContainer, std::vector<int>& bigContainer);
		void	fordJohnsonSort(std::vector<int>& container);
		void	binaryInsertWithJacobsthal(std::vector<int>& src, std::vector<int>& dst);

		// UTILITIES
		void	print(void);
};

// PARSE
bool	isNumber(const std::string& arg);
bool	isIntRange(const std::string& arg);
bool	isPositive(const std::string& arg);

// DEQUE
void	parseArgs(std::deque<int>& container, char **argv);
void	deleteDuplicates(std::deque<int>& container);

// VECTOR
void	parseArgs(std::vector<int>& container, char **argv);
void	deleteDuplicates(std::vector<int>& container);

//////////////// PRINT

enum	e_container {
	DEQUE,
	VECTOR
};

void	printBefore(int argc, char **argv);
void	printMsg(e_container type, clock_t start, clock_t end, int argc);

// Print DEQUE
void	printAfter(std::deque<int>& container);

// Print VECTOR
void	prontAfter(std::vector<int>& container);

// TEMPLATE
template	<typename Container>
void	printContainerStatement(int argc, char **argv, Container& container) {
	printBefore(argc, argv);
	printAfter(container);
}

#endif
