/*
 * lui_operator_division.cpp
 *
 *  Created on: 30-Mar-2021
 *  Author: Soumyadeep Dhar
 */

#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>

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

// This is the operator overloading function for division operator(/).
LargeInt LargeInt::operator/(const LargeInt &_x)
{
  // Is diviser is zero
  if (*this == 0)
  {
    return LargeInt{INFINITY};
  }

  // Is divident is zero
  if (*this == 0)
  {
    return LargeInt{0U};
  }

  // Initialize absolute
  LargeInt _absv(*this);
  _absv.positive = true;
  LargeInt _absx(_x);
  _absx.positive = true;

  // Is divident is small
  if (_absv < _absx)
  {
    return LargeInt{0U};
  }

  // Initialized as positive
  LargeInt _result(0U);

  // If divident and divisor are equql
  if (_absv == _absx)
  {
    //Set result
    _result = 1U;

    // Update sign information
    _result.positive = !(positive ^ _x.positive);

    return _result;
  }

  //Get size information
  unsigned int _sList1 = _nList.size();
  unsigned int _sList2 = _x._nList.size();

#ifdef PARI
  if (_pariInitialized)
  {
    // If large numbers are present
    if (_sList1 > 1 || _sList2 > 1)
    {
      // Get current stack top 
      pari_sp _sptop = avma;

      // Initialize pari variables
      GEN _vp, _xp;

      // Get result
      _xp = convert(_x);
      _vp = convert(*this);

      // Get result as x / y
      _result = convert(dvmdii(_vp, _xp, NULL));

      // Clear stack
      gerepileall(_sptop, 0);

      // Return computed result
      return _result;
    }
  }
#endif

  // Initialize remainder
  LargeInt _remainder(0U);
  for (auto nIndex1 = _sList1 - _sList2 + 1; nIndex1 < _sList1; ++nIndex1)
  {
    LargeInt _temp(_absv._nList[nIndex1]);
    _temp <<= (N_LIMIT_mDIGIT * (nIndex1 - (_sList1 - _sList2 + 1)));
    _remainder += _temp;
  }

  // For (_sList1 - _sList2 + 1) times iterate
  for (auto nIndex1 = _sList1 - _sList2 + 1; nIndex1 > 0; --nIndex1)
  {
    // Get node value
    long long unsigned int _nElement = _absv._nList[nIndex1 - 1];

    // Get intermediate divident
    LargeInt _divident(_remainder);
    _divident <<= N_LIMIT_mDIGIT;
    _divident += _nElement;

    long double _div = 0.0F;
    long double _dsr = 0.0F;
    long long int _quotient = 0;

    // Find new remainder
    if (_divident >= _absx)
    {
      unsigned int digitDiff = _divident.digits() - _absx.digits();

      _div = std::strtold(_divident.getValue()
                              .substr(0, std::min(_divident.digits(), (N_LIMIT_mDIGIT * 3)))
                              .c_str(),
                          0);
      _dsr = std::strtold(_absx.getValue()
                              .substr(0, std::min(_divident.digits(), ((N_LIMIT_mDIGIT * 3) - digitDiff)))
                              .c_str(),
                          0);

      // Calculate quotient
      _quotient = (_div / _dsr);

      // Update remainder
      LargeInt _nearest(_absx);
      _nearest *= _quotient;

      // Adjust nearest element
      if (_nearest > _divident)
      {
        _nearest -= _absx;
        _quotient -= 1;
      }

      // Find new remainder
      _remainder = _divident - _nearest;
    }
    else
    {
      _quotient = 0;
      _remainder = _divident;
    }

    // Update result
    _result._nList.insert(_result._nList.begin(), _quotient);
  }

  // Remove trailing zeros if any
  if (_result._nList.size() > 1U)
  {
    size_t _e = _result._nList.size() - 1;
    for (; (_e > 0) && (_result._nList[_e] == 0); --_e)
      ;

    // Erase elements
    _result._nList.erase(_result._nList.begin() + _e + 1, _result._nList.end());
  }

  // Update sign information
  _result.positive = !(positive ^ _x.positive);

  return _result;
}

template <>
LargeInt LargeInt::operator/(const char *_x)
{
  LargeInt _temp(_x);
  return *this / _temp;
}

template <>
LargeInt LargeInt::operator/(const std::string _x)
{
  return *this / _x.c_str();
}

// Specialized for char
template <>
LargeInt LargeInt::operator/(const char _x)
{
  return *this / std::to_string(_x);
}

// Specialized for unsigned char
template <>
LargeInt LargeInt::operator/(const unsigned char _x)
{
  return *this / std::to_string(_x);
}

// Specialized for short int
template <>
LargeInt LargeInt::operator/(const short int _x)
{
  return *this / std::to_string(_x);
}

// Specialized for unsigned short int
template <>
LargeInt LargeInt::operator/(const unsigned short int _x)
{
  return *this / std::to_string(_x);
}

// Specialized for int
template <>
LargeInt LargeInt::operator/(const int _x)
{
  return *this / std::to_string(_x);
}

// Specialized for unsigned int
template <>
LargeInt LargeInt::operator/(const unsigned int _x)
{
  return *this / std::to_string(_x);
}

// Specialized for long long unsigned int
template <>
LargeInt LargeInt::operator/(const long int _x)
{
  return *this / std::to_string(_x);
}

// Specialized for long long unsigned int
template <>
LargeInt LargeInt::operator/(const long unsigned int _x)
{
  return *this / std::to_string(_x);
}

// Specialized for long long unsigned int
template <>
LargeInt LargeInt::operator/(const long long int _x)
{
  return *this / std::to_string(_x);
}

// Specialized for long long unsigned int
template <>
LargeInt LargeInt::operator/(const long long unsigned int _x)
{
  return *this / std::to_string(_x);
}

// Specialized for float
template <>
LargeInt LargeInt::operator/(const float _x)
{
  return *this / std::to_string(_x).substr(0, std::to_string(_x).find("."));
}

// Specialized for double
template <>
LargeInt LargeInt::operator/(const double _x)
{
  return *this / std::to_string(_x).substr(0, std::to_string(_x).find("."));
}

// Specialized for long double
template <>
LargeInt LargeInt::operator/(const long double _x)
{
  return *this / std::to_string(_x).substr(0, std::to_string(_x).find("."));
}

} // namespace li
} // namespace dn
} // namespace ns
