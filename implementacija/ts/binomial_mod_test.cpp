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

// TODO(jureslak) test non prime
