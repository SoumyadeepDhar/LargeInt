cmake_minimum_required(VERSION 3.16.3)
project(LargeUInt)

# include directory for headers
#include_directories()

# Add source files
set(SOURCES largeuint.cpp main.cpp)

# Make target
add_executable(LargeUInt ${SOURCES})
