cmake_minimum_required(VERSION 3.15)
project(CV6 C)

set(CMAKE_C_STANDARD 99)

add_executable(CV6 main.c EvidStructs.h EvidFunctions.h)