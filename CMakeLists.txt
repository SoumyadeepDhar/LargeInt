cmake_minimum_required(VERSION 3.16.3)
project(LargeUInt)

# Include directory for headers
include_directories(include)

# Add source files
set(SOURCES 
    source/largeuint.cpp 
    source/main.cpp)

# Make Target
add_executable(LargeUInt ${SOURCES})


# Enable CTest
enable_testing()

# Add test source files
set(CTESTS_SOURCES 
    source/largeuint.cpp 
    tests/ctests/ctests.cpp)

# Make ctest target
add_executable(CTestLargeUInt ${CTESTS_SOURCES})
add_test(CTest CTestLargeUInt)
