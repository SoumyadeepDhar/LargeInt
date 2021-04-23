/*
 * lui_operator_division_equal.cpp
 *
 *  Created on: 30-Mar-2021
 *  Author: Soumyadeep Dhar
 */

#include <iostream>
#include <sstream>
#include <cstring>

#include "largeint.h"
#include "li_constants.h"

// Number system
namespace ns
{
// Decimal Number
namespace dn
{
// Large integer
namespace li
{

/// This is the operator overloading function for comparator operator(+=).
LargeInt &LargeInt::operator/=(const LargeInt &_x)
{
  *this = *this / _x;
  return *this;
}

template <>
LargeInt &LargeInt::operator/=(const char *_x)
{
  LargeInt _temp(_x);
  *this /= _temp;
  return *this;
}

template <>
LargeInt &LargeInt::operator/=(const std::string _x)
{
  *this /= _x.c_str();
  return *this;
}

// Specialized for char
template <>
LargeInt &LargeInt::operator/=(const char _x)
{
  *this /= std::to_string(_x);
  return *this;
}

// Specialized for unsigned char
template <>
LargeInt &LargeInt::operator/=(const unsigned char _x)
{
  *this /= std::to_string(_x);
  return *this;
} 

// Specialized for short int
template <>
LargeInt &LargeInt::operator/=(const short int _x)
{
  *this /= std::to_string(_x);
  return *this;
}

// Specialized for unsigned short int
template <>
LargeInt &LargeInt::operator/=(const unsigned short int _x)
{
  *this /= std::to_string(_x);
  return *this;
}


// Specialized for int
template <>
LargeInt &LargeInt::operator/=(const int _x)
{
  *this /= std::to_string(_x);
  return *this;
}

// Specialized for unsigned int
template <>
LargeInt &LargeInt::operator/=(const unsigned int _x)
{
  *this /= std::to_string(_x);
  return *this;
}

// Specialized for long long unsigned int
template <>
LargeInt &LargeInt::operator/=(const long int _x)
{
  *this /= std::to_string(_x);
  return *this;
}

// Specialized for long long unsigned int
template <>
LargeInt &LargeInt::operator/=(const long unsigned int _x)
{
  *this /= std::to_string(_x);
  return *this;
}

// Specialized for long long unsigned int
template <>
LargeInt &LargeInt::operator/=(const long long int _x)
{
  *this /= std::to_string(_x);
  return *this;
}

// Specialized for long long unsigned int
template <>
LargeInt &LargeInt::operator/=(const long long unsigned int _x)
{
  *this /= std::to_string(_x);
  return *this;
}

// Specialized for float
template <>
LargeInt &LargeInt::operator/=(const float _x)
{
  *this /= std::to_string(_x).substr(0, std::to_string(_x).find("."));
  return *this;
}

// Specialized for double
template <>
LargeInt &LargeInt::operator/=(const double _x)
{
  *this /= std::to_string(_x).substr(0, std::to_string(_x).find("."));
  return *this;
}

// Specialized for long double
template <>
LargeInt &LargeInt::operator/=(const long double _x)
{
  *this /= std::to_string(_x).substr(0, std::to_string(_x).find("."));
  return *this;
}

} // namespace li
} // namespace ds
} // namespace ns

