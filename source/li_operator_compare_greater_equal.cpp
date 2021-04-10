/*
 * lui_operator_compare_greater_equal.cpp
 *
 *  Created on: 09-Apr-2021
 *  Author: Soumyadeep Dhar
 */

#include <iostream>
#include <sstream>
#include <cstring>
#include "largeint.h"

// Number system
namespace ns
{
// Decimal Number
namespace dn
{
// Large integer
namespace li
{

/// This is the operator overloading function for comparator operator(>=).
bool LargeInt::operator>=(const LargeInt &_x)
{
  if (!positive && _x.positive)
  {
    return false;
  }
  else if (positive && !_x.positive)
  {
    return true;
  }
  else
  {
    unsigned int _nd = digits();
    unsigned int _md = _x.digits();

    if (_nd > _md)
    {
      return positive ? true : false;
    }
    else if (_nd < _md)
    {
      return positive ? false : true;
    }
    else
    {
      for (int _s = _nList.size() - 1; _s >= 0; --_s)
      {
        if (_nList[_s] > _x._nList[_s])
        {
          return positive ? true : false;
        }

        if (_nList[_s] < _x._nList[_s])
        {
          return positive ? false : true;
        }
      }
      return true;
    }
  }
}

template <>
bool LargeInt::operator>=(const char *_x)
{
  LargeInt _temp(_x);
  return *this >= _temp;
}

template <>
bool LargeInt::operator>=(const std::string _x)
{
  return *this >= _x.c_str();
}

// Specialized for int
template <>
bool LargeInt::operator>=(const int _x)
{
  return *this >= std::to_string(_x);
}

// Specialized for unsigned int
template <>
bool LargeInt::operator>=(const unsigned int _x)
{
  unsigned int _nd = digits();
  unsigned int _md = floor(log10(_x)) + 1;
  return positive ? (_nd > _md)
                        ? true
                    : (_nd < _md)
                        ? false
                    : (_x < N_LIMIT_mVALUE)
                        ? (_nList.back() >= _x)
                        : (_nList.back() >= (_x / N_LIMIT_mVALUE))
                  : false;
}

// Specialized for long long unsigned int
template <>
bool LargeInt::operator>=(const long int _x)
{
  return *this >= std::to_string(_x);
}

// Specialized for long long unsigned int
template <>
bool LargeInt::operator>=(const long unsigned int _x)
{
  return *this >= std::to_string(_x);
}

// Specialized for long long unsigned int
template <>
bool LargeInt::operator>=(const long long int _x)
{
  return *this >= std::to_string(_x);
}

// Specialized for long long unsigned int
template <>
bool LargeInt::operator>=(const long long unsigned int _x)
{
  return *this >= std::to_string(_x);
}

// Specialized for float
template <>
bool LargeInt::operator>=(const float _x)
{
  return *this >= std::to_string(_x).substr(0, std::to_string(_x).find("."));
}

// Specialized for double
template <>
bool LargeInt::operator>=(const double _x)
{
  return *this >= std::to_string(_x).substr(0, std::to_string(_x).find("."));
}

// Specialized for long double
template <>
bool LargeInt::operator>=(const long double _x)
{
  return *this >= std::to_string(_x).substr(0, std::to_string(_x).find("."));
}

} // namespace li
} // namespace ds
} // namespace ns
