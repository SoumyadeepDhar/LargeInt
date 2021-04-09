/*
 * tests_operator_multiply.cpp
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
// Test operator plus equal
namespace test_operator_plus_equal
{

// Test suit name
using TestOperatorMultiply = TestLargeUint;

TEST_F(TestOperatorMultiply, tests_multiply_UINT8_MAX)
{
    int _temp = UINT8_MAX;
    LargeInt a = 4;
    a = a * _temp;
    EXPECT_EQ(a.getValue(), "1020");
}

TEST_F(TestOperatorMultiply, tests_multiply_UINT16_MAX)
{
    int _temp = UINT16_MAX;
    LargeInt a = 4;
    a = a * _temp;
    EXPECT_EQ(a.getValue(), "262140");
}

TEST_F(TestOperatorMultiply, tests_multiply_UINT32_MAX)
{
    unsigned int _temp = UINT32_MAX;
    LargeInt a = "4";
    a = a * _temp;
    EXPECT_EQ(a.getValue(), "17179869180");
}

TEST_F(TestOperatorMultiply, tests_multiply_UINT64_MAX)
{
    long long unsigned int _temp = UINT64_MAX;
    LargeInt a = "100000000000000000070";
    a = a * _temp;
    EXPECT_EQ(a.getValue(), "1844674407370955162791272085159668613050");
}

TEST_F(TestOperatorMultiply, tests_multiply_const_char_ptr)
{
    LargeInt e1 = "12345";
    e1 = e1 * "100007";

    EXPECT_EQ(e1.getValue(), "1234586415");

    LargeInt e2 = "1844674407370955161518446744073709551615";
    e2 = e2 * "10000000000000000000000000000000000000000";
    EXPECT_EQ(e2.getValue(),
              "18446744073709551615184467440737095516150000000000000000000000000000000000000000");

    LargeInt e3 = "18446744073709551615.1844";
    e3 = e3 * "100000000000000000000";
    EXPECT_EQ(e3.getValue(),
              "1844674407370955161500000000000000000000");

    LargeInt e4 = ".18446744073709551615";
    e4 = e4 * 1000;
    EXPECT_EQ(e4.getValue(), "0");

    LargeInt e5 = "PQRST";
    e5 = e5 * 12345;
    EXPECT_EQ(e5.getValue(), "0");

    LargeInt e6 = "PQRST12345";
    e6 = e6 * "12345";
    EXPECT_EQ(e6.getValue(), "0");

    LargeInt e7 = "12345PQRST";
    e7 = e7 * "12345";
    EXPECT_EQ(e7.getValue(), "152399025");

    LargeInt e8 = "0012345PQRST";
    e8 = e8 * "12345";
    EXPECT_EQ(e8.getValue(), "152399025");
}

TEST_F(TestOperatorMultiply, tests_multiply_string)
{
    std::string str("18446744073709551615");
    LargeInt f = str;
    f = f * str;
    EXPECT_EQ(f.getValue(),
              "340282366920938463426481119284349108225");
}

TEST_F(TestOperatorMultiply, tests_multiply_FLT_MAX)
{
    LargeInt g = FLT_MAX;
    g = g * FLT_MAX;
    EXPECT_EQ(g.getValue(),
              "115792075433823913218582740440686722041514719101048865382650882077830519193600");
}

TEST_F(TestOperatorMultiply, tests_multiply_DBL_MAX)
{
    LargeInt h = DBL_MAX;
    h = h * DBL_MAX;
    EXPECT_EQ("617", std::to_string(h.digits()));
}

TEST_F(TestOperatorMultiply, tests_multiply_LDBL_MAX)
{
    LargeInt i = LDBL_MAX;
    i = i * LDBL_MAX;
    EXPECT_EQ("9865", std::to_string(i.digits()));
}

TEST_F(TestOperatorMultiply, tests_multiply_largeuint)
{
    LargeInt m = "36893488147419103230";
    LargeInt n = m;
    n = n * m;
    EXPECT_EQ(n.getValue(), "1361129467683753853705924477137396432900");
}

} // namespace test_operator_plus_equal
} // namespace testing
} // namespace li
} // namespace ds
} // namespace ns