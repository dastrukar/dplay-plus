#include <iostream>
#include <string>

// include stuff
#include "file.cpp"


std::ifstream config;
  std::string srcprt,
              params,
              presets,
              line;

int main()
{
    config = file::fetch_config();

    if (!file::check_config(config))
    {
        std::cout << "\nNo config file found.\nCreating a new one.";
        file::create_config("dplay.cfg");
        std::cout << "\nCreated config file.";

        goto exit;
    }

    // Get the lines from the file, and put them into their respective variables
    while (getline(config, line))
    {
        if (parser::check_line_type(line) == 2)
        {
            std::cout << "\n" << parser::get_variable_name(line);
            std::cout << "\n" << parser::get_variable_value(line);
        }
    }

    exit:
    std::cout << "\nExiting!";
    return 0;
}
