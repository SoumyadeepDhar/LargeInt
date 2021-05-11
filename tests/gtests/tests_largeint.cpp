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
    EXPECT_EQ(n.getValue(), "36893488147419103230");
}

TEST_F(TestLargeInt, tests_largeint_pow_0)
{
    LargeInt m = "36893488147419103230";
    LargeInt n = m.pow(0);
    EXPECT_EQ(n.getValue(), "1");
}

TEST_F(TestLargeInt, tests_largeint_pow_1)
{
    LargeInt m = "36893488147419103230";
    LargeInt n = m.pow(1);
    EXPECT_EQ(n.getValue(), "36893488147419103230");
}

TEST_F(TestLargeInt, tests_largeint_pow_2)
{
    LargeInt m = "36893488147419103230";
    LargeInt n = m.pow(2);
    EXPECT_EQ(n.getValue(), "1361129467683753853705924477137396432900");
}

TEST_F(TestLargeInt, tests_largeint_pow_3)
{
    LargeInt m = "36893488147419103230";
    LargeInt n = m.pow(3);
    EXPECT_EQ(n.getValue(), "50216813883093446102519538579558808206140574835118868267000");
}

TEST_F(TestLargeInt, tests_largeint_pow_4)
{
    LargeInt m = "36893488147419103230";
    LargeInt n = m.pow(4);
    EXPECT_EQ(n.getValue(), "1852673427797059126375401249074258956799496338789368466492073966373644202410000");
}

TEST_F(TestLargeInt, tests_largeint_root_0)
{
    LargeInt m = "36893488147419103230";
    LargeInt n = m.root(0);
    EXPECT_TRUE(n == "INFINITY");
}

TEST_F(TestLargeInt, tests_largeint_root_1)
{
    LargeInt m = "36893488147419103230";
    LargeInt n = m.root(1);
    EXPECT_TRUE(n == "36893488147419103230");
}

TEST_F(TestLargeInt, tests_largeint_root_2)
{
    LargeInt m = "1361129467683753853705924477137396432901";
    LargeInt n = m.root(2);
    EXPECT_TRUE(n == "36893488147419103230");
}

TEST_F(TestLargeInt, tests_largeint_root_3)
{
    LargeInt m = "50216813883093446102519538579558808206140574835118868267000";
    LargeInt n = m.root(3);
    EXPECT_TRUE(n == "36893488147419103230");
}

TEST_F(TestLargeInt, tests_largeint_root_4)
{
    LargeInt m = "18526734277970591263754012490742589567994963387893684664920739663736442024100001852673427797059126375401249074258956799496338789368466492073966373644202410000";
    LargeInt n = m.root(4);
    EXPECT_EQ(n.getValue(), "2074673301571409538209323192905998949900");
}

TEST_F(TestLargeInt, tests_largeint_factor_UINT64)
{
    std::vector<unsigned long long int> factors = LargeInt::factor(100);
    for (auto &f : factors)
    {
        EXPECT_EQ((100 % f), 0);
    }
}

TEST_F(TestLargeInt, tests_largeint_factor_LargeInt)
{
    LargeInt value("2074673301571409538209323192905998949900");
    std::vector<LargeInt> factors = value.factor();
    for (auto &f : factors)
    {
        EXPECT_EQ((value % f).getValue(), "0");
    }
}

} // namespace testing
} // namespace li
} // namespace dn
} // namespace ns