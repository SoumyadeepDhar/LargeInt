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

TEST_F(TestConstructor, tests_arg_constructor_UINT8_MAX)
{
    LargeUInt a(UINT8_MAX);
    EXPECT_EQ(a.getValue(), "255");
}

TEST_F(TestConstructor, tests_arg_constructor_UINT16_MAX)
{
    LargeUInt b(UINT16_MAX);
    EXPECT_EQ(b.getValue(), "65535");
}

TEST_F(TestConstructor, tests_arg_constructor_UINT32_MAX)
{
    LargeUInt c(UINT32_MAX);
    EXPECT_EQ(c.getValue(), "4294967295");
}

TEST_F(TestConstructor, tests_arg_constructor_UINT64_MAX)
{
    LargeUInt d(UINT64_MAX);
    EXPECT_EQ(d.getValue(), "18446744073709551615");
}

TEST_F(TestConstructor, tests_arg_constructor_FLT_MAX)
{
    LargeUInt e(FLT_MAX);
    EXPECT_EQ(e.getValue(), std::to_string(FLT_MAX).substr(0, std::to_string(FLT_MAX).find(".")).c_str());
}

TEST_F(TestConstructor, tests_arg_constructor_DBL_MAX)
{  
    LargeUInt f(DBL_MAX);
    EXPECT_EQ(f.getValue(), std::to_string(DBL_MAX).substr(0, std::to_string(DBL_MAX).find(".")).c_str());
 }

TEST_F(TestConstructor, tests_arg_constructor_LDBL_MAX)
{   
    LargeUInt g(LDBL_MAX);
    EXPECT_EQ(g.getValue(), std::to_string(LDBL_MAX).substr(0, std::to_string(LDBL_MAX).find(".")).c_str());
}

} // namespace test_constructor
} // namespace testing
} // namespace lui
} // namespace ds
} // namespace ns