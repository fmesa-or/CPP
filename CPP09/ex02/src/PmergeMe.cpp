#include "PmergeMe.hpp"

/***************
 * CONSTRUCTOR *
 **************/
PmergeMe::PmergeMe(void) {}

/********************
 * COPY CONSTRUCTOR *
 *******************/
PmergeMe::PmergeMe(const PmergeMe& other) :
	_bigDequeContainer(other._bigDequeContainer),
	_smallDequeContainer(other._smallDequeContainer),
	_finalDequeContainer(other._finalDequeContainer),
	_bigVectorContainer(other._bigVectorContainer),
	_smallVectorContainer(other._smallVectorContainer),
	_finalVectorContainer(other._finalVectorContainer) {}

/******************
 * EQUAL OPERATOR *
 *****************/
PmergeMe&	PmergeMe::operator=(const PmergeMe& other) {
	if (this != &other) {
		_bigDequeContainer = other._bigDequeContainer;
		_smallDequeContainer = other._smallDequeContainer;
		_finalDequeContainer = other._finalDequeContainer;
		_bigVectorContainer = other._bigVectorContainer;
		_smallVectorContainer = other._smallVectorContainer;
		_finalVectorContainer = other._finalVectorContainer;
	}
	return *this;
}

/**************
 * DESTRUCTOR *
 *************/
PmergeMe::~PmergeMe(void) {}

////////////////////////////METHODS////////////////////////////
//-----------------------------------------------------------//

// JACOBSTHAL

/*********************************************************************************
 * GENERATE JACOBSTHAL SEQUENCE                                                  *
 *                                                                               *
 * Builds 'sequence' using the Jacobsthal recurrence until it reaches 'limit'.   *
 * The generated values are later used by the insertion-order logic.             *
 *                                                                               *
 * 1. Returns immediately when 'limit' is zero.                                  *
 * 2. Initialises 'jacob_prev' and 'jacob_curr' to the first recurrence values.  *
 * 3. Pushes each value while 'jacob_curr' is lower than 'limit' and updates the *
 * 	recurrence state.                                                            *
 * 4. Appends the final value that reaches or exceeds 'limit'.                   *
 ********************************************************************************/
void	PmergeMe::generateJacobsthalSequence(std::vector<size_t>& sequence, size_t limit) {
	if (limit == 0)
		return;

	size_t	jacob_prev = 1;
	size_t	jacob_curr = 1;

	while (jacob_curr < limit) {
		sequence.push_back(jacob_curr);
		size_t	jacob_next = jacob_curr + 2 * jacob_prev;	// J(n) = J(n - 1) + 2 * J(n - 2)
		jacob_prev = jacob_curr;
		jacob_curr = jacob_next;
	}
	sequence.push_back(jacob_curr); // Saves first value overpassing or same as limit
}

/***************************************************************************************************
 * GENERATE INSERTION ORDER                                                                        *
 *                                                                                                 *
 * Builds 'insertionIndexes' for the Jacobsthal insertion strategy.                                *
 * The method records positions to insert and then appends the remaining values.                   *
 *                                                                                                 *
 * 1. Returns immediately when 'elementsToInsert' is zero.                                         *
 * 2. Generates 'jacobsthalPositions' with 'generateJacobsthalSequence'.                           *
 * 3. Tracks inserted indices in 'alreadyInserted' and walks each Jacobsthal range from 'endRange' *
 * 	down to 'previousJacob'.                                                                       *
 * 4. Appends any unseen index still left after the Jacobsthal sequence is processed.              *
 **************************************************************************************************/
void	PmergeMe::generateInsertionOrder(std::vector<size_t>& insertionIndexes, size_t elementsToInsert) {
	if (elementsToInsert == 0)
		return;
	
		std::vector<size_t>	jacobsthalPositions;
		generateJacobsthalSequence(jacobsthalPositions, elementsToInsert);

		std::vector<bool>	alreadyInserted(elementsToInsert, false);
		size_t	previousJacob = 0;

		for (size_t i = 0; i < jacobsthalPositions.size(); ++i) {
			size_t	currentJacob = jacobsthalPositions[i];
			size_t	endRange = (currentJacob <= elementsToInsert) ? currentJacob : elementsToInsert;

			for (size_t pos = endRange; pos > previousJacob; --pos) {
				size_t	idx = pos - 1;
				if(!alreadyInserted[idx]) {
					insertionIndexes.push_back(idx);
					alreadyInserted[idx] = true;
				}
			}
			previousJacob = currentJacob;
		}

		for (size_t i = 0; i < elementsToInsert; ++i) {
			if (!alreadyInserted[i])
				insertionIndexes.push_back(i);
		}
}

