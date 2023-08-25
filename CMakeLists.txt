cmake_minimum_required(VERSION 3.26)
project(
    dimensium_base
    LANGUAGES
        C CXX
)

set(CMAKE_CXX_STANDARD 20) ### MIGRATING TO C++20!!!
set(CMAKE_CXX_STANDARD_REQUIRED ON)
    


set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(lib)

add_subdirectory(src)
