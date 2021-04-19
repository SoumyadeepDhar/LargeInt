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
    // Initialization code here
    TestLargeInt(T value);

    // Perform tests here
    void SetUp() override;

    // Clear any test data after tests
    void TearDown() override;

    // Free up memory 
    ~TestLargeInt() override;
};

} // namespace testing
} // namespace li
} // namespace ds
} // namespace ns

#endif // TESTS_LARGEUINT_H_