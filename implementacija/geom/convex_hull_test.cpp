#include "convex_hull.h"

#include "gtest/gtest.h"

typedef complex<double> P;

TEST(ConvexHull, ConvexHull) {
    vector<P> points = {{0, 0}};
    vector<P> result = convex_hull(points);
    vector<P> expected;
    ASSERT_EQ(points, result);

    points = {{0, 0}, {1, 1}};
    result = convex_hull(points);
    ASSERT_EQ(points, result);

    points = {{0, 0}, {1, 1}, {2, 2}};
    result = convex_hull(points);
    expected = {{0, 0}, {2, 2}};
    ASSERT_EQ(expected, result);

    points = {{0, 0}, {1, 1}, {2, 2}, {3, 3}};
    result = convex_hull(points);
    expected = {{0, 0}, {3, 3}};
    ASSERT_EQ(expected, result);

    points = {{0, 0}, {1, -1}, {2, -2}, {3, -3}};
    result = convex_hull(points);
    expected = {{3, -3}, {0, 0}};
    ASSERT_EQ(expected, result);

    points = {{0, 0}, {0, 2}, {2, 0}, {1, 1}};
    result = convex_hull(points);
    expected = {{0, 0}, {2, 0}, {0, 2}};
    ASSERT_EQ(expected, result);

    points = {{0, 0}, {0, 2}, {2, 0}, {2, 2}};
    result = convex_hull(points);
    expected = {{0, 0}, {2, 0}, {2, 2}, {0, 2}};
    ASSERT_EQ(expected, result);

    points = {{0, 0}, {0, 2}, {2, 0}, {2, 2}, {1, 0}, {1, 1}, {2, 0},
              {2, 1}, {1, 2}, {1, 0}, {0, 0}, {0, 1}, {0, 2}};
    result = convex_hull(points);
    expected = {{0, 0}, {2, 0}, {2, 2}, {0, 2}};
    ASSERT_EQ(expected, result);

    points = {{0, 0}, {0, 2}, {2, 0}, {2, 2}, {1, 0}, {1, 1}, {2, 0},
              {2, 1}, {1, 2}, {1, 0}, {0, 0}, {0, 1}, {0, 2}, {-1, -1}};
    result = convex_hull(points);
    expected = {{-1, -1}, {2, 0}, {2, 2}, {0, 2}};
    ASSERT_EQ(expected, result);

    points = {{0, 0}, {0, 2}, {0, 4}, {0, 5}};
    result = convex_hull(points);
    expected = {{0, 0}, {0, 5}};
    ASSERT_EQ(expected, result);

    points = {{0, 0}, {2, 0}, {4, 0}, {5, 0}};
    result = convex_hull(points);
    expected = {{0, 0}, {5, 0}};
    ASSERT_EQ(expected, result);
}
