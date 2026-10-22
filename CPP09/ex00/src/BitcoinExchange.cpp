#include "BitcoinExchange.hpp"

/*******************************************************************************
 * CONSTRUCTOR                                                                 *
 *                                                                             *
 * Changes the string to a C compatible format with c_str()                    *
 * Then declares an object to habilitate reading from DB content with ifstream *
 *                                                                             *
 * Ends loading the map of the DB in the _db atribute                          *
 ******************************************************************************/
BitcoinExchange::BitcoinExchange(const std::string db_name) {
	std::ifstream db(db_name.c_str());
	if(!db.is_open()) {
		std::cerr << "Error: could not open database file: " << db_name << std::endl;
		return;
	}

	_db = load_db(db);
}

/************************
 * CONSTRUCTOR by other *
 ***********************/
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _db(other._db) {}

/**************
 * OPERATOR = *
 *************/
BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other)
		_db = other._db;
	return *this;
}

/**************
 * DESTRUCTOR *
 *************/
BitcoinExchange::~BitcoinExchange(void) {}

////////////////////////////METHODS////////////////////////////
//-----------------------------------------------------------//

/*************************************************************************
 * LOAD_DB                                                               *
 * Reads the db given and returns it as a MAP container                  *
 *                                                                       *
 * Separates the date from the value wih the position of ',' char given. *
 * 	Value before the colon is a date, and anything after is a value.     *
 ************************************************************************/
std::map<std::string, double>	BitcoinExchange::load_db(std::ifstream& db) {
	std::map<std::string, double>	db_map;
	std::string						line;

	std::getline(db, line);
	while(std::getline(db, line)) {
		size_t	pos = line.find(',');
		if (pos == std::string::npos)
			continue;
		
		std::string	date = line.substr(0, pos);
		std::string	rate_str = line.substr(pos + 1);
		double rate = 0;
		if (store_safe_stod(rate_str, rate))
			db_map[date] = rate;
	}
	return db_map;

}

/***********************************************************************************
 * STORE_SAFE_STOD                                                                 *
 * Retruns false if str is not a valid number                                      *
 *                                                                                 *
 * Converts the rate given as a str to a stream so it can be extracted into value. *
 * If fails, is not a number or the value is bigger than 1000 returns false.       *
 **********************************************************************************/
bool	BitcoinExchange::store_safe_stod(const std::string& str, double& value) {
	std::stringstream	numberStream(str);
	numberStream >> value;
	if (numberStream.fail() || !numberStream.eof() || value > 1000)
		return false;
	return true;
}

/*************************************************************************************
 * VALIDATE_DATE                                                                     *
 * Checks if date is a real date between 2009 and 2026                               *
 *                                                                                   *
 * Checks that has all the needed characters are correct xxxx-xx-xx (year-month-day) *
 * Separates the date in year, month and day                                         *
 * Adjust the day to the real day counting leap years                                *
 *                                                                                   *
 * Checks that date given exists                                                     *
 ************************************************************************************/
bool	BitcoinExchange::validate_date(const std::string& date) {
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;

	int	year = std::atoi(date.substr(0, 4).c_str());
	int	month = std::atoi(date.substr(5, 2).c_str());
	int	day = std::atoi(date.substr(8, 2).c_str());

	int	days_in_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
		days_in_month[1] = 29;

	if (year < 2009 || year > 2026)
		return false;
	if (month < 1 || month > 12)
		return false;
	if (day < 1)
		return false;
	if (day > days_in_month[month - 1])
		return false;
	
	return true;
}

/*********************************************************************************
 * PROCESS_INPUT_FILE                                                            *
 *                                                                               *
 * Creates a stream called input from a C string type converted with c_str()     *
 *	Checks if can be opened and if it's empty.                                   *
 * Stores the content of the file inside @param line string.                     *
 *	Finds separator '|', checks if date is valid and stores the value.           *
 *	Searchs for the date more closely (earlier) in the BD and prints it's value. *
 ********************************************************************************/
void	BitcoinExchange::process_input_file(const std::string& filename) {
	std::ifstream	input(filename.c_str());
	if(!input.is_open()) {
		std::cerr << "Error: could not open file: " << filename << std::endl;
		return;
	}

	std::string	line;
	while(line.empty()) {

		if (!std::getline(input, line)) {
			std::cerr << "Error: file " << filename << " is empty" << std::endl;
			exit(1);
		}
	}

	while(std::getline(input, line)) {
		if (line.empty())
			continue;
		
		size_t	pos = line.find('|');
		if(pos == std::string::npos) {
			std::cerr << "Error: | separation missing" << line << std::endl;
			continue;
		}

		std::string	date = trim(line.substr(0, pos));
		if(!validate_date(date)) {
			std::cerr << "Error: invalid date => " << date << std::endl;
			continue;
		}

		double value = 0;
		if (!store_safe_stod(line.substr(pos + 1), value)) {
			std::cerr << "Error: invalid value => " << line.substr(pos + 1) << std::endl;
			continue;
		}

		std::map<std:: string, double>::iterator	it = _db.find(date);
		if (it == _db.end()) {
			it = _db.lower_bound(date);
			if(it == _db.begin()) {
				std::cerr << "Error: no earlier date available => " << date << std::endl;
				continue;
			}
			--it;
		}

		double result = value * it->second;
		if (result < 0) {
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}
		if (result > 1e+100) {
			std::cerr << "Error: number too large." << std::endl;
			continue;
		}

		std::cout << " => " << value << " = " << result << std::endl;

	}
}

/*******************************************************
 * VALIDEXTENSION                                      *
 *                                                     *
 * Checks if the extensión of the file is a valid one. *
 ******************************************************/
void	validExtension(char **av) {
	std::string	input = av[1];
	size_t	pos = input.rfind('.');
	std::string	extension = input.substr(pos + 1);

	if (extension != "txt") {
		std::cerr << "Error: file format must be .txt" << std::endl;
		exit(1);
	}
}

/**********************************************************************
 * TRIM                                                               *
 *                                                                    *
 * Removes the spaces and tabulations from the beginging and the end. *
 *********************************************************************/
std::string	trim(const std::string& str) {
	size_t	first = str.find_first_not_of(" \t");

	if(first == std::string::npos)
		return "";

	size_t	last = str.find_last_not_of(" \t");
	return str.substr(first, (last - first) + 1);
}
