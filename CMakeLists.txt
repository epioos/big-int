cmake_minimum_required(VERSION 3.21)
project(big_int)

set(CMAKE_CXX_STANDARD 14)

add_executable(big_int main.cpp Zahl.cpp Zahl.h)
