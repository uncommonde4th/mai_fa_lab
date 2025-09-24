cmake_minimum_required(VERSION 3.10)
project(lab2)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(main
        src/main.c
)

target_include_directories(main PRIVATE include)
