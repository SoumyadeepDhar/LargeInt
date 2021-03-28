/*
 * gtest_fixture.h
 *
 *  Created on: 29-Mar-2021
 *  Author: soumyadeep dhar
 */

#ifndef GTEST_FIXTURE_H_
#define GTEST_FIXTURE_H_

#include <string.h>

#include "gtest/gtest.h"
#include "largeuint.h"
#include "test_fixture.h"

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

class GTestFixture : public TestFixture, public ::testing::Test
{
public:
    GTestFixture() : _largeUInt("9876543210123456789")
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

    virtual ~GTestFixture()
    {
        // cleanup any pending stuff, but no exceptions allowed
    }

protected:
    LargeUInt _largeUInt;
};

} // namespace testing
} // namespace lui
} // namespace ds
} // namespace ns

#endif // GTEST_FIXTURE_H_