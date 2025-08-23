#ifndef LIST_DIRECTORIES_H
#define LIST_DIRECTORIES_H
#include <string>
#include <vector>
#include <filesystem>
namespace fs = std::filesystem;

std::vector<fs::directory_entry> List_Directories(std::string s);
std::vector<std::string> String_Path(std::vector<fs::directory_entry> dirs);
#endif
