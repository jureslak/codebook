#include "longest_increasing_subsequence.h"

#include "gtest/gtest.h"

TEST(Dinamicno, LIS) {
    vector<int> a = {};
    vector<int> expected = {};
    ASSERT_EQ(expected, longest_increasing_subsequence(a));
    ASSERT_EQ(expected, longest_increasing_subsequence_square(a));
    a = { 1, 9, 3, 8, 11, 4, 5, 6, 4, 19, 7, 1, 8 };
    expected = {1, 3, 4, 5, 6, 7, 8};
    ASSERT_EQ(expected, longest_increasing_subsequence(a));
    ASSERT_EQ(expected, longest_increasing_subsequence_square(a));
}
