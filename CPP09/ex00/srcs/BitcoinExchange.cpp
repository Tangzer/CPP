#include "BitcoinExchange.hpp"

/****************************/
/* ---- CONSTRUCTORS  ----- */
/****************************/

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) : _db(copy._db) {}

BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange &copy) {
	if (this != &copy)
		_db = copy._db;
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

/****************************/
/* --- MEMBER FUNCTIONS --- */
/****************************/

static bool printError(const std::string &line) {
	std::cerr << "Error: bad input => " << line << '\n';
	return (false);
}

static bool isValidDate(int year, int month, int day) {
	if (month == 4 || month == 6 || month == 9 || month == 11) {
		if (day > 30)
			return (false);
	}
		//Vérifier années bisextiles
	else if (month == 2) {
		if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
			if (day > 29) {
				return (false);
			}
		}
		else {
			if (day > 28) {
				return (false);
			}
		}
	}
	return (true);
}

static bool checkDate(std::string &date) {
	std::string	year;
	std::string	month;
	std::string	day;
	int			intYear;
	int			intMonth;
	int			intDay;
	int			count;
	long int	len;

	count = 0;
	len = date.length();
	if (len != 10)
		return (printError(date));
	for (int i = 0; i < (int)date.length(); i++) {
		if (i != 0 && date[i] == '-')
			count++;
		else if (date[i] < '0' || date[i] > 9)
			return (printError(date));
		else if (count == 0)
			year += date[i];
		else if (count == 1)
			month += date[i];
		else if (count == 2)
			day += date[i];
	}
	if (year.length() != 4 || month.length() != 2 || day.length() != 2)
		return (printError(date));
	intYear = atoi(year.c_str());
	if (intYear <= 0)
		return (printError(date));
	intMonth = atoi(month.c_str());
	if (intMonth < 1 || intMonth > 12)
		return (printError(date));
	intDay = atoi(day.c_str());
	if (intDay < 1 || intDay > 31)
		return (printError(date));
	if (!isValidDate(intYear, intMonth, intDay))
		return (printError(date));
	return (true);
}

bool BitcoinExchange::parseLine(std::ifstream &in, const char *delims, bool checkValue, std::string &date, float &value) {
	std::string		line;
	size_t 			i;
	const char		*valuePtr;
	char 			*endPtr;

	std::getline(in, line);
	if (in.fail())
		return (false);
	//find date
	i = line.find_first_of(delims);
	if (i == std::string::npos)
		return (printError(line));
	date = line.substr(0, i);
	if (!checkDate(date))
		return (printError(date));
	//find value
	i = line.find_first_not_of(delims, i);
	valuePtr = line.c_str() + i;
	value = std::strtof(valuePtr, &endPtr);
	if (value < 0 || (checkValue && value > 1000)) {
		if (value < 0)
			return (printError("not a positive number"));
		else if (value > 1000)
			return (printError("number is too high"));
		else
			return (printError(std::string(valuePtr)));
	}
	return (true);
}

void	BitcoinExchange::createDB(const char *db) {
	std::ifstream	inputDB;
	std::string		header;
	std::string		date;
	float			value;

	inputDB.exceptions(std::ifstream::badbit);
	inputDB.open(db);
	if (inputDB.fail())
		throw (std::ios_base::failure("Failed to open file"));

	std::getline(inputDB, header);
	if (header != "date,exchange_rate")
		std::cerr << "Invalid file header..." << std::endl;

	while (!inputDB.eof()) {
		if (!parseLine(inputDB, ",", false, date, value))
			continue ;
		_db.insert(std::make_pair(date, value));
	}
}

void	BitcoinExchange::applyExchange(const char *file) {
	std::ifstream	input;
	std::string		header;
	std::string		date;
	float			value;

	input.exceptions(std::ifstream::badbit);
	input.open(file);
	if (input.fail())
		throw (std::ios_base::failure("Error: failed to open file."));
	std::getline(input, header);
	if (header != "date | value")
		throw (std::runtime_error("wrong header."));
	while (!input.eof()) {
		if (!parseLine(input, "|", true, date, value))
			continue ;
//		_db::iterator rate = _db.upper_bound(date);
	}
	input.close();
}