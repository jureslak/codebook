#include "articulation_points_and_bridges.h"

#include "gtest/gtest.h"

#include <algorithm>


TEST(ArticulationPointsAndBridgesTest, Tree) {
    // E is sorted
    const int E[][2] = {{0, 1}, {1, 2}, {1, 3}, {2, 4}, {2, 5}, {3, 6}, {5, 7}};
    int n = 8, m = 7;
    vector<int> articulation_points;
    vector<pair<int, int>> bridges;
    articulation_points_and_bridges(n, m, E, articulation_points, bridges);

    vector<int> expected = {1, 2, 3, 5};
    ASSERT_EQ(expected, articulation_points);

    std::sort(bridges.begin(), bridges.end());

    ASSERT_EQ(bridges.size(), m);
    for (int i = 0; i < m; ++i) {
        ASSERT_EQ(E[i][0], bridges[i].first);
        ASSERT_EQ(E[i][1], bridges[i].second);
    }
}

TEST(ArticulationPointsAndBridgesTest, Cycle) {
    // E is sorted
    const int E[][2] = {{0, 1}, {1, 2}, {2, 0}};
    int n = 3, m = 3;
    vector<int> articulation_points;
    vector<pair<int, int>> bridges;
    articulation_points_and_bridges(n, m, E, articulation_points, bridges);

    ASSERT_EQ(0, articulation_points.size());
    ASSERT_EQ(0, bridges.size());
}

TEST(ArticulationPointsAndBridgesTest, RootCase) {
    // E is sorted
    const int E[][2] = {{0, 1}, {0, 2}, {0, 3}};
    int n = 4, m = 3;
    vector<int> articulation_points;
    vector<pair<int, int>> bridges;
    articulation_points_and_bridges(n, m, E, articulation_points, bridges);

    ASSERT_EQ(1, articulation_points.size());
    EXPECT_EQ(0, articulation_points[0]);
    ASSERT_EQ(bridges.size(), m);
    for (int i = 0; i < m; ++i) {
        ASSERT_EQ(E[i][0], bridges[i].first);
        ASSERT_EQ(E[i][1], bridges[i].second);
    }
}

TEST(ArticulationPointsAndBridgesTest, General) {
    const int E[][2] = {{0, 1}, {1, 2}, {1, 3}, {1, 4}, {1, 6}, {2, 0}, {3, 5}, {4, 5}};
    int n = 7, m = 8;
    vector<int> articulation_points;
    vector<pair<int, int>> bridges;
    articulation_points_and_bridges(n, m, E, articulation_points, bridges);

    ASSERT_EQ(1, articulation_points.size());
    EXPECT_EQ(1, articulation_points[0]);

    ASSERT_EQ(bridges.size(), 1);
    EXPECT_EQ(std::make_pair(1, 6), bridges[0]);
}
