/*
 * lui_operator_plus.cpp
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

/// This is the operator overloading function for comparator operator(+).
LargeInt LargeInt::operator+(const LargeInt &_x)
{
  LargeInt _v;

  typedef enum _mod_compare_
  {
    _MODA_GREATER_THAN_MODB_,
    _MODB_GREATER_THAN_MODA_,
    _MODA_AND_MODB_is_EQUAL_,
  } MODC;

  // Set default as equal and find comparision
  MODC state = _MODA_AND_MODB_is_EQUAL_;

  unsigned int _nd = digits();
  unsigned int _md = _x.digits();

  // Comapare absulate values
  if (_nd > _md)
  {
    state = _MODA_GREATER_THAN_MODB_;
  }
  else if (_nd < _md)
  {
    state = _MODB_GREATER_THAN_MODA_;
  }
  else
  {
    for (int _s = _nList.size() - 1; _s >= 0; --_s)
    {
      if (_nList[_s] > _x._nList[_s])
      {
        state = _MODA_GREATER_THAN_MODB_;
        break;
      }

      if (_nList[_s] < _x._nList[_s])
      {
        state = _MODB_GREATER_THAN_MODA_;
        break;
      }
    }
  }

  // Check sign before operation
  if (positive && !_x.positive)
  {
    LargeInt _absx(_x);
    _absx.positive = true;

    switch (state)
    {
    case _MODA_GREATER_THAN_MODB_:
      _v = *this - _absx;
      _v.positive = true;
      break;
    case _MODB_GREATER_THAN_MODA_:
      _v = _absx - *this;
      _v.positive = false;
      break;
    case _MODA_AND_MODB_is_EQUAL_:
      _v = 0;
      break;
    }
  }
  else if (!positive && _x.positive)
  {
    LargeInt _absv(*this);
    _absv.positive = true;

    switch (state)
    {
    case _MODA_GREATER_THAN_MODB_:
      _v = _absv - _x;
      _v.positive = false;
      break;
    case _MODB_GREATER_THAN_MODA_:
      _v = _x;
      _v = _v - _absv;
      _v.positive = true;
      break;
    case _MODA_AND_MODB_is_EQUAL_:
      _v = 0;
      break;
    }
  }
  else
  {
    _v = *this;
    unsigned int _sList1 = _v._nList.size();
    unsigned int _sList2 = _x._nList.size();

    // Make sure current list has as many elements as the given list to add
    for (auto nIndex = _sList1; nIndex < _sList2; ++nIndex)
    {
      _v._nList.push_back(0UL);
    }

    // Add successive elements one by one in proper positions from given list
    for (auto nIndex = 0U; nIndex < _sList2; ++nIndex)
    {
      _v.add(*(_x._nList.begin() + nIndex), nIndex);
    }
  }

  return _v;
}

template <>
LargeInt LargeInt::operator+(const char *_x)
{
  LargeInt _temp(_x);
  return *this + _temp;
}

template <>
LargeInt LargeInt::operator+(const std::string _x)
{
  return *this + _x.c_str();
}

// Specialized for char
template <>
LargeInt LargeInt::operator+(const char _x)
{
  return *this + std::to_string(_x);
}

// Specialized for unsigned char
template <>
LargeInt LargeInt::operator+(const unsigned char _x)
{
  return *this + std::to_string(_x);
}

// Specialized for short int
template <>
LargeInt LargeInt::operator+(const short int _x)
{
  return *this + std::to_string(_x);
}

// Specialized for unsigned short int
template <>
LargeInt LargeInt::operator+(const unsigned short int _x)
{
  return *this + std::to_string(_x);
}

// Specialized for int
template <>
LargeInt LargeInt::operator+(const int _x)
{
  return *this + std::to_string(_x);
}

// Specialized for unsigned int
template <>
LargeInt LargeInt::operator+(const unsigned int _x)
{
  return *this + std::to_string(_x);
}

// Specialized for long int
template <>
LargeInt LargeInt::operator+(const long int _x)
{
  return *this + std::to_string(_x);
}

// Specialized for long unsigned int
template <>
LargeInt LargeInt::operator+(const long unsigned int _x)
{
  return *this + std::to_string(_x);
}

// Specialized for long long int
template <>
LargeInt LargeInt::operator+(const long long int _x)
{
  return *this + std::to_string(_x);
}

// Specialized for long long unsigned int
template <>
LargeInt LargeInt::operator+(const long long unsigned int _x)
{
  return *this + std::to_string(_x);
}

// Specialized for float
template <>
LargeInt LargeInt::operator+(const float _x)
{
  return *this + std::to_string(_x).substr(0, std::to_string(_x).find("."));
}

// Specialized for double
template <>
LargeInt LargeInt::operator+(const double _x)
{
  return *this + std::to_string(_x).substr(0, std::to_string(_x).find("."));
}

// Specialized for long double
template <>
LargeInt LargeInt::operator+(const long double _x)
{
  return *this + std::to_string(_x).substr(0, std::to_string(_x).find("."));
}

} // namespace li
} // namespace ds
} // namespace ns
