/*
 * tests_operator_plus.cpp
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
// Test operator plus
namespace test_operator_plus
{

// Test suit name
using TestOperatorPlus = TestLargeUint;

TEST_F(TestOperatorPlus, tests_assignment_plus_UINT8_MAX)
{
    int _temp = UINT8_MAX;
    LargeUInt a = 1000;
    a += _temp;
    EXPECT_EQ(a.getValue(), "1255");
}

TEST_F(TestOperatorPlus, tests_assignment_plus_UINT16_MAX)
{
    int _temp = UINT16_MAX;
    LargeUInt a = 100000;
    a += _temp;
    EXPECT_EQ(a.getValue(), "165535");
}

TEST_F(TestOperatorPlus, tests_assignment_plus_UINT32_MAX)
{
    unsigned int _temp = UINT32_MAX;
    LargeUInt a = "10000000000";
    a += _temp;
    EXPECT_EQ(a.getValue(), "14294967295");
}

TEST_F(TestOperatorPlus, tests_assignment_plus_UINT64_MAX)
{
    long long unsigned int _temp = UINT64_MAX;
    LargeUInt a = "100000000000000000000";
    a += _temp;
    EXPECT_EQ(a.getValue(), "118446744073709551615");
}

TEST_F(TestOperatorPlus, tests_assignment_plus_const_char_ptr)
{
    LargeUInt e1 = "12345";
    e1          += "100000";

    EXPECT_EQ(e1.getValue(), "112345");

    LargeUInt e2 = "1844674407370955161518446744073709551615";
    e2          += "10000000000000000000000000000000000000000";
    EXPECT_EQ(e2.getValue(), "11844674407370955161518446744073709551615");

    LargeUInt e3 = "18446744073709551615.1844";
    e3          += "100000000000000000000";
    EXPECT_EQ(e3.getValue(), "118446744073709551615");

    LargeUInt e4 = ".18446744073709551615";
    e4          += 1000;
    EXPECT_EQ(e4.getValue(), "1000");

    LargeUInt e5 = "PQRST";
    e5          += 12345;
    EXPECT_EQ(e5.getValue(), "12345");

    LargeUInt e6 = "PQRST12345";
    e6          += "12345";
    EXPECT_EQ(e6.getValue(), "12345");

    LargeUInt e7 = "12345PQRST";
    e7          += "12345";
    EXPECT_EQ(e7.getValue(), "24690");

    LargeUInt e8 = "0012345PQRST";
    e8          += "12345";
    EXPECT_EQ(e8.getValue(), "24690");
}

TEST_F(TestOperatorPlus, tests_assignment_plus_string)
{
    std::string str("18446744073709551615");
    LargeUInt f = str;
    f           += str;
    EXPECT_EQ(f.getValue(), "36893488147419103230");
}

TEST_F(TestOperatorPlus, tests_assignment_plus_FLT_MAX)
{
    LargeUInt g = FLT_MAX;
    g += FLT_MAX;
    EXPECT_EQ(g.getValue(), "680564693277057719623408366969033850880");
}

// TEST_F(TestOperatorPlus, tests_assignment_plus_DBL_MAX)
// {  
//     LargeUInt h = DBL_MAX;
//     h += DBL_MAX;
//     EXPECT_EQ(h.getValue(), std::to_string(DBL_MAX).substr(0, std::to_string(DBL_MAX).find(".")).c_str());
//  }

// TEST_F(TestOperatorPlus, tests_assignment_plus_LDBL_MAX)
// {   
//     LargeUInt i = LDBL_MAX;
//     EXPECT_EQ(i.getValue(), std::to_string(LDBL_MAX).substr(0, std::to_string(LDBL_MAX).find(".")).c_str());
// }

TEST_F(TestOperatorPlus, tests_assignment_plus_largeuint)
{   
    LargeUInt m = "36893488147419103230";
    LargeUInt n = m;
    n += m;
    EXPECT_EQ(n.getValue(), "73786976294838206460");
}

} // namespace test_operator_plus
} // namespace testing
} // namespace lui
} // namespace ds
} // namespace ns