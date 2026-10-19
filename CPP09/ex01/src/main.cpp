#include "RPN.hpp"

int	main(int argc, char **argv) {
	if (argc != 2 || !argv || !argv[1] || argv[1][0] == '\0' ) {
		std::cerr << "Error usage: ./RPN \"<num1> <num2> <arithmetich operator>\"" << std::endl;
		return 1;
	}

	RPN	polishCalc;
	polishCalc.processCalc(argv[1], polishCalc);
	polishCalc.printResult();

	return 0;
}
