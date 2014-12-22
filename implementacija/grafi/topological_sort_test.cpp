#include "topological_sort.h"

#include "gtest/gtest.h"

#include <algorithm>

TEST(TopologicalSortTest, Linear) {
    int E[][2] = {{0, 1}, {1, 2}, {2, 4}, {4, 3}};
    vector<int> expect({0, 1, 2, 4, 3});
    EXPECT_EQ(expect, topological_sort(5, 4, E));
}

TEST(TopologicalSortTest, Arbitrary) {
    int E[][2] = {};
    vector<int> expect({0, 1, 2, 3});
    vector<int> result = topological_sort(4, 0, E);
    std::sort(result.begin(), result.end());
    EXPECT_EQ(expect, result);
}

TEST(TopologicalSortTest, Correct) {
    int E[][2] = {{0, 1}, {0, 2}, {0, 3}, {2, 3}, {1, 4}, {4, 2}};
    vector<int> expect({0, 1, 4, 2, 3});
    EXPECT_EQ(expect, topological_sort(5, 6, E));
}

TEST(TopologicalSortTest, DetectsCycle) {
    int E[][2] = {{0, 1}, {1, 2}, {2, 0}};
    EXPECT_LT(topological_sort(3, 3, E).size(), 3);
}
