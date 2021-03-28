/*
 * largeuint.h
 *
 *  Created on: 03-Apr-2019
 *  Author: soumyadeep dhar
 */

#ifndef LARGEUINT_H_
#define LARGEUINT_H_

#include <string>
#include <vector>
#include <math.h>

// Number ststem
namespace ns
{
// Decimal Number
namespace dn
{
// Large unsigned integer
namespace lui
{

#define N_LIMIT_mVALUE 1000000000U
#define N_LIMIT_mDIGIT 9U

class LargeUInt
{
private:
  /// Split up data in nodes of N_LIMIT_mDIGIT
  std ::vector<unsigned int> _nList;

  /// Add unsigned value to specific positional node
  LargeUInt &add(const unsigned int _x, const unsigned int _iPosition = 0);

public:
  /// Constructor default
  LargeUInt();

  /// Constructor with  unsigned integer
  LargeUInt(const unsigned int _x);

  /// Constructor with unsigned integer as string
  LargeUInt(const std::string _x);

  /// Constructor with unsigned integer as large unsigned int
  LargeUInt(const LargeUInt &_x);

  /// Destructor default
  virtual ~LargeUInt();

  /// Get large unsigned integer as string for all the nodes
  std::string getNodes() const;

  /// Get large unsigned integer as string for all the nodes
  std::string getValue() const;

  /// Get number of digits
  unsigned int digits() const;

  /// This is the operator overloading function for assignment operator(=).
  LargeUInt &operator=(const unsigned int _x);

  /// This is the operator overloading function for assignment operator(=).
  LargeUInt &operator=(const LargeUInt &_x);

  /// This is the operator overloading function for assignment operator(+).
  LargeUInt &operator+=(const unsigned int _x);

  /// This is the operator overloading function for assignment operator(+).
  LargeUInt &operator+=(const LargeUInt &_x);

  /// This is the operator overloading function for assignment operator(<<).
  LargeUInt &operator<<=(const unsigned int _x);

  /// This is the operator overloading function for assignment operator(>>).
  LargeUInt &operator>>=(const unsigned int _x);

  /// This is the operator overloading function for shift operator(<<).
  LargeUInt operator<<(const unsigned int _x) const;

  /// This is the operator overloading function for shift operator(>>).
  LargeUInt operator>>(const unsigned int _x) const;

  /// This is the operator overloading function for comparator operator(<).
  bool operator<(const unsigned int _x);

  /// This is the operator overloading function for comparator operator(<=).
  bool operator<=(const unsigned int _x);

  /// This is the operator overloading function for comparator operator(>).
  bool operator>(const unsigned int _x);

  /// This is the operator overloading function for comparator operator(>=).
  bool operator>=(const unsigned int _x);

  /// This is the operator overloading function for comparator operator(==).
  bool operator==(const unsigned int _x);

  /// This is the operator overloading function for comparator operator(!=).
  bool operator!=(const unsigned int _x);

  /// This is the operator overloading function for comparator operator(<).
  bool operator<(const LargeUInt &_x);

  /// This is the operator overloading function for comparator operator(<=).
  bool operator<=(const LargeUInt &_x);

  /// This is the operator overloading function for comparator operator(>).
  bool operator>(const LargeUInt &_x);

  /// This is the operator overloading function for comparator operator(>=).
  bool operator>=(const LargeUInt &_x);

  /// This is the operator overloading function for comparator operator(==).
  bool operator==(const LargeUInt &_x);

  /// This is the operator overloading function for comparator operator(!=).
  bool operator!=(const LargeUInt &_x);
};

} // namespace lui
} // namespace ds
} // namespace ns

#endif // LARGEUINT_H_
