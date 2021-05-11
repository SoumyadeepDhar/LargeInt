/*
 * largeint.cpp
 *
 *  Created on: 03-Apr-2019
 *  Author: Soumyadeep Dhar
 */

#include <float.h>
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
{
  // Assign _x as current value
  *this = _x;
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

/// Assign filtered string value
void LargeInt::assignment(const std::string &_x)
{
  const int _nodeLength = N_LIMIT_mDIGIT;

  // Clear previous data
  _nList.clear();

  // Set sign information
  positive = _x[0] != '-' ? true : false;

  // Input string length
  int nDigit = _x.length();

  // Assign term by term
  int st = positive ? 0 : 1;
  int en = nDigit - 1;
  int position = nDigit;
  int length = _nodeLength;

  // Create nodes from the given string
  for (int _i = en; _i >= st; _i -= _nodeLength)
  {
    // Get length of string that represent current node
    length = std::min((position - st), _nodeLength);

    // Get starting position of current node
    position = std::max(st, (_i - _nodeLength + 1));

    // Create new node
    this->_nList.push_back(std::stoull(_x.substr(position, length)));
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

/// Get sqrt of the number
LargeInt LargeInt::sqrt()
{
  // For negative number or 0U
  if (*this <= 0U)
    return {0U};

  // For number in a single node
  if (*this < N_LIMIT_mVALUE)
    return {std::sqrt(std::stold(getValue()))};

  // Bakhshali's Method
  LargeInt _nA, _nB, _nR, _result, _number(*this);

  // Get even power 2n (total digits always greater than single node i.e. N_LIMIT_mDIGIT)
  unsigned int _eDigit = (std::min(digits(), static_cast<unsigned int>(FLT_MAX_10_EXP)) >> 1) << 1;

  // Keeping N_LIMIT_mDIGIT buffer to accurate estimation (n + N_LIMIT_mDIGIT)
  int _multiplier = ((digits() - _eDigit) >> 1) + N_LIMIT_mDIGIT;

  // Create a initial Integer estimation as square root
  _nR = std::sqrt(std::strtold(getValue().substr(0, _eDigit).c_str(), 0));

  // Adjust power to (n + N_LIMIT_mDIGIT)
  _nR <<= _multiplier;

  // Update original number
  _number <<= (N_LIMIT_mDIGIT * 2);

  do
  {
    // Keep note of last valid result
    _result = _nR;

    // Calculate _nA
    _nA = (_number - (_nR * _nR)) / (_nR * 2);

    // Calculate _nB
    _nB = _result + _nA;

    // Update result for next iteration
    _nR = _nB - ((_nA * _nA) / (_nB * 2));

    // Until no further improvement possible for square root
  } while (_result != _nR);

  // Readjust result to accurate decimal places
  _result >>= N_LIMIT_mDIGIT;

  // Return integer part of sqrt
  return _result;
}

/// Get nth power of the number
LargeInt LargeInt::pow(const unsigned int _x)
{
  // For 0U th power
  if (_x == 0U)
    return {1U};

  // For 0U th power
  if (_x == 1U)
    return {*this};

  // Temporary local result
  LargeInt _result(0U);

#ifdef PARI
  if (_pariInitialized)
  {
    // Get current stack top 
    pari_sp _sptop = avma;

    // Calculate (value^_x) using pari library
    GEN _xp = powiu(convert(*this), _x);

    // Get result
    _result = convert(_xp);

    // Clear stack
    gerepileall(_sptop, 0);

    // Return computed result
    return _result;
  }
#endif

  // If result already not computed
  _result = *this;
  LargeInt _temp(*this);

  // Multiple base value (n - 1) times
  for (auto index = 0U; index < (_x - 1); index++)
  {
    _result *= _temp;
  }

  //Find sign value
  _result.positive = positive ? true : !(_x % 2) ? true
                                                 : false;

  return _result;
}

/// Get nth root of the number
LargeInt LargeInt::root(const unsigned int _x)
{
  // For 0U th root
  if (_x == 0U)
    return {INFINITY};

  // For 1U th root
  if (_x == 1U)
    return *this;

  // For 2U th root
  if (_x == 2U)
    return this->sqrt();

  // For negative number or 0U
  if (*this <= 0U)
    return {0U};

  // For number in a single node
  if (*this < N_LIMIT_mVALUE)
    return {powl(std::stold(getValue()), (1.0 / _x))};

  // Temporary local result
  LargeInt _result(0U);

#ifdef PARI
  if (_pariInitialized)
  {
    // Get current stack top 
    pari_sp _sptop = avma;

    // Compute result using pari library
    GEN x = sqrtnint(convert(*this), _x);

    // Get result
    _result = convert(floor_safe(x));

    // Clear stack
    gerepileall(_sptop, 0);

    // Return integer part of the nth root
    return _result;
  }
#endif

  // Newton's method: (i + 1)th iteration root
  //                    --                              --
  //                1   |                       A        |
  //  X(i + 1) =  ----- | (n - 1).X(i) + --------------  |
  //                n   |                  X(i)^(n - 1)  |
  //                    --                              --
  LargeInt _nR, _nB, _nA(*this);

  // Select number of digits for initial estimate
  // (total digits always greater than single node i.e. N_LIMIT_mDIGIT)
  unsigned int _eDigit = std::min(digits(), static_cast<unsigned int>(DBL_MAX_10_EXP));

  // Keeping N_LIMIT_mDIGIT buffer to accurate estimation (n + N_LIMIT_mDIGIT)
  int _multiplier = (digits() - _eDigit) + N_LIMIT_mDIGIT;

  // Create a initial Integer estimation as square root
  _nR = powl(std::strtold(getValue().substr(0, _eDigit).c_str(), 0), (1.0 / _x));

  // Adjust power to (n + N_LIMIT_mDIGIT)
  _nR <<= _multiplier;

  // Update original number
  _nA <<= (N_LIMIT_mDIGIT * _x);
  do
  {
    // Keep note of last valid result
    _result = _nR;

    // Calculate result
    // _nR = ((_nR * (_x - 1)) + (_nA / (_nR.pow(_x - 1)))) / _x;
    _nB = _nR.pow(_x - 1);
    _nB = _nA / _nB;
    _nR *= (_x - 1);
    _nR += _nB;
    _nR /= _x;

    // Until no further improvement possible for the nth root
  } while (_result.getValue().substr(0, (_result.digits() - N_LIMIT_mDIGIT)) !=
           _nR.getValue().substr(0, (_nR.digits() - N_LIMIT_mDIGIT)));

  // Readjust result to accurate decimal places
  _result >>= N_LIMIT_mDIGIT;

  // Return integer part of the nth root
  return _result;
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

  // New nodes to be appended
  unsigned int _nNodes = _x / N_LIMIT_mDIGIT;

  // Number of digits to be shifted
  unsigned int _nDigit = _x - _nNodes * N_LIMIT_mDIGIT;

  // Complement digits to be shifted
  unsigned int _cDigit = N_LIMIT_mDIGIT - _nDigit;
  long long unsigned int _cValue = std::pow(10, _cDigit);
  long long unsigned int _nValue = std::pow(10, _nDigit);

  // Shift successive elements
  for (auto i = _nList.begin(); i != _nList.end(); ++i)
  {
    // Find carry to be added to the previous node
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

  // New nodes to be appended
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
      long long unsigned int _cValue = std::pow(10, _cDigit);
      long long unsigned int _nValue = std::pow(10, _nDigit);

      // Shift successive elements
      for (auto i = _nList.rbegin(); i != _nList.rend(); ++i)
      {
        // Find carry to be added to the previous node
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
} // namespace dn
} // namespace ns