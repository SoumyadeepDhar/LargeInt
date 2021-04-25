/*
 * tests_operator_modulus.cpp
 *
 *  Created on: 25-Apr-2021
 *  Author: Soumyadeep Dhar
 */

#include "gtests/tests_largeint.h"

// Number system
namespace ns
{
// Decimal Number
namespace dn
{
// Large integer
namespace li
{
// Testing module
namespace testing
{
// Test operator modulus
namespace test_operator_modulus
{

// Test suit name
using TestOperatorModulus = TestLargeInt;

// # define UINT8_MAX		(255)
TEST_F(TestOperatorModulus, tests_modulus_UINT8_MAX)
{
    int _temp;
    LargeInt a(0U);
    _temp = 4;
    a = UINT8_MAX;
    a = a % _temp;
    EXPECT_EQ(a.getValue(), std::to_string(UINT8_MAX % _temp));

    _temp = -4;
    a = UINT8_MAX;
    a = a % _temp;
    EXPECT_EQ(a.getValue(), std::to_string(UINT8_MAX % _temp));

    _temp = 4;
    a = (UINT8_MAX * -1);
    a = a % _temp;
    EXPECT_EQ(a.getValue(), std::to_string((UINT8_MAX * -1) % _temp));

    _temp = -4;
    a = (UINT8_MAX * -1);
    a = a % _temp;
    EXPECT_EQ(a.getValue(), std::to_string((UINT8_MAX * -1) % _temp));
}

TEST_F(TestOperatorModulus, tests_modulus_UINT16_MAX)
{
    int _temp = 4;
    LargeInt a(UINT16_MAX);
    a = a % _temp;
    EXPECT_EQ(a.getValue(), "3");
}

TEST_F(TestOperatorModulus, tests_modulus_UINT32_MAX)
{
    unsigned int _temp = 4;
    LargeInt a(UINT32_MAX);
    a = a % _temp;
    EXPECT_EQ(a.getValue(), "3");
}

TEST_F(TestOperatorModulus, tests_modulus_UINT64_MAX)
{
    long long unsigned int _temp = 4;
    LargeInt a(UINT64_MAX);
    a = a % _temp;
    EXPECT_EQ(a.getValue(), "3");
}

TEST_F(TestOperatorModulus, tests_modulus_const_char_ptr)
{
    LargeInt e1 = "12345";
    e1 = e1 % "5";
    EXPECT_EQ(e1.getValue(), "0");

    LargeInt e2 = "1844674407370955161518446744073709551615";
    e2 = e2 % "10000000000000000000";
    EXPECT_EQ(e2.getValue(), "8446744073709551615");

    LargeInt e3 = "18446744073709551615.1844";
    e3 = e3 % "100000000000";
    EXPECT_EQ(e3.getValue(), "73709551615");

    LargeInt e4 = ".18446744073709551615";
    e4 = e4 % 1000;
    EXPECT_EQ(e4.getValue(), "0");

    LargeInt e5 = "PQRST";
    e5 = e5 % 12345;
    EXPECT_EQ(e5.getValue(), "0");

    LargeInt e6 = "PQRST12345";
    e6 = e6 % "12345";
    EXPECT_EQ(e6.getValue(), "0");

    LargeInt e7 = "12345PQRST";
    e7 = e7 % "12345";
    EXPECT_EQ(e7.getValue(), "0");

    LargeInt e8 = "0012345PQRST";
    e8 = e8 % "12345";
    EXPECT_EQ(e8.getValue(), "0");
}

TEST_F(TestOperatorModulus, tests_modulus_string)
{
    std::string str("18446744073709551615");
    LargeInt f = str;
    f = f % str;
    EXPECT_EQ(f.getValue(), "0");
}

TEST_F(TestOperatorModulus, tests_modulus_FLT_MAX)
{
    LargeInt g = FLT_MAX;
    g = g % FLT_MAX;
    EXPECT_EQ(g.getValue(), "0");
}

TEST_F(TestOperatorModulus, tests_modulus_DBL_MAX)
{
    LargeInt h = DBL_MAX;
    h = h % DBL_MAX;
    EXPECT_EQ(h.getValue(), "0");
}

TEST_F(TestOperatorModulus, tests_modulus_LDBL_MAX)
{
    LargeInt i = LDBL_MAX;
    i = i % LDBL_MAX;
    EXPECT_EQ(i.getValue(), "0");
}

TEST_F(TestOperatorModulus, tests_modulus_largeuint)
{
    LargeInt c("85070591730234615847396907784232501248");
    LargeInt d(INT64_MAX);
    c -= d;
    LargeInt e = c % d;
    EXPECT_EQ(e.getValue(), "9223372036854775806");
  
    c = "99999999999999999999999999999999999999999980000000000000000000000000000000000000000001";
    LargeInt f = c % "9999999999999999999999999999999999999999999";
    EXPECT_EQ(f.getValue(), "0");
}

} // namespace test_operator_modulus
} // namespace testing
} // namespace li
} // namespace ds
} // namespace ns