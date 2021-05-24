/*
 * li_operator_assignment.cpp
 *
 *  Created on: 03-Apr-2019
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

/// This is the operator overloading function for assignment operator(=).
template <>
LargeInt &LargeInt::operator=(const char *_x)
{
  // Clear previous data if any
  _nList.clear();

  if (_x == NULL)
  {
    positive = true;
    _nList = {0U};
  }
  else
  {
    int sIndex, stIndex, enIndex;

    // Set sign information
    positive = _x[0] != '-' ? true : false;

    // Accumulator value for any node
    long long unsigned int value = 0;

    // Right to left position of the digits in the string
    unsigned int position = 0;

    // Input string length
    int nDigit = strlen(_x);

    // Fot all digits in the given string
    enIndex = nDigit;
    for (sIndex = positive ? 0U : 1U; sIndex < nDigit; ++sIndex)
    {
      // Stop processing if not a digit
      if (_x[sIndex] < 48 || _x[sIndex] > 57)
        break;

      // Update end index
      enIndex = sIndex;
    }

    // If valid digits present
    if (enIndex < nDigit)
    {
      // Based on sign set start index
      stIndex = positive ? 0U : 1U;

      // Fot all digits in the given string
      for (sIndex = enIndex; sIndex >= stIndex; --sIndex)
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

      // Check for zero value
      bool isNonZeroValuePresent = false;
      for (auto nElement : _nList)
      {
        if (nElement != 0U)
        {
          isNonZeroValuePresent = true;
          break;
        }
      }

      // If zero found
      if (isNonZeroValuePresent == false)
      {
        positive = true;
        _nList = {0U};
      }
      else
      {
        // Remove trailing zerosif any
        if (_nList.size() > 1U)
        {
          size_t _e = _nList.size() - 1;
          for (; (_e > 0) && (_nList[_e] == 0); --_e)
            ;

          // Erase elements
          _nList.erase(_nList.begin() + _e + 1, _nList.end());
        }
      }
    }
    else
    {
      positive = true;
      _nList = {0U};
    }
  }

  return *this;
}

// Specialized for char *
template <>
LargeInt &LargeInt::operator=(char *_x)
{
  *this = _x;
  return *this;
}

// Specialized for std::string
template <>
LargeInt &LargeInt::operator=(const std::string _x)
{
  *this = _x.c_str();
  return *this;
}

// Specialized for char
template <>
LargeInt &LargeInt::operator=(const char _x)
{
  *this = std::to_string(_x);
  return *this;
}

// Specialized for unsigned char
template <>
LargeInt &LargeInt::operator=(const unsigned char _x)
{
  *this = std::to_string(_x);
  return *this;
}

// Specialized for short int
template <>
LargeInt &LargeInt::operator=(const short int _x)
{
  *this = std::to_string(_x);
  return *this;
}

// Specialized for unsigned short int
template <>
LargeInt &LargeInt::operator=(const unsigned short int _x)
{
  *this = std::to_string(_x);
  return *this;
}

// Specialized for int
template <>
LargeInt &LargeInt::operator=(const int _x)
{
  *this = std::to_string(_x);
  return *this;
}

// Specialized for unsigned int
template <>
LargeInt &LargeInt::operator=(const unsigned int _x)
{
  *this = std::to_string(_x);
  return *this;
}

// Specialized for long long unsigned int
template <>
LargeInt &LargeInt::operator=(const long int _x)
{
  *this = std::to_string(_x);
  return *this;
}

// Specialized for long long unsigned int
template <>
LargeInt &LargeInt::operator=(const long unsigned int _x)
{
  *this = std::to_string(_x);
  return *this;
}

// Specialized for long long unsigned int
template <>
LargeInt &LargeInt::operator=(const long long int _x)
{
  *this = std::to_string(_x);
  return *this;
}

// Specialized for long long unsigned int
template <>
LargeInt &LargeInt::operator=(const long long unsigned int _x)
{
  *this = std::to_string(_x);
  return *this;
}

// Specialized for float
template <>
LargeInt &LargeInt::operator=(const float _x)
{
  // Get input data as string format
  std::string _value(std::to_string(_x).substr(0, std::to_string(_x).find(".")));

  // Assign value node by node
  this->assignment(_value);

  // Return self
  return *this;
}

// Specialized for double
template <>
LargeInt &LargeInt::operator=(const double _x)
{
  // Get input data as string format
  std::string _value(std::to_string(_x).substr(0, std::to_string(_x).find(".")));

  // Assign value node by node
  this->assignment(_value);

  // Return self
  return *this;
}

// Specialized for long double
template <>
LargeInt &LargeInt::operator=(const long double _x)
{
  // Get input data as string format
  std::string _value(std::to_string(_x).substr(0, std::to_string(_x).find(".")));

  // Assign value node by node
  this->assignment(_value);

  // Return self
  return *this;
}

/// This is the operator overloading function for assignment operator(+).
LargeInt &LargeInt::operator=(const LargeInt &_x)
{
  _nList = _x._nList;
  positive = _x.positive;
  return *this;
}

} // namespace li
} // namespace dn
} // namespace ns