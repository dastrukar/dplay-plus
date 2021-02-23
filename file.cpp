/*
 * Any function that uses fstream, will go here
 */

#include <iostream>
#include <fstream>
#include <string>

#include "parser.cpp"

#include "file.h"


namespace file
{
// Start of namespace "file"


/*
 * Returns "dplay.cfg"
 */
std::ifstream fetch_config()
{
    std::ifstream file("dplay.cfg");

    return file;
}


/*
 * Creates a new config file with the given "dir"
 */
void create_config(std::string dir)
{
    std::ofstream file(dir);

    // Write to file
    file << 
    "#Example config\n"
    <<
    "this is a file\n"
    <<
    ":this is a preset {\n"
    <<
    "}"
    ;
}


bool check_config(std::ifstream &file)
{
    if (file.good()) { return true; }
    return false;
}


/*
 * Returns variable value by the given `var`
 * If no variable is found, return an empty string
 * Args:
 * `var`  - Name of the variable
 * `file` - File to read through
 */
std::string get_variable_value_by_name(std::string var, std::ifstream &file)
{
    std::string line;

    while (getline(file, line))
    {
        if (parser::check_line_type(line) == 2 && parser::get_variable_name(line) == var)
        {
            return parser::get_variable_value(line);
        }
    }

    return "";
}


// End of namespace "parser"
}
