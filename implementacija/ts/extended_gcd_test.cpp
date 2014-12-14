#include "extended_gcd.h"

#include "gtest/gtest.h"

TEST(ExtGcdTest, AllSmallNumbers) {
    for (int i = -50; i < 50; ++i) {
        for (int j = -50; j < 50; ++j) {
            int x, y;
            int d = ext_gcd(i, j, x, y);
            ASSERT_EQ(d, i * x + j * y);
        }
    }
}

TEST(ExtGcdTest, LargePositive) {
    int offi = 123412, offj = 1672356;
    for (int i = -50; i < 50; ++i) {
        for (int j = -50; j < 50; ++j) {
            int x, y;
            int d = ext_gcd(i+offi, j+offj, x, y);
            ASSERT_EQ(d, (i+offi) * x + (j+offj) * y);
        }
    }
}

TEST(ExtGcdTest, LargeNegative) {
    int offi = -13412, offj = -172356;
    for (int i = -50; i < 50; ++i) {
        for (int j = -50; j < 50; ++j) {
            int x, y;
            int d = ext_gcd(i+offi, j+offj, x, y);
            ASSERT_EQ(d, (i+offi) * x + (j+offj) * y);
        }
    }
}
