cmake_minimum_required(VERSION 3.16.3)
SET(PROJECT_NAME "LargeInt")
SET(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

# Project information
project(${PROJECT_NAME} VERSION 1.0 LANGUAGES CXX)
string(TOLOWER ${PROJECT_NAME} PROJECT_NAME_LOWER)

# Include directory for the project
include_directories(include)

# Support for pari available 
option(PARI_SUPPORT "PARI Library support" ON)

# Build with pari library suppot
if(${PARI_SUPPORT})

    # Include default pari path
    # /usr/local/include/pari/
    # /usr/include/x86_64-linux-gnu/pari/
    include_directories("/usr/include/x86_64-linux-gnu/pari/")

    # External library to do large int operations
    find_library(PARI_LIB NAMES pari HINTS "/usr/local/lib/")

    # Link pari library
    link_libraries(${PARI_LIB})
    
    # Add compilar flags
    add_compile_definitions("PARI")

endif()

# Add source files
set(SOURCES 
    source/largeint.cpp
    source/li_pari_functions.cpp
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
    source/li_operator_multiply_equal.cpp
    source/li_operator_multiply.cpp
    source/li_operator_division_equal.cpp
    source/li_operator_division.cpp
    source/li_operator_modulus_equal.cpp
    source/li_operator_modulus.cpp)

# Compilar options
add_compile_options(-O3 -Wall -Wextra)

# Make Target
add_library(${PROJECT_NAME_LOWER} SHARED ${SOURCES})


# Enable CTest
enable_testing()

# Include directory for the tests
include_directories(tests/include)

# Add test source files
set(CTESTS_SOURCES  
    tests/ctests/tests_largeint.cpp
    tests/ctests/tests_ctests.cpp)

# Make ctest target
add_executable(CTest${PROJECT_NAME} ${CTESTS_SOURCES})

# Links the executable to the LargeUInt C++ library.
target_link_libraries (CTest${PROJECT_NAME} LINK_PUBLIC ${PROJECT_NAME_LOWER})

# Add CTest to CI
add_test(CTest CTest${PROJECT_NAME})


# GTest option
option(GTEST_GIT_CI "GTest during git push" OFF)

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
        tests/gtests/tests_operator_modulus_equal.cpp
        tests/gtests/tests_operator_modulus.cpp
        )

    # Compilar options
    add_compile_options(-O3 -Wall -Wextra)

    # Make Gtest target
    add_executable(GTest${PROJECT_NAME} ${GTESTS_SOURCES})

    # Links the executable to the LargeUInt C++ library.
    target_link_libraries (GTest${PROJECT_NAME} LINK_PUBLIC ${PROJECT_NAME_LOWER})
    message("-- CMAKE PROJECT_NAME: " ${PROJECT_NAME})
    target_link_libraries (GTest${PROJECT_NAME} LINK_PUBLIC ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES})
    message("-- CMAKE GTEST_LIBRARIES: " ${GTEST_LIBRARIES})
    message("-- CMAKE GTEST_MAIN_LIBRARIES: " ${GTEST_MAIN_LIBRARIES})

    # Add GTest to CI
    add_test(GTest GTest${PROJECT_NAME})
endif()
