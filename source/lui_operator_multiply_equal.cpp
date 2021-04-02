/*
 * lui_operator_multiply.cpp
 *
 *  Created on: 30-Mar-2021
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

// Specialized for int
template <>
LargeUInt &LargeUInt::operator*=(const int _x)
{
  // Keep note of initial value
  LargeUInt _iV(*this);
  std::vector<int> mDigits;

  // Get number of digits in multiplier
  for (int nValue = _x; nValue > 0; nValue /= 10)
  {
    mDigits.push_back(nValue - ((nValue / 10) * 10));
  }

  // Clear current Value
  *this = 0;

  // Multiply digit by digit
  for (int nIndex = mDigits.size() - 1; nIndex >= 0; --nIndex)
  {
    // Create temporary variable
    LargeUInt _v(_iV);

    // Update with current multiplier
    _v.mul(static_cast<long long unsigned int>(mDigits[nIndex]), nIndex);

    // Update result
    *this += _v;
  }
  return *this;
}

// Specialized for unsigned int
template <>
LargeUInt &LargeUInt::operator*=(const unsigned int _x)
{
  // Keep note of initial value
  LargeUInt _iV(*this);
  std::vector<int> mDigits;

  // Get number of digits in multiplier
  for (unsigned int nValue = _x; nValue > 0; nValue /= 10)
  {
    mDigits.push_back(nValue - ((nValue / 10) * 10));
  }

  // Clear current Value
  *this = 0;

  // Multiply digit by digit
  for (int nIndex = mDigits.size() - 1; nIndex >= 0; --nIndex)
  {
    // Create temporary variable
    LargeUInt _v(_iV);

    // Update with current multiplier
    _v.mul(static_cast<long long unsigned int>(mDigits[nIndex]), nIndex);

    // Update result
    *this += _v;
  }
  return *this;
}

// Specialized for long long unsigned int
template <>
LargeUInt &LargeUInt::operator*=(const long unsigned int _x)
{
  // Keep note of initial value
  LargeUInt _iV(*this);
  std::vector<int> mDigits;

  // Get number of digits in multiplier
  for (long unsigned int nValue = _x; nValue > 0; nValue /= 10)
  {
    mDigits.push_back(nValue - ((nValue / 10) * 10));
  }

  // Clear current Value
  *this = 0;

  // Multiply digit by digit
  for (int nIndex = mDigits.size() - 1; nIndex >= 0; --nIndex)
  {
    // Create temporary variable
    LargeUInt _v(_iV);

    // Update with current multiplier
    _v.mul(static_cast<long long unsigned int>(mDigits[nIndex]), nIndex);

    // Update result
    *this += _v;
  }
  return *this;
}

// Specialized for long long unsigned int
template <>
LargeUInt &LargeUInt::operator*=(const long long unsigned int _x)
{
  // Keep note of initial value
  LargeUInt _iV(*this);
  std::vector<int> mDigits;

  // Get number of digits in multiplier
  for (long long unsigned int nValue = _x; nValue > 0; nValue /= 10)
  {
    mDigits.push_back(nValue - ((nValue / 10) * 10));
  }

  // Clear current Value
  *this = 0;

  // Multiply digit by digit
  for (int nIndex = mDigits.size() - 1; nIndex >= 0; --nIndex)
  {
    // Create temporary variable
    LargeUInt _v(_iV);

    // Update with current multiplier
    _v.mul(static_cast<long long unsigned int>(mDigits[nIndex]), nIndex);

    // Update result
    *this += _v;
  }
  return *this;
}

// Specialized for const char *
template <>
LargeUInt &LargeUInt::operator*=(const char *_x)
{
  // Keep note of initial value
  LargeUInt _iV(*this);

  // Get valid input string
  LargeUInt _mX(_x);

  // Get representative string
  std::string _strX(_mX.getValue());
  unsigned int _nLength = _strX.length();

  // Clear current Value
  *this = 0;

  // Multiply digit by digit
  for (int nValue = _nLength - 1; nValue >= 0; --nValue)
  {
    // Create temporary variable
    LargeUInt _v(_iV);

    // Update with current multiplier
    _v.mul((static_cast<long long unsigned int>(_strX[nValue] - 48)),
           (_nLength - nValue - 1));

    // Update result
    *this += _v;
  }
  return *this;
}

template <>
LargeUInt &LargeUInt::operator*=(const std::string _x)
{
  // Add new value
  *this *= _x.c_str();
  return *this;
}

// Specialized for float
template <>
LargeUInt &LargeUInt::operator*=(const float _x)
{
  LargeUInt _temp = _x;
  *this *= _temp;
  return *this;
}

// Specialized for double
template <>
LargeUInt &LargeUInt::operator*=(const double _x)
{
  LargeUInt _temp = _x;
  *this *= _temp;
  return *this;
}

// Specialized for long double
template <>
LargeUInt &LargeUInt::operator*=(const long double _x)
{
  LargeUInt _temp = _x;
  *this *= _temp;
  return *this;
}

// This is the operator overloading function for assignment operator(+).
LargeUInt &LargeUInt::operator*=(const LargeUInt &_x)
{
  // Keep note of initial value
  LargeUInt _iV(*this);

  // Get representative string
  std::string _strX(_x.getValue());
  unsigned int _nLength = _strX.length();

  // Clear current Value
  *this = 0;

  // Multiply digit by digit
  for (int nValue = _nLength - 1; nValue >= 0; --nValue)
  {
    // Create temporary variable
    LargeUInt _v(_iV);

    // Update with current multiplier
    _v.mul((static_cast<long long unsigned int>(_strX[nValue] - 48)),
           (_nLength - nValue - 1));

    // Update result
    *this += _v;
  }
  return *this;
}

} // namespace lui
} // namespace ds
} // namespace ns
