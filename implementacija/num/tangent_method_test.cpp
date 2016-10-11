#include "tangent_method.h"

#include "gtest/gtest.h"

TEST(Numerics, Tangent) {
    double root = tangent_method(
        [](double x) { return x*x-7; },
        [](double x) { return 2*x; },
        3.0,
        1e-14,
        100);
    EXPECT_DOUBLE_EQ(std::sqrt(7), root);
}
