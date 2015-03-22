#include "edmonds_karp_maximal_flow.h"

#include "gtest/gtest.h"

TEST(MaxFlow, EdmondsKarp) {
    vector<vector<int>> C = {
        { 0, 20, 10,  0},
        {20,  0,  5, 10},
        {10,  5,  0, 20},
        { 0, 10, 20,  0}};
    ASSERT_EQ(25, edmonds_karp_maximal_flow(C, 0, 3));
}
