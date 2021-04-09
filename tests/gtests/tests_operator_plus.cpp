/*
 * tests_operator_plus.cpp
 *
 *  Created on: 30-Mar-2021
 *  Author: Soumyadeep Dhar
 */

#include "gtests/tests_largeuint.h"

// Number ststem
namespace ns
{
// Decimal Number
namespace dn
{
// Large unsigned integer
namespace li
{
// Testing module
namespace testing
{
// Test operator plus
namespace test_operator_plus
{

// Test suit name
using TestOperatorPlus = TestLargeUint;

TEST_F(TestOperatorPlus, tests_plus_UINT8_MAX)
{
    LargeInt _temp1 = 1000;
    int _temp2 = UINT8_MAX;
    LargeInt a = _temp1 + _temp2;
    EXPECT_EQ(a.getValue(), "1255");
}

TEST_F(TestOperatorPlus, tests_plus_UINT16_MAX)
{
    LargeInt _temp1 = 100000;
    int _temp2 = UINT16_MAX;
    LargeInt a = _temp1 + _temp2;
    EXPECT_EQ(a.getValue(), "165535");
}

TEST_F(TestOperatorPlus, tests_plus_UINT32_MAX)
{
    LargeInt _temp1 = "10000000000";
    unsigned int _temp2 = UINT32_MAX;
    LargeInt a = _temp1 + _temp2;
    EXPECT_EQ(a.getValue(), "14294967295");
}

TEST_F(TestOperatorPlus, tests_plus_UINT64_MAX)
{
    LargeInt _temp1 = "100000000000000000000";
    long long unsigned int _temp2 = UINT64_MAX;
    LargeInt a = _temp1 + _temp2;
    EXPECT_EQ(a.getValue(), "118446744073709551615");
}

TEST_F(TestOperatorPlus, tests_plus_const_char_ptr)
{
    LargeInt e1 = "12345";
    e1 = e1 + "100000";

    EXPECT_EQ(e1.getValue(), "112345");

    LargeInt e2 = "1844674407370955161518446744073709551615";
    e2 = e2 + "10000000000000000000000000000000000000000";
    EXPECT_EQ(e2.getValue(), "11844674407370955161518446744073709551615");

    LargeInt e3 = "18446744073709551615.1844";
    e3 = e3 + "100000000000000000000";
    EXPECT_EQ(e3.getValue(), "118446744073709551615");

    LargeInt e4 = ".18446744073709551615";
    e4 = e4 + 1000;
    EXPECT_EQ(e4.getValue(), "1000");

    LargeInt e5 = "PQRST";
    e5 = e5 + 12345;
    EXPECT_EQ(e5.getValue(), "12345");

    LargeInt e6 = "PQRST12345";
    e6 = e6 + "12345";
    EXPECT_EQ(e6.getValue(), "12345");

    LargeInt e7 = "12345PQRST";
    e7 = e7 + "12345";
    EXPECT_EQ(e7.getValue(), "24690");

    LargeInt e8 = "0012345PQRST";
    e8 = e8 + "12345";
    EXPECT_EQ(e8.getValue(), "24690");
}

TEST_F(TestOperatorPlus, tests_plus_string)
{
    std::string str("18446744073709551615");
    LargeInt f = str;
    f = f + str;
    EXPECT_EQ(f.getValue(), "36893488147419103230");
}

TEST_F(TestOperatorPlus, tests_plus_FLT_MAX)
{
    LargeInt g = FLT_MAX;
    g = g + FLT_MAX;
    EXPECT_EQ(g.getValue(), "680564693277057719623408366969033850880");
}

TEST_F(TestOperatorPlus, tests_plus_DBL_MAX)
{
    LargeInt h = DBL_MAX;
    h = h + DBL_MAX;
    LargeInt r = DBL_MAX;
    r *= 2;
    EXPECT_EQ(h.getValue(), r.getValue());
 }

TEST_F(TestOperatorPlus, tests_plus_LDBL_MAX)
{
    LargeInt i = LDBL_MAX;
    i = i + LDBL_MAX;
    LargeInt r = LDBL_MAX;
    r *= 2;
    EXPECT_EQ(i.getValue(), r.getValue());
}

TEST_F(TestOperatorPlus, tests_plus_largeuint)
{
    LargeInt m = "36893488147419103230";
    LargeInt n = m;
    n = n + m;
    EXPECT_EQ(n.getValue(), "73786976294838206460");
}

} // namespace test_operator_plus
} // namespace testing
} // namespace li
} // namespace ds
} // namespace ns