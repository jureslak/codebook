#include "gauss.h"

#include "gtest/gtest.h"

TEST(Gauss, Simple) {
    vector<double> ans;
    vector<vector<double>> A = {{1, 2, 4}, {-2, 1, 1}};
    // x + 2y = 4
    // -2x + y = 1
    // ----------
    // x = 2/5, y = 9/5
    int num = gauss(A, ans);
    EXPECT_EQ(0, num);
    ASSERT_EQ(2, ans.size());
    EXPECT_DOUBLE_EQ(2. / 5., ans[0]);
    EXPECT_DOUBLE_EQ(9. / 5., ans[1]);
}

TEST(Gauss, Identity) {
    vector<double> ans;
    vector<vector<double>> A =
      {{1, 0, 0, 0, 0, 0, 2.3},
       {0, 1, 0, 0, 0, 0, -2.3},
       {0, 0, 1, 0, 0, 0, 1.7},
       {0, 0, 0, 1, 0, 0, 7.2},
       {0, 0, 0, 0, 1, 0, 2.8},
       {0, 0, 0, 0, 0, 1, -0.6}};
    int num = gauss(A, ans);
    EXPECT_EQ(0, num);
    ASSERT_EQ(6, ans.size());
    EXPECT_DOUBLE_EQ(2.3, ans[0]);
    EXPECT_DOUBLE_EQ(-2.3, ans[1]);
    EXPECT_DOUBLE_EQ(1.7, ans[2]);
    EXPECT_DOUBLE_EQ(7.2, ans[3]);
    EXPECT_DOUBLE_EQ(2.8, ans[4]);
    EXPECT_DOUBLE_EQ(-0.6, ans[5]);
}

TEST(Gauss, Random) {
    vector<double> ans;
    vector<vector<double>> A = {
        {82.4113, 73.9253, 18.9727, 15.4042, 7.40314, 95.3701, 91.0566},
        {72.8763, 37.3776, 47.5842, 1.37608, 63.5227, 0.647154, 82.8649},
        {47.4233, 85.9488, 28.5702, 25.6003, 14.2051, 29.2152, 70.8742},
        {57.7295, 60.7732, 80.4512, 14.1768, 99.9357, 19.7478, 20.3121},
        {4.33458, 28.8906, 49.3959, 11.1695, 60.2027, 65.8782, 36.3657},
        {47.7787, 18.2337, 26.9947, 31.3327, 97.7098, 60.3573, 42.7469}};
    int num = gauss(A, ans);
    EXPECT_EQ(0, num);
    ASSERT_EQ(6, ans.size());
    for (int i = 0; i < 6; ++i) {
        double sum = 0;
        for (int j = 0; j < 6; ++j) {
            sum += A[i][j] * ans[j];
        }
        EXPECT_NEAR(sum, A[i][6], 1e-9);
    }
}

TEST(Gauss, RandomTooManyEquations) {
    vector<double> ans;
    vector<vector<double>> A = {
        {82.4113, 73.9253, 18.9727, 15.4042, 7.40314, 95.3701, 91.0566},
        {82.4113, 73.9253, 18.9727, 15.4042, 7.40314, 95.3701, 91.0566},
        {82.4113, 73.9253, 18.9727, 15.4042, 7.40314, 95.3701, 91.0566},
        {82.4113, 73.9253, 18.9727, 15.4042, 7.40314, 95.3701, 91.0566},
        {72.8763, 37.3776, 47.5842, 1.37608, 63.5227, 0.647154, 82.8649},
        {72.8763, 37.3776, 47.5842, 1.37608, 63.5227, 0.647154, 82.8649},
        {72.8763, 37.3776, 47.5842, 1.37608, 63.5227, 0.647154, 82.8649},
        {47.4233, 85.9488, 28.5702, 25.6003, 14.2051, 29.2152, 70.8742},
        {57.7295, 60.7732, 80.4512, 14.1768, 99.9357, 19.7478, 20.3121},
        {4.33458, 28.8906, 49.3959, 11.1695, 60.2027, 65.8782, 36.3657},
        {47.7787, 18.2337, 26.9947, 31.3327, 97.7098, 60.3573, 42.7469}};
    int num = gauss(A, ans);
    EXPECT_EQ(0, num);
    ASSERT_EQ(6, ans.size());
    for (int i = 0; i < 6; ++i) {
        double sum = 0;
        for (int j = 0; j < 6; ++j) {
            sum += A[i][j] * ans[j];
        }
        EXPECT_NEAR(sum, A[i][6], 1e-9);
    }
}

TEST(Gauss, InfZero) {
    vector<double> ans;
    vector<vector<double>> A = {{0, 0, 0}, {0, 0, 0}};
    int num = gauss(A, ans);
    EXPECT_EQ(2, num);
}

TEST(Gauss, InfDependent) {
    vector<double> ans;
    vector<vector<double>> A = {{1, 2, 1}, {-2, -4, -2}};
    int num = gauss(A, ans);
    EXPECT_EQ(1, num);
}

TEST(Gauss, NoSolutionDependent) {
    vector<double> ans;
    vector<vector<double>> A = {{1, 2, 0}, {-2, -4, 3}};
    int num = gauss(A, ans);
    EXPECT_EQ(-1, num);
}

TEST(Gauss, NoSolutionZero) {
    vector<double> ans;
    vector<vector<double>> A = {{0, 0, 0}, {0, 0, 1}};
    int num = gauss(A, ans);
    EXPECT_EQ(-1, num);
}

TEST(Gauss, DetZero) {
    EXPECT_DOUBLE_EQ(0., det({{1, 0}, {1, 0}}));
    EXPECT_DOUBLE_EQ(0., det({{1, 0}, {-1, 0}}));
    EXPECT_DOUBLE_EQ(0., det({{1, 5}, {-2, -10}}));
    EXPECT_DOUBLE_EQ(0., det({{0, 0}, {0, 0}}));
}
TEST(Gauss, DetNonZero) {
    EXPECT_DOUBLE_EQ(1., det({{1, 0}, {0, 1}}));
    EXPECT_DOUBLE_EQ(-2., det({{1, 2}, {3, 4}}));
    EXPECT_DOUBLE_EQ(13951.26398565795, det({{46.4335, 29.2094, 69.5536},
                                             {77.4667, 54.7561, 83.2264},
                                             {34.0556, 23.5947, 89.0536}}));
}
