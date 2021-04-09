/*
 * lui_operator_minus.cpp
 *
 *  Created on: 30-Mar-2021
 *  Author: Soumyadeep Dhar
 */

#include <iostream>
#include <sstream>
#include <cstring>
#include "largeint.h"

// Number ststem
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
LargeInt LargeInt::operator-(const int _x)
{
  LargeInt _temp(_x);
  return *this - _temp;
}

// Specialized for unsigned int
template <>
LargeInt LargeInt::operator-(const unsigned int _x)
{
  LargeInt _temp(_x);
  return *this - _temp;
}

// Specialized for long long unsigned int
template <>
LargeInt LargeInt::operator-(const long unsigned int _x)
{
  LargeInt _temp(_x);
  return *this - _temp;
}

// Specialized for long long unsigned int
template <>
LargeInt LargeInt::operator-(const long long unsigned int _x)
{
  LargeInt _temp(_x);
  return *this - _temp;
}

// Specialized for const char *
template <>
LargeInt LargeInt::operator-(const char *_x)
{
  LargeInt _temp(_x);
  return *this - _temp;
}

template <>
LargeInt LargeInt::operator-(const std::string _x)
{
  LargeInt _temp(_x);
  return *this - _temp;
}

// Specialized for float
template <>
LargeInt LargeInt::operator-(const float _x)
{
  LargeInt _temp(_x);
  return *this - _temp;
}

// Specialized for double
template <>
LargeInt LargeInt::operator-(const double _x)
{
  LargeInt _temp(_x);
  return *this - _temp;
}

// Specialized for long double
template <>
LargeInt LargeInt::operator-(const long double _x)
{
  LargeInt _temp(_x);
  return *this - _temp;
}

// This is the operator overloading function for assignment operator(-).
LargeInt LargeInt::operator-(const LargeInt &_x)
{
  LargeInt _v(*this);
  unsigned int _sList1 = _v._nList.size();
  unsigned int _sList2 = _x._nList.size();

  // Make sure current list has as many elements as the given list to add
  for (auto nIndex = _sList1; nIndex < _sList2; ++nIndex)
  {
    _v._nList.push_back(0UL);
  }

  // Substract successive elements one by one in proper positions from given list
  for (auto nIndex = 0U; nIndex < _sList2; ++nIndex)
  {
    _v.sub(*(_x._nList.begin() + nIndex), nIndex);
  }

  // Remove trailing zerosif any 
  if(_nList.size() > 1U)
  {
    size_t _e = _v._nList.size() - 1;
    for(; (_e > 0) && (_v._nList[_e] == 0); --_e);
    
    // Erase elements
    _v._nList.erase(_v._nList.begin() + _e + 1, _v._nList.end());
  }
  return _v;
}

} // namespace li
} // namespace ds
} // namespace ns