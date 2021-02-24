#include <iostream>
#include <string>

// include stuff
#include "file.cpp"


std::ifstream config;
  std::string srcprt,
              preset,
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
    std::cout << "\nLooking for SRCPRT variable.";
    srcprt = file::get_variable_value_by_name("SRCPRT", config);

    if (srcprt == "") { std::cout << "\nNo SRCPRT variable found."; goto exit; }
    std::cout << "\nSRCPRT=" + srcprt;

    std::cout << "\nLooking for PRESET variable.";
    preset = file::get_variable_value_by_name("PRESET", config);

    if (preset != "") 
    {
        std::cout << "\nPRESET=" + preset;
    }
    else
    { std::cout << "\nNo PRESET variable found, ignoring all presets."; }

    std::cout << "\n" + file::get_preset(preset, config);

    exit:
    std::cout << "\nExiting!";
    return 0;
}
