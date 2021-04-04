/*
 * largeuint.cpp
 *
 *  Created on: 03-Apr-2019
 *  Author: Soumyadeep Dhar
 */

#include <iostream>
#include <sstream>
#include <cstring>
#include "largeuint.h"

// Number ststem
namespace ns
{
// Decimal Number
namespace dn
{
// Large unsigned integer
namespace lui
{


// Specialized for const char *
template <>
LargeUInt &LargeUInt::operator=(const char *_x)
{
  // Clear previous data if any
  _nList.clear();

  int sIndex, eIndex;

  // accumulator value for any node
  long long unsigned int value = 0;

  // Right to left position of the digits in the string
  unsigned int position = 0;

  // Input string length
  unsigned int nDigit = strlen(_x);

  // Fot all digits in the given string
  eIndex = nDigit;
  for (sIndex = 0; sIndex < nDigit; ++sIndex)
  {
    // Stop processing if not a digit
    if (_x[sIndex] < 48 || _x[sIndex] > 57)
      break;

    // Update end index
    eIndex = sIndex;
  }

  // If valid digits present
  if (eIndex < nDigit)
  {
    // Fot all digits in the given string
    for (sIndex = eIndex; sIndex >= 0; --sIndex)
    {
      // Calculate positional significance within the  node
      int power = position - (_nList.size() * N_LIMIT_mDIGIT);

      // Update position for next iteration
      position++;

      // Find value for the desimal place
      value += (_x[sIndex] - 48) * powl(10, power);

      // Keep only 'N_LIMIT_mDIGIT' in any node
      if ((power + 1) == N_LIMIT_mDIGIT)
      {
        // Insert data in nodelist
        _nList.push_back(value);

        // Clear value accumulator
        value = 0;
      }
    }

    // Append remaining digits
    if (position % N_LIMIT_mDIGIT)
    {
      _nList.push_back(value);
    }
  }
  else
  {
    _nList.push_back(0UL);
  }

  return *this;
}

template <>
LargeUInt &LargeUInt::operator=(const std::string _x)
{
  *this = _x.c_str();
  return *this;
}

// Specialized for long long unsigned int
template <>
LargeUInt &LargeUInt::operator=(const long long unsigned int _x)
{
  *this = std::to_string(_x);
  return *this;
}

// Specialized for int
template <>
LargeUInt &LargeUInt::operator=(const int _x)
{
  *this = static_cast<long long unsigned int>(_x);
  return *this;
}

// Specialized for unsigned int
template <>
LargeUInt &LargeUInt::operator=(const unsigned int _x)
{
  *this = static_cast<long long unsigned int>(_x);
  return *this;
}

// Specialized for long long unsigned int
template <>
LargeUInt &LargeUInt::operator=(const long unsigned int _x)
{
  *this = static_cast<long long unsigned int>(_x);
  return *this;
}

// Specialized for float
template <>
LargeUInt &LargeUInt::operator=(const float _x)
{
  *this = std::to_string(_x).substr(0, std::to_string(_x).find("."));
  return *this;
}

// Specialized for double
template <>
LargeUInt &LargeUInt::operator=(const double _x)
{
  *this = std::to_string(_x).substr(0, std::to_string(_x).find("."));
  return *this;
}

// Specialized for long double
template <>
LargeUInt &LargeUInt::operator=(const long double _x)
{
  *this = std::to_string(_x).substr(0, std::to_string(_x).find("."));
  return *this;
}

/// This is the operator overloading function for assignment operator(+).
LargeUInt &LargeUInt::operator=(const LargeUInt &_x)
{
  _nList = _x._nList;
  return *this;
}

} // namespace lui
} // namespace ds
} // namespace ns
