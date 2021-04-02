/*
 * lui_operator_plus_equal.cpp
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
LargeUInt &LargeUInt::operator+=(const int _x)
{
  this->add(static_cast<long long unsigned int>(_x));
  return *this;
}

// Specialized for unsigned int
template <>
LargeUInt &LargeUInt::operator+=(const unsigned int _x)
{
  this->add(static_cast<long long unsigned int>(_x));
  return *this;
}

// Specialized for long long unsigned int
template <>
LargeUInt &LargeUInt::operator+=(const long unsigned int _x)
{
  this->add(static_cast<long long unsigned int>(_x));
  return *this;
}

// Specialized for long long unsigned int
template <>
LargeUInt &LargeUInt::operator+=(const long long unsigned int _x)
{
  this->add(_x);
  return *this;
}

// Specialized for const char *
template <>
LargeUInt &LargeUInt::operator+=(const char *_x)
{
  LargeUInt _temp(_x);
  *this += _temp;
  return *this;
}

template <>
LargeUInt &LargeUInt::operator+=(const std::string _x)
{
  // Add new value
  *this += _x.c_str();
  return *this;
}

// Specialized for float
template <>
LargeUInt &LargeUInt::operator+=(const float _x)
{
  LargeUInt _temp(_x);
  *this += _temp;
  return *this;
}

// Specialized for double
template <>
LargeUInt &LargeUInt::operator+=(const double _x)
{
  LargeUInt _temp(_x);
  *this += _temp;
  return *this;
}

// Specialized for long double
template <>
LargeUInt &LargeUInt::operator+=(const long double _x)
{
  LargeUInt _temp(_x);
  *this += _temp;
  return *this;
}

// This is the operator overloading function for assignment operator(+).
LargeUInt &LargeUInt::operator+=(const LargeUInt &_x)
{
  unsigned int _sList1 = _nList.size();
  unsigned int _sList2 = _x._nList.size();

  // Make sure current list has as many elements as the given list to add
  for (auto nIndex = _sList1; nIndex < _sList2; ++nIndex)
  {
    _nList.push_back(0UL);
  }

  // Add successive elements one by one in proper positions from given list
  for (auto nIndex = 0U; nIndex < _sList2; ++nIndex)
  {
    this->add(*(_x._nList.begin() + nIndex), nIndex);
  }

  return *this;
}

} // namespace lui
} // namespace ds
} // namespace ns
