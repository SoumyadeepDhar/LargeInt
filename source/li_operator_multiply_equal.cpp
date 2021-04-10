/*
 * lui_operator_multiply_equal.cpp
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

// Specialized for int
template <>
LargeInt &LargeInt::operator*=(const int _x)
{
  LargeInt _temp(_x);
  *this *= _temp;
  return *this;
}

// Specialized for unsigned int
template <>
LargeInt &LargeInt::operator*=(const unsigned int _x)
{
  LargeInt _temp(_x);
  *this *= _temp;
  return *this;
}

// Specialized for long long unsigned int
template <>
LargeInt &LargeInt::operator*=(const long unsigned int _x)
{
  LargeInt _temp(_x);
  *this *= _temp;
  return *this;
}

// Specialized for long long unsigned int
template <>
LargeInt &LargeInt::operator*=(const long long unsigned int _x)
{
  LargeInt _temp(_x);
  *this *= _temp;
  return *this;
}

// Specialized for const char *
template <>
LargeInt &LargeInt::operator*=(const char *_x)
{
  LargeInt _temp(_x);
  *this *= _temp;
  return *this;
}

template <>
LargeInt &LargeInt::operator*=(const std::string _x)
{
  LargeInt _temp(_x);
  *this *= _temp;
  return *this;
}

// Specialized for float
template <>
LargeInt &LargeInt::operator*=(const float _x)
{
  LargeInt _temp(_x);
  *this *= _temp;
  return *this;
}

// Specialized for double
template <>
LargeInt &LargeInt::operator*=(const double _x)
{
  LargeInt _temp(_x);
  *this *= _temp;
  return *this;
}

// Specialized for long double
template <>
LargeInt &LargeInt::operator*=(const long double _x)
{
  LargeInt _temp(_x);
  *this *= _temp;
  return *this;
}

// This is the operator overloading function for assignment operator(+).
LargeInt &LargeInt::operator*=(const LargeInt &_x)
{
  unsigned int _sList1 = _nList.size();
  unsigned int _sList2 = _x._nList.size();

  // Initialized with list2
  LargeInt _iV(*this);

  // Clear current value to store result
  *this = 0U;

  // For each elements in first list multiply them to the other list
  for (auto nIndex1 = 0U; nIndex1 < _sList1; ++nIndex1)
  {
    // Initialized with list2
    LargeInt _temp(_x);

    // Store n(i) = m(0)n(i) + m(1)n(i) + ... + m(M)n(i)
    for (auto nIndex2 = 0U; nIndex2 < _sList2; ++nIndex2)
    {
      // Note of newly computed value
      _temp._nList[nIndex2] *= _iV._nList[nIndex1];
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
    *this += _temp;
  }

  return *this;
}

} // namespace li
} // namespace ds
} // namespace ns
