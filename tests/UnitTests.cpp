//
// Created by Daniel Wendt on 26.07.25.
//

#include "UnitTests.h"
//
// Created by Daniel Wendt on 26.07.25.
//

#include "../src/Units.h"
#include <cmath>
#include <gtest/gtest.h>

// Helper function for floating point comparison
bool isApproximatelyEqual(double a, double b, double epsilon = 1e-9) {
    return std::abs(a - b) < epsilon;
}

class UnitConverterTest : public ::testing::Test {
  protected:
    void SetUp() override {
        // Setup code if needed
    }

    void TearDown() override {
        // Cleanup code if needed
    }
};

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

TEST_F(UnitConverterTest, SameTemperatureUnit) {
    auto result = convert(25.0, Unit::Celsius, Unit::Celsius);
    ASSERT_TRUE(result.has_value());
    EXPECT_TRUE(isApproximatelyEqual(*result, 25.0));

    result = convert(77.0, Unit::Fahrenheit, Unit::Fahrenheit);
    ASSERT_TRUE(result.has_value());
    EXPECT_TRUE(isApproximatelyEqual(*result, 77.0));
}

// ========== LENGTH CONVERSION TESTS ==========

TEST_F(UnitConverterTest, MeterToKilometer) {
    auto result = convert(1000.0, Unit::Meter, Unit::Kilometer);
    ASSERT_TRUE(result.has_value());
    EXPECT_TRUE(isApproximatelyEqual(*result, 1.0));

    result = convert(2500.0, Unit::Meter, Unit::Kilometer);
    ASSERT_TRUE(result.has_value());
    EXPECT_TRUE(isApproximatelyEqual(*result, 2.5));
}

TEST_F(UnitConverterTest, KilometerToMeter) {
    auto result = convert(1.0, Unit::Kilometer, Unit::Meter);
    ASSERT_TRUE(result.has_value());
    EXPECT_TRUE(isApproximatelyEqual(*result, 1000.0));

    result = convert(0.5, Unit::Kilometer, Unit::Meter);
    ASSERT_TRUE(result.has_value());
    EXPECT_TRUE(isApproximatelyEqual(*result, 500.0));
}

TEST_F(UnitConverterTest, SameLengthUnit) {
    auto result = convert(42.0, Unit::Meter, Unit::Meter);
    ASSERT_TRUE(result.has_value());
    EXPECT_TRUE(isApproximatelyEqual(*result, 42.0));

    result = convert(3.14, Unit::Kilometer, Unit::Kilometer);
    ASSERT_TRUE(result.has_value());
    EXPECT_TRUE(isApproximatelyEqual(*result, 3.14));
}

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

// ========== PARAMETRIZED TESTS ==========

class TemperatureConversionTest : public ::testing::TestWithParam<std::tuple<double, double>> {};

TEST_P(TemperatureConversionTest, CelsiusToFahrenheitRoundTrip) {
    double celsius = std::get<0>(GetParam());
    double expected_fahrenheit = std::get<1>(GetParam());

    // Convert C to F
    auto result = convert(celsius, Unit::Celsius, Unit::Fahrenheit);
    ASSERT_TRUE(result.has_value());
    EXPECT_TRUE(isApproximatelyEqual(*result, expected_fahrenheit));

    // Convert back F to C
    auto back_result = convert(*result, Unit::Fahrenheit, Unit::Celsius);
    ASSERT_TRUE(back_result.has_value());
    EXPECT_TRUE(isApproximatelyEqual(*back_result, celsius));
}

INSTANTIATE_TEST_SUITE_P(TemperatureValues, TemperatureConversionTest,
                         ::testing::Values(std::make_tuple(0.0, 32.0),
                                           std::make_tuple(100.0, 212.0),
                                           std::make_tuple(-40.0, -40.0),
                                           std::make_tuple(37.0, 98.6),
                                           std::make_tuple(-273.15, -459.67) // Absolute zero
                                           ));

// ========== MAIN FUNCTION ==========

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}