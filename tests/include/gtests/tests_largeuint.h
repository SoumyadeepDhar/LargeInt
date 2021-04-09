/*
 * tests_largeuint.h
 *
 *  Created on: 29-Mar-2021
 *  Author: soumyadeep dhar
 */

#ifndef TESTS_LARGEUINT_H_
#define TESTS_LARGEUINT_H_

#include "gtest_fixture.h"

// Number ststem
namespace ns
{
// Decimal Number
namespace dn
{
// Large unsigned integer
namespace li
{
// Testing module    
namespace testing
{

class TestLargeUint : public GTestFixture
{
public:
    TestLargeUint()
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

    virtual ~TestLargeUint()
    {
        // cleanup any pending stuff, but no exceptions allowed
    }
};

} // namespace testing
} // namespace li
} // namespace ds
} // namespace ns

#endif // TESTS_LARGEUINT_H_