/*
 * tests_operator_compare_lesser_equal.cpp
 *
 *  Created on: 03-Apr-2019
 *  Modified on: 09-Apr-2021
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
// Test assignment
namespace test_operator_compare_lesser_equal
{
// Test suit name
using TestCompareLesserEqual = TestLargeInt;

/* Minimum of signed integral types.  */
// # define INT8_MIN		(-128)
TEST_F(TestCompareLesserEqual, tests_compare_INT8_MIN)
{
    LargeInt a(INT8_MIN);
    EXPECT_TRUE(a <= INT8_MIN);
    EXPECT_TRUE(a <= INT8_MAX);
    EXPECT_FALSE(a <= INT16_MIN);
}

// # define INT16_MIN		(-32767-1)
TEST_F(TestCompareLesserEqual, tests_compare_INT16_MIN)
{
    LargeInt a(INT16_MIN);
    EXPECT_TRUE(a <= INT16_MIN);
    EXPECT_TRUE(a <= INT16_MAX);
    EXPECT_FALSE(a <= INT32_MIN);
}

// # define INT32_MIN		(-2147483647-1)
TEST_F(TestCompareLesserEqual, tests_compare_INT32_MIN)
{
    LargeInt a(INT32_MIN);
    EXPECT_TRUE(a <= INT32_MIN);
    EXPECT_TRUE(a <= INT32_MAX);
    EXPECT_FALSE(a <= INT64_MIN);
}

// # define INT64_MIN		(-__INT64_C(9223372036854775807)-1)
TEST_F(TestCompareLesserEqual, tests_compare_INT64_MIN)
{
    LargeInt a(INT64_MIN);
    EXPECT_TRUE(a <= INT64_MIN);
    EXPECT_TRUE(a <= INT64_MAX);
    EXPECT_FALSE(a <= "-9223372036854775809");
}

// Maximum of signed integral types.  //
// # define INT8_MAX		(127)
TEST_F(TestCompareLesserEqual, tests_compare_INT8_MAX)
{
    LargeInt a(INT8_MAX);
    EXPECT_TRUE(a <= INT16_MAX);
    EXPECT_TRUE(a <= INT8_MAX);
    EXPECT_FALSE(a < INT8_MIN);
}

// # define INT16_MAX		(32767)
TEST_F(TestCompareLesserEqual, tests_compare_INT16_MAX)
{
    LargeInt a(INT16_MAX);
    EXPECT_TRUE(a <= INT32_MAX);
    EXPECT_TRUE(a <= INT16_MAX);
    EXPECT_FALSE(a <= INT16_MIN);
}

// # define INT32_MAX		(2147483647)
TEST_F(TestCompareLesserEqual, tests_compare_INT32_MAX)
{
    LargeInt a(INT32_MAX);
    EXPECT_TRUE(a <= INT64_MAX);
    EXPECT_TRUE(a <= INT32_MAX);
    EXPECT_FALSE(a <= INT32_MIN);
}

// # define INT64_MAX		(__INT64_C(9223372036854775807))
TEST_F(TestCompareLesserEqual, tests_compare_INT64_MAX)
{
    LargeInt a(INT64_MAX);
    EXPECT_TRUE(a <= UINT64_MAX);
    EXPECT_TRUE(a <= INT64_MAX);
    EXPECT_FALSE(a <= INT64_MIN);
}

// # define UINT8_MAX		(255)
TEST_F(TestCompareLesserEqual, tests_compare_UINT8_MAX)
{
    LargeInt a(UINT8_MAX);
    EXPECT_TRUE(a <= UINT16_MAX);
    EXPECT_TRUE(a <= UINT8_MAX);
    EXPECT_FALSE(a <= INT8_MIN);
}

// # define UINT16_MAX		(65535)
TEST_F(TestCompareLesserEqual, tests_compare_UINT16_MAX)
{
    LargeInt a(UINT16_MAX);
    EXPECT_TRUE(a <= UINT32_MAX);
    EXPECT_TRUE(a <= UINT16_MAX);
    EXPECT_FALSE(a <= INT16_MIN);
}

// # define UINT32_MAX		(4294967295U)
TEST_F(TestCompareLesserEqual, tests_compare_UINT32_MAX)
{
    LargeInt a(UINT32_MAX);
    EXPECT_TRUE(a <= UINT64_MAX);
    EXPECT_TRUE(a <= UINT32_MAX);
    EXPECT_FALSE(a <= INT32_MIN);
}

// # define UINT64_MAX		(__UINT64_C(18446744073709551615))
TEST_F(TestCompareLesserEqual, tests_compare_UINT64_MAX)
{
    LargeInt a(UINT64_MAX);
    EXPECT_TRUE(a <= "18446744073709551616");
    EXPECT_TRUE(a <= UINT64_MAX);
    EXPECT_FALSE(a <= INT64_MIN);
}

TEST_F(TestCompareLesserEqual, tests_compare_const_char_ptr)
{
    LargeInt e1("12345");
    EXPECT_TRUE(e1 <= "123456");

    LargeInt e2("1844674407370955161518446744073709551615");
    EXPECT_TRUE(e2 <= "1844674407370955161518446744073709551615");

    LargeInt e3("18446744073709551615.1844");
    EXPECT_TRUE(e3 <= "18446744073709551616");

    LargeInt e4(".18446744073709551615");
    EXPECT_TRUE(e4 <= "1");

    LargeInt e5("PQRST");
    EXPECT_TRUE(e5 <= "1");

    LargeInt e6("PQRST12345");
    EXPECT_TRUE(e6 <= "1");

    LargeInt e7("12345PQRST");
    EXPECT_TRUE(e7 <= "12346");

    LargeInt e8("0012345PQRST");
    EXPECT_TRUE(e8 <= "12346");
}

TEST_F(TestCompareLesserEqual, tests_compare_string)
{
    std::string str("18446744073709551615");
    LargeInt f(str);
    EXPECT_TRUE(f <= str);
    EXPECT_TRUE(f <= "18446744073709551616");
    EXPECT_FALSE(f <= "18446744073709551614");
}

TEST_F(TestCompareLesserEqual, tests_compare_FLT_MAX)
{
    LargeInt g(FLT_MAX);
    EXPECT_TRUE(g <= DBL_MAX);
    EXPECT_TRUE(g <= FLT_MAX);
}

TEST_F(TestCompareLesserEqual, tests_compare_DBL_MAX)
{
    LargeInt h(DBL_MAX);
    EXPECT_TRUE(h <= LDBL_MAX);
    EXPECT_TRUE(h <= DBL_MAX);
}

TEST_F(TestCompareLesserEqual, tests_compare_LDBL_MAX)
{
    LargeInt i(LDBL_MAX);
    LargeInt j(DBL_MAX);
    EXPECT_TRUE(j <= i);
    EXPECT_TRUE(i <= LDBL_MAX);
}

} // namespace test_operator_compare_lesser_equal
} // namespace testing
} // namespace li
} // namespace ds
} // namespace ns