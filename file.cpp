#include <iostream>
#include <fstream>
#include <string>

#include "file.h"

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


bool check_config(std::ifstream& file)
{
    if (file.good()) { return true; }
    return false;
}
