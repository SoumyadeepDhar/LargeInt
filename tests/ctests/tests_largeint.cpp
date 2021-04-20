/*
 * tests_largeint.cpp
 *
 *  Created on: 20-Apr-2021
 *  Author: soumyadeep dhar
 */

#include <assert.h>
#include "ctests/tests_largeint.h"

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
TestLargeInt<T>::TestLargeInt(T value)
    : typedata(value), largeIint(typedata)
{
}

template <typename T>
void TestLargeInt<T>::SetUp()
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

    // Test left shift
    largeIint = largeIint << 20;
    assert(((largeIint / duplicate).digits() - 1) == 20);

    // Test right shift
    largeIint = largeIint >> 20;
    assert(largeIint.getValue() == duplicate.getValue());

    // Test addition
    largeIint += typedata;
    assert(largeIint.getValue() == (duplicate * 2).getValue());

    // Test subtraction
    largeIint -= typedata;
    assert(largeIint.getValue().compare(std::to_string(typedata)) == 0);

    // Test multiplecation
    largeIint *= typedata;
    assert(largeIint.getValue() == (duplicate * duplicate).getValue());

    // Test devision
    largeIint /= typedata;
    assert(largeIint.getValue().compare(std::to_string(typedata)) == 0);

    // Test left shift
    largeIint <<= 20;
    assert(((largeIint / duplicate).digits() - 1) == 20);

    // Test right shift
    largeIint >>= 20;
    assert(largeIint.getValue() == duplicate.getValue());
}

template <typename T>
void TestLargeInt<T>::TearDown()
{
    // Code here will be called just after the test completes
    typedata = (T)0;
    largeIint = typedata;
}

template <typename T>
TestLargeInt<T>::~TestLargeInt()
{
}

/// Explicit instantiation of template class
template class TestLargeInt<char>;
template class TestLargeInt<short int>;
template class TestLargeInt<int>;
template class TestLargeInt<long int>;
template class TestLargeInt<long long int>;

} // namespace testing
} // namespace li
} // namespace ds
} // namespace ns
