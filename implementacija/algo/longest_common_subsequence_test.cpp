#include "longest_common_subsequence.h"

#include "gtest/gtest.h"

TEST(Dinamicno, LCS) {
    vector<int> a = {1,  2, 3, 4, 5,  6, 7};
    vector<int> b = {2, 10, 4, 6, 12, 7};
    vector<int> expected = {2, 4, 6, 7};
    ASSERT_EQ(expected, longest_common_subsequence(a, b));
    ASSERT_EQ(4, longest_common_subsequence_length(a, b));
    a = {};
    b = {1, 2, 3};
    expected = {};
    ASSERT_EQ(expected, longest_common_subsequence(a, b));
    ASSERT_EQ(0, longest_common_subsequence_length(a, b));
    ASSERT_EQ(expected, longest_common_subsequence(b, a));
    ASSERT_EQ(0, longest_common_subsequence_length(a, b));
    a = {1, 2, 4, 5};
    b = {1, 2, 5};
    ASSERT_EQ(b, longest_common_subsequence(a, b));
    ASSERT_EQ(3, longest_common_subsequence_length(a, b));
    ASSERT_EQ(b, longest_common_subsequence(b, a));
    ASSERT_EQ(3, longest_common_subsequence_length(a, b));
    a = {};
    b = {};
    ASSERT_EQ(a, longest_common_subsequence(a, b));
    ASSERT_EQ(0, longest_common_subsequence_length(a, b));
}
