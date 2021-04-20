/*
 * lui_operator_multiply.cpp
 *
 *  Created on: 30-Mar-2021
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

// This is the operator overloading function for assignment operator(*).
LargeInt LargeInt::operator*(const LargeInt &_x)
{
  unsigned int _sList1 = _nList.size();
  unsigned int _sList2 = _x._nList.size();

  // Initialized as positive
  LargeInt _result(0U);

  // For each elements in first list multiply them to the other list
  for (auto nIndex1 = 0U; nIndex1 < _sList1; ++nIndex1)
  {
    // Initialized with abs(list2)
    LargeInt _temp(_x);
    _temp.positive = true;

    // Store n(i) = m(0)n(i) + m(1)n(i) + ... + m(M)n(i)
    for (auto nIndex2 = 0U; nIndex2 < _sList2; ++nIndex2)
    {
      // Note of newly computed value
      _temp._nList[nIndex2] *= _nList[nIndex1];
    }

    // Adjust successive carry
    for (auto nIndex2 = 0U; nIndex2 < _sList2; ++nIndex2)
    {
      // Most significant digits outside store range
      long long unsigned int _carry = _temp._nList[nIndex2] / N_LIMIT_mVALUE;

      // If carry exits
      if (_carry > 0U)
      {
        // Update nodes with all other digits
        _temp._nList[nIndex2] = _temp._nList[nIndex2] - _carry * N_LIMIT_mVALUE;

        // Update next (if exist) node with carry value
        if (std::next(_temp._nList.begin() + nIndex2) != _temp._nList.end())
        {
          // Add carry to next node position
          _temp.add(_carry, (nIndex2 + 1));
        }
        else
        {
          // Append carry as last node
          _temp._nList.push_back(_carry);
        }
      }
    }

    // Adjust node position
    _temp <<= (nIndex1 * N_LIMIT_mDIGIT);

    // Update result
    _result += _temp;
  }

  // Update sign information
  _result.positive = !(positive ^ _x.positive);

  return _result;
}

template <>
LargeInt LargeInt::operator*(const char *_x)
{
  LargeInt _temp(_x);
  return *this * _temp;
}

template <>
LargeInt LargeInt::operator*(const std::string _x)
{
  return *this * _x.c_str();
}

// Specialized for char
template <>
LargeInt LargeInt::operator*(const char _x)
{
  return *this * std::to_string(_x);
}

// Specialized for unsigned char
template <>
LargeInt LargeInt::operator*(const unsigned char _x)
{
  return *this * std::to_string(_x);
}

// Specialized for short int
template <>
LargeInt LargeInt::operator*(const short int _x)
{
  return *this * std::to_string(_x);
}

// Specialized for unsigned short int
template <>
LargeInt LargeInt::operator*(const unsigned short int _x)
{
  return *this * std::to_string(_x);
}

// Specialized for int
template <>
LargeInt LargeInt::operator*(const int _x)
{
  return *this * std::to_string(_x);
}

// Specialized for unsigned int
template <>
LargeInt LargeInt::operator*(const unsigned int _x)
{
  return *this * std::to_string(_x);
}

// Specialized for long int
template <>
LargeInt LargeInt::operator*(const long int _x)
{
  return *this * std::to_string(_x);
}

// Specialized for long unsigned int
template <>
LargeInt LargeInt::operator*(const long unsigned int _x)
{
  return *this * std::to_string(_x);
}

// Specialized for long long int
template <>
LargeInt LargeInt::operator*(const long long int _x)
{
  return *this * std::to_string(_x);
}

// Specialized for long long unsigned int
template <>
LargeInt LargeInt::operator*(const long long unsigned int _x)
{
  return *this * std::to_string(_x);
}

// Specialized for float
template <>
LargeInt LargeInt::operator*(const float _x)
{
  return *this * std::to_string(_x).substr(0, std::to_string(_x).find("."));
}

// Specialized for double
template <>
LargeInt LargeInt::operator*(const double _x)
{
  return *this * std::to_string(_x).substr(0, std::to_string(_x).find("."));
}

// Specialized for long double
template <>
LargeInt LargeInt::operator*(const long double _x)
{
  return *this * std::to_string(_x).substr(0, std::to_string(_x).find("."));
}

} // namespace li
} // namespace ds
} // namespace ns

