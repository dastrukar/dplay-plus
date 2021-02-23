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
 * Looks for "$SRCPRT=" and returns its value in the config
 * If no "$SRCPRT=" is found, return an empty string
 */
std::string get_srcprt(std::ifstream &file)
{
    std::string line;

    while (getline(file, line))
    {
        if (parser::check_line_type(line) == 2 && parser::get_variable_name(line) == "SRCPRT")
        {
            return parser::get_variable_value(line);
        }
    }

    // If no "SRCPRT" is found, return an empty string
    return "";
}


// End of namespace "parser"
}
