#include "binomial_mod.h"

#include "gtest/gtest.h"

#include "binomial.h"

TEST(Binomial, Modp) {
    for (int i = 5; i < 30; i += 4) {
        for (int j = 5; j <= i; j += 4) {
            for (int p : {2, 3, 5, 7, 13}) {
                ASSERT_EQ(binomial(i, j) % p, binomial_modp(i, j, p));
            }
        }
    }
}

TEST(Binomial, Mod) {
    for (int i = 5; i < 30; i += 4) {
        for (int j = 5; j <= i; j += 4) {
            for (int m : {6, 15, 35, 70, 770}) {
                ASSERT_EQ(binomial(i, j) % m, binomial_mod(i, j, m))
                    << "i: " << i << " j: " << j << " m: " << m << " bin: " << binomial(i, j);
            }
        }
    }
}

TEST(Binomial, Death) {
    ::testing::FLAGS_gtest_death_test_style = "threadsafe";
    EXPECT_DEATH(binomial_mod(8, 4, 4),
                 "Invalid number, numbers containing prime powers not supported.");
}
