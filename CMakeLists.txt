cmake_minimum_required(VERSION 3.17)
project(cards)

set(CMAKE_CXX_STANDARD 17)

add_executable(cards main.cpp generation.h individual.h random.h)