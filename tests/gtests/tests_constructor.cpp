#include "gtests/tests_constructor.h"

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
// Test constructors
namespace test_constructor
{
TEST_F(TestConstructor, tests_default_constructor)
{
    LargeUInt a;
    EXPECT_EQ(a.getValue(), std::string("0"));
}

TEST_F(TestConstructor, tests_arg_constructor_unsigned_int)
{
    LargeUInt a(10U);
    EXPECT_EQ(a.getValue(), std::string("10"));

    LargeUInt b(UINT32_MAX);
    EXPECT_EQ(b.getValue(), std::to_string(UINT32_MAX).c_str());

    long long unsigned int m = UINT64_MAX;
}

} // namespace test_constructor
} // namespace testing
} // namespace lui
} // namespace ds
} // namespace ns