#include <iostream>
#include <fstream>
#include <string>

// include stuff
#include "file.cpp"

// headers
#include "file.h"


int main()
{
    std::string config = fetch_config();

    if (config == "")
    {
        std::cout << "No config file found.\nCreating a new one.";
        create_config("dplay.cfg");
        config = fetch_config();
    }
    std::cout << config;

    return 0;
}
