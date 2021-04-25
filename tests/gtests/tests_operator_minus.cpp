/*
 * tests_operator_minus.cpp
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
// Test operator minus
namespace test_operator_minus
{

// Test suit name
using TestOperatorMinus = TestLargeInt;

/* Minimum of signed integral types.  */
// # define INT8_MIN		(-128)
TEST_F(TestOperatorMinus, tests_minus_INT8_MIN)
{
    LargeInt a;
    LargeInt b(INT8_MIN);
    a = b - INT8_MIN;
    EXPECT_EQ(a.getValue(), "0");

    a = b - INT8_MAX;
    EXPECT_EQ(a.getValue(), "-255");

    a = b - "-255";
    EXPECT_EQ(a.getValue(), std::to_string(INT8_MAX));
}


// # define INT16_MIN		(-32767-1)
TEST_F(TestOperatorMinus, tests_minus_INT16_MIN)
{
    LargeInt a;
    LargeInt b(INT16_MIN);
    a = b - INT16_MIN;
    EXPECT_EQ(a.getValue(), "0");

    a = b - INT16_MAX;
    EXPECT_EQ(a.getValue(), "-65535");

    a = b - "-65535";
    EXPECT_EQ(a.getValue(), std::to_string(INT16_MAX));
}

// # define INT32_MIN		(-2147483647-1)
TEST_F(TestOperatorMinus, tests_minus_INT32_MIN)
{
    LargeInt a;
    LargeInt b(INT32_MIN);
    a = b - INT32_MIN;
    EXPECT_EQ(a.getValue(), "0");

    a = b - INT32_MAX;
    EXPECT_EQ(a.getValue(), "-4294967295");

    a = b - "-4294967295";
    EXPECT_EQ(a.getValue(), std::to_string(INT32_MAX));
}

// # define INT64_MIN		(-__INT64_C(9223372036854775807)-1)
TEST_F(TestOperatorMinus, tests_minus_INT64_MIN)
{
    LargeInt a;
    LargeInt b(INT64_MIN);
    a = b - INT64_MIN;
    EXPECT_EQ(a.getValue(), "0");

    a = b - INT64_MAX;
    EXPECT_EQ(a.getValue(), "-18446744073709551615");

    a = b - "-18446744073709551615";
    EXPECT_EQ(a.getValue(), std::to_string(INT64_MAX));
}


// Maximum of signed integral types.
// # define INT8_MAX		(127)
TEST_F(TestOperatorMinus, tests_minus_INT8_MAX)
{
    LargeInt a;
    LargeInt b(INT8_MAX);
    a = b - INT8_MAX;
    EXPECT_EQ(a.getValue(), "0");

    a = b - INT8_MIN;
    EXPECT_EQ(a.getValue(), "255");

    a = b - "255";
    EXPECT_EQ(a.getValue(), "-128");
}

// # define INT16_MAX		(32767)
TEST_F(TestOperatorMinus, tests_minus_INT16_MAX)
{
    LargeInt a;
    LargeInt b(INT16_MAX);
    a = b - INT16_MAX;
    EXPECT_EQ(a.getValue(), "0");

    a = b - INT16_MIN;
    EXPECT_EQ(a.getValue(), "65535");

    a = b - "65535";
    EXPECT_EQ(a.getValue(), "-32768");
}

// # define INT32_MAX		(2147483647)
TEST_F(TestOperatorMinus, tests_minus_INT32_MAX)
{
    LargeInt a;
    LargeInt b(INT32_MAX);
    a = b - INT32_MAX;
    EXPECT_EQ(a.getValue(), "0");

    a = b - INT32_MIN;
    EXPECT_EQ(a.getValue(), "4294967295");

    a = b - "4294967295";
    EXPECT_EQ(a.getValue(), "-2147483648");
}

// # define INT64_MAX		(__INT64_C(9223372036854775807))
TEST_F(TestOperatorMinus, tests_minus_INT64_MAX)
{
    LargeInt a;
    LargeInt b(INT64_MAX);
    a = b - INT64_MAX;
    EXPECT_EQ(a.getValue(), "0");

    a = b - INT64_MIN;
    EXPECT_EQ(a.getValue(), "18446744073709551615");

    a = b - "18446744073709551615";
    EXPECT_EQ(a.getValue(), "-9223372036854775808");
}


// # define UINT8_MAX		(255)
TEST_F(TestOperatorMinus, tests_minus_UINT8_MAX)
{
    LargeInt a;
    LargeInt b(UINT8_MAX);
    a = b - UINT8_MAX;
    EXPECT_EQ(a.getValue(), "0");

    a = b - INT8_MIN;
    EXPECT_EQ(a.getValue(), "383");

    a = b - "-255";
    EXPECT_EQ(a.getValue(), "510");
}

// # define UINT16_MAX		(65535)
TEST_F(TestOperatorMinus, tests_minus_UINT16_MAX)
{
    LargeInt a;
    LargeInt b(UINT16_MAX);
    a = b - UINT16_MAX;
    EXPECT_EQ(a.getValue(), "0");

    a = b - INT16_MIN;
    EXPECT_EQ(a.getValue(), "98303");

    a = b - "131071";
    EXPECT_EQ(a.getValue(), "-65536");
}

// # define UINT32_MAX		(4294967295U)
TEST_F(TestOperatorMinus, tests_minus_UINT32_MAX)
{
    LargeInt a;
    LargeInt b(UINT32_MAX);
    a = b - UINT32_MAX;
    EXPECT_EQ(a.getValue(), "0");

    a = b - INT32_MIN;
    EXPECT_EQ(a.getValue(), "6442450943");

    a = b - "8589934590";
    EXPECT_EQ(a.getValue(), "-4294967295");
}

// # define UINT64_MAX		(__UINT64_C(18446744073709551615))
TEST_F(TestOperatorMinus, tests_minus_UINT64_MAX)
{
    LargeInt a;
    LargeInt b(UINT64_MAX);
    a = b - UINT64_MAX;
    EXPECT_EQ(a.getValue(), "0");

    a = b - INT64_MIN;
    EXPECT_EQ(a.getValue(), "27670116110564327423");

    a = b - "36893488147419103231";
    EXPECT_EQ(a.getValue(), "-18446744073709551616");
}


TEST_F(TestOperatorMinus, tests_minus_const_char_ptr)
{
    LargeInt e1("54321");
    e1 = e1 - "100000";
    EXPECT_EQ(e1.getValue(), "-45679");
}

TEST_F(TestOperatorMinus, tests_minus_string)
{
    std::string str("18446744073709551615");
    LargeInt f = str;
    f = f - str;
    EXPECT_EQ(f.getValue(), "0");
}

TEST_F(TestOperatorMinus, tests_minus_FLT_MAX)
{
    LargeInt g = FLT_MAX;
    g = g - FLT_MAX;
    EXPECT_EQ(g.getValue(), "0");
}

TEST_F(TestOperatorMinus, tests_minus_DBL_MAX)
{
    LargeInt h = DBL_MAX;
    h = h - DBL_MAX;
    EXPECT_EQ(h.getValue(), "0");
 }

TEST_F(TestOperatorMinus, tests_minus_LDBL_MAX)
{
    LargeInt i = LDBL_MAX;
    i = i - LDBL_MAX;
    EXPECT_EQ(i.getValue(), "0");
}

TEST_F(TestOperatorMinus, tests_minus_largeuint)
{
    LargeInt m = "36893488147419103230";
    LargeInt n = m;
    n = n - m;
    EXPECT_EQ(n.getValue(), "0");
}

} // namespace test_operator_minus
} // namespace testing
} // namespace li
} // namespace dn
} // namespace ns