cmake_minimum_required(VERSION 3.26)
project(
    libFreecraft
    LANGUAGES
        C CXX
)



## configuration options

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(
    LEVELDB_INCLUDE_PATH
        ""
    CACHE STRING
        "The path to include/ directory of LevelDB"
    FORCE
)

add_subdirectory(src)