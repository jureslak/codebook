#include "maximum_subarray.h"

#include <algorithm>

using std::sort;
using std::reverse;

#include "gtest/gtest.h"

TEST(MaximumSubarray, Works) {
    vector<int> a = {1, 2, 3, 4, 5};
    vector<int> expected = a;
    EXPECT_EQ(15, maximum_subarray(a));
    EXPECT_EQ(a, maximum_subarray_extract(a));

    a = {-1, -2, -3, -4, -5};
    expected = {};
    EXPECT_EQ(0, maximum_subarray(a));
    EXPECT_EQ(expected, maximum_subarray_extract(a));

    a = {3, 4, -8, 6, -1, 9, -10, 6};
    expected = {6, -1, 9};
    EXPECT_EQ(14, maximum_subarray(a));
    EXPECT_EQ(expected, maximum_subarray_extract(a));

    a = {};
    EXPECT_EQ(0, maximum_subarray(a));
    EXPECT_EQ(a, maximum_subarray_extract(a));

    a = {1};
    EXPECT_EQ(1, maximum_subarray(a));
    EXPECT_EQ(a, maximum_subarray_extract(a));
}

TEST(MaximumSubarray, Kth) {
    vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, -1, -5, -3, -4, 5, -6, 3, -6, 9, -9, -1, 0, 8, 12, -34,
        123, 4, 33, -45, 0};
    int n = a.size();
    vector<int> subsums;
    for (int i = 0; i < n; ++i) {
        int sum = a[i];
        subsums.push_back(sum);
        for (int j = i+1; j < n; ++j) {
            sum += a[j];
            subsums.push_back(sum);
        }
    }

    sort(subsums.begin(), subsums.end());
    reverse(subsums.begin(), subsums.end());

    for (size_t k = 0; k < subsums.size(); ++k) {
        EXPECT_EQ(subsums[k], maximum_subarray(a, k+1));
    }
}
