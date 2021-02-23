#include <string>
#include <fstream>

std::ifstream fetch_config();
         void create_config(std::string dir);
         bool check_config(std::ifstream& file);
  std::string get_variable_value_by_name(std::string var, std::ifstream &file);
