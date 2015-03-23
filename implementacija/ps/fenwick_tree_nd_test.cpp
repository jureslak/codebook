#include "fenwick_tree_nd.h"

#include "gtest/gtest.h"

TEST(FenwickTest, FenwickTreeND) {
    int n = 3, m = 4, k = 5;
    vector<vector<vector<int>>> tree(n, vector<vector<int>>(m, vector<int>(k, 0)));
    ASSERT_EQ(0, subsum(0, 0, 0, 0, 0, 0, tree));
    inc(0, 0, 0, 1, tree);
    inc(0, 1, 0, 3, tree);
    ASSERT_EQ(1, subsum(0, 0, 0, 0, 0, 0, tree));
    ASSERT_EQ(4, subsum(0, 0, 0, 0, 1, 0, tree));
    inc(0, 1, 0, -2, tree);
    ASSERT_EQ(2, subsum(0, 0, 0, 1, 1, 1, tree));
    inc(1, 1, 1, -2, tree);
    ASSERT_EQ(-2, subsum(1, 1, 1, 1, 1, 1, tree));
}
