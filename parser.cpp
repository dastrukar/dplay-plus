#include <cctype>
#include <iostream>
#include <string>

#include "parser.h"


namespace parser
{
// Start of namespace "parser"

/*
 * Removes starting whitespace
 */
std::string remove_starting_whitespace(std::string str)
{
    int length = str.length();

    for (int i = 0; i < length; i++)
    {
        if (!std::isspace(str[i]))
        {
            if (i == 0) { break; }
            else { str.erase(0, i); break; }
        }
    }

    return str;
}

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


/*
 * Attempts to return the variable name on the given line.
 */
std::string get_variable_name(std::string str)
{
    std::string var;

    str = remove_starting_whitespace(str);

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


/*
 * Attempts to return the value of a variable from the given string
 */
std::string get_variable_value(std::string str)
{
    std::string value;
    int length = str.length();

    str = remove_starting_whitespace(str);

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


std::string get_preset_name(std::string str)
{
    std::string name;
    int length = str.length();

    for (int i = 1; i < length; i++)
    {
        name += str[i];
    }

    // Remove any excess whitespace/curly brackets
    for (int i = length - 2; i < length; i--)
    {
        if (name[i] == ' ' || name[i] == '{' || name[i] == '}') { name.erase(i); }
        else { std::cout << "\nbreak!"; break; }
    }

    return name;
}


// End of namespace "parser"
}
