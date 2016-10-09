#include "all_pairs_widest_path.h"

#include "gtest/gtest.h"

TEST(AllPairsWidestPath, Works) {
    vector<vector<pair<int, int>>> graf = {
        /* 0: */ {{1, 1}, {2, 9}},
        /* 1: */ {{7, 9}, {1, 10}},
        /* 2: */ {{3, 6}, {5, 10}},
        /* 3: */ {{0, 3}},
        /* 4: */ {{8, 1}},
        /* 5: */ {{0, 5}},
        /* 6: */ {},
        /* 7: */ {},
        /* 8: */ {},
        /* 9: */ {{6, 4}}};

    vector<vector<int>> expected =
        {{0, 1, 9, 6, 0, 9, 0, 1, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 9, 0, 0},
         {5, 1, 0, 6, 0, 10, 0, 1, 0, 0},
         {3, 1, 3, 0, 0, 3, 0, 1, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
         {5, 1, 5, 5, 0, 0, 0, 1, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 4, 0, 0, 0}};

    vector<vector<int>> result = all_pairs_widest_path(graf);
    EXPECT_EQ(expected, result);
}
