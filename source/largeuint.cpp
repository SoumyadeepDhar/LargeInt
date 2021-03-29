/*
 * largeuint.cpp
 *
 *  Created on: 03-Apr-2019
 *  Author: Soumyadeep Dhar
 */

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

LargeUInt::LargeUInt()
{
  _nList.push_back(0U);
}

// Generic function for any type to large unsigned int
template <typename T>
LargeUInt::LargeUInt(const T _x)
{
  _nList.push_back(reinterpret_cast<long long unsigned int>(_x));
}

// Specialized for unsigned int
template <>
LargeUInt::LargeUInt(const unsigned int _x)
{
  _nList.push_back(reinterpret_cast<unsigned int>(_x));
}

// Specialized for long long unsigned int
template <>
LargeUInt::LargeUInt(const long long unsigned int _x)
{
  // Most significant digit
  long long unsigned int _msd = _x / N_LIMIT_mVALUE;

  // All other digits
  long long unsigned int _aod = _x - _msd * N_LIMIT_mVALUE;

  // Update nodes
  _msd ? (_nList.push_back(_aod), _nList.push_back(_msd))
       : (_nList.push_back(_aod));
}

// Specialized for const char *
template <>
LargeUInt::LargeUInt(const char *_x)
{
  // accumulator value for any node
  long long unsigned int value = 0;

  // Right to left position of the digits in the string
  unsigned int position = 0;

  // Input string length
  unsigned int nDigit = strlen(_x);

  // Fot all digits in the given string
  for (int sIndex = nDigit - 1; sIndex >= 0; --sIndex, position++)
  {
    // Calculate positional significance within the  node
    int power = position - (_nList.size() * N_LIMIT_mDIGIT);

    // Find value for the desimal place
    value += (_x[sIndex] - 48) * pow(10, power);

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
}

template <>
LargeUInt::LargeUInt(const std::string _x)
{
  // accumulator value for any node
  long long unsigned int value = 0;

  // Right to left position of the digits in the string
  unsigned int position = 0;

  // Input string length
  unsigned int nDigit = _x.length();

  // Fot all digits in the given string
  for (int sIndex = nDigit - 1; sIndex >= 0; --sIndex, position++)
  {
    // Calculate positional significance within the  node
    int power = position - (_nList.size() * N_LIMIT_mDIGIT);

    // Find value for the desimal place
    value += (_x[sIndex] - 48) * pow(10, power);

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
}

LargeUInt::LargeUInt(const LargeUInt &_x)
{
  _nList = _x._nList;
}
LargeUInt::~LargeUInt()
{
  _nList.clear();
}
// Get large unsigned integer as string for all the nodes
std::string LargeUInt::getNodes() const
{
  int nIndex = 0;
  std::ostringstream str;

  // Get most significant node
  str << "[" << nIndex++ << "]" << std::to_string(*_nList.rbegin());

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
std::string LargeUInt::getValue() const
{
  std::ostringstream str;

  // Get most significant node
  str << std::to_string(*_nList.rbegin());

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
unsigned int LargeUInt::digits() const
{
  return ((_nList.size() - 1) * N_LIMIT_mDIGIT) + floor(log10(_nList.back())) + 1;
}

LargeUInt &LargeUInt::add(const long long unsigned int _x, const unsigned int _iPosition)
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

  return *this;
}

/// This is the operator overloading function for assignment operator(+).
LargeUInt &LargeUInt::operator=(const unsigned int _x)
{
  // Clear previous data if any
  _nList.clear();

  // Most significant digit
  long long unsigned int _msd = _x / N_LIMIT_mVALUE;

  // All other digits
  long long unsigned int _aod = _x - _msd * N_LIMIT_mVALUE;

  // Update nodes
  _msd ? (_nList.push_back(_aod), _nList.push_back(_msd))
       : (_nList.push_back(_aod));

  return *this;
}

/// This is the operator overloading function for assignment operator(+).
LargeUInt &LargeUInt::operator=(const LargeUInt &_x)
{
  // Clear previous data if any
  _nList.clear();

  // Update nodes
  _nList = _x._nList;

  return *this;
}

// This is the operator overloading function for assignment operator(+).
LargeUInt &LargeUInt::operator+=(const unsigned int _x)
{
  // Add given value
  this->add(_x);
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
    _nList.push_back(0U);
  }

  // Add successive elements one by one in proper positions from given list
  for (auto nIndex = 0U; nIndex < _sList2; ++nIndex)
  {
    this->add(*(_x._nList.begin() + nIndex), nIndex);
  }

  return *this;
}

// This is the operator overloading function for assignment operator(<<).
LargeUInt &LargeUInt::operator<<=(const unsigned int _x)
{
  long long unsigned int _mCarry = __UINT64_C(0);

  // New nodes tobe appended
  unsigned int _nNodes = _x / N_LIMIT_mDIGIT;

  // Number of digits to be shifted
  unsigned int _nDigit = _x - _nNodes * N_LIMIT_mDIGIT;

  if (_nDigit > 0)
  {
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
  }

  // Append nodes at the beginging of the vector
  if (_nNodes > 0)
  {
    _nList.insert(_nList.begin(), _nNodes, 0U);
  }

  return *this;
}

// This is the operator overloading function for assignment operator(>>).
LargeUInt &LargeUInt::operator>>=(const unsigned int _x)
{
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

      // If empty node present at theend remove it
      if (_nList.back() == 0)
      {
        _nList.pop_back();
      }
    }
  }
  else
  {
    _nList.clear();
    _nList.push_back(0U);
  }

  return *this;
}

