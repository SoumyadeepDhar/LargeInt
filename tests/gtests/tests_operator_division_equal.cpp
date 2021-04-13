/*
 * tests_operator_division_equal.cpp
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
// Test operator multiply equal
namespace test_operator_division_equal
{

// Test suit name
using TestOperatorDivisionEqual = TestLargeInt;

TEST_F(TestOperatorDivisionEqual, tests_division_equal_UINT8_MAX)
{
    int _temp = 4;
    LargeInt a(UINT8_MAX);
    a /= _temp;
    EXPECT_EQ(a.getValue(), "63");
}

TEST_F(TestOperatorDivisionEqual, tests_division_equal_UINT16_MAX)
{
    int _temp = 4;
    LargeInt a(UINT16_MAX);
    a /= _temp;
    EXPECT_EQ(a.getValue(), "16383");
}

TEST_F(TestOperatorDivisionEqual, tests_division_equal_UINT32_MAX)
{
    unsigned int _temp = 4;
    LargeInt a(UINT32_MAX);
    a /= _temp;
    EXPECT_EQ(a.getValue(), "1073741823");
}

TEST_F(TestOperatorDivisionEqual, tests_division_equal_UINT64_MAX)
{
    long long unsigned int _temp = 4;
    LargeInt a(UINT64_MAX);
    a /= _temp;
    EXPECT_EQ(a.getValue(), "4611686018427387903");
}

TEST_F(TestOperatorDivisionEqual, tests_division_equal_const_char_ptr)
{
    LargeInt e1 = "12345";
    e1 /= "5";
    EXPECT_EQ(e1.getValue(), "2469");

    LargeInt e2 = "1844674407370955161518446744073709551615";
    e2 /= "10000000000000000000";
    EXPECT_EQ(e2.getValue(), "184467440737095516151");

    LargeInt e3 = "18446744073709551615.1844";
    e3 /= "100000000000";
    EXPECT_EQ(e3.getValue(), "184467440");

    LargeInt e4 = ".18446744073709551615";
    e4 /= 1000;
    EXPECT_EQ(e4.getValue(), "0");

    LargeInt e5 = "PQRST";
    e5 /= 12345;
    EXPECT_EQ(e5.getValue(), "0");

    LargeInt e6 = "PQRST12345";
    e6 /= "12345";
    EXPECT_EQ(e6.getValue(), "0");

    LargeInt e7 = "12345PQRST";
    e7 /= "12345";
    EXPECT_EQ(e7.getValue(), "1");

    LargeInt e8 = "0012345PQRST";
    e8 /= "12345";
    EXPECT_EQ(e8.getValue(), "1");
}

TEST_F(TestOperatorDivisionEqual, tests_division_equal_string)
{
    std::string str("18446744073709551615");
    LargeInt f = str;
    f /= str;
    EXPECT_EQ(f.getValue(), "1");
}

TEST_F(TestOperatorDivisionEqual, tests_division_equal_FLT_MAX)
{
    LargeInt g(FLT_MAX);
    g /= FLT_MAX;
    EXPECT_EQ(g.getValue(), "1");
}

TEST_F(TestOperatorDivisionEqual, tests_division_equal_DBL_MAX)
{
    LargeInt h(DBL_MAX);
    h /= DBL_MAX;
    EXPECT_EQ(h.getValue(), "1");
}

TEST_F(TestOperatorDivisionEqual, tests_division_equal_LDBL_MAX)
{
    LargeInt i(LDBL_MAX);
    i /= LDBL_MAX;
    EXPECT_EQ(i.getValue(), "1");
}

TEST_F(TestOperatorDivisionEqual, tests_division_equal_largeuint)
{
    LargeInt m = "36893488147419103230";
    LargeInt n = m;
    n /= m;
    EXPECT_EQ(n.getValue(), "1");
}

} // namespace test_operator_division_equal
} // namespace testing
} // namespace li
} // namespace ds
} // namespace ns