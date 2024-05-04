#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <limits>
#include <iostream>
#include <string>

class ScalarConverter
{
    public:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &New_ScalarConverter);
    ScalarConverter &operator=(const ScalarConverter &copy);
    ~ScalarConverter();
    static void  convert(std::string raw_string);
};

#endif