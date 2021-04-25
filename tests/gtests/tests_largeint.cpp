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

TEST_F(TestLargeInt, tests_largeint_increment_postfix)
{
    LargeInt m = "36893488147419103230";
    LargeInt n = m;
    EXPECT_TRUE(m++ == n);
    EXPECT_TRUE(m == (n + 1));
}

TEST_F(TestLargeInt, tests_largeint_decrement_postfix)
{
    LargeInt m = "36893488147419103230";
    LargeInt n = m;
    EXPECT_TRUE(m-- == n);
    EXPECT_TRUE(m == (n - 1));
}

TEST_F(TestLargeInt, tests_largeint_increment_prefix)
{
    LargeInt m = "36893488147419103230";
    LargeInt n = m;
    EXPECT_TRUE(++m == (n + 1));
}

TEST_F(TestLargeInt, tests_largeint_decrement_prefix)
{
    LargeInt m = "36893488147419103230";
    LargeInt n = m;
    EXPECT_TRUE(--m == (n - 1));
}

TEST_F(TestLargeInt, tests_largeint_sqrt)
{
    LargeInt m = "1361129467683753853705924477137396432901";
    LargeInt n = m.sqrt();
    EXPECT_TRUE(n == "36893488147419103230");
}

} // namespace testing
} // namespace li
} // namespace dn
} // namespace ns