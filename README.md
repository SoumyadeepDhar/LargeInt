## LargeInt

MIT License
Copyright (c) 2021 Soumyadeep Dhar
Development contact: Soumyadeep Dhar, <s.dhar.in@gmail.com>

## Introduction

'LargeInt' class to hold large integer numbers (0, ±1, ±2, ±3, ...) in 
base 10. It is similar to any primitive data type like int or float. 
It has operator overloads for +, -, *, /, +=, -=, *=, /=. It also has 
support for comparator operator overload <, <=, >, >=, ==, !=. It also 
support increment / decrement ++, --, prefix and postfix unary operation. 
It has support for <<, <<=, >>, >>= where it multiply the number with 
power(10, x).

## Library

'largeint.so' is the library and 'largeint.h' is the header to include in 
any c++ project to have the support for large integer operations.

## Building on Linux

It has simple cmake build, It aslo supports Gtest and Ctest to check various 
functionalities. To enable GTest update in '~/work/LargeInt/CMakeLists.txt'
Set GTest option "option(GTEST_GIT_CI "GTest during git push" ON)"

1. Start a terminal

2. 'cd' to the 'LargeInt' folder on your system
'$ cd ~/work/LargeInt'

3. Create a build directory and 'cd' to it
'$ mkdir build'
'$ cd build'

4. Run Cmake to generate the required build files.
'$ cmake -b . -s ..'

5. Start the build
'$ make'

## Dependencies

The build process has no external dependencies. Only c++ and cmake required.
If GTest is enabled then install GTest from Git and set envionment as default.


