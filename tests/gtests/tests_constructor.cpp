#include "gtest/gtest.h"
#include <bits/stdc++.h>
#include "largeuint.h"

TEST(CheckTest, test1) {
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

    EXPECT_EQ(a.get(), b.get());
}