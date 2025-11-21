cmake_minimum_required(VERSION 3.10)
project(lab1)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(main_int
        ../src/main.c
        ../src/myVector.c
)
add_executable(main_str
        ../src/mainStr.c
        ../src/myVectorStr.c
)
target_include_directories(main_int PRIVATE include)
target_link_libraries(main_int m)
target_include_directories(main_str PRIVATE include)
target_link_libraries(main_str m)


