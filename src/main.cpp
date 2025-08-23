#include <iostream>
#include "Database_Functions.h"
#include "Directory_Functions.h"
#include <string>
#include <vector>

int main() {
    std::cout << "Created Database" << std::endl;
    Database_Create();
    std::string s = "build";
    std::vector<fs::directory_entry> dirs = List_Directories(s);
    String_Path(dirs);
    return 0;
}
