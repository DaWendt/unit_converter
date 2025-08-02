//
// Created by Daniel Wendt on 02.08.25.
//

#include "common/TestHelpers.h"
#include <gtest/gtest.h>

// ========== ERROR HANDLING TESTS ==========

TEST_F(UnitConverterTest, IncompatibleUnits) {
    // Temperature to Length should fail
    auto result = convert(25.0, Unit::Celsius, Unit::Meter);
    EXPECT_FALSE(result.has_value());

    // Length to Temperature should fail
    result = convert(100.0, Unit::Kilometer, Unit::Fahrenheit);
    EXPECT_FALSE(result.has_value());
}

TEST_F(UnitConverterTest, ZeroValues) {
    auto result = convert(0.0, Unit::Celsius, Unit::Fahrenheit);
    ASSERT_TRUE(result.has_value());
    EXPECT_TRUE(isApproximatelyEqual(*result, 32.0));

    result = convert(0.0, Unit::Meter, Unit::Kilometer);
    ASSERT_TRUE(result.has_value());
    EXPECT_TRUE(isApproximatelyEqual(*result, 0.0));
}

TEST_F(UnitConverterTest, NegativeValues) {
    auto result = convert(-10.0, Unit::Celsius, Unit::Fahrenheit);
    ASSERT_TRUE(result.has_value());
    EXPECT_TRUE(isApproximatelyEqual(*result, 14.0));

    result = convert(-500.0, Unit::Meter, Unit::Kilometer);
    ASSERT_TRUE(result.has_value());
    EXPECT_TRUE(isApproximatelyEqual(*result, -0.5));
}

// ========== EDGE CASE TESTS ==========

TEST_F(UnitConverterTest, VeryLargeValues) {
    auto result = convert(1000000.0, Unit::Meter, Unit::Kilometer);
    ASSERT_TRUE(result.has_value());
    EXPECT_TRUE(isApproximatelyEqual(*result, 1000.0));
}

TEST_F(UnitConverterTest, VerySmallValues) {
    auto result = convert(0.001, Unit::Kilometer, Unit::Meter);
    ASSERT_TRUE(result.has_value());
    EXPECT_TRUE(isApproximatelyEqual(*result, 1.0));
}
