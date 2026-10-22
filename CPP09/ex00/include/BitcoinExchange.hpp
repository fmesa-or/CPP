#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <iostream>
#include <fstream>
#include <sstream>

class BitcoinExchange {
	private:
		std::map<std::string, double>	_db;
		std::map<std::string, double>	load_db(std::ifstream& db);
		bool							store_safe_stod(const std::string& str, double& value);
		bool							validate_date(const std::string& date);

	public:
		BitcoinExchange(const std::string db_name);
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange&	operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		void				process_input_file(const std::string& filename);

};

void		validExtension(char **av);
std::string	trim(const std::string& str);

#endif
