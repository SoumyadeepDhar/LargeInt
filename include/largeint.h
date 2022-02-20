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

// Number system
namespace ns
{
// Decimal Number
namespace dn
{
// Large integer
namespace li
{
// Class LargeInt
class LargeInt
{
  // Declaration of public member and methods
public:
  /// Constructor default
  LargeInt();

  /// Constructor with argument
  template <typename T>
  LargeInt(const T _x);

  /// Constructor with large int value.
  LargeInt(const LargeInt &_x);

  /// Destructor default
  virtual ~LargeInt();

  /// Get sign of the large integer as symbol (-) if negative
  std::string getSign() const;

  /// Get large integer as string with all the nodes information
  std::string getNodes() const;

  /// Get large integer as string without all the nodes information
  std::string getValue() const;

  /// Get number of digits
  unsigned int digits() const;

  /// Get sqrt of the number
  LargeInt sqrt();

  /// Get nth power of the number
  LargeInt pow(const unsigned int _x);

  /// Get nth root of the number
  LargeInt root(const unsigned int _x);

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

  /// This is the operator overloading function for operator(/).
  template <typename T>
  LargeInt operator/(const T _x);

  /// This is the operator overloading function for operator(/).
  LargeInt operator/(const LargeInt &_x);

  /// This is the operator overloading function for assignment operator(%).
  template <typename T>
  LargeInt &operator%=(const T _x);

  /// This is the operator overloading function for assignment operator(%).
  LargeInt &operator%=(const LargeInt &_x);

  /// This is the operator overloading function for operator(%).
  template <typename T>
  LargeInt operator%(const T _x);

  /// This is the operator overloading function for operator(%).
  LargeInt operator%(const LargeInt &_x);

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

  /// This is the operator overloading function for shift operator(<<).
  LargeInt operator<<(const unsigned int _x) const;

  /// This is the operator overloading function for assignment operator(>>).
  LargeInt &operator>>=(const unsigned int _x);

  /// This is the operator overloading function for shift operator(>>).
  LargeInt operator>>(const unsigned int _x) const;

  /// This is the operator overloading function for assignment operator(++) prefix.
  LargeInt operator++();

  /// This is the operator overloading function for assignment operator(++) postfix.
  LargeInt operator++(int);

  /// This is the operator overloading function for assignment operator(--) prefix.
  LargeInt operator--();

  /// This is the operator overloading function for assignment operator(--) postfix.
  LargeInt operator--(int);

#ifdef PARI
  // Initialize PARI library
  static void InitializePARI();

  // Close PARI library
  static void ClosePARI();

  // Clear PARI stack
  static void ClearStackPARI();

  // Get pari-gp direct support using PARI command
  static std::string EvaluatePARI(const std::string _command);

  // Check given number is prime or not
  static bool IsPrime(const std::string _number);

  // Check given number is prime or not
  static bool IsPrime(const unsigned long long int _number);

  // Get facors of given unsigned integer number
  static std::vector<unsigned long long int> Factor(const unsigned long long int _x);

  // Get facors of given large integer number presented as string
  static std::vector<LargeInt> Factor(const std::string _number);

  // Get facors of given Large integer number
  std::vector<LargeInt> Factor();
#endif

  // Declaration of private member and methods
private:
  /// Sign info for the number
  bool positive;

  /// Split up data in nodes of N_LIMIT_mDIGIT
  std ::vector<long long unsigned int> _nList;

  /// Add unsigned value to specific positional node
  void add(const long long unsigned int _x, const unsigned int _iPosition = 0);

  /// Subtract unsigned value to specific positional node
  void sub(const long long unsigned int _x, const unsigned int _iPosition = 0);

  /// Assign filtered string value
  void assignment(const std::string &_x);

// If pari support is defind
#ifdef PARI
  // Marker to Identify pari is already initialized
  static bool _pariInitialized;

  // Large integer base value
  static long int *_gN_LIMIT_mVALUE;

  // Initial stack position of top
  static unsigned long int _isptop;

  /// Convert  GEN(long *) value to Large int
  static LargeInt convert(long int *_g);

  /// Convert  Large int to GEN(long *)
  static long int *convert(const LargeInt &_x);
#endif
};

} // namespace li
} // namespace dn
} // namespace ns

#endif // LARGEINT_H_