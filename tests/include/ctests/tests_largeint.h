/*
 * tests_largeint.h
 *
 *  Created on: 20-Apr-2021
 *  Author: soumyadeep dhar
 */

#ifndef TESTS_LARGEUINT_H_
#define TESTS_LARGEUINT_H_

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

template <typename T>
class TestLargeInt : public TestFixture
{
    T typedata;
    LargeInt largeIint;

public:
    TestLargeInt(T value) : typedata(value), largeIint(typedata)
    {
    }

    virtual void SetUp()
    {
        LargeInt duplicate(typedata);

        // Test addition
        largeIint = largeIint + typedata;
        assert(largeIint.getValue() == (duplicate * 2).getValue());

        // Test subtraction
        largeIint = largeIint - typedata;
        assert(largeIint.getValue().compare(std::to_string(typedata)) == 0);

        // Test multiplecation
        largeIint = largeIint * typedata;
        assert(largeIint.getValue() == (duplicate * duplicate).getValue());

        // Test devision
        largeIint = largeIint / typedata;
        assert(largeIint.getValue().compare(std::to_string(typedata)) == 0);
    }

    virtual void TearDown()
    {
        // code here will be called just after the test completes
        // ok to through exceptions from here if need be

        // Clear data
        typedata = (T)0;
        largeIint = typedata;
    }

    virtual ~TestLargeInt()
    {
        // cleanup any pending stuff, but no exceptions allowed
    }
};

} // namespace testing
} // namespace li
} // namespace ds
} // namespace ns

#endif // TESTS_LARGEUINT_H_