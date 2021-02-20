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