/// This is the operator overloading function for shift operator(<<).
LargeUInt LargeUInt::operator<<(const unsigned int _x) const
{
  // Create temporary storage
  LargeUInt _temp(*this);

  // Shift _x times
  _temp <<= _x;

  // return newly computed value
  return _temp;
}

/// This is the operator overloading function for shift operator(>>).
LargeUInt LargeUInt::operator>>(const unsigned int _x) const
{
  // Create temporary storage
  LargeUInt _temp(*this);

  // Shift _x times
  _temp >>= _x;

  // return newly computed value
  return _temp;
}

/// This is the operator overloading function for comparator operator(<).
bool LargeUInt::operator<(const unsigned int _x)
{
  unsigned int _nd = digits();
  unsigned int _md = floor(log10(_x)) + 1;
  return (_nd < _md)
             ? true
         : (_nd > _md)
             ? false
         : (_x < N_LIMIT_mVALUE)
             ? (_nList.back() < _x)
         : (_nList.back() < (_x / N_LIMIT_mVALUE))
             ? true
         : (_nList.back() > (_x / N_LIMIT_mVALUE))
             ? false
             : *(_nList.rbegin() - 1) < (_x % N_LIMIT_mVALUE);
}

/// This is the operator overloading function for comparator operator(<=).
bool LargeUInt::operator<=(const unsigned int _x)
{
  unsigned int _nd = digits();
  unsigned int _md = floor(log10(_x)) + 1;
  return (_nd < _md)
             ? true
         : (_nd > _md)
             ? false
         : (_x < N_LIMIT_mVALUE)
             ? (_nList.back() <= _x)
         : (_nList.back() < (_x / N_LIMIT_mVALUE))
             ? true
         : (_nList.back() > (_x / N_LIMIT_mVALUE))
             ? false
             : *(_nList.rbegin() - 1) <= (_x % N_LIMIT_mVALUE);
}

/// This is the operator overloading function for comparator operator(>).
bool LargeUInt::operator>(const unsigned int _x)
{
  unsigned int _nd = digits();
  unsigned int _md = floor(log10(_x)) + 1;
  return (_nd > _md)
             ? true
         : (_nd < _md)
             ? false
         : (_x < N_LIMIT_mVALUE)
             ? (_nList.back() > _x)
         : (_nList.back() > (_x / N_LIMIT_mVALUE))
             ? true
         : (_nList.back() < (_x / N_LIMIT_mVALUE))
             ? false
             : *(_nList.rbegin() - 1) > (_x % N_LIMIT_mVALUE);
}

