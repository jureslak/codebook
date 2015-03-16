#include "dijkstra_square.h"

#include "gtest/gtest.h"

TEST(SSSP, DijkstraSquare) {
    vector<vector<pair<int, int>>> graf = {{{1, 1}, {2, 7}, {3, 2}}, {{4, 1}},
        {{3, 9}, {5, 1}}, {{1, 4}, {4, 5}, {5, 3}, {6, 2}}, {{6, 1}}, {{6, 8}}, {}};
    vector<int> pot = {0, 1, 4, 6};
    ASSERT_EQ(pot, dijkstra_square(graf, 0, 6));
}
