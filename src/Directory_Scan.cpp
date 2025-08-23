#include <ostream>
#include <string>
#include <vector>
#include "Directory_Functions.h"
#include <iostream>
// Return vector of all paths inside a directory with subdiretories using recursive
// directory iterator
std::vector<fs::directory_entry> List_Directories(std::string dir){
    std::vector<fs::directory_entry> dir_entries;

    for (const fs::directory_entry& dir_entry : fs::recursive_directory_iterator(dir))
        dir_entries.push_back(dir_entry);

    return dir_entries;
}
// uses the vector with directory entry objects to convert them to string represenatation to store in Database
std::vector<std::string> String_Path(std::vector<fs::directory_entry> dirs){
    std::vector<std::string> Paths;
    for (auto p: dirs){
        std::cout << p.path() << std::endl;
    }
}
