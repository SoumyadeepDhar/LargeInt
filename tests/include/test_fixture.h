/*
 * test_fixture.h
 *
 *  Created on: 29-Mar-2021
 *  Author: soumyadeep dhar
 */

#ifndef TEST_FIXTURE_H_
#define TEST_FIXTURE_H_

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

class TestFixture
{
public:

    // initialization code here
    TestFixture() {}

    // code here will execute just before the test ensues
    virtual void SetUp() = 0;

    // code here will be called just after the test completes
    // ok to through exceptions from here if need be
    virtual void TearDown() = 0;

    // cleanup any pending stuff, but no exceptions allowed
    virtual ~TestFixture() {}
};

} // namespace testing
} // namespace lui
} // namespace ds
} // namespace ns

#endif // TEST_FIXTURE_H_