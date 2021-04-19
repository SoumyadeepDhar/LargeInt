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
// Large integer
namespace li
{
// Testing module    
namespace testing
{

class TestFixture
{
public:

    // Initialization code here
    TestFixture() {}

    // Code here will execute just before the test ensues
    virtual void SetUp() = 0;

    // Code here will be called just after the test completes
    // ok to through exceptions from here if need be
    virtual void TearDown() = 0;

    // Cleanup any pending stuff, but no exceptions allowed
    virtual ~TestFixture() {}
};

} // namespace testing
} // namespace li
} // namespace ds
} // namespace ns

#endif // TEST_FIXTURE_H_