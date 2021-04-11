/*
 * tests_operator_minus_equal_equal.cpp
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
// Test operator minus equal
namespace test_operator_minus_equal
{

// Test suit name
using TestOperatorMinusEqual = TestLargeInt;

TEST_F(TestOperatorMinusEqual, tests_minus_equal_largeuint)
{
    LargeInt m = "-36893488147419103230";
    LargeInt n = m;
    n -= m;
    EXPECT_EQ(n.getValue(), "0");

    n -= "36893488147419103230";
    EXPECT_EQ(n.getValue(), m.getValue());
}

} // namespace test_operator_minus_equal
} // namespace testing
} // namespace li
} // namespace ds
} // namespace ns