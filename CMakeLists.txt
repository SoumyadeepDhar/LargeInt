cmake_minimum_required(VERSION 3.16.3)
SET(PROJECT_NAME "LargeUInt")
SET(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

# Project information
project(${PROJECT_NAME} VERSION 0.0.1 LANGUAGES CXX)

# Include directory for the project
include_directories(include)

# Add source files
set(SOURCES 
    source/largeint.cpp
    source/li_operator_assignment.cpp
    source/li_operator_compare_lesser.cpp
    source/li_operator_compare_lesser_equal.cpp
    source/li_operator_compare_greater.cpp
    source/li_operator_compare_greater_equal.cpp
    source/li_operator_equal.cpp
    source/li_operator_unequal.cpp
    source/li_operator_plus_equal.cpp
    source/li_operator_plus.cpp
    source/li_operator_minus_equal.cpp
    source/li_operator_minus.cpp
    source/li_operator_division_equal.cpp
    source/li_operator_division.cpp
    source/li_operator_multiply_equal.cpp
    source/li_operator_multiply.cpp)

# Make Target
add_library(largeint SHARED ${SOURCES})


# GTest option
option(GTEST_GIT_CI "GTest during git push" OFF)

# Enable CTest
enable_testing()

# Include directory for the tests
include_directories(tests/include)

# Add test source files
set(CTESTS_SOURCES  
    tests/ctests/tests_largeint.cpp
    tests/ctests/tests_ctests.cpp)

# Make ctest target
add_executable(CTestLargeInt ${CTESTS_SOURCES})

# Links the executable to the LargeUInt C++ library.
target_link_libraries (CTestLargeInt LINK_PUBLIC largeint)

# Add CTest to CI
add_test(CTest CTestLargeInt)

# Checks for GTest
if(${GTEST_GIT_CI})

    find_package(GTest REQUIRED)
    include_directories(${GTEST_INCLUDE_DIRS})

    # Add test source files
    set(GTESTS_SOURCES  
        tests/gtests/tests_gtests.cpp
        tests/gtests/tests_largeint.cpp
        tests/gtests/tests_constructor.cpp
        tests/gtests/tests_operator_assignment.cpp
        tests/gtests/tests_operator_compare_lesser.cpp
        tests/gtests/tests_operator_compare_lesser_equal.cpp
        tests/gtests/tests_operator_compare_greater.cpp
        tests/gtests/tests_operator_compare_greater_equal.cpp
        tests/gtests/tests_operator_equal.cpp
        tests/gtests/tests_operator_unequal.cpp
        tests/gtests/tests_operator_minus_equal.cpp
        tests/gtests/tests_operator_minus.cpp
        tests/gtests/tests_operator_plus_equal.cpp
        tests/gtests/tests_operator_plus.cpp
        tests/gtests/tests_operator_multiply_equal.cpp
        tests/gtests/tests_operator_multiply.cpp
        tests/gtests/tests_operator_division_equal.cpp
        tests/gtests/tests_operator_division.cpp
        )

    # Make Gtest target
    add_executable(GTestLargeInt ${GTESTS_SOURCES})

    # Links the executable to the LargeUInt C++ library.
    target_link_libraries (GTestLargeInt LINK_PUBLIC largeint)
    target_link_libraries (GTestLargeInt LINK_PUBLIC ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES})

    # Add GTest to CI
    add_test(GTest GTestLargeInt)
endif()
