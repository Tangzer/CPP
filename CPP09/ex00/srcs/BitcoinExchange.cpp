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

void	BitcoinExchange::createDB(const char *db) {
	std::ifstream	inputDB;
	std::string		header;
	std::string		date;
	float			value;
	unsigned int	count;

	inputDB.exceptions(std::ifstream::badbit);
	inputDB.open(db);
	if (inputDB.fail())
		throw (std::ios_base::failure("Failed to open file"));

	std::getline(inputDB, header);
	if (header != "date,exchange_rate")
		std::cerr << "Invalid file header..." << std::endl;
	count = 0;
	while (!inputDB.eof()) {
		if (!parseLine(inputDB, ",", false, date, value))
			continue ;
		_db.insert(std::make_pair(date, value));
		count++;
	}
	if (count == 0) {
		std::cout << "Error: Data file is empty\n";
		exit(1);
	}
	inputDB.close();
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
		if (!parseLine(input, " |", true, date, value))
			continue ;
		if (date < _db.begin()->first) {
			std::cerr << "Error: The date '" << date
					<< "' is earlier than the first date in the database!\n";
			continue ;
		}
		_mapIterator it = _db.lower_bound(date);
		if (it == _db.end() || it->first != date)
			it--;
		const float newval = value * it->second;
		std::cout << date << " => " << value
				  << " = " << newval << "\n";
	}
	input.close();
}