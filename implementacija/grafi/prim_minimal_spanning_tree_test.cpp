#include "prim_minimal_spanning_tree.h"

#include "gtest/gtest.h"

TEST(MST, Prim) {
    vector<vector<pair<int, int>>> graf = {{{2, 1}, {1, 4}, {3, 3}}, {{0, 4}, {3, 6}, {5, 4}},
        {{0, 1}, {3, 2}, {4, 1}}, {{0, 3}, {1, 6}, {2, 2}, {4, 5}, {5, -2}, {6, -8}}, {{2, 1},
        {3, 5}, {6, 3}}, {{1, 4}, {3, -2}, {6, 4}}, {{5, 4}, {3, -8}, {4, 3}}};
    ASSERT_EQ(-2, prim_minimal_spanning_tree(graf));
}
