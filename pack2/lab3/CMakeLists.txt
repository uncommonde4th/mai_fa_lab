cmake_minimum_required(VERSION 3.10)
project(lab3)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(main
        ../src/main.c
        ../src/newprintf.c
)

target_include_directories(main PRIVATE include)
target_link_libraries(main m)
