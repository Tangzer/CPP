#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <map>

class BitcoinExchange {
private:
	typedef std::greater_equal<std::string>		_compare;
	std::map<std::string, float, _compare>		_db;
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &copy);
	BitcoinExchange & operator=(const BitcoinExchange &copy);
	~BitcoinExchange();

	bool 		parseLine(std::ifstream &in, const char *delims, bool checkValue, std::string &date, float &value);
	void		createDB(const char *db);
	void		applyExchange(const char *file);

//	bool	printError(const std::string &line);
//	bool	checkDate(std::string &date);
//	bool	isValidDate(int year, int month, int day);
};

#endif