/// This is the operator overloading function for comparator operator(>=).
bool LargeUInt::operator>=(const unsigned int _x)
{
  unsigned int _nd = digits();
  unsigned int _md = floor(log10(_x)) + 1;
  return (_nd > _md)
             ? true
         : (_nd < _md)
             ? false
         : (_x < N_LIMIT_mVALUE)
             ? (_nList.back() >= _x)
         : (_nList.back() > (_x / N_LIMIT_mVALUE))
             ? true
         : (_nList.back() < (_x / N_LIMIT_mVALUE))
             ? false
             : *(_nList.rbegin() - 1) >= (_x % N_LIMIT_mVALUE);
}

/// This is the operator overloading function for comparator operator(==).
bool LargeUInt::operator==(const unsigned int _x)
{
  return !(*this != _x);
}

/// This is the operator overloading function for comparator operator(!=).
bool LargeUInt::operator!=(const unsigned int _x)
{
  unsigned int _digits = floor(log10(_x)) + 1;
  return digits() != _digits
             ? true
         : (_x < N_LIMIT_mVALUE)
             ? _nList.back() != _x
             : ((*(_nList.rbegin()) != (_x / N_LIMIT_mVALUE)) ||
                (*(_nList.rbegin() - 1) != (_x % N_LIMIT_mVALUE)));
}

/// This is the operator overloading function for comparator operator(<).
bool LargeUInt::operator<(const LargeUInt &_x)
{
  unsigned int _nd = digits();
  unsigned int _md = _x.digits();

  if (_nd < _md)
  {
    return true;
  }
  else if (_nd > _md)
  {
    return false;
  }
  else
  {
    for (int _s = _nList.size() - 1; _s >= 0; --_s)
    {
      if (_nList[_s] < _x._nList[_s])
      {
        return true;
      }

      if (_nList[_s] > _x._nList[_s])
      {
        return false;
      }
    }
    return false;
  }
}

/// This is the operator overloading function for comparator operator(<=).
bool LargeUInt::operator<=(const LargeUInt &_x)
{
  unsigned int _nd = digits();
  unsigned int _md = _x.digits();

  if (_nd < _md)
  {
    return true;
  }
  else if (_nd > _md)
  {
    return false;
  }
  else
  {
    for (int _s = _nList.size() - 1; _s >= 0; --_s)
    {
      if (_nList[_s] < _x._nList[_s])
      {
        return true;
      }

      if (_nList[_s] > _x._nList[_s])
      {
        return false;
      }
    }
    return true;
  }
}

/// This is the operator overloading function for comparator operator(>).
bool LargeUInt::operator>(const LargeUInt &_x)
{
  unsigned int _nd = digits();
  unsigned int _md = _x.digits();

  if (_nd > _md)
  {
    return true;
  }
  else if (_nd < _md)
  {
    return false;
  }
  else
  {
    for (int _s = _nList.size() - 1; _s >= 0; --_s)
    {
      if (_nList[_s] > _x._nList[_s])
      {
        return true;
      }

      if (_nList[_s] < _x._nList[_s])
      {
        return false;
      }
    }
    return false;
  }
}

/// This is the operator overloading function for comparator operator(>=).
bool LargeUInt::operator>=(const LargeUInt &_x)
{
  unsigned int _nd = digits();
  unsigned int _md = _x.digits();

  if (_nd > _md)
  {
    return true;
  }
  else if (_nd < _md)
  {
    return false;
  }
  else
  {
    for (int _s = _nList.size() - 1; _s >= 0; --_s)
    {
      if (_nList[_s] > _x._nList[_s])
      {
        return true;
      }

      if (_nList[_s] < _x._nList[_s])
      {
        return false;
      }
    }
    return true;
  }
}

/// This is the operator overloading function for comparator operator(==).
bool LargeUInt::operator==(const LargeUInt &_x)
{
  return !(*this != _x);
}

/// This is the operator overloading function for comparator operator(!=).
bool LargeUInt::operator!=(const LargeUInt &_x)
{
  unsigned int _nd = digits();
  unsigned int _md = _x.digits();
  if (_nd != _md)
  {
    return true;
  }
  else
  {
    for (int _s = _nList.size() - 1; _s >= 0; --_s)
    {
      if (_nList[_s] != _x._nList[_s])
      {
        return true;
      }
    }
    return false;
  }
}

} // namespace lui
} // namespace ds
} // namespace ns