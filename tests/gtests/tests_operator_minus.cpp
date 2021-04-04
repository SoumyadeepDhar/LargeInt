/*
 * tests_operator_minus.cpp
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
namespace lui
{
// Testing module
namespace testing
{
// Test operator minus
namespace test_operator_minus
{

// Test suit name
using TestOperatorMinus = TestLargeUint;

TEST_F(TestOperatorMinus, tests_minus_UINT8_MAX_positive)
{
    LargeUInt _temp1 = 1000;
    unsigned int _temp2 = UINT8_MAX;
    LargeUInt a = _temp1 - _temp2;
    EXPECT_EQ(a.getValue(), "745");
}

TEST_F(TestOperatorMinus, tests_minus_UINT8_MAX_negetive)
{
    LargeUInt _temp1 = UINT8_MAX;
    unsigned int _temp2 = 1000;
    LargeUInt a = _temp1 - _temp2;
    EXPECT_EQ(a.getValue(), "18446744073709550871");
}

TEST_F(TestOperatorMinus, tests_minus_UINT16_MAX_positive)
{
    LargeUInt _temp1 = 100000U;
    unsigned int _temp2 = UINT16_MAX;
    LargeUInt a = _temp1 - _temp2;
    EXPECT_EQ(a.getValue(), "34465");
}

TEST_F(TestOperatorMinus, tests_minus_UINT16_MAX_negetive)
{
    LargeUInt _temp1 = UINT16_MAX;
    unsigned int _temp2 = 100000U;
    LargeUInt a = _temp1 - _temp2;
    EXPECT_EQ(a.getValue(), "18446744073709517151");
}

TEST_F(TestOperatorMinus, tests_minus_UINT32_MAX_positive)
{
    LargeUInt _temp1 = "10000000000UL";
    unsigned int _temp2 = UINT32_MAX;
    LargeUInt a = _temp1 - _temp2;
    EXPECT_EQ(a.getValue(), "5705032705");
}

TEST_F(TestOperatorMinus, tests_minus_UINT32_MAX_negetive)
{
    LargeUInt _temp1 = UINT32_MAX;
    LargeUInt _temp2 = "10000000000UL";
    LargeUInt a = _temp1 - _temp2;
    EXPECT_EQ(a.getValue(), "18446744073709551610294967295");
}

TEST_F(TestOperatorMinus, tests_minus_UINT64_MAX_positive)
{
    LargeUInt _temp1 = "100000000000000000000UL";
    long long unsigned int _temp2 = UINT64_MAX;
    LargeUInt a = _temp1 - _temp2;
    EXPECT_EQ(a.getValue(), "81553255926290448385");
}

TEST_F(TestOperatorMinus, tests_minus_UINT64_MAX_negetive)
{
    LargeUInt _temp1 = UINT32_MAX;
    LargeUInt _temp2 = "100000000000000000000UL";
    LargeUInt a = _temp1 - _temp2;
    EXPECT_EQ(a.getValue(), "18446744073709551516000000004294967295");
}

TEST_F(TestOperatorMinus, tests_minus_const_char_ptr)
{
    LargeUInt e1 = "12345";
    e1 = e1 - "10000";

    EXPECT_EQ(e1.getValue(), "2345");

    LargeUInt e2 = "1844674407370955161518446744073709551615";
    e2 = e2 - "1000000000000000000000000000000000000000";
    EXPECT_EQ(e2.getValue(),
              "844674407370955161518446744073709551615");

    LargeUInt e3 = "18446744073709551615.1844";
    e3 = e3 - "10000000000000000000";
    EXPECT_EQ(e3.getValue(), "8446744073709551615");

    LargeUInt e4 = ".18446744073709551615";
    e4 = e4 - 1000;
    EXPECT_EQ(e4.getValue(), "18446744073709550616");

    LargeUInt e5 = "PQRST";
    e5 = e5 - 12345;
    EXPECT_EQ(e5.getValue(), "18446744073709539271");

    LargeUInt e6 = "PQRST12345";
    e6 = e6 - "12345";
    EXPECT_EQ(e6.getValue(), "18446744073709539271");

    LargeUInt e7 = "12345PQRST";
    e7 = e7 - "12345";
    EXPECT_EQ(e7.getValue(), "0");

    LargeUInt e8 = "0012345PQRST";
    e8 = e8 - "12345";
    EXPECT_EQ(e8.getValue(), "0");
}

TEST_F(TestOperatorMinus, tests_minus_string)
{
    std::string str("18446744073709551615");
    LargeUInt f = str;
    f = f - str;
    EXPECT_EQ(f.getValue(), "0");
}

TEST_F(TestOperatorMinus, tests_minus_FLT_MAX)
{
    LargeUInt g = FLT_MAX;
    g = (g + 1000) - FLT_MAX;
    EXPECT_EQ(g.getValue(), "1000");
}

TEST_F(TestOperatorMinus, tests_minus_DBL_MAX)
{
    LargeUInt h = DBL_MAX;
    h = (h + 1000) - DBL_MAX;
    EXPECT_EQ(h.getValue(), "1000");
}

TEST_F(TestOperatorMinus, tests_minus_LDBL_MAX)
{
    LargeUInt i = LDBL_MAX;
    i = (i + 1000) - LDBL_MAX;
    EXPECT_EQ(i.getValue(), "1000");
}

TEST_F(TestOperatorMinus, tests_minus_largeuint)
{
    LargeUInt m = "36893488147419103230";
    LargeUInt n = m;
    n = n - m;
    EXPECT_EQ(n.getValue(), "0");
}

} // namespace test_operator_plus
} // namespace testing
} // namespace lui
} // namespace ds
} // namespace ns