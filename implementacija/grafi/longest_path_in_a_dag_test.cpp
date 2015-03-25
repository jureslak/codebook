#include "longest_path_in_a_dag.h"

#include "gtest/gtest.h"

TEST(LongestPath, DAG) {
    vector<vector<pair<int, int>>> graf = {{{1, 1}, {2, 7}, {3, 2}}, {{4, 1}},
        {{3, 9}, {5, 1}}, {{1, 4}, {4, 5}, {5, 3}, {6, 2}}, {{6, 1}}, {{6, 8}}, {}};
    ASSERT_EQ(27, longest_path_in_a_dag(graf, 0, 6));
}
