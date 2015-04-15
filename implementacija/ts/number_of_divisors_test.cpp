#include "number_of_divisors.h"

#include "gtest/gtest.h"

TEST(NumbeOfDvisors, Works) {
    for (int n = 1; n < 1000; ++n) {
        int exp = 0;
        for (int i = 1; i <= n; ++i) exp += (n % i == 0);
        EXPECT_EQ(exp, number_of_divisors(n));
    }
}
