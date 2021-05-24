/*
 * lui_operator_unequal.cpp
 *
 *  Created on: 30-Mar-2021
 *  Author: Soumyadeep Dhar
 */

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

/// This is the operator overloading function for not equal operator(!=).
bool LargeInt::operator!=(const LargeInt &_x)
{
    if (positive && !_x.positive)
  {
    return true;
  }
  else if (!positive && _x.positive)
  {
    return true;
  }
  else
  {
    unsigned int _nd = digits();
    unsigned int _md = _x.digits();
    if (_nd != _md)
    {
      return true;
    }
    else
    {
      for (int _s = _nList.size() - 1; _s >= 0; --_s)
      {
        if (_nList[_s] != _x._nList[_s])
        {
          return true;
        }
      }
      return false;
    }
  }
}

template <>
bool LargeInt::operator!=(const char *_x)
{
  LargeInt _temp(_x);
  return *this != _temp;
}

template <>
bool LargeInt::operator!=(const std::string _x)
{
  return *this != _x.c_str();
}

// Specialized for char
template <>
bool LargeInt::operator!=(const char _x)
{
  return *this != std::to_string(_x);
}

// Specialized for unsigned char
template <>
bool LargeInt::operator!=(const unsigned char _x)
{
  return *this != std::to_string(_x);
}

// Specialized for short int
template <>
bool LargeInt::operator!=(const short int _x)
{
  return *this != std::to_string(_x);
}

// Specialized for unsigned short int
template <>
bool LargeInt::operator!=(const unsigned short int _x)
{
  return *this != std::to_string(_x);
}

// Specialized for int
template <>
bool LargeInt::operator!=(const int _x)
{
  return *this != std::to_string(_x);
}

// Specialized for unsigned int
template <>
bool LargeInt::operator!=(const unsigned int _x)
{
  return *this != std::to_string(_x);
}

// Specialized for long int
template <>
bool LargeInt::operator!=(const long int _x)
{
  return *this != std::to_string(_x);
}

// Specialized for long unsigned int
template <>
bool LargeInt::operator!=(const long unsigned int _x)
{
  return *this != std::to_string(_x);
}

// Specialized for long long int
template <>
bool LargeInt::operator!=(const long long int _x)
{
  return *this != std::to_string(_x);
}

// Specialized for long long unsigned int
template <>
bool LargeInt::operator!=(const long long unsigned int _x)
{
  return *this != std::to_string(_x);
}

// Specialized for float
template <>
bool LargeInt::operator!=(const float _x)
{
  return *this != std::to_string(_x).substr(0, std::to_string(_x).find("."));
}

// Specialized for double
template <>
bool LargeInt::operator!=(const double _x)
{
  return *this != std::to_string(_x).substr(0, std::to_string(_x).find("."));
}

// Specialized for long double
template <>
bool LargeInt::operator!=(const long double _x)
{
  return *this != std::to_string(_x).substr(0, std::to_string(_x).find("."));
}

} // namespace li
} // namespace dn
} // namespace ns
