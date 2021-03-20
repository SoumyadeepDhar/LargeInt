/*
 * LargeUInt.cpp
 *
 *  Created on: 03-Apr-2019
 *  Author: Soumyadeep Dhar
 */

#include "largeuint.h"
#include <sstream>

LargeUInt::LargeUInt()
{
	_nList.push_back(0U);
}

LargeUInt::LargeUInt(const unsigned int _x)
{
	// Most significant digit
	unsigned int _msd = _x / N_LIMIT_VALUE;

	// All other digits
	unsigned int _aod = _x - _msd * N_LIMIT_VALUE;

	// Update nodes
	_msd ? _nList.push_back(_aod)
		 : _nList.push_back(_aod)
		 , _nList.push_back(_msd);
}

LargeUInt::LargeUInt(const std::string _x)
{
	// accumulator value for any node
	unsigned int value = 0;

	// Right to left position of the digits in the string
	unsigned int position = 0;

	// Input string length
	unsigned int nDigit = _x.length();

	// Fot all digits in the given string
	for (int sIndex = nDigit - 1; sIndex >= 0; --sIndex, position++)
	{

		// Calculate positional significance within the  node
		int power = position - (_nList.size() * N_LIMIT_LENGTH);

		// Find value for the desimal place
		value += (_x[sIndex] - 48) * pow(10, power);

		// Keep only 'N_LIMIT_LENGTH' digits in any node
		if ((power + 1) == N_LIMIT_LENGTH)
		{

			// Insert data in nodelist
			_nList.push_back(value);

			// Clear value accumulator
			value = 0;
		}
	}

	// Append remaining digits
	if (position % N_LIMIT_LENGTH)
		_nList.push_back(value);
}

LargeUInt::LargeUInt(const LargeUInt &_x)
{
	_nList = _x._nList;
}

LargeUInt::~LargeUInt()
{
	_nList.clear();
}

std::string LargeUInt::get()
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

		for (unsigned int x = N_LIMIT_LENGTH; x > value.length(); x--)
		{
			str << "0";
		}

		str << value;
	}

	return str.str();
}

LargeUInt &LargeUInt::add(const unsigned int _x, const unsigned int _iPosition)
{
	// Get positional value to add
	auto _cPosition = _nList.begin() + _iPosition;

	// Get resultant
	unsigned int _value = *_cPosition + _x;

	// Get carry
	unsigned int _carry = _value / N_LIMIT_VALUE;

	// Update node value
	*_cPosition = _value - _carry * N_LIMIT_VALUE;

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
	unsigned int _msd = _x / N_LIMIT_VALUE;

	// All other digits
	unsigned int _aod = _x - _msd * N_LIMIT_VALUE;

	// Update nodes
	_msd ? _nList.push_back(_aod) 
		 : _nList.push_back(_aod)
		 , _nList.push_back(_msd);

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
