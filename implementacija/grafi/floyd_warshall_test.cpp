#include "floyd_warshall.h"

#include "gtest/gtest.h"

namespace {
int INF = numeric_limits<int>::max();
}

TEST(SSSP, FloydWarshall) {
    vector<vector<int>> dist;

    int E[][3] = {{0, 1, 1}, {0, 3, 2}, {0, 2, 7}, {1, 4, 1}, {2, 3, 9},
        {2, 5, 1}, {3, 1, 4}, {3, 4, 5}, {3, 5, 3}, {3, 6, -2}, {4, 6, 1},
        {5, 6, 8}};

    dist = {{ 0 , 1  , 7  , 2  , 2  , 5  ,  0},
            {INF, 0  , INF, INF, 1  , INF,  2},
            {INF, 13 , 0  , 9  , 14 , 1  ,  7},
            {INF, 4  , INF, 0  , 5  , 3  , -2},
            {INF, INF, INF, INF, 0  , INF,  1},
            {INF, INF, INF, INF, INF, 0  ,  8},
            {INF, INF, INF, INF, INF, INF,  0}};

    ASSERT_EQ(dist, floyd_warshall(7, 12, E));
}
