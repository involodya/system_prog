cmake_minimum_required(VERSION 3.20)
project(system_prog)

set(CMAKE_CXX_STANDARD 14)

add_executable(system_prog main.c defines.h solve.h solve.c unittest.h unittest.c)
