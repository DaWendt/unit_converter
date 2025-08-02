//
// Created by Daniel Wendt on 02.08.25.
//

#include "common/TestHelpers.h"
#include <gtest/gtest.h>

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