#include "bellman_ford.h"

#include "gtest/gtest.h"

namespace {
int INF = numeric_limits<int>::max();
}

TEST(SSSP, BellmanFord) {
    vector<vector<pair<int, int>>> graf;
    vector<int> dist;
    graf = {{{1, 1}, {2, 7}, {3, 2}}, {{4, 1}}, {{3, 9}}, {{1, 4}, {4, 5}, {6, -2}},
            {{6, 1}}, {{6, 8}}, {}};
    dist = {0, 1, 7, 2, 2, INF, 0};
    ASSERT_EQ(dist, bellman_ford(graf, 0));

    graf = {{{1, 1}, {2, 7}, {3, 2}}, {{4, 1}}, {{3, 9}}, {{1, 4}, {4, 5}},
            {{6, 1}}, {{6, 8}}, {{3, -6}}};  // zero cycle
    dist = {0, 1, 7, -3, 2, INF, 3};
    ASSERT_EQ(dist, bellman_ford(graf, 0));

    graf = {{{1, 1}, {2, 7}, {3, 2}}, {{4, 1}}, {{3, 9}}, {{1, 4}, {4, 5}},
            {{6, 1}}, {{6, 8}}, {{3, -7}}};  // negative cycle
    dist = {};
    ASSERT_EQ(dist, bellman_ford(graf, 0));
}
