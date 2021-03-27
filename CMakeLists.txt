cmake_minimum_required(VERSION 3.16.3)
SET(PROJECT_NAME "LargeUInt")
SET(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

# Project information
project(${PROJECT_NAME} VERSION 0.0.1 LANGUAGES CXX)

# Include directory for the project
include_directories(include)
include_directories(library)

# Add source files
set(SOURCES 
    source/largeuint.cpp)

# Make Target
add_library(largeuint SHARED ${SOURCES})

# Install library
install(TARGETS largeuint DESTINATION library)

# Enable CTest
enable_testing()

# Add test source files
set(CTESTS_SOURCES  
    tests/ctests/ctests.cpp)

# Make ctest target
add_executable(CTestLargeUInt ${CTESTS_SOURCES})

# Links the executable to the LargeUInt C++ library.
target_link_libraries (CTestLargeUInt LINK_PUBLIC largeuint)

# Add CTest
add_test(CTest CTestLargeUInt)