// DEQUE

/****************************************************************************************************************
 * SPLIT PAIRS                                                                                                  *
 *                                                                                                              *
 * Pairs adjacent values from 'container' and separates the smaller value into 'smallContainer'.                *
 * The larger value is stored in 'bigContainer'; an odd final element is also appended to 'smallContainer'.     *
 *                                                                                                              *
 * 1. Iterates over the deque by pairs using the index step of two.                                             *
 * 2. Compares 'container[i]' and 'container[i + 1]' to keep the lower value in 'smallContainer' and the higher *
 * 	value in 'bigContainer'.                                                                                    *
 * 3. Adds the final unmatched element from 'container.back()' to 'smallContainer' when the deque size is odd.  *
 ***************************************************************************************************************/
void	PmergeMe::splitPairs(const std::deque<int>& container, std::deque<int>& smallContainer, std::deque<int>& bigContainer) {
	for (size_t i = 0; i + 1 < container.size(); i += 2) {
		if (container[i] < container[i + 1]) {
			smallContainer.push_back(container[i]);
			bigContainer.push_back(container[i + 1]);
		}
		else {
			smallContainer.push_back(container[i + 1]);
			bigContainer.push_back(container[i]);
		}
	}
	if (container.size() % 2 != 0)
		smallContainer.push_back(container.back());
}

/*******************************************************************************************************
 * FORD JOHNSON SORT                                                                                   *
 *                                                                                                     *
 * Recursively sorts 'container' by splitting it into 'smallContainer' and 'bigContainer'.             *
 * The function inserts the smaller half into the larger half using the Jacobsthal order.              *
 *                                                                                                     *
 * 1. Returns immediately when 'container' has one element or fewer.                                   *
 * 2. Creates 'smallContainer' and 'bigContainer' and fills them with 'splitPairs'.                    *
 * 3. Recursively sorts 'bigContainer' and inserts 'smallContainer' with 'binaryInsertWithJacobsthal'. *
 * 4. Copies the final sorted result back into 'container' and stores it in '_finalDequeContainer'.    *
 ******************************************************************************************************/
void	PmergeMe::fordJohnsonSort(std::deque<int>& container) {
	if (container.size() <= 1)
		return;

	std::deque<int>	smallContainer, bigContainer;

	splitPairs(container, smallContainer, bigContainer);
	fordJohnsonSort(bigContainer);
	binaryInsertWithJacobsthal(smallContainer, bigContainer);

	container = bigContainer;
	_finalDequeContainer = bigContainer;
}

/******************************************************************************************
 * BINARY INSERT WITH JACOBSTHAL                                                          *
 *                                                                                        *
 * Uses 'insertionOrder' to insert the values from 'src' into the correct place in 'dst'. *
 * The method relies on 'std::lower_bound' so each integer is placed in order.            *
 *                                                                                        *
 * 1. Returns immediately when 'src' is empty.                                            *
 * 2. Generates 'insertionOrder' with 'generateInsertionOrder' using the size of 'src'.   *
 * 3. For each index in 'insertionOrder', finds the insertion position with               *
 * 	'std::lower_bound' and inserts 'src[idx]' into 'dst'.                                 *
 *****************************************************************************************/
void	PmergeMe::binaryInsertWithJacobsthal(std::deque<int>& src, std::deque<int>& dst) {
	if (src.empty())
		return;

	std::vector<size_t>	insertionOrder;
	generateInsertionOrder(insertionOrder, src.size());

	for (size_t i = 0; i < insertionOrder.size(); ++i) {
		size_t	idx = insertionOrder[i];
		std::deque<int>::iterator	it = std::lower_bound(dst.begin(), dst.end(), src[idx]);
		dst.insert(it, src[idx]);
	}
}

/******************************************************************************************
 * DELETE DUPLICATES                                                                      *
 *                                                                                        *
 * Removes duplicate values from 'container' while preserving the first occurrence order. *
 * The function rebuilds the deque using a set to keep track of values already seen.      *
 *                                                                                        *
 * 1. Initialises 'seenValues' and 'result' to track unique integers.                     *
 * 2. Iterates over 'container' and pushes each unseen value into 'result'.               *
 * 3. Assigns the filtered deque back to 'container' once the pass finishes.              *
 *****************************************************************************************/
void	deleteDuplicates(std::deque<int>& container) {
	std::set<int>	seenValues;
	std::deque<int>	result;

	for (size_t i = 0; i < container.size(); ++i) {
		if (seenValues.find(container[i]) == seenValues.end()) {
			seenValues.insert(container[i]);
			result.push_back(container[i]);
		}
	}
	container = result;
}

