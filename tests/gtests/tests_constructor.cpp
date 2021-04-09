/*
 * tests_constructor.cpp
 *
 *  Created on: 03-Apr-2019
 *  Modified on: 30-Mar-2021
 *  Author: Soumyadeep Dhar
 */

#include "gtests/tests_largeint.h"

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
// Test constructors
namespace test_constructor
{

// Test suit name
using TestConstructor = TestLargeUint;

TEST_F(TestConstructor, tests_default_constructor)
{
    LargeInt a;
    EXPECT_EQ(a.getValue(), std::string("0"));
}

TEST_F(TestConstructor, tests_arg_constructor_UINT8_MAX)
{
    LargeInt a(UINT8_MAX);
    EXPECT_EQ(a.getValue(), "255");
}

TEST_F(TestConstructor, tests_arg_constructor_UINT16_MAX)
{
    LargeInt b(UINT16_MAX);
    EXPECT_EQ(b.getValue(), "65535");
}

TEST_F(TestConstructor, tests_arg_constructor_UINT32_MAX)
{
    LargeInt c(UINT32_MAX);
    EXPECT_EQ(c.getValue(), "4294967295");
}

TEST_F(TestConstructor, tests_arg_constructor_UINT64_MAX)
{
    LargeInt d(UINT64_MAX);
    EXPECT_EQ(d.getValue(), "18446744073709551615");
}

TEST_F(TestConstructor, tests_arg_constructor_const_char_ptr_null)
{
    char *ptr = NULL;
    LargeInt a(ptr);
    EXPECT_EQ(a.getValue(), std::string("0"));
}

TEST_F(TestConstructor, tests_arg_constructor_const_char_ptr_zero)
{
    LargeInt e1a("0");
    EXPECT_EQ(e1a.getValue(), "0");

    LargeInt e1b("-0");
    EXPECT_EQ(e1b.getValue(), "0");

    LargeInt e1c("0000000000000000000");
    EXPECT_EQ(e1c.getValue(), "0");

    LargeInt e1d("-0000000000000000000");
    EXPECT_EQ(e1d.getValue(), "0");
}

TEST_F(TestConstructor, tests_arg_constructor_const_char_ptr_nonzero)
{
    LargeInt e1a("12345");
    EXPECT_EQ(e1a.getValue(), "12345");

    LargeInt e1b("-12345");
    EXPECT_EQ(e1b.getValue(), "-12345");

    LargeInt e2a("1844674407370955161518446744073709551615");
    EXPECT_EQ(e2a.getValue(), "1844674407370955161518446744073709551615");

    LargeInt e2b("-1844674407370955161518446744073709551615");
    EXPECT_EQ(e2b.getValue(), "-1844674407370955161518446744073709551615");

    LargeInt e3a("18446744073709551615.1844");
    EXPECT_EQ(e3a.getValue(), "18446744073709551615");

    LargeInt e3b("-18446744073709551615.1844");
    EXPECT_EQ(e3b.getValue(), "-18446744073709551615");

    LargeInt e4a(".18446744073709551615");
    EXPECT_EQ(e4a.getValue(), "0");

    LargeInt e4b("-.18446744073709551615");
    EXPECT_EQ(e4b.getValue(), "0");

    LargeInt e5a("PQRST");
    EXPECT_EQ(e5a.getValue(), "0");

    LargeInt e5b("-PQRST");
    EXPECT_EQ(e5b.getValue(), "0");

    LargeInt e6a("PQRST12345");
    EXPECT_EQ(e6a.getValue(), "0");

    LargeInt e6b("-PQRST12345");
    EXPECT_EQ(e6b.getValue(), "0");

    LargeInt e7a("12345PQRST");
    EXPECT_EQ(e7a.getValue(), "12345");

    LargeInt e7b("-12345PQRST");
    EXPECT_EQ(e7b.getValue(), "-12345");

    LargeInt e8a("0012345PQRST");
    EXPECT_EQ(e8a.getValue(), "12345");

    LargeInt e8b("-0012345PQRST");
    EXPECT_EQ(e8b.getValue(), "-12345");
}

TEST_F(TestConstructor, tests_arg_constructor_string)
{
    std::string strA("18446744073709551615");
    LargeInt fa(strA);
    EXPECT_EQ(fa.getValue(), "18446744073709551615");

    std::string strB("-18446744073709551615");
    LargeInt fb(strB);
    EXPECT_EQ(fb.getValue(), "-18446744073709551615");
}

TEST_F(TestConstructor, tests_arg_constructor_FLT_MAX)
{
    std::string floatMaxToString(std::to_string(FLT_MAX).substr(0, std::to_string(FLT_MAX).find(".")));
    LargeInt gA(FLT_MAX);
    EXPECT_EQ(gA.getValue(), floatMaxToString.c_str());

    LargeInt gB(FLT_MAX * -1.0F);
    EXPECT_EQ(gB.getValue(), std::string("-" + floatMaxToString).c_str());
}

TEST_F(TestConstructor, tests_arg_constructor_DBL_MAX)
{  
    LargeInt h(DBL_MAX);
    EXPECT_EQ(h.getValue(), std::to_string(DBL_MAX).substr(0, std::to_string(DBL_MAX).find(".")).c_str());
 }

TEST_F(TestConstructor, tests_arg_constructor_LDBL_MAX)
{   
    LargeInt i(LDBL_MAX);
    EXPECT_EQ(i.getValue(), std::to_string(LDBL_MAX).substr(0, std::to_string(LDBL_MAX).find(".")).c_str());
}

TEST_F(TestConstructor, tests_copy_constructor)
{   
    LargeInt m(UINT64_MAX);
    LargeInt n(m);
    EXPECT_EQ(n.getValue(), m.getValue());
}

} // namespace test_constructor
} // namespace testing
} // namespace li
} // namespace ds
} // namespace ns