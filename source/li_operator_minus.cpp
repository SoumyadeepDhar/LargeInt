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

/// This is the operator overloading function for comparator operator(+).
LargeInt LargeInt::operator-(const LargeInt &_x)
{
  LargeInt _v(*this);

  typedef enum _mod_compare_
  {
    _MODA_GREATER_THAN_MODB_,
    _MODB_GREATER_THAN_MODA_,
    _MODA_AND_MODB_is_EQUAL_,
  } MODC;

#ifdef PARI
  
  if(_pariInitialized)
  {
    // Get size information
    const unsigned int _sList1 = _v._nList.size();
    const unsigned int _sList2 = _x._nList.size();

    // If large numbers are present
    if (_sList1 > 1 || _sList2 > 1)
    {
      // Get current stack top 
      pari_sp _sptop = avma;

      // Initialize pari variables
      GEN _vp, _xp;

      // Get result
      _xp = convert(_x);
      _vp = convert(_v);

      // Get result as x * y
      _v = convert(subii(_vp, _xp));

      // Clear stack
      gerepileall(_sptop, 0);

      // Return computed result
      return _v;
    }
  }
#endif

  // Set default as equal and find comparision
  MODC state = _MODA_AND_MODB_is_EQUAL_;

  const unsigned int _nd = _v.digits();
  const unsigned int _md = _x.digits();

  // Comapare absolute values
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
    for (int _s = _v._nList.size() - 1; _s >= 0; --_s)
    {
      if (_v._nList[_s] > _x._nList[_s])
      {
        state = _MODA_GREATER_THAN_MODB_;
        break;
      }

      if (_v._nList[_s] < _x._nList[_s])
      {
        state = _MODB_GREATER_THAN_MODA_;
        break;
      }
    }
  }

  // Check sign before operation
  if (_v.positive && !_x.positive)
  {
    LargeInt _absx(_x);
    _absx.positive = true;

    _v += _absx;
    _v.positive = true;
  }
  else if (!_v.positive && _x.positive)
  {
    LargeInt _absv(_v);
    _absv.positive = true;

    _v = _absv + _x;
    _v.positive = false;
  }
  else
  {
    switch (state)
    {
    case _MODA_GREATER_THAN_MODB_:
    {
      unsigned int _sList2 = _x._nList.size();

      // Substract successive elements one by one in proper positions from given list
      for (auto nIndex = 0U; nIndex < _sList2; ++nIndex)
      {
        _v.sub(*(_x._nList.begin() + nIndex), nIndex);
      }
      // Mark resultant as the sign of A
      _v.positive = positive;
      break;
    }
    case _MODB_GREATER_THAN_MODA_:
    {
      _v = _x;
      unsigned int _sList1 = _nList.size();

      // Substract successive elements one by one in proper positions from given list
      for (auto nIndex = 0U; nIndex < _sList1; ++nIndex)
      {
        _v.sub(*(_nList.begin() + nIndex), nIndex);
      }

      // Mark resultant as inverse sign of B
      _v.positive = !_x.positive;
      break;
    }
    case _MODA_AND_MODB_is_EQUAL_:
    {
      _v = 0;
      break;
    }
    }
  }

  // Remove trailing zeros if any
  if (_v._nList.size() > 1U)
  {
    size_t _e = _v._nList.size() - 1;
    for (; (_e > 0) && (_v._nList[_e] == 0); --_e)
      ;

    // Erase elements
    _v._nList.erase(_v._nList.begin() + _e + 1, _v._nList.end());
  }

  return _v;
}

template <>
LargeInt LargeInt::operator-(const char *_x)
{
  LargeInt _temp(_x);
  return *this - _temp;
}

template <>
LargeInt LargeInt::operator-(const std::string _x)
{
  return *this - _x.c_str();
}

// Specialized for char
template <>
LargeInt LargeInt::operator-(const char _x)
{
  return *this - std::to_string(_x);
}

// Specialized for unsigned char
template <>
LargeInt LargeInt::operator-(const unsigned char _x)
{
  return *this - std::to_string(_x);
}

// Specialized for short int
template <>
LargeInt LargeInt::operator-(const short int _x)
{
  return *this - std::to_string(_x);
}

// Specialized for unsigned short int
template <>
LargeInt LargeInt::operator-(const unsigned short int _x)
{
  return *this - std::to_string(_x);
}

// Specialized for int
template <>
LargeInt LargeInt::operator-(const int _x)
{
  return *this - std::to_string(_x);
}

// Specialized for unsigned int
template <>
LargeInt LargeInt::operator-(const unsigned int _x)
{
  return *this - std::to_string(_x);
}

// Specialized for long long unsigned int
template <>
LargeInt LargeInt::operator-(const long int _x)
{
  return *this - std::to_string(_x);
}

// Specialized for long long unsigned int
template <>
LargeInt LargeInt::operator-(const long unsigned int _x)
{
  return *this - std::to_string(_x);
}

// Specialized for long long unsigned int
template <>
LargeInt LargeInt::operator-(const long long int _x)
{
  return *this - std::to_string(_x);
}

// Specialized for long long unsigned int
template <>
LargeInt LargeInt::operator-(const long long unsigned int _x)
{
  return *this - std::to_string(_x);
}

// Specialized for float
template <>
LargeInt LargeInt::operator-(const float _x)
{
  return *this - std::to_string(_x).substr(0, std::to_string(_x).find("."));
}

// Specialized for double
template <>
LargeInt LargeInt::operator-(const double _x)
{
  return *this - std::to_string(_x).substr(0, std::to_string(_x).find("."));
}

// Specialized for long double
template <>
LargeInt LargeInt::operator-(const long double _x)
{
  return *this - std::to_string(_x).substr(0, std::to_string(_x).find("."));
}

} // namespace li
} // namespace dn
} // namespace ns
