#include "BitcoinExchange.hpp"

int	main(int argc, char **av) {
	if (argc != 2) {
		std::cerr << "Error: usage ./btc <input.txt>" << std::endl;
		return 1;
	}

	// validExtension(av);
	BitcoinExchange	btcExchanger("data.csv");
	btcExchanger.process_input_file(av[1]);

	return 0;
}
