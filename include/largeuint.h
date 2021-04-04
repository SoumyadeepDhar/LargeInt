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

#define N_LIMIT_mVALUE 1000000000U // __UINT64_C(1000000000000000000)
#define N_LIMIT_mDIGIT 9U // 18U

class LargeUInt
{
private:
  /// Sign info for the number
  bool positive;

  /// Split up data in nodes of N_LIMIT_mDIGIT
  std ::vector<long long unsigned int> _nList;

  /// Add unsigned value to specific positional node
  void add(const long long unsigned int _x, const unsigned int _iPosition = 0);

  /// Subtract unsigned value to specific positional node
  void sub(const long long unsigned int _x, const unsigned int _iPosition = 0);

public:
  /// Constructor default
  LargeUInt();

  /// Constructor with argument
  template <typename T>
  LargeUInt(const T _x);

  /// Constructor with unsigned integer as large unsigned int
  LargeUInt(const LargeUInt &_x);

  /// Destructor default
  virtual ~LargeUInt();

  /// Get large unsigned integer as string for all the nodes
  std::string getSign() const;

  /// Get large unsigned integer as string for all the nodes
  std::string getNodes() const;

  /// Get large unsigned integer as string for all the nodes
  std::string getValue() const;

  /// Get number of digits
  unsigned int digits() const;

  /// This is the operator overloading function for assignment operator(=).
  template <typename T>
  LargeUInt &operator=(const T _x);

  /// This is the operator overloading function for assignment operator(=).
  LargeUInt &operator=(const LargeUInt &_x);

  /// This is the operator overloading function for assignment operator(+).
  template <typename T>
  LargeUInt &operator+=(const T _x);

  /// This is the operator overloading function for assignment operator(+).
  LargeUInt &operator+=(const LargeUInt &_x);

  /// This is the operator overloading function for operator(+).
  template <typename T>
  LargeUInt operator+(const T _x);

  /// This is the operator overloading function for operator(+).
  LargeUInt operator+(const LargeUInt &_x);

  /// This is the operator overloading function for assignment operator(-).
  template <typename T>
  LargeUInt &operator-=(const T _x);

  /// This is the operator overloading function for assignment operator(-).
  LargeUInt &operator-=(const LargeUInt &_x);

  /// This is the operator overloading function for operator(-).
  template <typename T>
  LargeUInt operator-(const T _x);

  /// This is the operator overloading function for operator(-).
  LargeUInt operator-(const LargeUInt &_x);

  /// This is the operator overloading function for assignment operator(*).
  template <typename T>
  LargeUInt &operator*=(const T _x);

  /// This is the operator overloading function for assignment operator(*).
  LargeUInt &operator*=(const LargeUInt &_x);

  /// This is the operator overloading function for operator(*).
  template <typename T>
  LargeUInt operator*(const T _x);

  /// This is the operator overloading function for operator(*).
  LargeUInt operator*(const LargeUInt &_x);

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
