#include "bipartite_matching.h"

#include "gtest/gtest.h"

TEST(Bipartite, MCBMandMVC) {
    vector<vector<int>> graph = {{5}, {3, 4, 6}, {5}, {1}, {1}, {0, 2}, {1}};
    vector<int> cover_result = {1, 5};
    ASSERT_EQ(2, bipartite_matching(graph, 3));
    ASSERT_EQ(cover_result, minimal_cover(graph, 3));
    graph = {{}, {}, {}, {}};
    cover_result = {};
    ASSERT_EQ(0, bipartite_matching(graph, 2));
    ASSERT_EQ(cover_result, minimal_cover(graph, 2));
    graph = {{5, 8, 9}, {5, 6}, {5}, {6, 7}, {9}, {0, 1, 2}, {1, 3}, {3}, {0}, {0, 4}};
    cover_result = {0, 1, 2, 3, 4};
    ASSERT_EQ(5, bipartite_matching(graph, 5));
    ASSERT_EQ(cover_result, minimal_cover(graph, 5));
}
