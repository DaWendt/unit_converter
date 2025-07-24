#include <gtest/gtest.h>
#include "../include/your_header.hpp"

int add(int a, int b) {
    return a + b;
}

TEST(MathTest, Addition) {
    EXPECT_EQ(add(2, 2), 4);
}
