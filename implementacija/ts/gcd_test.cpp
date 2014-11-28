#include "gcd.h"
#include "gtest/gtest.h"

TEST(GcdTest, Zero) {
    EXPECT_EQ(0,  gcd(0, 0));
    EXPECT_EQ(8,  gcd(8, 0));
    EXPECT_EQ(-9, gcd(0, -9));
}

TEST(GcdTest, Divisor) {
    EXPECT_EQ(3, gcd(6, 3));
    EXPECT_EQ(6, gcd(24, 6));
    EXPECT_EQ(1, gcd(-7, 1));
}

TEST(GcdTest, General) {
    EXPECT_EQ(3,  gcd(24, 15));
    EXPECT_EQ(12, gcd(144, 60));
    EXPECT_EQ(1,  gcd(81, 64));
}

TEST(GcdTest, Negative) {
    EXPECT_EQ(3,  abs(gcd(-24, 15)));
    EXPECT_EQ(12, abs(gcd(144, -60)));
    EXPECT_EQ(3,  abs(gcd(-81, -64*3)));
}
