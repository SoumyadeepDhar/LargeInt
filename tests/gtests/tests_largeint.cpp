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

TEST_F(TestLargeInt, tests_largeuint_increment_postfix)
{
    LargeInt m = "36893488147419103230";
    LargeInt n = m;
    EXPECT_TRUE(m++ == n);
    EXPECT_TRUE(m == (n + 1));
}

TEST_F(TestLargeInt, tests_largeuint_decrement_postfix)
{
    LargeInt m = "36893488147419103230";
    LargeInt n = m;
    EXPECT_TRUE(m-- == n);
    EXPECT_TRUE(m == (n - 1));
}

TEST_F(TestLargeInt, tests_largeuint_increment_prefix)
{
    LargeInt m = "36893488147419103230";
    LargeInt n = m;
    EXPECT_TRUE(++m == (n + 1));
}

TEST_F(TestLargeInt, tests_largeuint_decrement_prefix)
{
    LargeInt m = "36893488147419103230";
    LargeInt n = m;
    EXPECT_TRUE(--m == (n - 1));
}

} // namespace testing
} // namespace li
} // namespace ds
} // namespace ns