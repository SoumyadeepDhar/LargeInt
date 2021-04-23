/*
 * largeint.h
 *
 *  Created on: 03-Apr-2019
 *  Author: soumyadeep dhar
 */

#ifndef LARGEINT_H_
#define LARGEINT_H_

#include <string>
#include <vector>
#include <math.h>

// Number system
namespace ns
{
// Decimal Number
namespace dn
{
// Large integer
namespace li
{
class LargeInt
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
  LargeInt();

  /// Constructor with argument
  template <typename T>
  LargeInt(const T _x);

  /// Constructor with unsigned integer as large unsigned int
  LargeInt(const LargeInt &_x);

  /// Destructor default
  virtual ~LargeInt();

  /// Get sign of the large integer as symbol (-)if negetive
  std::string getSign() const;

  /// Get large unsigned integer as string for all the nodes
  std::string getNodes() const;

  /// Get large unsigned integer as string for all the nodes
  std::string getValue() const;

  /// Get number of digits
  unsigned int digits() const;

  /// This is the operator overloading function for assignment operator(=).
  template <typename T>
  LargeInt &operator=(const T _x);

  /// This is the operator overloading function for assignment operator(=).
  LargeInt &operator=(const LargeInt &_x);

  /// This is the operator overloading function for assignment operator(+).
  template <typename T>
  LargeInt &operator+=(const T _x);

  /// This is the operator overloading function for assignment operator(+).
  LargeInt &operator+=(const LargeInt &_x);

  /// This is the operator overloading function for operator(+).
  template <typename T>
  LargeInt operator+(const T _x);

  /// This is the operator overloading function for operator(+).
  LargeInt operator+(const LargeInt &_x);

  /// This is the operator overloading function for assignment operator(-).
  template <typename T>
  LargeInt &operator-=(const T _x);

  /// This is the operator overloading function for assignment operator(-).
  LargeInt &operator-=(const LargeInt &_x);

  /// This is the operator overloading function for operator(-).
  template <typename T>
  LargeInt operator-(const T _x);

  /// This is the operator overloading function for operator(-).
  LargeInt operator-(const LargeInt &_x);

  /// This is the operator overloading function for assignment operator(*).
  template <typename T>
  LargeInt &operator*=(const T _x);

  /// This is the operator overloading function for assignment operator(*).
  LargeInt &operator*=(const LargeInt &_x);

  /// This is the operator overloading function for operator(*).
  template <typename T>
  LargeInt operator*(const T _x);

  /// This is the operator overloading function for operator(*).
  LargeInt operator*(const LargeInt &_x);

  /// This is the operator overloading function for assignment operator(/).
  template <typename T>
  LargeInt &operator/=(const T _x);

  /// This is the operator overloading function for assignment operator(/).
  LargeInt &operator/=(const LargeInt &_x);

  /// This is the operator overloading function for operator().
  template <typename T>
  LargeInt operator/(const T _x);

  /// This is the operator overloading function for operator(/).
  LargeInt operator/(const LargeInt &_x);

  /// This is the operator overloading function for comparator operator(<).
  template <typename T>
  bool operator<(const T _x);

  /// This is the operator overloading function for comparator operator(<).
  bool operator<(const LargeInt &_x);

  /// This is the operator overloading function for comparator operator(<=).
  template <typename T>
  bool operator<=(const T _x);

  /// This is the operator overloading function for comparator operator(<=).
  bool operator<=(const LargeInt &_x);

  /// This is the operator overloading function for comparator operator(>).
  template <typename T>
  bool operator>(const T _x);

  /// This is the operator overloading function for comparator operator(>).
  bool operator>(const LargeInt &_x);

  /// This is the operator overloading function for comparator operator(>=).
  template <typename T>
  bool operator>=(const T _x);

  /// This is the operator overloading function for comparator operator(>=).
  bool operator>=(const LargeInt &_x);

  /// This is the operator overloading function for comparator operator(==).
  template <typename T>
  bool operator==(const T _x);

  /// This is the operator overloading function for comparator operator(==).
  bool operator==(const LargeInt &_x);

  /// This is the operator overloading function for comparator operator(!=).
  template <typename T>
  bool operator!=(const T _x);

  /// This is the operator overloading function for comparator operator(!=).
  bool operator!=(const LargeInt &_x);

  /// This is the operator overloading function for assignment operator(<<).
  LargeInt &operator<<=(const unsigned int _x);

  /// This is the operator overloading function for assignment operator(>>).
  LargeInt &operator>>=(const unsigned int _x);

  /// This is the operator overloading function for shift operator(<<).
  LargeInt operator<<(const unsigned int _x) const;

  /// This is the operator overloading function for shift operator(>>).
  LargeInt operator>>(const unsigned int _x) const;

  /// This is the operator overloading function for assignment operator(++) prefix.
  LargeInt operator++();

  /// This is the operator overloading function for assignment operator(--) prefix.
  LargeInt operator--();

  /// This is the operator overloading function for assignment operator(++) postfix.
  LargeInt operator++(int);

  /// This is the operator overloading function for assignment operator(--) postfix.
  LargeInt operator--(int);
};

} // namespace li
} // namespace ds
} // namespace ns

#endif // LARGEINT_H_