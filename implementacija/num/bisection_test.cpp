#include "bisection.h"

#include "gtest/gtest.h"

TEST(Numerics, Bisection) {
    double root = bisection(
        [](double x) { return x*x-7; },
        0,
        7,
        1e-16);
    EXPECT_DOUBLE_EQ(std::sqrt(7), root);
}

TEST(Numerics, BisectionDecreasing) {
    double root = bisection(
        [](double x) { return -x*x+7; },
        0,
        7,
        1e-16);
    EXPECT_DOUBLE_EQ(std::sqrt(7), root);
}
