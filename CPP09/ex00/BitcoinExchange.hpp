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
	BitcoinExchange() {}
	BitcoinExchange(const BitcoinExchange &copy) : _db(copy._db) {}
	BitcoinExchange &operator=(const BitcoinExchange &copy) {if (this != &copy) {_db = copy._db;} return (*this);}
	~BitcoinExchange() {}

	void		applyExchange(const char *file);
};

#endif