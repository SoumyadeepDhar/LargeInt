/*
 * tests_largeint.h
 *
 *  Created on: 29-Mar-2021
 *  Author: soumyadeep dhar
 */

#ifndef TESTS_LARGEUINT_H_
#define TESTS_LARGEUINT_H_

#include "gtest/gtest.h"
#include "largeint.h"
#include "test_fixture.h"

// Number ststem
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

class TestLargeInt : public TestFixture, public ::testing::Test
{
public:
    TestLargeInt()
    {
        // initialization code here
    }

    virtual void SetUp()
    {
        // code here will execute just before the test ensues
    }

    virtual void TearDown()
    {
        // code here will be called just after the test completes
        // ok to through exceptions from here if need be
    }

    virtual ~TestLargeInt()
    {
        // cleanup any pending stuff, but no exceptions allowed
    }
};

} // namespace testing
} // namespace li
} // namespace dn
} // namespace ns

#endif // TESTS_LARGEUINT_H_