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
  // Test char value positive
  ns::dn::li::testing::TestLargeInt<char> charValuePositive(INT8_MAX);
  charValuePositive.SetUp();
  charValuePositive.TearDown();

  // Test char value negetive
  ns::dn::li::testing::TestLargeInt<char> charValueNegetive(INT8_MIN);
  charValueNegetive.SetUp();
  charValueNegetive.TearDown();

  // Test short int value positive
  ns::dn::li::testing::TestLargeInt<short int> shortintValuePositive(INT16_MAX);
  shortintValuePositive.SetUp();
  shortintValuePositive.TearDown();

  // Test short int value negetive
  ns::dn::li::testing::TestLargeInt<short int> shortintValueNegetive(INT16_MIN);
  shortintValueNegetive.SetUp();
  shortintValueNegetive.TearDown();

  // Test int value positive
  ns::dn::li::testing::TestLargeInt<int> intValuePositive(INT32_MAX);
  intValuePositive.SetUp();
  intValuePositive.TearDown();

  // Test int value negetive
  ns::dn::li::testing::TestLargeInt<int> intValueNegetive(INT32_MIN);
  intValueNegetive.SetUp();
  intValueNegetive.TearDown();

  // Test long int value positive
  ns::dn::li::testing::TestLargeInt<long int> longintValuePositive(INT64_MAX);
  longintValuePositive.SetUp();
  longintValuePositive.TearDown();

  // Test long int value negetive
  ns::dn::li::testing::TestLargeInt<long int> longintValueNegetive(INT64_MIN);
  longintValueNegetive.SetUp();
  longintValueNegetive.TearDown();

  // Test long long int value positive
  ns::dn::li::testing::TestLargeInt<long long int> longlongintValuePositive(UINT64_MAX);
  longlongintValuePositive.SetUp();
  longlongintValuePositive.TearDown();

  // Test long long int value negetive
  ns::dn::li::testing::TestLargeInt<long long int> longlongintValueNegetive(INT64_MIN);
  longlongintValueNegetive.SetUp();
  longlongintValueNegetive.TearDown();

  // Test float value positive
  ns::dn::li::testing::TestLargeInt<float> floatValuePositive(FLT_MAX);
  floatValuePositive.SetUp();
  floatValuePositive.TearDown();

  // Test float value negetive
  ns::dn::li::testing::TestLargeInt<float> floatValueNegetive(FLT_MAX * -1.0);
  floatValueNegetive.SetUp();
  floatValueNegetive.TearDown();

  /** Tests are fine, to reduce checkin time are disabled 
  // Test double value positive
  ns::dn::li::testing::TestLargeInt<double> doubleValuePositive(DBL_MAX);
  doubleValuePositive.SetUp();
  doubleValuePositive.TearDown();

  // Test double value negetive
  ns::dn::li::testing::TestLargeInt<double> doubleValueNegetive(DBL_MAX * -1.0);
  doubleValueNegetive.SetUp();
  doubleValueNegetive.TearDown();

  // Test long double value positive
  ns::dn::li::testing::TestLargeInt<long double> longdoubleValuePositive(LDBL_MAX);
  longdoubleValuePositive.SetUp();
  longdoubleValuePositive.TearDown();

  // Test long double value negetive
  ns::dn::li::testing::TestLargeInt<long double> longdoubleValueNegetive(LDBL_MAX * -1.0);
  longdoubleValueNegetive.SetUp();
  longdoubleValueNegetive.TearDown();
  **/

  return 0;
}
