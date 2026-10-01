#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string& dbFile) {
    std::string line;
    std::string date;
    std::string value;

    std::ifstream File(dbFile.c_str());
    if (!File.is_open())
		throw std::runtime_error("cannot open db file!");
	std::getline(File, line);
    while (std::getline(File, line)) {
        std::stringstream ss(line);
        std::getline(ss, date, ',');
        std::getline(ss, value);
		_db[date] = atof(value.c_str());
    }
	File.close();
}

BitcoinExchange::BitcoinExchange() {};

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
    this->_db = other._db;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other)
        this->_db = other._db;
    return *this;
}

bool isValidNumber(std::string& value) {
    int point = 0;
    for (size_t i = 0; i < value.length(); i++)
    {
        if (i == 0 && (value[0] == '+' || value[0] == '-'))
            i++;
        if (i != 0 && value[i] == '.') {
            point++;
            i++;
        }
        if (!isdigit(value[i]) || point > 1)
            return false;
    }
    return true;
}

bool BitcoinExchange::parseLine(std::string line, std::string &date, std::string &value)
{
    std::stringstream ss(line);
    std::string year, month, day;
    bool bad_date = false;
    bool bad_value = false;

    date = line;
    value = "";

    if (line.find('|') != std::string::npos)
    {
        std::getline(ss, date, '|');
        std::getline(ss, value);

        size_t start = date.find_first_not_of(' ');
        size_t end = date.find_last_not_of(' ');
        date = date.substr(start, end - start + 1);

        start = value.find_first_not_of(' ');
        end = value.find_last_not_of(' ');
        value = value.substr(start, end - start + 1);
    }

    if (!value.empty() && !date.empty()
        && date.length() == 10
        && date[4] == '-'
        && date[7] == '-')
    {
        year = date.substr(0, 4);
        month = date.substr(5, 2);
        day = date.substr(8, 2);

        for (size_t i = 0; i < year.length(); i++)
            if (!isdigit(year[i]))
                bad_date = true;

        if (month < "01" || month > "12"
            || day < "01" || day > "31"
            || !isdigit(month[0]) || !isdigit(month[1])
            || !isdigit(day[0]) || !isdigit(day[1]))
            bad_date = true;

        if (!isValidNumber(value))
            bad_value = true;

        if (atof(value.c_str()) < 0)
        {
            std::cerr << "Error: not a positive number.\n";
            return false;
        }

        if (atof(value.c_str()) > 1000)
        {
            std::cerr << "Error: too large a number.\n";
            return false;
        }
    }
    else
        bad_date = true;

    if (bad_date)
    {
        std::cerr << "Error: bad input => " << date << "\n";
        return false;
    }

    if (bad_value)
    {
        std::cerr << "Error: bad input => " << value << "\n";
        return false;
    }

    return true;
}

void BitcoinExchange::handleInput(const std::string& inputFile)
{
    std::ifstream file(inputFile.c_str());
    if (file.fail())
        throw std::runtime_error("cannot open input file!");

    std::string line;
    std::string date;
    std::string value;

    std::getline(file, line);

    while (std::getline(file, line))
    {
        if (!parseLine(line, date, value))
            continue;

        std::map<std::string, float>::iterator it = _db.lower_bound(date);
        float result;

        if (it != _db.end() && it->first == date)
        {
            result = atof(value.c_str()) * it->second;
        }
        else if (it != _db.begin())
        {
            --it;
            result = atof(value.c_str()) * it->second;
        }
        else
        {
            std::cout << "Error: date is too early => "
                      << date << "\n";
            continue;
        }

        std::cout << date << " => "
                  << value << " = "
                  << result << std::endl;
    }
}

BitcoinExchange::~BitcoinExchange() {};
