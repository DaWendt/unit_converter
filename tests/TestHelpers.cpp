//
// Created by Daniel Wendt on 02.08.25.
//

#include "common/TestHelpers.h"
#include <cmath>

// Helper function for floating point comparison
bool isApproximatelyEqual(double a, double b, double epsilon) {
    return std::abs(a - b) < epsilon;
}

// Helper function for rounding
double roundToTwoDigits(double input) {
    return std::round(input * 100.0) / 100;
}
