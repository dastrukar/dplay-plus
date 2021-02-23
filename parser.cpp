#include <iostream>
#include <string>

#include "parser.h"


namespace parser
{
// Start of namespace "parser"

/*
 * Returns the following values:
 * 0: If none of the below are true
 * 1: If the first char is '#'
 * 2: If the first char is '$'
 * 3: If the first char is ':'
 */
int check_line_type(std::string str)
{
    switch (str[0])
    {
        case '#': return 1; break;
        case '$': return 2; break;
        case ':': return 3; break;
    }

    return 0;
}

/*
 * Prints out a message depending on the given type
 * 0: Invalid variable
 * 1: Variable is missing '='
 */
void print_variable_error(int type)
{
    switch (type)
    {
        case 0: std::cout << "$Invalid variable, ignoring."; break;
        case 1: std::cout << "$Variable is missing '=', ignoring."; break;
    }
}

std::string get_variable_name(std::string str)
{
    std::string var;

    if (str.length() > 8)
    {
        for (int i = 1; i <= 6; i++)
        {
            var += str[i];
        }
        return var;
    }
    print_variable_error(0);
    return "";
}

std::string get_variable_value(std::string str)
{
    std::string value;
            int length = str.length();

    if (length > 8)
    {
        if (str[7] != '=') { print_variable_error(1); goto none; }

        for (int i = 8; i < length; i++)
        {
            value += str[i];
        }
        return value;
    }

    none:
    return "";
}

// End of namespace "parser"
}
