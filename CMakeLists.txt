cmake_minimum_required(VERSION 3.24)
project(cerebro LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

# --- SQLiteCpp Dependency ---
FetchContent_Declare(
    SQLiteCpp
    GIT_REPOSITORY https://github.com/SRombauts/SQLiteCpp.git
    GIT_TAG        3.3.3
)

# --- Google Test --- 
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/release-1.12.1.zip
)

# Tell SQLiteCpp to build its own bundled, internal sqlite3 library.
# This avoids any conflict with system libraries.
set(SQLITECPP_INTERNAL_SQLITE ON CACHE BOOL "Build the bundled SQLite3")

# This downloads and builds the dependency using the setting above
FetchContent_MakeAvailable(SQLiteCpp)
FetchContent_MakeAvailable(googletest)

# --- Our Project Target ---
add_executable(cerebro src/main.cpp src/Create_Database.cpp src/Directory_Scan.cpp) 

# Link everything together. This will now link against SQLiteCpp
# AND its internally-built sqlite3 library.
target_link_libraries(cerebro PRIVATE SQLiteCpp)