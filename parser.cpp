#include <iostream>
#include <string>

#include "parser.h"


/*
 * Returns true, if there's a # at the start of the line
 */
bool check_comment(std::string text)
{
    if (text[0] == '#') { return true; }

    return false;
}


/*
 * Returns true, if there's a : at the start of the line
 */
bool check_preset(std::string text)
{
    if (text[0] == ':') { return true; }

    return false;
}


/*
 * Returns true, if there's a $ at the start of the line
 */
bool check_variable(std::string text)
{
    if (text[0] == '$') { return true; }

    return false;
}


std::string get_variable(std::string text)
{
    if (check_variable(text))
    {
        std::string variable;
        for(int i = 1; i < 6; i++) { variable += text[i]; }

        return variable;
    }
}
