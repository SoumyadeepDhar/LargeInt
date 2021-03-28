/*
 * tests_constructor.h
 *
 *  Created on: 29-Mar-2021
 *  Author: soumyadeep dhar
 */

#ifndef TESTS_CONSTRUCTOR_H_
#define TESTS_CONSTRUCTOR_H_

#include "gtest_fixture.h"

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

class TestConstructor : public GTestFixture
{
public:
    TestConstructor()
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

    virtual ~TestConstructor()
    {
        // cleanup any pending stuff, but no exceptions allowed
    }
};

} // namespace test_constructor
} // namespace testing
} // namespace lui
} // namespace ds
} // namespace ns

#endif // TESTS_CONSTRUCTOR_H_