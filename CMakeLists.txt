cmake_minimum_required(VERSION 3.15)
project(my_cpp_project)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(ENABLE_ASAN "Enable Address Sanitizer" OFF)

if(ENABLE_ASAN)
    add_compile_options(-fsanitize=address -fno-omit-frame-pointer)
    add_link_options(-fsanitize=address)
endif()

include_directories(include)

add_executable(my_app src/main.cpp)
enable_testing()
add_subdirectory(tests)
