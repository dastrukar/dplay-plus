#include <iostream>
#include <fstream>
#include <string>

#include "file.h"

/*
 * Returns the contents of "dplay.cfg"
 */
std::string fetch_config()
{
    std::string config = "";
    std::string temp_string;
    std::ifstream file("dplay.cfg");

    // Check if file exists
    if (!file.good()) { file.close(); return ""; }

    while (getline(file, temp_string))
    {
        config += temp_string;
    }

    file.close();

    return config;
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
