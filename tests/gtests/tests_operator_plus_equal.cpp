/*
 * tests_operator_plus_equal.cpp
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
// Test operator plus equal
namespace test_operator_plus_equal
{

// Test suit name
using TestOperatorPlusEqual = TestLargeInt;

TEST_F(TestOperatorPlusEqual, tests_plus_equal_largeuint)
{
    LargeInt m = "36893488147419103230";
    LargeInt n = m;
    n += m;
    EXPECT_EQ(n.getValue(), "73786976294838206460");
}

} // namespace test_operator_plus_equal
} // namespace testing
} // namespace li
} // namespace ds
} // namespace ns