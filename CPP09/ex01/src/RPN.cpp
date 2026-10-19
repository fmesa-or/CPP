#include "RPN.hpp"

/*******************************************************************************
 * CONSTRUCTOR                                                                 *
 *                                                                             *
 * Initializes an empty stack to store the numbers used in the calculation.    *
 ******************************************************************************/
RPN::RPN(void) {}

/************************
 * CONSTRUCTOR by other *
 ***********************/
/**
 * Copies the stack from another RPN calculator.
 */
RPN::RPN(const RPN& other) : _numsPile(other._numsPile) {}

/********************************************************************************
 * OPERATOR =                                                                   *
 *                                                                              *
 * Copies the stack from another RPN calculator when the objects are different. *
 *******************************************************************************/
RPN&	RPN::operator=(const RPN& other) {
	if (this != &other)
		_numsPile = other._numsPile;
	return *this;
}

/**************************************
 * DESTRUCTOR                         *
 *                                    *
 * Releases the calculator resources. *
 *************************************/
RPN::~RPN(void) {}

////////////////////////////METHODS////////////////////////////
//-----------------------------------------------------------//

/****************************************************
 * PUSH                                             *
 *                                                  *
 * Pushes a number from the input inside _numsPile. *
 ***************************************************/
void	RPN::push(std::string& arg) {
	_numsPile.push(atoi(arg.c_str()));
}

/************************************************************************
 * PERFORM_OPERATION                                                    *
 *                                                                      *
 * Performs the operation given using the two numbers at the top of the *
 *	stack and pushes the result back into it.                           *
 ***********************************************************************/
void	RPN::performOperation(std::string& op) {
	if (_numsPile.size() < 2) {
		std::cerr << "Error: must be at least 2 numbers in stack to operate" << std::endl;
		exit(1);
	}

	long	firstNum = _numsPile.top();
	_numsPile.pop();
	long	secondNum = _numsPile.top();
	_numsPile.pop();

	long	result;

	switch (op[0]) {
		case '+':
			result = secondNum + firstNum;
			break;
		case '-':
			result = secondNum - firstNum;
			break;
		case '*':
			result = secondNum * firstNum;
			break;
		case '/':
			if (firstNum == 0) {
				std::cerr << "Error: can't divide by zero" << std::endl;
				exit(1);
			}
			result = secondNum / firstNum;
			break;
		default:
			std::cerr << "Error: bad operations" << std::endl;
			exit(1);
	}

	if (result < INT_MIN || result > INT_MAX) {
		std::cerr << "Error: number out of int range" << std::endl;
		exit(1);
	}

	_numsPile.push(static_cast<int>(result));
}

/************************************************************************
 * PROCESS_CALC                                                         *
 *                                                                      *
 * Reads each token from the input expression and processes numbers and *
 *	operators in RPN order.                                             *
 ***********************************************************************/
void	RPN::processCalc(char *av, RPN& polishCalc) {
	std::istringstream	iss(av);
	std::string			arg;

	while (iss >> arg && isValid(arg)) {
		if (isNumber(arg)) {
			polishCalc.push(arg);
			continue;
		}
		polishCalc.performOperation(arg);
	}
}

/************************************************************************
 * PRINT_RESULT                                                         *
 * Validates the final stack and prints the result of the calculation.  *
 ************************************************************************/
void	RPN::printResult(void) const {
	if (_numsPile.empty()) {
		std::cerr << "Error: empty or invalid expression" << std::endl;
		exit(1);
	}
	if (_numsPile.size() > 1) {
		std::cerr << "Error: invalid expression (remaining numbers in stack)" << std::endl;
		exit(1);
	}
	std::cout << _numsPile.top() << std::endl;
}

/********************************************************
 * PRINT_STACK                                          *
 *                                                      *
 * Prints all the values currently stored in the stack. *
 *******************************************************/
void	RPN::printStack(void) const {
	std::stack<int>	copy = _numsPile;

	for (size_t i = 0; !copy.empty(); ++i) {
		std::cout << "[" << i << "] " << copy.top() << std::endl;
		copy.pop();
	}
}

/*****************************************************
 * IS_NUMBER                                         *
 *                                                   *
 * Checks if the given string represents an integer. *
 ****************************************************/
bool	isNumber(const std::string& arg) {
	if (arg.empty())
		return false;
	if (arg == "-") // Aquí revisa todo el string
		return false;
	for (size_t i = 0; i < arg.size(); ++i) {
		if (i == 0 && arg[i] == '-')
			continue;
		if (!isdigit(arg[i]))
			return false;
	}
	return true;
}

/*****************************************************************
 * IS_OPERATOR                                                   *
 *                                                               *
 * Checks if the given string is one of the supported arithmetic *
 *	operators.                                                   *
 ****************************************************************/
bool	isOperator(const std::string& arg) {
	return ((arg.size() == 1)
		&& (arg[0] == '+'
		|| arg[0] == '-'
		|| arg[0] == '*'
		|| arg[0] == '/'));
}

/***********************************************************************
 * IS_VALID                                                            *
 *                                                                     *
 * Checks if the given token is a valid number or arithmetic operator. *
 **********************************************************************/
bool	isValid(std::string& arg) {
	if (isOperator(arg))
		return true;
	
	if (isNumber(arg)) {
		std::istringstream	iss(arg);
		int					num;

		iss >> num;
		if (num > 9) {
			std::cerr << "Error: 9 is max value allowed" << std::endl;
			exit(1);
		}

		return true;
	}

	std::cerr << "Error: Input allowed <-, +, *, /> and numbers from 0 to 9" << std::endl;
	exit(1);
}
