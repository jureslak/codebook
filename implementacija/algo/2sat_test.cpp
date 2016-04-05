#include "2sat.h"

#include "gtest/gtest.h"

TEST(Solve2SAT, Var2node) {
    EXPECT_EQ(0, var2node(1, 4));
    EXPECT_EQ(1, var2node(2, 4));
    EXPECT_EQ(2, var2node(3, 4));
    EXPECT_EQ(3, var2node(4, 4));
    EXPECT_EQ(4, var2node(-1, 4));
    EXPECT_EQ(5, var2node(-2, 4));
    EXPECT_EQ(6, var2node(-3, 4));
    EXPECT_EQ(7, var2node(-4, 4));
}

TEST(Solve2SAT, Evaluate) {
    vector<pair<int, int>> formula = {{1, 2}, {2, 3}, {2, -3}, {2, -1}};
    EXPECT_TRUE(evaluate(formula, {0, 1, 0}));
    EXPECT_TRUE(evaluate(formula, {0, 1, 1}));
    EXPECT_TRUE(evaluate(formula, {1, 1, 0}));
    EXPECT_TRUE(evaluate(formula, {1, 1, 1}));
    EXPECT_FALSE(evaluate(formula, {0, 0, 0}));
    EXPECT_FALSE(evaluate(formula, {0, 0, 1}));
    EXPECT_FALSE(evaluate(formula, {1, 0, 0}));
    EXPECT_FALSE(evaluate(formula, {1, 0, 1}));
}

TEST(Solve2SAT, Works) {
    vector<pair<int, int>> formula;
    vector<int> solution;
    formula = {{1, 2}, {2, 3}, {2, -3}, {2, -1}};
    solution = solve_2sat(formula, 3);
    EXPECT_TRUE(evaluate(formula, solution));
    formula = {{1, 1}, {-2, -1}, {-3, -1}};
    solution = solve_2sat(formula, 3);
    EXPECT_EQ(vector<int>({1, 0, 0}), solution);
    EXPECT_TRUE(evaluate(formula, solution));
    formula = {{1, 1}, {2, 2}, {3, 3}, {4, 4}};
    solution = solve_2sat(formula, 4);
    EXPECT_TRUE(evaluate(formula, solution));
    formula = {{1, 1}, {2, 2}, {2, 2}, {4, 4}, {3, 3}, {4, 4}};
    solution = solve_2sat(formula, 4);
    EXPECT_TRUE(evaluate(formula, solution));
    formula = {{1, 1}, {-1, -1}};
    solution = solve_2sat(formula, 1);
    EXPECT_EQ(vector<int>(1, -1), solution);
    formula = {{1, -2}, {2, -1}, {-3, 2}, {-3, -1}, {3, 3}, {-3, -1}};
    solution = solve_2sat(formula, 3);
    EXPECT_EQ(vector<int>(3, -1), solution);
}
