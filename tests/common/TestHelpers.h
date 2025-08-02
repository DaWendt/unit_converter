//
// Created by Daniel Wendt on 02.08.25.
//

#ifndef TEST_HELPERS_H
#define TEST_HELPERS_H

#include "../src/Units.h"
#include <gtest/gtest.h>
#include <cmath>

// Shared helper functions
bool isApproximatelyEqual(double a, double b, double epsilon = 1e-9);
double roundToTwoDigits(double input);

// Base test class
class UnitConverterTest : public ::testing::Test {
  protected:
    void SetUp() override {}
    void TearDown() override {}
};

#endif
