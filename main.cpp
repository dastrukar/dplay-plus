#include <iostream>
#include <string>

// include stuff
#include "file.cpp"

// headers
#include "file.h"


std::ifstream config;

int main()
{
    config = fetch_config();

    if (!check_config(config))
    {
        std::cout << "No config file found.\nCreating a new one.\n";
        create_config("dplay.cfg");
        std::cout << "Created config file.\n";

        goto exit;
    }

    exit:
    std::cout << "Exiting!\n";
    return 0;
}
