#include <iostream>
#include <string>

#include "parser.h"


/*
 * Returns the following values:
 * 0: If none of the below are true
 * 1: If the first char is '#'
 * 2: If the first char is '$'
 * 3: If the first char is ':'
 */
int check_line_type(std::string text)
{
    switch (text[0])
    {
        case '#': return 1; break;
        case '$': return 2; break;
        case ':': return 3; break;
    }

    return 0;
}


std::string get_variable(std::string text)
{
    return text;
}
