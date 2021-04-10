/*
 * tests_operator_plus_equal.cpp
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
// Test operator plus equal
namespace test_operator_plus_equal
{

// Test suit name
using TestOperatorPlusEqual = TestLargeInt;

TEST_F(TestOperatorPlusEqual, tests_plus_equal_UINT8_MAX)
{
    int _temp = UINT8_MAX;
    LargeInt a = 1000;
    a += _temp;
    EXPECT_EQ(a.getValue(), "1255");
}

TEST_F(TestOperatorPlusEqual, tests_plus_equal_UINT16_MAX)
{
    int _temp = UINT16_MAX;
    LargeInt a = 100000;
    a += _temp;
    EXPECT_EQ(a.getValue(), "165535");
}

TEST_F(TestOperatorPlusEqual, tests_plus_equal_UINT32_MAX)
{
    unsigned int _temp = UINT32_MAX;
    LargeInt a = "10000000000";
    a += _temp;
    EXPECT_EQ(a.getValue(), "14294967295");
}

TEST_F(TestOperatorPlusEqual, tests_plus_equal_UINT64_MAX)
{
    long long unsigned int _temp = UINT64_MAX;
    LargeInt a = "100000000000000000000";
    a += _temp;
    EXPECT_EQ(a.getValue(), "118446744073709551615");
}

TEST_F(TestOperatorPlusEqual, tests_plus_equal_const_char_ptr)
{
    LargeInt e1 = "12345";
    e1 += "100000";

    EXPECT_EQ(e1.getValue(), "112345");

    LargeInt e2 = "1844674407370955161518446744073709551615";
    e2 += "10000000000000000000000000000000000000000";
    EXPECT_EQ(e2.getValue(), "11844674407370955161518446744073709551615");

    LargeInt e3 = "18446744073709551615.1844";
    e3 += "100000000000000000000";
    EXPECT_EQ(e3.getValue(), "118446744073709551615");

    LargeInt e4 = ".18446744073709551615";
    e4 += 1000;
    EXPECT_EQ(e4.getValue(), "1000");

    LargeInt e5 = "PQRST";
    e5 += 12345;
    EXPECT_EQ(e5.getValue(), "12345");

    LargeInt e6 = "PQRST12345";
    e6 += "12345";
    EXPECT_EQ(e6.getValue(), "12345");

    LargeInt e7 = "12345PQRST";
    e7 += "12345";
    EXPECT_EQ(e7.getValue(), "24690");

    LargeInt e8 = "0012345PQRST";
    e8 += "12345";
    EXPECT_EQ(e8.getValue(), "24690");
}

TEST_F(TestOperatorPlusEqual, tests_plus_equal_string)
{
    std::string str("18446744073709551615");
    LargeInt f = str;
    f += str;
    EXPECT_EQ(f.getValue(), "36893488147419103230");
}

TEST_F(TestOperatorPlusEqual, tests_plus_equal_FLT_MAX)
{
    LargeInt g = FLT_MAX;
    g += FLT_MAX;
    EXPECT_EQ(g.getValue(), "680564693277057719623408366969033850880");
}

TEST_F(TestOperatorPlusEqual, tests_plus_equal_DBL_MAX)
{
    LargeInt h = DBL_MAX;
    h += DBL_MAX;
    LargeInt r = DBL_MAX;
    r *= 2;
    EXPECT_EQ(h.getValue(), r.getValue());
 }

TEST_F(TestOperatorPlusEqual, tests_plus_equal_LDBL_MAX)
{
    LargeInt i = LDBL_MAX;
    i += LDBL_MAX;
    LargeInt r = LDBL_MAX;
    r *= 2;
    EXPECT_EQ(i.getValue(), r.getValue());
}

TEST_F(TestOperatorPlusEqual, tests_plus_equal_largeuint)
{
    LargeInt m = "36893488147419103230";
    LargeInt n = m;
    n += m;
    EXPECT_EQ(n.getValue(), "73786976294838206460");
}

} // namespace test_operator_plus_equal
} // namespace testing
} // namespace li
} // namespace ds
} // namespace ns