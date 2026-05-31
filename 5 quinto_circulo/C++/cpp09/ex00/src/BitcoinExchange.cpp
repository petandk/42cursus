#include "../inc/BitcoinExchange.hpp"
#include <fstream>
#include <string>
#include <map>
#include <stdexcept>
#include <sstream>
#include <cctype>
#include <iostream>

/*
    This function is only for debugging so it has to be in a ifdef.
    Otherwise -Werror will trigger because of unused function.
*/
#ifdef DEBUG
    static void printMap(const std::map<std::string, float> &mp, const std::string &header, int limit = 100)
    {
        std::cout << "[DEBUG] " << header << " (limited to " << limit << " lines)"<< std::endl;
        for (std::map<std::string, float>::const_iterator it = mp.begin(); it != mp.end()&& limit > 0; it++, limit--)
            std::cout << "\t" << it->first << " => " << it->second << std::endl;
    }
#endif

static bool isNumber(const std::string &str)
{
    for (size_t i = 0; i < str.size(); i++)
    {
        if (!std::isdigit(static_cast<unsigned char>(str[i])))
            return (false);
    }
    return (!str.empty());
}

static float strToFloat(const std::string &str)
{
    std::stringstream ss(str);
    float num;
    char other;

    // if cannot convert to int or there's anything after
    if (!(ss >> num) || (ss >> other)) 
        throw std::runtime_error("ERROR: Invalid number: " + str);
    return (num);
}
/*
    First parse string then convert to number then check if valid
    then check if is a leap year so we know the month limit.
    Finally I check if the day is < than month limit.
 */
static bool parseDate(const std::string &date)
{
    //date example: 2011-01-03
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return (false);
    std::string year = date.substr(0, 4);
    std::string month = date.substr(5, 2);
    std::string day = date.substr(8, 2);

    if (!isNumber(year) || !isNumber(month) || !isNumber(day))
        return (false);

    // % doesnt work with double so I had to convert them to int
    int y = static_cast<int>(strToFloat(year));
    int m = static_cast<int>(strToFloat(month));
    int d = static_cast<int>(strToFloat(day));

    if (y < 0 || m < 1 || m > 12 || d < 1)
        return (false);
    
    bool leap = ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0));
    int monthLimits[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (leap)
        monthLimits[1] = 29;
    return (d <= monthLimits[m - 1]); // true if valid day of month, false if > monthLimit
}

static std::map<std::string, float> readDB(std::ifstream &file, const std::string &header, const std::string &separator)
{
    std::string line;
    std::map<std::string, float> data;

    // runtime_error = This class defines the type of objects thrown as exceptions to report errors that can only be detected during runtime.
    
    if (!std::getline(file, line))
        throw std::runtime_error("ERROR: Cannot read the header.");
    if (line != header)
        throw std::runtime_error("ERROR: Invalid header: " + line);
    
    while (std::getline(file,line))
    {
        if (line.empty())
            continue;
        /*
            std::find -> iterator/pointer needs <algorithm>. Looks for a element in a range, NOT a substring
            std::string::find -> index(size_type) just from std::string. Looks for a substring
            since we want to find a substring std::string::find is it!!!
        */
        std::string::size_type separatorPos = line.find(separator);
        if (separatorPos == std::string::npos)
            throw std::runtime_error("ERROR: Missing separator in line: " + line);
        std::string date = line.substr(0, separatorPos);
        std::string value = line.substr(separatorPos + separator.size());
        if (!parseDate(date))
            throw std::runtime_error("ERROR: Wrong date or date format: " + date);
        float parsedValue = strToFloat(value);
        data[date] = parsedValue;
    }
    return (data);
}

static void processAndPrint(std::ifstream &file, std::map<std::string, float> &db, const std::string &header, const std::string &separator)
{
    std::string line;
    if (!std::getline(file, line))
        throw std::runtime_error("ERROR: Cannot read the header.");
    if (line != header)
        throw std::runtime_error("ERROR: Invalid header: " + line);
    while (std::getline(file,line))
    {
        if (line.empty())
            continue;
        try{
            std::string::size_type separatorPos = line.find(separator);
            if (separatorPos == std::string::npos)
            {
                std::cout << "Error: bad input => " << line << std::endl;
                continue;
            }
            std::string date = line.substr(0, separatorPos);
            if (!parseDate(date))
            {
                std::cout << "Error: bad input => " << date << std::endl;
                continue;
            }
            std::string value = line.substr(separatorPos + separator.size());
            float parsedValue = strToFloat(value);
            if (parsedValue < 0)
            {
                std::cout << "Error: not a positive number." << std::endl;
                continue;
            }
            if (parsedValue > 1000)
            {
                std::cout << "Error: too large a number." << std::endl;
                continue;
            }
            //lower_bound returns first element >= to date.
            //so if date is end() we need the last one, and if it returns a date that is
            //not the one we are searching, means the date is older, so we need the one before
            std::map <std::string, float>::iterator it = db.lower_bound(date);
            if (it == db.end() || it->first != date)
            {
                if (it == db.begin())
                {
                    std::cout << "Error: bad input => " << date << " precedes our data." << std::endl;
                    continue;
                }
                --it;
            }
            float result = parsedValue * it->second;
            std::cout << date << " => " << parsedValue << " = " << result << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
}

int btcExchange(const std::string &file)
{
    std::map<std::string, float> database;
    std::ifstream db("files/data.csv"), am(file.c_str());
    if (!db.is_open())
        throw std::runtime_error("ERROR: Cannot open the database.");
    if (!am.is_open())
        throw std::runtime_error("ERROR: Cannot open the input file.");
    database = readDB(db, "date,exchange_rate", ",");
    #ifdef DEBUG
        std::cout <<  "\033[1;33m\t-----debug message-----" << std::endl;
        printMap(database, "Database map");
        std::cout << "\033[0m";
    #endif
    processAndPrint(am, database, "date | value", " | ");
    return(0);
}