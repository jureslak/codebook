#include "euler_phi.h"

#include "gtest/gtest.h"

#include "implementacija/ts/gcd.h"

TEST(EulerPhiTest, AllSmall) {
    for (int i = 0; i < 100; ++i) {
        int f = 0;
        for (int j = 1; j <= i; ++j) {
            if (gcd(i, j) == 1) f++;
        }
        ASSERT_EQ(f, euler_phi(i)) << "with i = " << i;
    }
}
