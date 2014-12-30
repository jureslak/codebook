#include "strongly_connected_components.h"

#include "gtest/gtest.h"

TEST(StronglyConnectedComponentsTest, DAG) {
    vector<vector<pair<int, int>>> G = {
        {{1, 1}, {2, 2}, {3, 3}}, {{2, 2}, {3, 3}}, {{3, 3}}, {}
    };
    vector<vector<int>> result_comps = {{3}, {2}, {1}, {0}};
    vector<map<int, int>> result_dag = {
        {}, {{0, 3}}, {{0, 3}, {1, 2}}, {{0, 3}, {1, 2}, {2, 1}}
    };  // result is isomorphic
    vector<vector<int>> comps;
    vector<map<int, int>> dag;
    strongly_connected_components(G, comps, dag);
    EXPECT_EQ(result_comps, comps);
    EXPECT_EQ(result_dag, dag);
}

TEST(StronglyConnectedComponentsTest, Complete) {
    vector<vector<pair<int, int>>> G = {
        {{1, 1}, {2, 2}}, {{0, 0}, {2, 2}}, {{0, 0}, {1, 1}}
    };
    vector<vector<int>> result_comps = {{2, 1, 0}};
    vector<map<int, int>> result_dag = {{}};
    vector<vector<int>> comps;
    vector<map<int, int>> dag;
    strongly_connected_components(G, comps, dag);
    EXPECT_EQ(result_comps, comps);
    EXPECT_EQ(result_dag, dag);
}

TEST(StronglyConnectedComponentsTest, Separated) {
    vector<vector<pair<int, int>>> G = {
        {{1, 1}}, {{0, 0}}, {}
    };
    vector<vector<int>> result_comps = {{1, 0}, {2}};
    vector<map<int, int>> result_dag = {{}, {}};
    vector<vector<int>> comps;
    vector<map<int, int>> dag;
    strongly_connected_components(G, comps, dag);
    EXPECT_EQ(result_comps, comps);
    EXPECT_EQ(result_dag, dag);
}

TEST(StronglyConnectedComponentsTest, TwoCycles) {
    vector<vector<pair<int, int>>> G = {
        {{1, 1}, {2, 1}}, {{0, 0}, {2, 2}}, {{3, 3}}, {{2, 2}}
    };
    vector<vector<int>> result_comps = {{3, 2}, {1, 0}};
    vector<map<int, int>> result_dag = {{}, {{0, 3}}};
    vector<vector<int>> comps;
    vector<map<int, int>> dag;
    strongly_connected_components(G, comps, dag);
    EXPECT_EQ(result_comps, comps);
    EXPECT_EQ(result_dag, dag);
}
