//
// Created by Daniel Wendt on 02.08.25.
//

#include "common/TestHelpers.h"
#include <gtest/gtest.h>

// ========== TEMPERATURE CONVERSION TESTS ==========

TEST_F(UnitConverterTest, CelsiusToFahrenheit) {
    auto result = convert(0.0, Unit::Celsius, Unit::Fahrenheit);
    ASSERT_TRUE(result.has_value());
    EXPECT_TRUE(isApproximatelyEqual(*result, 32.0));

    result = convert(100.0, Unit::Celsius, Unit::Fahrenheit);
    ASSERT_TRUE(result.has_value());
    EXPECT_TRUE(isApproximatelyEqual(*result, 212.0));

    result = convert(-40.0, Unit::Celsius, Unit::Fahrenheit);
    ASSERT_TRUE(result.has_value());
    EXPECT_TRUE(isApproximatelyEqual(*result, -40.0));
}

TEST_F(UnitConverterTest, FahrenheitToCelsius) {
    auto result = convert(32.0, Unit::Fahrenheit, Unit::Celsius);
    ASSERT_TRUE(result.has_value());
    EXPECT_TRUE(isApproximatelyEqual(*result, 0.0));

    result = convert(212.0, Unit::Fahrenheit, Unit::Celsius);
    ASSERT_TRUE(result.has_value());
    EXPECT_TRUE(isApproximatelyEqual(*result, 100.0));

    result = convert(-40.0, Unit::Fahrenheit, Unit::Celsius);
    ASSERT_TRUE(result.has_value());
    EXPECT_TRUE(isApproximatelyEqual(*result, -40.0));
}

TEST_F(UnitConverterTest, CelsiusToKelvin) {
    auto result = convert(-273.15, Unit::Celsius, Unit::Kelvin);
    ASSERT_TRUE(result.has_value());
    ASSERT_TRUE(isApproximatelyEqual(*result, 0.0));

    result = convert(200.0, Unit::Celsius, Unit::Kelvin);
    ASSERT_TRUE(result.has_value());
    ASSERT_TRUE(isApproximatelyEqual(*result, 473.15));

    result = convert(-400.0, Unit::Celsius, Unit::Kelvin);
    ASSERT_TRUE(result.has_value());
    ASSERT_TRUE(isApproximatelyEqual(*result, -126.85));
}

TEST_F(UnitConverterTest, KelvinToCelsius) {
    auto result = convert(273.15, Unit::Kelvin, Unit::Celsius);
    ASSERT_TRUE(result.has_value());
    ASSERT_TRUE(isApproximatelyEqual(*result, 0.0));

    result = convert(473.15, Unit::Kelvin, Unit::Celsius);
    ASSERT_TRUE(result.has_value());
    ASSERT_TRUE(isApproximatelyEqual(*result, 200.0));

    result = convert(-400.0, Unit::Kelvin, Unit::Celsius);
    ASSERT_TRUE(result.has_value());
    ASSERT_TRUE(isApproximatelyEqual(*result, -673.15));
}

TEST_F(UnitConverterTest, SameTemperatureUnit) {
    auto result = convert(25.0, Unit::Celsius, Unit::Celsius);
    ASSERT_TRUE(result.has_value());
    EXPECT_TRUE(isApproximatelyEqual(*result, 25.0));

    result = convert(77.0, Unit::Fahrenheit, Unit::Fahrenheit);
    ASSERT_TRUE(result.has_value());
    EXPECT_TRUE(isApproximatelyEqual(*result, 77.0));

    result = convert(25.0, Unit::Kelvin, Unit::Kelvin);
    ASSERT_TRUE(result.has_value());
    ASSERT_TRUE(isApproximatelyEqual(*result, 25.0));
}
