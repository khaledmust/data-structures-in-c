cmake_minimum_required(VERSION 3.26)
project(data_structures C)

set(CMAKE_C_STANDARD 99)

add_executable(data_structures main.c
        stack.c
        stack.h)
