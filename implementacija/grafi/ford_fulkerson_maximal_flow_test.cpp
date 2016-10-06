#include "ford_fulkerson_maximal_flow.h"

#include "gtest/gtest.h"

TEST(MaxFlow, FordFulkerson) {
    vector<vector<int>> C = {
        { 0, 20, 10,  0},
        {20,  0,  5, 10},
        {10,  5,  0, 20},
        { 0, 10, 20,  0}};
    ASSERT_EQ(25, ford_fulkerson_maximal_flow(C, 0, 3));

    C = {{0, 0, 0, 0, 0, 0, 200000, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 200000, 0, 0, 0},
         {0, 0, 0, 200000, 200000, 0, 200000, 200000, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0, 0, 3},
         {0, 0, 0, 0, 0, 0, 0, 0, 0, 3},
         {0, 0, 0, 0, 0, 0, 0, 0, 0, 3},
         {0, 0, 0, 0, 0, 0, 0, 0, 0, 3},
         {0, 0, 0, 0, 0, 0, 0, 0, 0, 3},
         {5, 5, 5, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    ASSERT_EQ(8, ford_fulkerson_maximal_flow(C, 8, 9));
}
