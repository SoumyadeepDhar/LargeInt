/*
 * largeint.cpp
 *
 *  Created on: 03-Apr-2019
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
// Large unsigned integer
namespace li
{

LargeInt::LargeInt() : positive(true)
{
  _nList = {0U};
}

// Specialized for const char *
template <>
LargeInt::LargeInt(const char *_x)
    : positive(true)
{
  if (_x == NULL)
  {
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
    unsigned int nDigit = strlen(_x);

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
      bool isNobZeroValuePresent = false;
      for (auto nElement : _nList)
      {
        if (nElement != 0U)
        {
          isNobZeroValuePresent = true;
          break;
        }
      }

      // If zero found
      if (isNobZeroValuePresent == false)
      {
        positive = true;
        _nList = {0U};
      }

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
    else
    {
      positive = true;
      _nList = {0U};
    }
  }
}

// Specialized for char *
template <>
LargeInt::LargeInt(char *_x)
    : LargeInt(static_cast<const char *>(_x))
{
}

template <>
LargeInt::LargeInt(const std::string _x)
    : LargeInt(_x.c_str())
{
}

// Specialized for long long unsigned int
template <>
LargeInt::LargeInt(const long long unsigned int _x)
    : LargeInt(std::to_string(_x))
{
}

// Specialized for long long int
template <>
LargeInt::LargeInt(const long long int _x)
    : LargeInt(static_cast<long long unsigned int>(abs(_x)))
{
  // Update sign information
  positive = _x < 0 ? false : true;
}

// Specialized for long unsigned int
template <>
LargeInt::LargeInt(const long unsigned int _x)
    : LargeInt(static_cast<long long unsigned int>(_x))
{
}

// Specialized for long int
template <>
LargeInt::LargeInt(const long int _x)
    : LargeInt(static_cast<long long unsigned int>(abs(_x)))
{
  positive = _x < 0 ? false : true;
}

// Specialized for unsigned int
template <>
LargeInt::LargeInt(const unsigned int _x)
    : LargeInt(static_cast<long long unsigned int>(_x))
{
}

// Specialized for int
template <>
LargeInt::LargeInt(const int _x)
    : LargeInt(std::to_string(_x))
{
}

// Specialized for unsigned short int
template <>
LargeInt::LargeInt(const unsigned short int _x)
    : LargeInt(static_cast<long long unsigned int>(_x))
{
}

// Specialized for short int
template <>
LargeInt::LargeInt(const short int _x)
    : LargeInt(std::to_string(_x))
{
}

// Specialized for unsigned char
template <>
LargeInt::LargeInt(const unsigned char _x)
    : LargeInt(static_cast<long long unsigned int>(_x))
{
}

// Specialized for char
template <>
LargeInt::LargeInt(const char _x)
    : LargeInt(std::to_string(_x))
{
}

// Specialized for float
template <>
LargeInt::LargeInt(const float _x)
    : LargeInt(std::to_string(_x).substr(0, std::to_string(_x).find(".")))
{
}

// Specialized for double
template <>
LargeInt::LargeInt(const double _x)
    : LargeInt(std::to_string(_x).substr(0, std::to_string(_x).find(".")))
{
}

// Specialized for long double
template <>
LargeInt::LargeInt(const long double _x)
    : LargeInt(std::to_string(_x).substr(0, std::to_string(_x).find(".")))
{
}

LargeInt::LargeInt(const LargeInt &_x)
{
  // Set sign information
  positive = _x.positive;

  // Set value
  _nList = _x._nList;
}

LargeInt::~LargeInt()
{
  _nList.clear();
}

void LargeInt::add(const long long unsigned int _x, const unsigned int _iPosition)
{
  // Get positional value to add
  auto _cPosition = _nList.begin() + _iPosition;

  // Get resultant
  long long unsigned int _value = *_cPosition + _x;

  // Get carry
  long long unsigned int _carry = _value / N_LIMIT_mVALUE;

  // Update node value
  *_cPosition = _value - _carry * N_LIMIT_mVALUE;

  // If carry value present
  if (_carry > 0)
  {
    // Update next (if exist) node with carry value
    if (std::next(_cPosition) != _nList.end())
    {
      // Add carry to next node position
      add(_carry, (_iPosition + 1));
    }
    else
    {
      // Append carry as last node
      _nList.push_back(_carry);
    }
  }
}

void LargeInt::sub(const long long unsigned int _x, const unsigned int _iPosition)
{
  // Get positional value to add
  auto _cPosition = _nList.begin() + _iPosition;

  // Get carry
  long long unsigned int _carry = *_cPosition < _x ? 1U : 0U;

  // If carry value present
  if (_carry > 0)
  {
    // Update result
    *_cPosition = ((N_LIMIT_mVALUE + *_cPosition) - _x);

    // Update next (if exist) node with carry value
    if (std::next(_cPosition) != _nList.end())
    {
      // Substract carry to next node position
      sub(_carry, (_iPosition + 1));
    }
  }
  else
  {
    // Update node value
    *_cPosition -= _x;
  }
}

// Get large integer sign information as string
std::string LargeInt::getSign() const
{
  return positive ? "" : "-";
}

// Get large unsigned integer as string for all the nodes
std::string LargeInt::getNodes() const
{
  int nIndex = 0;
  std::ostringstream str;

  // Get most significant node
  str << "[" << nIndex++ << "]" << getSign() << std::to_string(*_nList.rbegin());

  // Get all other nodes
  for (auto i = _nList.rbegin() + 1; i != _nList.rend(); ++i)
  {
    str << " [" << nIndex++ << "]";
    std::string value(std::to_string(*i));

    for (unsigned int x = N_LIMIT_mDIGIT; x > value.length(); x--)
    {
      str << "0";
    }

    str << value;
  }

  return str.str();
}

// Get large unsigned integer as string for all the nodes
std::string LargeInt::getValue() const
{
  std::ostringstream str;

  // Get most significant node
  str << getSign() << std::to_string(*_nList.rbegin());

  // Get all other nodes
  for (auto i = _nList.rbegin() + 1; i != _nList.rend(); ++i)
  {
    std::string value(std::to_string(*i));

    for (unsigned int x = N_LIMIT_mDIGIT; x > value.length(); x--)
    {
      str << "0";
    }

    str << value;
  }

  return str.str();
}

/// Get number of digits
unsigned int LargeInt::digits() const
{
  return ((_nList.size() - 1) * N_LIMIT_mDIGIT) + floor(log10(_nList.back())) + 1;
}

// This is the operator overloading function for assignment operator(<<).
LargeInt &LargeInt::operator<<=(const unsigned int _x)
{
  // If current value is zero or shift amount is zero then do nothing
  if (*this == 0U || _x == 0U)
  {
    return *this;
  }

  long long unsigned int _mCarry = __UINT64_C(0);

  // New nodes tobe appended
  unsigned int _nNodes = _x / N_LIMIT_mDIGIT;

  // Number of digits to be shifted
  unsigned int _nDigit = _x - _nNodes * N_LIMIT_mDIGIT;

  // Complement digits to be shifted
  unsigned int _cDigit = N_LIMIT_mDIGIT - _nDigit;
  long long unsigned int _cValue = pow(10, _cDigit);
  long long unsigned int _nValue = pow(10, _nDigit);

  // Shift succesive elements
  for (auto i = _nList.begin(); i != _nList.end(); ++i)
  {
    // Find carry to be added tothe previous node
    long long unsigned int _nCarry = *i / _cValue;

    // Update current node
    *i = (*i - (_nCarry * _cValue)) * _nValue + _mCarry;

    // Update carry
    _mCarry = _nCarry;
  }

  // If carry present add new node with carry
  if (_mCarry > 0)
  {
    _nList.push_back(_mCarry);
  }

  // Append nodes at the beginging of the vector
  if (_nNodes > 0)
  {
    _nList.insert(_nList.begin(), _nNodes, 0U);
  }

  return *this;
}

// This is the operator overloading function for assignment operator(>>).
LargeInt &LargeInt::operator>>=(const unsigned int _x)
{
  // If current value is zero or shift amount is zero then do nothing
  if (*this == 0U || _x == 0U)
  {
    return *this;
  }

  // Set default
  long long unsigned int _mCarry = __UINT64_C(0);

  // New nodes tobe appended
  unsigned int _nNodes = _x / N_LIMIT_mDIGIT;

  // Number of digits to be shifted
  unsigned int _nDigit = _x - _nNodes * N_LIMIT_mDIGIT;

  // If given number is larger than shift length
  if (_nNodes < _nList.size())
  {

    // Erase _nNodes nodes from begining
    if (_nNodes > 0)
    {
      _nList.erase(_nList.begin(), _nList.begin() + _nNodes);
    }

    // Digits has to be shifted
    if (_nDigit > 0)
    {
      // Complement digits to be shifted
      unsigned int _cDigit = N_LIMIT_mDIGIT - _nDigit;
      long long unsigned int _cValue = pow(10, _cDigit);
      long long unsigned int _nValue = pow(10, _nDigit);

      // Shift succesive elements
      for (auto i = _nList.rbegin(); i != _nList.rend(); ++i)
      {
        // Find carry to be added tothe previous node
        long long unsigned int _nCarry = *i - ((*i / _nValue) * _nValue);

        // Update current node
        *i = *i / _nValue + _mCarry;

        // Update carry
        _mCarry = (_nCarry * _cValue);
      }

      // If empty node present at the end then remove it
      if (_nList.back() == 0)
      {
        _nList.pop_back();
      }
    }
  }
  else
  {
    positive = true;
    _nList = {0U};
  }

  return *this;
}

/// This is the operator overloading function for shift operator(<<).
LargeInt LargeInt::operator<<(const unsigned int _x) const
{
  // Create temporary storage
  LargeInt _temp(*this);

  // If current value is not zero and shift amount is not zero then do operation
  if (_temp != 0U && _x != 0U)
  {
    // Shift _x times
    _temp <<= _x;
  }

  // return newly computed value
  return _temp;
}

/// This is the operator overloading function for shift operator(>>).
LargeInt LargeInt::operator>>(const unsigned int _x) const
{
  // Create temporary storage
  LargeInt _temp(*this);

  // If current value is not zero and shift amount is not zero then do operation
  if (_temp != 0U && _x != 0U)
  {
    // Shift _x times
    _temp >>= _x;
  }

  // return newly computed value
  return _temp;
}

/// This is the operator overloading function for assignment operator(++) prefix.
LargeInt LargeInt::operator++()
{
  *this += 1;
  return *this;
}

/// This is the operator overloading function for assignment operator(--) prefix.
LargeInt LargeInt::operator--()
{
  *this -= 1;
  return *this;
}

/// This is the operator overloading function for assignment operator(++) postfix.
LargeInt LargeInt::operator++(int)
{
  LargeInt _temp(*this);
  *this += 1;
  return _temp;
}

/// This is the operator overloading function for assignment operator(--) postfix.
LargeInt LargeInt::operator--(int)
{
  LargeInt _temp(*this);
  *this -= 1;
  return _temp;
}

} // namespace li
} // namespace ds
} // namespace ns