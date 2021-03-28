/*
 * main.cpp
 *
 *  Created on: 03-Apr-2019
 *  Modified on: 09-Mar-2021
 *  Author: Soumyadeep Dhar
 */

#include <bits/stdc++.h>
#include "largeuint.h"
int main()
{
  ns::dn::lui::LargeUInt a("12345923456789");
  std::cout << "a: " << a.get() << std::endl;

  ns::dn::lui::LargeUInt b("999999999923456789");
  std::cout << "b: " << b.get() << std::endl;

  a += b;
  std::cout << "(a += b):a = " << a.get() << std::endl;

  b += a;
  std::cout << "(b += a):b = " << b.get() << std::endl;

  std::cout << "(a < b) = " << (a < b) << std::endl;
  std::cout << "(a <= b) = " << (a <= b) << std::endl;
  std::cout << "(a > b) = " << (a > b) << std::endl;
  std::cout << "(a >= b) = " << (a >= b) << std::endl;
  std::cout << "(a == b) = " << (a == b) << std::endl;
  std::cout << "(a != b) = " << (a != b) << std::endl;

  std::cout << "(a < 123) = " << (a < 123) << std::endl;
  std::cout << "(a <= 123) = " << (a <= 123) << std::endl;
  std::cout << "(a > 123) = " << (a > 123) << std::endl;
  std::cout << "(a >= 123) = " << (a >= 123) << std::endl;
  std::cout << "(a == 123) = " << (a == 123) << std::endl;
  std::cout << "(a != 123) = " << (a != 123) << std::endl;

  a = b;
  std::cout << "(a = b):a = " << a.get() << std::endl;
  b = a;
  std::cout << "(b = a):b = " << b.get() << std::endl;

  std::cout << "(a == b) = " << (a == b) << std::endl;
  std::cout << "(a != b) = " << (a != b) << std::endl;

  b <<= 12U;
  std::cout << "(b <<=  12U):b = " << b.get() << std::endl;
  a >>= 12U;
  std::cout << "(a >>=  12U):a = " << a.get() << std::endl;

  return 0;
}
