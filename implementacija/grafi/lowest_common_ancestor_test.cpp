#include "lowest_common_ancestor.h"

#include "gtest/gtest.h"

TEST(LCA, Level) {
    vector<int> tree = {0, 0, 1, 2};
    vector<int> expected = {0, 1, 2, 3};
    EXPECT_EQ(expected, levels(tree));

    tree = {1, 2, 3, 3};
    expected = {3, 2, 1, 0};
    EXPECT_EQ(expected, levels(tree));

    tree = {1, 5, 3, 1, 3, 5, 5, 3};
    expected = {2, 1, 3, 2, 3, 0, 1, 3};
    EXPECT_EQ(expected, levels(tree));
}

TEST(LCA, Preprocess) {
    vector<int> tree = {0, 0, 1, 2};
    vector<vector<int>> expected = {{0, 0}, {0, 0}, {1, 0}, {2, 1}};
    EXPECT_EQ(expected, preprocess(tree));

    tree = {1, 2, 3, 3};
    expected = {{1, 2}, {2, 3}, {3, 3}, {3, 3}};
    EXPECT_EQ(expected, preprocess(tree));

    tree = {1, 5, 3, 1, 3, 5, 5, 3};
    expected = {{1, 5, 5}, {5, 5, 5}, {3, 1, 5}, {1, 5, 5},
                {3, 1, 5}, {5, 5, 5}, {5, 5, 5}, {3, 1, 5}};
    EXPECT_EQ(expected, preprocess(tree));
}

TEST(LCA, LCA) {
    vector<int> tree = {0, 0, 1, 2};
    vector<vector<int>> p = preprocess(tree);
    vector<int> l = levels(tree);
    EXPECT_EQ(0, find_lca(tree, 0, 0, p, l));
    EXPECT_EQ(0, find_lca(tree, 0, 1, p, l));
    EXPECT_EQ(0, find_lca(tree, 0, 2, p, l));
    EXPECT_EQ(0, find_lca(tree, 0, 3, p, l));
    EXPECT_EQ(0, find_lca(tree, 1, 0, p, l));
    EXPECT_EQ(1, find_lca(tree, 1, 1, p, l));
    EXPECT_EQ(1, find_lca(tree, 1, 2, p, l));
    EXPECT_EQ(1, find_lca(tree, 1, 3, p, l));
    EXPECT_EQ(0, find_lca(tree, 2, 0, p, l));
    EXPECT_EQ(1, find_lca(tree, 2, 1, p, l));
    EXPECT_EQ(2, find_lca(tree, 2, 2, p, l));
    EXPECT_EQ(2, find_lca(tree, 2, 3, p, l));
    EXPECT_EQ(0, find_lca(tree, 3, 0, p, l));
    EXPECT_EQ(1, find_lca(tree, 3, 1, p, l));
    EXPECT_EQ(2, find_lca(tree, 3, 2, p, l));
    EXPECT_EQ(3, find_lca(tree, 3, 3, p, l));

    tree = {1, 2, 3, 3};
    p = preprocess(tree);
    l = levels(tree);
    EXPECT_EQ(0, find_lca(tree, 0, 0, p, l));
    EXPECT_EQ(1, find_lca(tree, 0, 1, p, l));
    EXPECT_EQ(2, find_lca(tree, 0, 2, p, l));
    EXPECT_EQ(3, find_lca(tree, 0, 3, p, l));
    EXPECT_EQ(1, find_lca(tree, 1, 0, p, l));
    EXPECT_EQ(1, find_lca(tree, 1, 1, p, l));
    EXPECT_EQ(2, find_lca(tree, 1, 2, p, l));
    EXPECT_EQ(3, find_lca(tree, 1, 3, p, l));
    EXPECT_EQ(2, find_lca(tree, 2, 0, p, l));
    EXPECT_EQ(2, find_lca(tree, 2, 1, p, l));
    EXPECT_EQ(2, find_lca(tree, 2, 2, p, l));
    EXPECT_EQ(3, find_lca(tree, 2, 3, p, l));
    EXPECT_EQ(3, find_lca(tree, 3, 0, p, l));
    EXPECT_EQ(3, find_lca(tree, 3, 1, p, l));
    EXPECT_EQ(3, find_lca(tree, 3, 2, p, l));
    EXPECT_EQ(3, find_lca(tree, 3, 3, p, l));

    tree = {1, 5, 3, 1, 3, 5, 5, 3, 3};
    p = preprocess(tree);
    l = levels(tree);
    EXPECT_EQ(0, find_lca(tree, 0, 0, p, l));
    EXPECT_EQ(1, find_lca(tree, 0, 1, p, l));
    EXPECT_EQ(1, find_lca(tree, 0, 2, p, l));
    EXPECT_EQ(5, find_lca(tree, 6, 3, p, l));
    EXPECT_EQ(3, find_lca(tree, 2, 4, p, l));
    EXPECT_EQ(5, find_lca(tree, 6, 5, p, l));
    EXPECT_EQ(1, find_lca(tree, 4, 1, p, l));
    EXPECT_EQ(1, find_lca(tree, 4, 1, p, l));
    EXPECT_EQ(3, find_lca(tree, 8, 7, p, l));
}
