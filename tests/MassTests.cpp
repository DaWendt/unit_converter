//
// Created by Daniel Wendt on 02.08.25.
//

#include "common/TestHelpers.h"
#include <gtest/gtest.h>

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