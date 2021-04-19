/*
 * main.cpp
 *
 *  Created on: 03-Apr-2019
 *  Modified on: 09-Mar-2021
 *  Author: Soumyadeep Dhar
 */

#include <bits/stdc++.h>
#include "ctests/tests_largeint.h"

int main()
{
  // Test int value positive
  ns::dn::li::testing::TestLargeInt<int> intValuePositive(INT8_MAX);
  intValuePositive.SetUp();
  intValuePositive.TearDown();

  // Test int value negetive
  ns::dn::li::testing::TestLargeInt<int> intValueNegetive(INT8_MIN);
  intValueNegetive.SetUp();
  intValueNegetive.TearDown();

  // Test short int value positive
  // ns::dn::li::testing::TestLargeInt<short int> shortintValuePositive(INT16_MIN);
  // shortintValuePositive.SetUp();
  // shortintValuePositive.TearDown();

  // Test short int value negetive
  // ns::dn::li::testing::TestLargeInt<short int> shortintValueNegetive(INT16_MIN);
  // shortintValueNegetive.SetUp();
  // shortintValueNegetive.TearDown();

  // Test long int value positive
  ns::dn::li::testing::TestLargeInt<long int> longintValuePositive(INT64_MAX);
  longintValuePositive.SetUp();
  longintValuePositive.TearDown();

  // Test long int value negetive
  ns::dn::li::testing::TestLargeInt<long int> longintValueNegetive(INT64_MIN);
  longintValueNegetive.SetUp();
  longintValueNegetive.TearDown();

  return 0;
}
