/*
 * tests_operator_equal.cpp
 *
 *  Created on: 23-Apr-2021
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
// Test operator equal
namespace test_operator_equal
{

// Test suit name
using TestOperatorEqual = TestLargeInt;

/* Minimum of signed integral types.  */
// # define INT8_MIN		(-128)
TEST_F(TestOperatorEqual, tests_equal_INT8_MIN)
{
    LargeInt a;
    LargeInt b(INT8_MIN);
    a = b + INT8_MIN;
    EXPECT_FALSE(a == (-256 + 1));

    a = b + INT8_MAX;
    EXPECT_FALSE(a == (-1 + 1));

    a = b + 128;
    EXPECT_FALSE(a == (0 + 1));
}


// # define INT16_MIN		(-32767-1)
TEST_F(TestOperatorEqual, tests_equal_INT16_MIN)
{
    LargeInt a;
    LargeInt b(INT16_MIN);
    a = b + INT16_MIN;
    EXPECT_TRUE(a == -65536);

    a = b + INT16_MAX;
    EXPECT_TRUE(a == -1);

    a = b + 32768;
    EXPECT_TRUE(a == 0);
}

// # define INT32_MIN		(-2147483647-1)
TEST_F(TestOperatorEqual, tests_equal_INT32_MIN)
{
    LargeInt a;
    LargeInt b(INT32_MIN);
    a = b + INT32_MIN;
    EXPECT_TRUE(a  == -4294967296);

    a = b + INT32_MAX;
    EXPECT_TRUE(a == -1);

    a = b + "2147483648";
    EXPECT_TRUE(a == 0);
}

// # define INT64_MIN		(-__INT64_C(9223372036854775807)-1)
TEST_F(TestOperatorEqual, tests_equal_INT64_MIN)
{
    LargeInt a;
    LargeInt b(INT64_MIN);
    a = b + INT64_MIN;
    EXPECT_TRUE(a == "-18446744073709551616");

    a = b + INT64_MAX;
    EXPECT_TRUE(a == -1);

    a = b + "9223372036854775808";
    EXPECT_TRUE(a == 0);
}

// Maximum of signed integral types.  //
// # define INT8_MAX		(127)
TEST_F(TestOperatorEqual, tests_equal_INT8_MAX)
{
    LargeInt a;
    LargeInt b(INT8_MAX);
    a = b + INT8_MAX;
    EXPECT_TRUE(a == 254);

    a = b + INT8_MIN;
    EXPECT_TRUE(a == -1);

    a = b + "-127";
    EXPECT_TRUE(a == 0);
}

// # define INT16_MAX		(32767)
TEST_F(TestOperatorEqual, tests_equal_INT16_MAX)
{
    LargeInt a;
    LargeInt b(INT16_MAX);
    a = b + INT16_MAX;
    EXPECT_TRUE(a == 65534);

    a = b + INT16_MIN;
    EXPECT_TRUE(a == -1);

    a = b + "-32767";
    EXPECT_TRUE(a == 0);
}

// # define INT32_MAX		(2147483647)
TEST_F(TestOperatorEqual, tests_equal_INT32_MAX)
{
    LargeInt a;
    LargeInt b(INT32_MAX);
    a = b + INT32_MAX;
    EXPECT_TRUE(a == 4294967294);

    a = b + INT32_MIN;
    EXPECT_TRUE(a == -1);

    a = b + "-2147483647";
    EXPECT_TRUE(a == 0);
}

// # define INT64_MAX		(__INT64_C(9223372036854775807))
TEST_F(TestOperatorEqual, tests_equal_INT64_MAX)
{
    LargeInt a;
    LargeInt b(INT64_MAX);
    a = b + INT64_MAX;
    EXPECT_TRUE(a == "18446744073709551614");

    a = b + INT64_MIN;
    EXPECT_TRUE(a == -1);

    a = b + "-9223372036854775807";
    EXPECT_TRUE(a == 0);
}

// # define UINT8_MAX		(255)
TEST_F(TestOperatorEqual, tests_equal_UINT8_MAX)
{
    LargeInt a;
    LargeInt b(UINT8_MAX);
    a = b + UINT8_MAX;
    EXPECT_TRUE(a == 510);

    a = b + INT8_MIN;
    EXPECT_TRUE(a == 127);

    a = b + "-255";
    EXPECT_TRUE(a == 0);
}

// # define UINT16_MAX		(65535)
TEST_F(TestOperatorEqual, tests_equal_UINT16_MAX)
{
    LargeInt a;
    LargeInt b(UINT16_MAX);
    a = b + UINT16_MAX;
    EXPECT_TRUE(a == 131070);

    a = b + INT16_MIN;
    EXPECT_TRUE(a == 32767);

    a = b + "-65535";
    EXPECT_TRUE(a == 0);
}

// # define UINT32_MAX		(4294967295U)
TEST_F(TestOperatorEqual, tests_equal_UINT32_MAX)
{
    LargeInt a;
    LargeInt b(UINT32_MAX);
    a = b + UINT32_MAX;
    EXPECT_TRUE(a == 8589934590);

    a = b + INT32_MIN;
    EXPECT_TRUE(a == 2147483647);

    a = b + "-4294967295";
    EXPECT_TRUE(a == 0);
}

// # define UINT64_MAX		(__UINT64_C(18446744073709551615))
TEST_F(TestOperatorEqual, tests_equal_UINT64_MAX)
{
    LargeInt a;
    LargeInt b(UINT64_MAX);
    a = b + UINT64_MAX;
    EXPECT_TRUE(a == "36893488147419103230");

    a = b + INT64_MIN;
    EXPECT_TRUE(a == "9223372036854775807");

    a = b + "-18446744073709551615";
    EXPECT_TRUE(a == 0);
}

TEST_F(TestOperatorEqual, tests_equal_const_char_ptr)
{
    LargeInt e1("54321");
    e1 = e1 + "600000";
    EXPECT_TRUE(e1 == 654321);
}

TEST_F(TestOperatorEqual, tests_equal_string)
{
    std::string str("18446744073709551615");
    LargeInt f = str;
    f = f + str;
    EXPECT_TRUE(f == "36893488147419103230");
}

TEST_F(TestOperatorEqual, tests_equal_FLT_MAX)
{
    LargeInt g = FLT_MAX;
    g = g + FLT_MAX;
    EXPECT_TRUE(g == "680564693277057719623408366969033850880");
}

TEST_F(TestOperatorEqual, tests_equal_DBL_MAX)
{
    LargeInt h = DBL_MAX;
    h = h + DBL_MAX;
    LargeInt r = DBL_MAX;
    r *= 2;
    EXPECT_TRUE(h == r);
 }

TEST_F(TestOperatorEqual, tests_equal_LDBL_MAX)
{
    LargeInt i = LDBL_MAX;
    i = i + LDBL_MAX;
    LargeInt r = LDBL_MAX;
    r *= 2;
    EXPECT_TRUE(i == r);
}

TEST_F(TestOperatorEqual, tests_equal_largeuint)
{
    LargeInt m = "36893488147419103230";
    LargeInt n = m;
    n = n + m;
    EXPECT_TRUE(n == (m * 2));
}
} // namespace test_operator_equal
} // namespace testing
} // namespace li
} // namespace dn
} // namespace ns