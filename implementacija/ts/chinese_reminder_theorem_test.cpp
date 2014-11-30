#include "chinese_reminder_theorem.h"

#include "gtest/gtest.h"
#include "implementacija/ts/gcd.h"

#include <vector>
#include <utility>

using std::vector;
using std::pair;

TEST(MulInverseTest, WorksSmall) {
    for (int m = 2; m < 100; ++m) {
        for (int a = -100; a < 100; ++a) {
            if (gcd(a, m) == 1) {
                int ia = mul_inverse(a, m);
                ASSERT_EQ(1, ((a * ia) % m + m) % m);
            }
        }
    }
}

TEST(MulInverseTest, WorksLarge) {
    for (int m = 19500; m < 10000; ++m) {
        for (int a = 19000; a < 20000; ++a) {
            if (gcd(a, m) == 1) {
                int ia = mul_inverse(a, m);
                ASSERT_EQ(1, ((a * ia) % m + m) % m);
            }
        }
    }
}

TEST(MulInverseTest, WorksLargeNegative) {
    for (int m = 19500; m < 10000; ++m) {
        for (int a = -20000; a < -19000; ++a) {
            if (gcd(a, m) == 1) {
                int ia = mul_inverse(a, m);
                ASSERT_EQ(1, ((a * ia) % m + m) % m);
            }
        }
    }
}

TEST(ChineseReminderTheoremTest, WorksSmall) {
    vector<int> m = {2, 3, 5, 7, 11};
    for (int x = 0; x < 2*3*5*7*11; ++x) {
        vector<pair<int, int>> cong;
        for (int mi : m) cong.push_back({x % mi, mi});
        ASSERT_EQ(x, chinese_reminder_theorem(cong));
    }
}

TEST(ChineseReminderTheoremTest, WorksLargeish) {
    vector<int> m = {41, 43, 61, 113};
    int M = 1; for (int i : m) M *= i;
    for (int x = 10000; x < 20000; ++x) {
        vector<pair<int, int>> cong;
        for (int mi : m) cong.push_back({x % mi, mi});
        ASSERT_EQ(x % M, chinese_reminder_theorem(cong));
    }
}

TEST(ChineseReminderTheoremTest, WorksLargeishNegative) {
    vector<int> m = {73, 61, 11, 131};
    int M = 1; for (int i : m) M *= i;
    for (int x = -20000; x < -10000; ++x) {
        vector<pair<int, int>> cong;
        for (int mi : m) cong.push_back({x % mi, mi});
        ASSERT_EQ((x % M + M) % M, chinese_reminder_theorem(cong));
    }
}
