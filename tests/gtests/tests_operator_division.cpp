/*
 * tests_operator_division.cpp
 *
 *  Created on: 30-Mar-2021
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
// Test operator multiply
namespace test_operator_division
{

// Test suit name
using TestOperatorDivision = TestLargeInt;

TEST_F(TestOperatorDivision, tests_division_UINT8_MAX)
{
    int _temp = 4;
    LargeInt a(UINT8_MAX);
    a = a / _temp;
    EXPECT_EQ(a.getValue(), "63");
}

TEST_F(TestOperatorDivision, tests_division_UINT16_MAX)
{
    int _temp = 4;
    LargeInt a(UINT16_MAX);
    a = a / _temp;
    EXPECT_EQ(a.getValue(), "16383");
}

TEST_F(TestOperatorDivision, tests_division_UINT32_MAX)
{
    unsigned int _temp = 4;
    LargeInt a(UINT32_MAX);
    a = a / _temp;
    EXPECT_EQ(a.getValue(), "1073741823");
}

TEST_F(TestOperatorDivision, tests_division_UINT64_MAX)
{
    long long unsigned int _temp = 4;
    LargeInt a(UINT64_MAX);
    a = a / _temp;
    EXPECT_EQ(a.getValue(), "4611686018427387903");
}

TEST_F(TestOperatorDivision, tests_division_const_char_ptr)
{
    LargeInt e1 = "12345";
    e1 = e1 / "5";
    EXPECT_EQ(e1.getValue(), "2469");

    LargeInt e2 = "1844674407370955161518446744073709551615";
    e2 = e2 / "10000000000000000000";
    EXPECT_EQ(e2.getValue(), "184467440737095516151");

    LargeInt e3 = "18446744073709551615.1844";
    e3 = e3 / "100000000000";
    EXPECT_EQ(e3.getValue(), "184467440");

    LargeInt e4 = ".18446744073709551615";
    e4 = e4 / 1000;
    EXPECT_EQ(e4.getValue(), "0");

    LargeInt e5 = "PQRST";
    e5 = e5 / 12345;
    EXPECT_EQ(e5.getValue(), "0");

    LargeInt e6 = "PQRST12345";
    e6 = e6 / "12345";
    EXPECT_EQ(e6.getValue(), "0");

    LargeInt e7 = "12345PQRST";
    e7 = e7 / "12345";
    EXPECT_EQ(e7.getValue(), "1");

    LargeInt e8 = "0012345PQRST";
    e8 = e8 / "12345";
    EXPECT_EQ(e8.getValue(), "1");
}

TEST_F(TestOperatorDivision, tests_division_string)
{
    std::string str("18446744073709551615");
    LargeInt f = str;
    f = f / str;
    EXPECT_EQ(f.getValue(), "1");
}

TEST_F(TestOperatorDivision, tests_division_FLT_MAX)
{
    LargeInt g = FLT_MAX;
    g = g / FLT_MAX;
    EXPECT_EQ(g.getValue(), "1");
}

TEST_F(TestOperatorDivision, tests_division_DBL_MAX)
{
    LargeInt h = DBL_MAX;
    h = h / DBL_MAX;
    EXPECT_EQ(h.getValue(), "1");
}

TEST_F(TestOperatorDivision, tests_division_LDBL_MAX)
{
    LargeInt i = LDBL_MAX;
    i = i / LDBL_MAX;
    EXPECT_EQ(i.getValue(), "1");
}

TEST_F(TestOperatorDivision, tests_division_largeuint)
{
    LargeInt c("85070591730234615847396907784232501248");
    LargeInt d(INT64_MAX);
    c -= d;
    LargeInt e = c / d;
    EXPECT_EQ(e.getValue(), "9223372036854775805");
  
    c = "99999999999999999999999999999999999999999980000000000000000000000000000000000000000001";
    LargeInt f = c / "9999999999999999999999999999999999999999999";
    EXPECT_EQ(f.getValue(), "9999999999999999999999999999999999999999999");
}


/* Minimum of signed integral types.  */
// # define INT8_MIN		(-128)
TEST_F(TestOperatorDivision, tests_division_INT8_MIN)
{
    LargeInt a;
    LargeInt b(INT8_MIN);
    a = b / INT8_MIN;
    EXPECT_EQ(a.getValue(), "1");

    a = b / INT8_MAX;
    EXPECT_EQ(a.getValue(), "-1");
}


// # define INT16_MIN		(-32767-1)
TEST_F(TestOperatorDivision, tests_division_INT16_MIN)
{
    LargeInt a;
    LargeInt b(INT16_MIN);
    a = b / INT16_MIN;
    EXPECT_EQ(a.getValue(), "1");

    a = b / INT16_MAX;
    EXPECT_EQ(a.getValue(), "-1");
}

// # define INT32_MIN		(-2147483647-1)
TEST_F(TestOperatorDivision, tests_division_INT32_MIN)
{
    LargeInt a;
    LargeInt b(INT32_MIN);
    a = b / INT32_MIN;
    EXPECT_EQ(a.getValue(), "1");

    a = b / INT32_MAX;
    EXPECT_EQ(a.getValue(), "-1");
}

// # define INT64_MIN		(-__INT64_C(9223372036854775807)-1)
TEST_F(TestOperatorDivision, tests_division_INT64_MIN)
{
    LargeInt a;
    LargeInt b(INT64_MIN);
    a = b / INT64_MIN;
    EXPECT_EQ(a.getValue(), "1");

    a = b / INT64_MAX;
    EXPECT_EQ(a.getValue(), "-1");
}

} // namespace test_operator_multiply
} // namespace testing
} // namespace li
} // namespace ds
} // namespace ns