/********************************************************************************************
 * PARSE ARGS                                                                               *
 *                                                                                          *
 * Validates each argument in 'argv', converts accepted values to integers, and stores them *
 * 	in 'container'.                                                                         *
 * The function throws on invalid input and removes duplicates before returning.            *
 *                                                                                          *
 * 1. Iterates over each string in 'argv' until the terminator is reached.                  *
 * 2. Checks 'isNumber', 'isIntRange', and 'isPositive' for every value and throws          *
 * 	'std::invalid_argument' on the first failure.                                           *
 * 3. Pushes the validated integer into 'container' and removes repeated values with        *
 * 	'deleteDuplicates'.                                                                     *
 *******************************************************************************************/
void	parseArgs(std::deque<int>& container, char **argv) {
	for (size_t i = 0; argv[i]; ++i) {
		if (!isNumber(argv[i]))
			throw std::invalid_argument("argument is not a number.");
		if (!isIntRange(argv[i]))
			throw std::invalid_argument("argument number is out of INT range.");
		if (!isPositive(argv[i]))
			throw std::invalid_argument("argument number must be positive");

		container.push_back(atoi(argv[i]));
	}

	deleteDuplicates(container);
}

// VECTOR

/***************************************************************************************************
 * SPLIT PAIRS                                                                                     *
 *                                                                                                 *
 * Pairs adjacent values from 'container' and stores the smaller element in 'smallContainer'.      *
 * The larger element goes to 'bigContainer'; an odd final member is appended to 'smallContainer'. *
 *                                                                                                 *
 * 1. Loops over the vector in steps of two using the index increment of two.                      *
 * 2. Compares 'container[i]' and 'container[i + 1]' and sends the smaller value to                *
 * 	'smallContainer' and the larger one to 'bigContainer'.                                         *
 * 3. When the vector size is odd, pushes 'container.back()' into 'smallContainer' as the last     *
 * 	unmatched value.                                                                               *
 **************************************************************************************************/
void	PmergeMe::splitPairs(const std::vector<int>& container, std::vector<int>& smallContainer, std::vector<int>& bigContainer) {
	for (size_t i = 0; i + 1 < container.size(); i += 2) {
		if (container[i] < container[i + 1]) {
			smallContainer.push_back(container[i]);
			bigContainer.push_back(container[i + 1]);
		}
		else {
			smallContainer.push_back(container[i + 1]);
			bigContainer.push_back(container[i]);
		}
	}
	if (container.size() % 2 != 0)
		smallContainer.push_back(container.back());
}

/*****************************************************************************************************
 * FORD JOHNSON SORT                                                                                 *
 *                                                                                                   *
 * Recursively sorts 'container' by splitting it into 'smallContainer' and 'bigContainer'.           *
 * The function inserts the smaller half back into the larger half using the Jacobsthal order.       *
 *                                                                                                   *
 * 1. Stops immediately when 'container' contains zero or one value.                                 *
 * 2. Creates 'smallContainer' and 'bigContainer' and fills them with 'splitPairs'.                  *
 * 3. Recursively sorts 'bigContainer' and then inserts 'smallContainer' with                        *
 *	'binaryInsertWithJacobsthal'.                                                                    *
 * 4. Writes the final sorted result back into 'container' and stores it in '_finalVectorContainer'. *
 ****************************************************************************************************/
void	PmergeMe::fordJohnsonSort(std::vector<int>& container) {
	if (container.size() <= 1)
		return;

	std::vector<int>	smallContainer, bigContainer;

	splitPairs(container, smallContainer, bigContainer);
	fordJohnsonSort(bigContainer);
	binaryInsertWithJacobsthal(smallContainer, bigContainer);

	container = bigContainer;
	_finalVectorContainer = bigContainer;
}

/************************************************************************************************
 * BINARY INSERT WITH JACOBSTHAL                                                                *
 *                                                                                              *
 * Uses 'insertionOrder' to insert each value from 'src' into its sorted location in 'dst'.     *
 * The method depends on 'std::lower_bound' to place each integer in order.                     *
 *                                                                                              *
 * 1. Returns immediately when 'src' is empty.                                                  *
 * 2. Generates 'insertionOrder' from the size of 'src' and 'generateInsertionOrder'.           *
 * 3. For each index in 'insertionOrder', selects a value from 'src', finds the insertion point *
 *	in 'dst', and inserts it with 'std::vector<int>::insert'.                                   *
 ***********************************************************************************************/
