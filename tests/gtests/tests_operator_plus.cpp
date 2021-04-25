/*
 * tests_operator_plus.cpp
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
// Test operator plus
namespace test_operator_plus
{

// Test suit name
using TestOperatorPlus = TestLargeInt;

/* Minimum of signed integral types.  */
// # define INT8_MIN		(-128)
TEST_F(TestOperatorPlus, tests_plus_INT8_MIN)
{
    LargeInt a;
    LargeInt b(INT8_MIN);
    a = b + INT8_MIN;
    EXPECT_EQ(a.getValue(), "-256");

    a = b + INT8_MAX;
    EXPECT_EQ(a.getValue(), "-1");

    a = b + 128;
    EXPECT_EQ(a.getValue(), "0");
}


// # define INT16_MIN		(-32767-1)
TEST_F(TestOperatorPlus, tests_plus_INT16_MIN)
{
    LargeInt a;
    LargeInt b(INT16_MIN);
    a = b + INT16_MIN;
    EXPECT_EQ(a.getValue(), "-65536");

    a = b + INT16_MAX;
    EXPECT_EQ(a.getValue(), "-1");

    a = b + 32768;
    EXPECT_EQ(a.getValue(), "0");
}

// # define INT32_MIN		(-2147483647-1)
TEST_F(TestOperatorPlus, tests_plus_INT32_MIN)
{
    LargeInt a;
    LargeInt b(INT32_MIN);
    a = b + INT32_MIN;
    EXPECT_EQ(a.getValue(), "-4294967296");

    a = b + INT32_MAX;
    EXPECT_EQ(a.getValue(), "-1");

    a = b + "2147483648";
    EXPECT_EQ(a.getValue(), "0");
}

// # define INT64_MIN		(-__INT64_C(9223372036854775807)-1)
TEST_F(TestOperatorPlus, tests_plus_INT64_MIN)
{
    LargeInt a;
    LargeInt b(INT64_MIN);
    a = b + INT64_MIN;
    EXPECT_EQ(a.getValue(), "-18446744073709551616");

    a = b + INT64_MAX;
    EXPECT_EQ(a.getValue(), "-1");

    a = b + "9223372036854775808";
    EXPECT_EQ(a.getValue(), "0");
}

// Maximum of signed integral types.  //
// # define INT8_MAX		(127)
TEST_F(TestOperatorPlus, tests_plus_INT8_MAX)
{
    LargeInt a;
    LargeInt b(INT8_MAX);
    a = b + INT8_MAX;
    EXPECT_EQ(a.getValue(), "254");

    a = b + INT8_MIN;
    EXPECT_EQ(a.getValue(), "-1");

    a = b + "-127";
    EXPECT_EQ(a.getValue(), "0");
}

// # define INT16_MAX		(32767)
TEST_F(TestOperatorPlus, tests_plus_INT16_MAX)
{
    LargeInt a;
    LargeInt b(INT16_MAX);
    a = b + INT16_MAX;
    EXPECT_EQ(a.getValue(), "65534");

    a = b + INT16_MIN;
    EXPECT_EQ(a.getValue(), "-1");

    a = b + "-32767";
    EXPECT_EQ(a.getValue(), "0");
}

// # define INT32_MAX		(2147483647)
TEST_F(TestOperatorPlus, tests_plus_INT32_MAX)
{
    LargeInt a;
    LargeInt b(INT32_MAX);
    a = b + INT32_MAX;
    EXPECT_EQ(a.getValue(), "4294967294");

    a = b + INT32_MIN;
    EXPECT_EQ(a.getValue(), "-1");

    a = b + "-2147483647";
    EXPECT_EQ(a.getValue(), "0");
}

// # define INT64_MAX		(__INT64_C(9223372036854775807))
TEST_F(TestOperatorPlus, tests_plus_INT64_MAX)
{
    LargeInt a;
    LargeInt b(INT64_MAX);
    a = b + INT64_MAX;
    EXPECT_EQ(a.getValue(), "18446744073709551614");

    a = b + INT64_MIN;
    EXPECT_EQ(a.getValue(), "-1");

    a = b + "-9223372036854775807";
    EXPECT_EQ(a.getValue(), "0");
}

// # define UINT8_MAX		(255)
TEST_F(TestOperatorPlus, tests_plus_UINT8_MAX)
{
    LargeInt a;
    LargeInt b(UINT8_MAX);
    a = b + UINT8_MAX;
    EXPECT_EQ(a.getValue(), "510");

    a = b + INT8_MIN;
    EXPECT_EQ(a.getValue(), "127");

    a = b + "-255";
    EXPECT_EQ(a.getValue(), "0");
}

// # define UINT16_MAX		(65535)
TEST_F(TestOperatorPlus, tests_plus_UINT16_MAX)
{
    LargeInt a;
    LargeInt b(UINT16_MAX);
    a = b + UINT16_MAX;
    EXPECT_EQ(a.getValue(), "131070");

    a = b + INT16_MIN;
    EXPECT_EQ(a.getValue(), "32767");

    a = b + "-65535";
    EXPECT_EQ(a.getValue(), "0");
}

// # define UINT32_MAX		(4294967295U)
TEST_F(TestOperatorPlus, tests_plus_UINT32_MAX)
{
    LargeInt a;
    LargeInt b(UINT32_MAX);
    a = b + UINT32_MAX;
    EXPECT_EQ(a.getValue(), "8589934590");

    a = b + INT32_MIN;
    EXPECT_EQ(a.getValue(), "2147483647");

    a = b + "-4294967295";
    EXPECT_EQ(a.getValue(), "0");
}

// # define UINT64_MAX		(__UINT64_C(18446744073709551615))
TEST_F(TestOperatorPlus, tests_plus_UINT64_MAX)
{
    LargeInt a;
    LargeInt b(UINT64_MAX);
    a = b + UINT64_MAX;
    EXPECT_EQ(a.getValue(), "36893488147419103230");

    a = b + INT64_MIN;
    EXPECT_EQ(a.getValue(), "9223372036854775807");

    a = b + "-18446744073709551615";
    EXPECT_EQ(a.getValue(), "0");
}

TEST_F(TestOperatorPlus, tests_plus_const_char_ptr)
{
    LargeInt e1("54321");
    e1 = e1 + "600000";
    EXPECT_EQ(e1.getValue(), "654321");
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
} // namespace dn
} // namespace ns