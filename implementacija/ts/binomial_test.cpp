#include "binomial.h"

#include "gtest/gtest.h"

TEST(Binomial, Small) {
    EXPECT_EQ(1, binomial(1, 0));
    EXPECT_EQ(1, binomial(2, 0));
    EXPECT_EQ(1, binomial(3, 0));
    EXPECT_EQ(1, binomial(4, 0));
    EXPECT_EQ(1, binomial(5, 0));
    EXPECT_EQ(1, binomial(6, 0));
    EXPECT_EQ(0, binomial(0, 1));
    EXPECT_EQ(1, binomial(1, 1));
    EXPECT_EQ(2, binomial(2, 1));
    EXPECT_EQ(3, binomial(3, 1));
    EXPECT_EQ(4, binomial(4, 1));
    EXPECT_EQ(5, binomial(5, 1));
    EXPECT_EQ(6, binomial(6, 1));
    EXPECT_EQ(0, binomial(0, 2));
    EXPECT_EQ(0, binomial(1, 2));
    EXPECT_EQ(1, binomial(2, 2));
    EXPECT_EQ(3, binomial(3, 2));
    EXPECT_EQ(6, binomial(4, 2));
    EXPECT_EQ(10, binomial(5, 2));
    EXPECT_EQ(15, binomial(6, 2));
    EXPECT_EQ(0, binomial(0, 3));
    EXPECT_EQ(0, binomial(1, 3));
    EXPECT_EQ(0, binomial(2, 3));
    EXPECT_EQ(1, binomial(3, 3));
    EXPECT_EQ(4, binomial(4, 3));
    EXPECT_EQ(10, binomial(5, 3));
    EXPECT_EQ(20, binomial(6, 3));
    EXPECT_EQ(0, binomial(0, 4));
    EXPECT_EQ(0, binomial(1, 4));
    EXPECT_EQ(0, binomial(2, 4));
    EXPECT_EQ(0, binomial(3, 4));
    EXPECT_EQ(1, binomial(4, 4));
    EXPECT_EQ(5, binomial(5, 4));
    EXPECT_EQ(15, binomial(6, 4));
    EXPECT_EQ(0, binomial(0, 5));
    EXPECT_EQ(0, binomial(1, 5));
    EXPECT_EQ(0, binomial(2, 5));
    EXPECT_EQ(0, binomial(3, 5));
    EXPECT_EQ(0, binomial(4, 5));
    EXPECT_EQ(1, binomial(5, 5));
    EXPECT_EQ(6, binomial(6, 5));
    EXPECT_EQ(0, binomial(0, 6));
    EXPECT_EQ(0, binomial(1, 6));
    EXPECT_EQ(0, binomial(2, 6));
    EXPECT_EQ(0, binomial(3, 6));
    EXPECT_EQ(0, binomial(4, 6));
    EXPECT_EQ(0, binomial(5, 6));
    EXPECT_EQ(1, binomial(6, 6));
}

TEST(Binomial, Negative) {
    EXPECT_EQ(0, binomial(-1, -2));
    EXPECT_EQ(0, binomial(-1, 2));
    EXPECT_EQ(0, binomial(1, -2));
}

TEST(Binomial, Approx) {
    EXPECT_DOUBLE_EQ(1, binomial_approx(1, 0));
    EXPECT_DOUBLE_EQ(1, binomial_approx(2, 0));
    EXPECT_DOUBLE_EQ(1, binomial_approx(3, 0));
    EXPECT_DOUBLE_EQ(1, binomial_approx(4, 0));
    EXPECT_DOUBLE_EQ(1, binomial_approx(5, 0));
    EXPECT_DOUBLE_EQ(1, binomial_approx(6, 0));
    EXPECT_DOUBLE_EQ(0, binomial_approx(0, 1));
    EXPECT_DOUBLE_EQ(1, binomial_approx(1, 1));
    EXPECT_DOUBLE_EQ(2, binomial_approx(2, 1));
    EXPECT_DOUBLE_EQ(3, binomial_approx(3, 1));
    EXPECT_DOUBLE_EQ(4, binomial_approx(4, 1));
    EXPECT_DOUBLE_EQ(5, binomial_approx(5, 1));
    EXPECT_DOUBLE_EQ(6, binomial_approx(6, 1));
    EXPECT_DOUBLE_EQ(0, binomial_approx(0, 2));
    EXPECT_DOUBLE_EQ(0, binomial_approx(1, 2));
    EXPECT_DOUBLE_EQ(1, binomial_approx(2, 2));
    EXPECT_DOUBLE_EQ(3, binomial_approx(3, 2));
    EXPECT_DOUBLE_EQ(6, binomial_approx(4, 2));
    EXPECT_DOUBLE_EQ(10, binomial_approx(5, 2));
    EXPECT_DOUBLE_EQ(15, binomial_approx(6, 2));
    EXPECT_DOUBLE_EQ(0, binomial_approx(0, 3));
    EXPECT_DOUBLE_EQ(0, binomial_approx(1, 3));
    EXPECT_DOUBLE_EQ(0, binomial_approx(2, 3));
    EXPECT_DOUBLE_EQ(1, binomial_approx(3, 3));
    EXPECT_DOUBLE_EQ(4, binomial_approx(4, 3));
    EXPECT_DOUBLE_EQ(10, binomial_approx(5, 3));
    EXPECT_DOUBLE_EQ(20, binomial_approx(6, 3));
    EXPECT_DOUBLE_EQ(0, binomial_approx(0, 4));
    EXPECT_DOUBLE_EQ(0, binomial_approx(1, 4));
    EXPECT_DOUBLE_EQ(0, binomial_approx(2, 4));
    EXPECT_DOUBLE_EQ(0, binomial_approx(3, 4));
    EXPECT_DOUBLE_EQ(1, binomial_approx(4, 4));
    EXPECT_DOUBLE_EQ(5, binomial_approx(5, 4));
    EXPECT_DOUBLE_EQ(15, binomial_approx(6, 4));
    EXPECT_DOUBLE_EQ(0, binomial_approx(0, 5));
    EXPECT_DOUBLE_EQ(0, binomial_approx(1, 5));
    EXPECT_DOUBLE_EQ(0, binomial_approx(2, 5));
    EXPECT_DOUBLE_EQ(0, binomial_approx(3, 5));
    EXPECT_DOUBLE_EQ(0, binomial_approx(4, 5));
    EXPECT_DOUBLE_EQ(1, binomial_approx(5, 5));
    EXPECT_DOUBLE_EQ(6, binomial_approx(6, 5));
    EXPECT_DOUBLE_EQ(0, binomial_approx(0, 6));
    EXPECT_DOUBLE_EQ(0, binomial_approx(1, 6));
    EXPECT_DOUBLE_EQ(0, binomial_approx(2, 6));
    EXPECT_DOUBLE_EQ(0, binomial_approx(3, 6));
    EXPECT_DOUBLE_EQ(0, binomial_approx(4, 6));
    EXPECT_DOUBLE_EQ(0, binomial_approx(5, 6));
    EXPECT_DOUBLE_EQ(1, binomial_approx(6, 6));
}

TEST(Binomial, PascalTriangle) {
    vector<vector<int>> expected = {
        {1, 0, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {1, 2, 1, 0, 0},
        {1, 3, 3, 1, 0},
        {1, 4, 6, 4, 1}};
    EXPECT_EQ(expected, pascal_triangle(5));
}