void	PmergeMe::binaryInsertWithJacobsthal(std::vector<int>& src, std::vector<int>& dst) {
	if (src.empty())
		return;

	std::vector<size_t>	insertionOrder;
	generateInsertionOrder(insertionOrder, src.size());

	for (size_t i = 0; i < insertionOrder.size(); ++i) {
		size_t	idx = insertionOrder[i];
		std::vector<int>::iterator	it = std::lower_bound(dst.begin(), dst.end(), src[idx]);
		dst.insert(it, src[idx]);
	}
}

/*********************************************************************************************
 * DELETE DUPLICATES                                                                         *
 *                                                                                           *
 * Removes duplicate integers from 'container' while preserving the first occurrence order.  *
 * The helper rebuilds the vector using a set to track values already seen.                  *
 *                                                                                           *
 * 1. Initialises 'seenValues' and 'result' before the scan.                                 *
 * 2. Iterates over every element in 'container' and appends only unseen values to 'result'. *
 * 3. Replaces 'container' with the deduplicated vector once the scan ends.                  *
 ********************************************************************************************/
void	deleteDuplicates(std::vector<int>& container) {
	std::set<int>		seenValues;
	std::vector<int>	result;

	for (size_t i = 0; i < container.size(); ++i) {
		if (seenValues.find(container[i]) == seenValues.end()) {
			seenValues.insert(container[i]);
			result.push_back(container[i]);
		}
	}
	container = result;
}

/***********************************************************************************************
 * PARSE ARGS                                                                                  *
 *                                                                                             *
 * Validates each argument in 'argv', converts accepted values to integers, and stores them in *
 *	'container'.                                                                               *
 * The function throws on invalid input and removes duplicates before returning.               *
 *                                                                                             *
 * 1. Iterates over each string in 'argv' until the end of the array.                          *
 * 2. Runs 'isNumber', 'isIntRange', and 'isPositive' on every element and throws              *
 * 	'std::invalid_argument' on the first failure.                                              *
 * 3. Pushes each valid integer into 'container' and then removes repeated values with         *
 * 	'deleteDuplicates'.                                                                        *
 **********************************************************************************************/
void	parseArgs(std::vector<int>& container, char **argv) {
	for (size_t i = 0; argv[i]; ++i) {
		if (!isNumber(argv[i]))
			throw std::invalid_argument("argument is not a number.");
		if (!isIntRange(argv[i]))
			throw std::invalid_argument("argument number is out of INT range.");
		if (!isPositive(argv[i]))
			throw std::invalid_argument("argument number must be positive");

		container.push_back(atoi(argv[i]));
	}

	deleteDuplicates(container);
}

// UTILITIES
/************************************************************************************************************
 * PRINT                                                                                                    *
 *                                                                                                          *
 * Prints the final sorted values stored in '_finalDequeContainer'.                                         *
 * Each element is displayed in brackets and separated by a comma and a space.                              *
 *                                                                                                          *
 * 1. Starts the output with the label 'Final Container:'.                                                  *
 * 2. Iterates over '_finalDequeContainer' with the index 'i' and prints each value inside square brackets. *
 * 3. Adds a comma and a space between elements except after the final one and prints the newline.          *
 ***********************************************************************************************************/
void	PmergeMe::print(void) {
	std::cout << "Final Container: ";

	for (size_t i = 0; i < _finalDequeContainer.size(); ++i) {
		std::cout << "[" << _finalDequeContainer[i] << "]";
		if (i != _finalDequeContainer.size() - 1)
			std::cout << ", ";
	}

	std::cout << std::endl;
}

// PARSE

/*************************************************************************************************************
 * IS NUMBER                                                                                                 *
 *                                                                                                           *
 * Checks whether 'arg' contains only decimal digits and an optional leading '-'.                            *
 * The function is used to reject malformed numeric arguments before conversion.                             *
 *                                                                                                           *
 * 1. Returns false immediately for an empty string.                                                         *
 * 2. Sets 'start' to one when the first character is '-' and scans the remaining characters with 'isdigit'. *
 * 3. Returns false on the first non-digit character and true for valid numeric strings.                     *
 ************************************************************************************************************/
bool	isNumber(const std::string& arg) {
	if (arg.empty())
		return false;

	size_t	start = (arg[0] == '-') ? 1 : 0;
	if (start == arg.size())
		return false;

	for (size_t i = start; i < arg.size(); ++i) {
		if (!isdigit(static_cast<unsigned char>(arg[i])))
			return false;
	}
	return true;
}

