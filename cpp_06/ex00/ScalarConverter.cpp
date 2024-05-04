#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
    std::cout << "Default Constructor is called ." << std::endl;
}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy)
{
    std::cout << "Copy Assignment is called" << std::endl ;   
}

ScalarConverter::ScalarConverter(const ScalarConverter &New_ScalarConverter)
{
    std::cout << "ScalarConverter copy constructor called" << std::endl;
    *this = New_ScalarConverter;
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "destructor is called " << std::endl;
}

static void convert(std::string raw_string)
{
    //flags:
    int empty_flag = 0;
    int char_flag = 0;
    int int_flag = 0;
    int float_flag = 0;
    int double_flag = 0;
    int symbol_flag = 0;
    int non_displayable_characters = 0;
    int Error_flag = 0;
    int f_flag = 0;
    int dot_flag = 0;
    //counters:
    int plus_counter = 0;
    int minus_counter = 0;
    int dot_counter = 0;
    int f_counter = 0;

    int Actual_value;


    int i = 0;
    int j = raw_string.length() - 1;

    // Handling whitespaces
    while ( i < raw_string.length() && raw_string[i] == ' ')
        i++;
    while ( j >= 0 && raw_string[j] == ' ')
        j--;
    //check if the string is empty 
    if (i > j)
        empty_flag = 1;

    // 1 character case :
    // non_displayable_characters case:
    if (i == j && (raw_string[i] <= 0 && raw_string[i] >= 31)) 
        non_displayable_characters = 1;
    // char case:
    if (i == j && !(raw_string[i] >= '0' && raw_string[i] <= '9'))
        char_flag = 1;
    // int case:
    if (i == j && (raw_string[i] >= '0' && raw_string[i] <= '9'))
        int_flag = 1;
    // symbol case:
    if (i == j && ((raw_string[i] >= 32 && raw_string[i] <= 47) || (raw_string[i] >= 58 && raw_string[i] <= 64) || (raw_string[i] >= 91 && raw_string[i] <= 96 ) || (raw_string[i] >= 123 && raw_string[i] <= 127)))
        symbol_flag = 1;

    // multiple characters :
    // handling if the first character is not a + or - or a digit error 
    if (raw_string[i] != '+'  ||  raw_string[i] != '-' || !(raw_string[i] >= '0' && raw_string[i] <= '9'))
        Error_flag = 1;

    // handling if there's multiple + or - or . or f 
    while ( i < raw_string.length())
    {
        if (raw_string[i] == '+')
        {
            plus_counter++;
            if (plus_counter > 1)
                Error_flag = 1;
            i++;
        }
        else if (raw_string[i] == '-')
        {
            minus_counter++;
            if (plus_counter > 1)
                Error_flag = 1;
            i++;
        }
        else if (raw_string[i] == '.')
        {
            dot_counter++;
            if (plus_counter > 1)
                Error_flag = 1;
            i++;
        }
        else if (raw_string[i] == 'f')
        {
            f_counter++;
            if (plus_counter > 1)
                Error_flag = 1;
            i++;
        }
        else 
            i++;
    }
    i = 0;
    // handling if there's multiple symboles or characters anything but numbers :
    while (i < raw_string.length())
    {
        if ((raw_string[i] >= 0  && raw_string[i] <= 47) || (raw_string[i] >= 58  && raw_string[i] <= 101 || (raw_string[i] >= 103  && raw_string[i] <= 127)))
            Error_flag = 1;
        i++;
    }
    i = 0;
    // flags check:
    while (i < raw_string.length())
    {
        if (raw_string[i] == 'f')
            f_flag = 1;
        if (raw_string[i] == '.')
            dot_flag = 1;
        i++;
    }
    // handling if the '.' is the last character ;
    while (i < raw_string.length())
    {
        if (raw_string[i] == '.')
        {
            // if '.' is the last character.
            if (i + 1 > raw_string.length())
                Error_flag = 1;
            
            // if '.' is not followed by a degit .
            if (!(raw_string[i + 1] >= '0' && raw_string[i + 1] <= '9'))
                Error_flag = 1;
        }
        i++;
    }
    i = 0;
    //handling if the 'f' is not the last character ;
    while (i < raw_string.length())
    {
        if (raw_string[i] == 'f')
        {
            // if not 'f' not the last character
            if (!(i + 1 > raw_string.length()))
                Error_flag = 1;
            
            // if 'f' is followed by a degit 
            if ((raw_string[i + 1] >= '0' && raw_string[i + 1] <= '9')) 
                Error_flag = 1;
        }
        i++;
    }
    i = 0;

    // Int / float / double checks :
    if (Actual_value >= INT_MAX && Actual_value <= INT_MIN && !f_flag && !dot_flag)
        //Actual_value is int ;
    else if (Actual_value >= FLOAT_MAX && Actual_value <= FLOAT_MIN && f_flag && dot_flag)
        //Actual_value is float ;
    else if (Actual_value >= DOUBLE_MAX && Actual_value <= DOUBLE_MIN && !f_flag && dot_flag)
        //Actual_value is double ;
    else
        Error_flag = 1;
    
    

    

    // Hard code the scientific cases :

    
    

    

    




}