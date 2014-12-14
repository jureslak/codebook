#include "fast_power.h"

#include "gtest/gtest.h"

#include <cmath>

TEST(FastPowerTest, WorksZero) {
    for (int i = 0; i < 5; ++i) {
        EXPECT_EQ(1, fast_power(i, 0));
    }
}

TEST(FastPowerTest, WorksPositive) {
    for (int g = 0; g < 9; ++g) {
        for (int n = 1; n < 9; ++n) {
            ASSERT_EQ(pow(g, n), fast_power(g, n));
        }
    }
}

TEST(FastPowerTest, WorskNegative) {
    for (int g = -9; g > 0; --g) {
        for (int n = 1; n < 9; ++n) {
            ASSERT_EQ(pow(g, n), fast_power(g, n));
        }
    }
}
