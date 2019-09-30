cmake_minimum_required(VERSION 3.14)
project(CV2 C)

set(CMAKE_C_STANDARD 99)

add_executable(CV2 main.c functions.h Dates.h hodina2.h)