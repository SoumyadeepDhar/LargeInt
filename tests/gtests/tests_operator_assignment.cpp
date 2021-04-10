/*
 * tests_assignment.cpp
 *
 *  Created on: 03-Apr-2019
 *  Modified on: 30-Mar-2021
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
namespace test_assignment
{
// Test suit name
using TestAssignment = TestLargeInt;

TEST_F(TestAssignment, tests_assignment_UINT8_MAX)
{
    LargeInt a = UINT8_MAX;
    EXPECT_EQ(a.getValue(), "255");
}

TEST_F(TestAssignment, tests_assignment_UINT16_MAX)
{
    LargeInt b = UINT16_MAX;
    EXPECT_EQ(b.getValue(), "65535");
}

TEST_F(TestAssignment, tests_assignment_UINT32_MAX)
{
    LargeInt c = UINT32_MAX;
    EXPECT_EQ(c.getValue(), "4294967295");
}

TEST_F(TestAssignment, tests_assignment_UINT64_MAX)
{
    LargeInt d = UINT64_MAX;
    EXPECT_EQ(d.getValue(), "18446744073709551615");
}

TEST_F(TestAssignment, tests_assignment_const_char_ptr)
{
    LargeInt e1 = "12345";
    EXPECT_EQ(e1.getValue(), "12345");

    LargeInt e2 = "1844674407370955161518446744073709551615";
    EXPECT_EQ(e2.getValue(), "1844674407370955161518446744073709551615");

    LargeInt e3 = "18446744073709551615.1844";
    EXPECT_EQ(e3.getValue(), "18446744073709551615");

    LargeInt e4 = ".18446744073709551615";
    EXPECT_EQ(e4.getValue(), "0");

    LargeInt e5 = "PQRST";
    EXPECT_EQ(e5.getValue(), "0");

    LargeInt e6 = "PQRST12345";
    EXPECT_EQ(e6.getValue(), "0");

    LargeInt e7 = "12345PQRST";
    EXPECT_EQ(e7.getValue(), "12345");

    LargeInt e8 = "0012345PQRST";
    EXPECT_EQ(e8.getValue(), "12345");
}

TEST_F(TestAssignment, tests_assignment_string)
{
    std::string str("18446744073709551615");
    LargeInt f = str;
    EXPECT_EQ(f.getValue(), "18446744073709551615");
}

TEST_F(TestAssignment, tests_assignment_FLT_MAX)
{
    LargeInt g = FLT_MAX;
    EXPECT_EQ(g.getValue(), std::to_string(FLT_MAX).substr(0, std::to_string(FLT_MAX).find(".")).c_str());
}

TEST_F(TestAssignment, tests_assignment_DBL_MAX)
{  
    LargeInt h = DBL_MAX;
    EXPECT_EQ(h.getValue(), std::to_string(DBL_MAX).substr(0, std::to_string(DBL_MAX).find(".")).c_str());
 }

TEST_F(TestAssignment, tests_assignment_LDBL_MAX)
{   
    LargeInt i = LDBL_MAX;
    EXPECT_EQ(i.getValue(), std::to_string(LDBL_MAX).substr(0, std::to_string(LDBL_MAX).find(".")).c_str());
}

TEST_F(TestAssignment, tests_copy_assignment)
{   
    LargeInt m = UINT64_MAX;
    LargeInt n = m;
    EXPECT_EQ(n.getValue(), m.getValue());
}

} // namespace test_assignment
} // namespace testing
} // namespace li
} // namespace ds
} // namespace ns