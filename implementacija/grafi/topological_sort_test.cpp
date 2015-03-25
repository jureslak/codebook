#include "topological_sort.h"

#include "gtest/gtest.h"

#include <algorithm>

TEST(TopologicalSortTest, Linear) {
    vector<vector<int>> graf = {{1}, {2}, {4}, {}, {3}};
    vector<int> expect({0, 1, 2, 4, 3});
    EXPECT_EQ(expect, topological_sort(graf));
}

TEST(TopologicalSortTest, Arbitrary) {
    vector<vector<int>> graf = {{}, {}, {}, {}};
    vector<int> expect({0, 1, 2, 3});
    vector<int> result = topological_sort(graf);
    std::sort(result.begin(), result.end());
    EXPECT_EQ(expect, result);
}

TEST(TopologicalSortTest, Correct) {
    vector<vector<int>> graf = {{1, 2, 3}, {4}, {}, {}, {2}};
    vector<int> expect({0, 1, 3, 4, 2});
    EXPECT_EQ(expect, topological_sort(graf));
}

TEST(TopologicalSortTest, DetectsCycle) {
    vector<vector<int>> graf = {{1}, {2}, {0}};
    EXPECT_LT(topological_sort(graf).size(), 3);
}