/*********************************************************************************************
 * IS RANGE                                                                                  *
 *                                                                                           *
 * Converts 'arg' with 'std::strtol' and checks that it fits within 'INT_MIN' and 'INT_MAX'. *
 * The helper also rejects invalid numeric conversions reported through 'errno'.             *
 *                                                                                           *
 * 1. Resets 'errno' before calling 'std::strtol' on 'arg.c_str()'.                          *
 * 2. Stores the parsed value in 'num' and verifies that the call did not fail.              *
 * 3. Returns true only when 'num' remains within the integer range.                         *
 ********************************************************************************************/
bool	isIntRange(const std::string& arg) {
	char	*end;

	errno = 0;
	long	num = std::strtol(arg.c_str(), &end, 10);
	return (errno == 0 && num >= INT_MIN && num <= INT_MAX);
}

/***********************************************************************************************
 * IS POSITIVE                                                                                 *
 *                                                                                             *
 * Returns true only for non-negative integer strings after rejecting '-0' values.             *
 * The helper is used to block negative values before they are pushed into a container.        *
 *                                                                                             *
 * 1. Checks the special '-0' case when 'arg' has more than one character.                     *
 * 2. Uses 'std::atoi' on 'arg.c_str()' and accepts only values greater than or equal to zero. *
 **********************************************************************************************/
bool	isPositive(const std::string& arg) {
		if (arg.size() > 1 && arg[0] == '-' && arg[1] == '0')
			return false;
		return std::atoi(arg.c_str()) >= 0;
}


//////////////// PRINT

/******************************************************************************
 * PRINT BEFORE                                                               *
 *                                                                            *
 * Prints the original input arguments preceded by 'Before:'.                 *
 * The helper shows the values supplied to the program before sorting.        *
 *                                                                            *
 * 1. Prints the label 'Before:' as the first output text.                    *
 * 2. Loops from 'i = 0' to 'argc - 1' and prints each argument in 'argv[i]'. *
 * 3. Ends the output with a newline after all values are shown.              *
 *****************************************************************************/
void	printBefore(int argc, char **argv) {
	std::cout << "Before:";

	for (int i = 0; i < argc - 1; ++i)
		std::cout << " " << argv[i];

	std::cout << std::endl;
}

/************************************************************************************************
 * PRINT MSG                                                                                    *
 *                                                                                              *
 * Measures elapsed time in microseconds and prints the result for the selected container type. *
 * The function reports how long the sort took on 'argc - 1' elements.                          *
 *                                                                                              *
 * 1. Computes 'elapsed_time' from the difference between 'end' and 'start'.                    *
 * 2. Checks whether 'type' is 'DEQUE' or another container type.                               *
 * 3. Prints the element count and elapsed microseconds with the matching container label.      *
 ***********************************************************************************************/
void	printMsg(e_container type, clock_t start, clock_t end, int argc) {
	double	elapsed_time = static_cast<double>(end - start) * 1000000.0 / CLOCKS_PER_SEC;

	if (type == DEQUE)
		std::cout << "Time to process a range of " 
			<< (argc - 1) << " elements with std::deque: "
			<< elapsed_time << " us" << std::endl;
	else
		std::cout << "Time to process a range of " 
			<< (argc - 1) << " elements with std::vector: "
			<< elapsed_time << " us" << std::endl;
}

/************************************************************************************************
 * PRINT AFTER                                                                                  *
 *                                                                                              *
 * Prints every integer in 'container' after the 'After:' label.                                *
 * The helper renders the final deque content in sorted order.                                  *
 *                                                                                              *
 * 1. Prints 'After:' before iterating.                                                         *
 * 2. Uses a deque iterator to walk each element from 'container.begin()' to 'container.end()'. *
 * 3. Displays each value with a leading space and terminates with a newline.                   *
 ***********************************************************************************************/
void	printAfter(std::deque<int>& container) {
	std::cout << "After:";

	std::deque<int>::iterator	it = container.begin();
	for(; it != container.end(); ++it)
		std::cout << " " << *it;
	std::cout << std::endl;
}

/*************************************************************************************************
 * PRINT AFTER                                                                                   *
 *                                                                                               *
 * Prints every integer in 'container' after the 'After:' label.                                 *
 * The helper displays the final vector content in sorted order.                                 *
 *                                                                                               *
 * 1. Prints 'After:' before iterating.                                                          *
 * 2. Uses a vector iterator to walk each element from 'container.begin()' to 'container.end()'. *
 * 3. Displays each value with a leading space and terminates with a newline.                    *
 ************************************************************************************************/
void	printAfter(std::vector<int>& container) {
	std::cout << "After:";

	std::vector<int>::iterator	it = container.begin();
	for(; it != container.end(); ++it)
		std::cout << " " << *it;
	std::cout << std::endl;
}
