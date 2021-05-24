## LargeInt

MIT License
Copyright (c) 2021 Soumyadeep Dhar
Development contact: Soumyadeep Dhar, <s.dhar.in@gmail.com>

## Introduction

'LargeInt' class to hold large integer numbers (0, ±1, ±2, ±3, ...) in 
base 10 upto 4294967295 digits. It is similar to any primitive data type 
like int or float. 

It has operator overloads for +, -, *, /, +=, -=, *=, /=. It also has 
support for comparator operator overload <, <=, >, >=, ==, !=. It also 
support increment / decrement ++, --, prefix and postfix unary operation. 

It has support for <<, <<=, >>, >>= where it multiply the number with 
power(10, x).

## Library

'largeint.so' is the library and 'largeint.h' is the header to include in 
any c++ project to have the support for large integer operations.

## Building on Linux

It has simple cmake build, It also supports Gtest and Ctest to check various 
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

## Dependencies and Support

The build process has no external dependencies. Only c++ and cmake required.
If GTest is enabled then install GTest from Git and set environment as default.
If PARI library support is required then install PARI and enable it in cmake.
PARI documentation can be found in https://pari.math.u-bordeaux.fr/ . 
PARI itself provides all necessary large integer operations.

## Public Member Functions

        LargeInt ()
        Constructor default.
    
    template<typename T >
        LargeInt (const T _x)
        Constructor with argument.
    
        LargeInt (const LargeInt &_x)
        Constructor with large int value.
    
    virtual 	~LargeInt ()
        Destructor default.

    
    std::string 	getSign () const
        Get sign of the large integer as symbol (-) if negative.
    
    std::string 	getNodes () const
        Get large integer as string with all the nodes information.
    
    std::string 	getValue () const
        Get large integer as string without all the nodes information.
    
    unsigned int 	digits () const
        Get number of digits.


    LargeInt 	sqrt ()
        Get sqrt of the number.
    
    LargeInt 	pow (const unsigned int _x)
        Get nth power of the number.
    
    LargeInt 	root (const unsigned int _x)
        Get nth root of the number.


    template<typename T >
    LargeInt & 	operator= (const T _x)
        This is the operator overloading function for assignment operator(=). 
    
    LargeInt & 	operator= (const LargeInt &_x)
        This is the operator overloading function for assignment operator(=). 
    
    template<typename T >
    LargeInt & 	operator+= (const T _x)
        This is the operator overloading function for assignment operator(+). 
    
    LargeInt & 	operator+= (const LargeInt &_x)
        This is the operator overloading function for assignment operator(+). 
    
    template<typename T >
    LargeInt 	operator+ (const T _x)
        This is the operator overloading function for operator(+). 
    
    LargeInt 	operator+ (const LargeInt &_x)
        This is the operator overloading function for operator(+). 
    
    template<typename T >
    LargeInt & 	operator-= (const T _x)
        This is the operator overloading function for assignment operator(-). 
    
    LargeInt & 	operator-= (const LargeInt &_x)
        This is the operator overloading function for assignment operator(-). 
    
    template<typename T >
    LargeInt 	operator- (const T _x)
        This is the operator overloading function for operator(-). 
    
    LargeInt 	operator- (const LargeInt &_x)
        This is the operator overloading function for operator(-). 
    
    template<typename T >
    LargeInt & 	operator*= (const T _x)
        This is the operator overloading function for assignment operator(*). 
    
    LargeInt & 	operator*= (const LargeInt &_x)
        This is the operator overloading function for assignment operator(*). 
    
    template<typename T >
    LargeInt 	operator* (const T _x)
        This is the operator overloading function for operator(*). 
    
    LargeInt 	operator* (const LargeInt &_x)
        This is the operator overloading function for operator(*). 
    
    template<typename T >
    LargeInt & 	operator/= (const T _x)
        This is the operator overloading function for assignment operator(/). 
    
    LargeInt & 	operator/= (const LargeInt &_x)
        This is the operator overloading function for assignment operator(/). 
    
    template<typename T >
    LargeInt 	operator/ (const T _x)
        This is the operator overloading function for operator(/). 
    
    LargeInt 	operator/ (const LargeInt &_x)
        This is the operator overloading function for operator(/). 
    
    template<typename T >
    LargeInt & 	operator%= (const T _x)
        This is the operator overloading function for assignment operator(%). 
    
    LargeInt & 	operator%= (const LargeInt &_x)
        This is the operator overloading function for assignment operator(%). 
    
    template<typename T >
    LargeInt 	operator% (const T _x)
        This is the operator overloading function for operator(%). 
    
    LargeInt 	operator% (const LargeInt &_x)
        This is the operator overloading function for operator(%). 
    
    LargeInt & 	operator<<= (const unsigned int _x)
        This is the operator overloading function for assignment operator(<<). 
    
    LargeInt 	operator<< (const unsigned int _x) const
        This is the operator overloading function for shift operator(<<). 
    
    LargeInt & 	operator>>= (const unsigned int _x)
        This is the operator overloading function for assignment operator(>>). 
    
    LargeInt 	operator>> (const unsigned int _x) const
        This is the operator overloading function for shift operator(>>). 
    
    LargeInt 	operator++ ()
        This is the operator overloading function for assignment operator(++) prefix. 
    
    LargeInt 	operator++ (int)
        This is the operator overloading function for assignment operator(++) postfix.
    
    LargeInt 	operator-- ()
        This is the operator overloading function for assignment operator(--) prefix.
    
    LargeInt 	operator-- (int)
        This is the operator overloading function for assignment operator(--) postfix.


    template<typename T >
    bool 	operator< (const T _x)
        This is the operator overloading function for comparator operator(<). 
    
    bool 	operator< (const LargeInt &_x)
        This is the operator overloading function for comparator operator(<). 
    
    template<typename T >
    bool 	operator<= (const T _x)
        This is the operator overloading function for comparator operator(<=). 
    
    bool 	operator<= (const LargeInt &_x)
        This is the operator overloading function for comparator operator(<=). 
    
    template<typename T >
    bool 	operator> (const T _x)
        This is the operator overloading function for comparator operator(>). 
    
    bool 	operator> (const LargeInt &_x)
        This is the operator overloading function for comparator operator(>). 
    
    template<typename T >
    bool 	operator>= (const T _x)
        This is the operator overloading function for comparator operator(>=). 
    
    bool 	operator>= (const LargeInt &_x)
        This is the operator overloading function for comparator operator(>=). 
    
    template<typename T >
    bool 	operator== (const T _x)
        This is the operator overloading function for comparator operator(==). 
    
    bool 	operator== (const LargeInt &_x)
        This is the operator overloading function for comparator operator(==). 
    
    template<typename T >
    bool 	operator!= (const T _x)
        This is the operator overloading function for comparator operator(!=). 
    
    bool 	operator!= (const LargeInt &_x)
        This is the operator overloading function for comparator operator(!=). 
    
