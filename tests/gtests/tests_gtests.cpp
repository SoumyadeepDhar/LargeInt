/*
 * tests_gtests.cpp
 *
 *  Created on: 03-Apr-2019
 *  Modified on: 30-Mar-2021
 *  Author: Soumyadeep Dhar
 */

#include "gtest/gtest.h"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
