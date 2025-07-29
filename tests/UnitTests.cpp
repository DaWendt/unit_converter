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

// Helper function for rounding
double roundToTwoDigits(double input) {
    return std::round(input * 100.0) / 100;
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

// ========== MASS CONVERSION TESTS ==========

TEST_F(UnitConverterTest, KiloToPound) {
    auto result = convert(0.0, Unit::Kilogram, Unit::Pound);
    ASSERT_TRUE(result.has_value());
    ASSERT_TRUE(isApproximatelyEqual(*result, 0.0));

    result = convert(50.0, Unit::Kilogram, Unit::Pound);
    ASSERT_TRUE(result.has_value());
    ASSERT_TRUE(isApproximatelyEqual(*result, 110.23));

    result = convert(-10.0, Unit::Kilogram, Unit::Pound);
    ASSERT_TRUE(result.has_value());
    ASSERT_TRUE(isApproximatelyEqual(roundToTwoDigits(*result), -22.05));
}

TEST_F(UnitConverterTest, PoundToKilo) {
    auto result = convert(0.0, Unit::Pound, Unit::Kilogram);
    ASSERT_TRUE(result.has_value());
    ASSERT_TRUE(isApproximatelyEqual(*result, 0.0));

    result = convert(50.0, Unit::Pound, Unit::Kilogram);
    ASSERT_TRUE(result.has_value());
    ASSERT_TRUE(isApproximatelyEqual(roundToTwoDigits(*result), 22.68));

    result = convert(-10.0, Unit::Pound, Unit::Kilogram);
    ASSERT_TRUE(result.has_value());
    ASSERT_TRUE(isApproximatelyEqual(roundToTwoDigits(*result), -4.54));
}

TEST_F(UnitConverterTest, SameMassUnit) {
    auto result = convert(10.0, Unit::Kilogram, Unit::Kilogram);
    ASSERT_TRUE(result.has_value());
    ASSERT_TRUE(isApproximatelyEqual(*result, 10.0));

    result = convert(10.0, Unit::Pound, Unit::Pound);
    ASSERT_TRUE(result.has_value());
    ASSERT_TRUE(isApproximatelyEqual(*result, 10.0));
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

// ========== MAIN FUNCTION ==========

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}