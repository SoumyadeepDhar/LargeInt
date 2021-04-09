/*
 * tests_operator_compare_less.cpp
 *
 *  Created on: 03-Apr-2019
 *  Modified on: 09-Apr-2021
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
// Test assignment
namespace test_operator_compare_less
{
// Test suit name
using TestCompareLess = TestLargeUint;

TEST_F(TestCompareLess, tests_compare_UINT8_MAX)
{
    LargeInt a(UINT8_MAX);
    EXPECT_TRUE (a < UINT16_MAX);
    EXPECT_FALSE(a < UINT8_MAX);
    EXPECT_FALSE(a < 0);
    EXPECT_FALSE(a < (-1 * UINT8_MAX));
}

TEST_F(TestCompareLess, tests_compare_UINT16_MAX)
{
    LargeInt b(UINT16_MAX);
    EXPECT_TRUE (b < UINT32_MAX);
    EXPECT_FALSE(b < UINT16_MAX);
    EXPECT_FALSE(b < 0);
    EXPECT_FALSE(b < (-1 * UINT16_MAX));
}

TEST_F(TestCompareLess, tests_compare_UINT32_MAX)
{
    LargeInt c(UINT32_MAX);
    EXPECT_TRUE (c < UINT64_MAX);
    EXPECT_FALSE(c < UINT32_MAX);
    EXPECT_FALSE(c < 0);
    EXPECT_FALSE(c < (-1 * UINT32_MAX));
}


TEST_F(TestCompareLess, tests_compare_UINT64_MAX)
{
    LargeInt d(UINT64_MAX);
    LargeInt e(UINT64_MAX);
    e <<= 10;
    EXPECT_TRUE (d < e);
    EXPECT_FALSE(d < UINT32_MAX);
    EXPECT_FALSE(d < 0);
    EXPECT_FALSE(d < -12345);
}

TEST_F(TestCompareLess, tests_compare_const_char_ptr)
{
    LargeInt e1("12345");
    EXPECT_TRUE(e1 < "123456");

    LargeInt e2("1844674407370955161518446744073709551615");
    EXPECT_TRUE(e1 < "1844674407370955161518446744073709551616");

    LargeInt e3("18446744073709551615.1844");
    EXPECT_TRUE(e3 < "18446744073709551616");

    LargeInt e4(".18446744073709551615");
    EXPECT_TRUE(e4 < "1");

    LargeInt e5("PQRST");
    EXPECT_TRUE(e5 < "1");

    LargeInt e6("PQRST12345");
    EXPECT_TRUE(e6 < "1");

    LargeInt e7("12345PQRST");
    EXPECT_TRUE(e7 < "12346");

    LargeInt e8("0012345PQRST");
    EXPECT_TRUE(e8 < "12346");
}

TEST_F(TestCompareLess, tests_compare_string)
{
    std::string str("18446744073709551615");
    LargeInt f(str);
    EXPECT_TRUE(f < "18446744073709551616");
    EXPECT_FALSE(f < str);
}

TEST_F(TestCompareLess, tests_compare_FLT_MAX)
{
    LargeInt g(FLT_MAX);
    EXPECT_TRUE(g < DBL_MAX);
    EXPECT_FALSE(g < FLT_MAX);
}

TEST_F(TestCompareLess, tests_compare_DBL_MAX)
{  
    LargeInt h(DBL_MAX);
    EXPECT_TRUE(h < LDBL_MAX);
    EXPECT_FALSE(h < DBL_MAX);
 }

TEST_F(TestCompareLess, tests_compare_LDBL_MAX)
{   
    LargeInt i(LDBL_MAX);
    LargeInt j(DBL_MAX);
    EXPECT_TRUE(j < i);
    EXPECT_FALSE(i < LDBL_MAX);

}

} // namespace test_operator_compare_less
} // namespace testing
} // namespace lui
} // namespace ds
} // namespace ns