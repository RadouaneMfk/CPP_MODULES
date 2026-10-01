#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <iomanip>
#include <exception>
#include <stdlib.h>

class BitcoinExchange {
    private:
        std::map<std::string, float> _db;
    public:
        BitcoinExchange();
        BitcoinExchange(const std::string& dbFile);
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        void handleInput(const std::string& inputFile);
        bool parseLine(std::string line, std::string &date, std::string &value);
        ~BitcoinExchange();
};
