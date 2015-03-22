#include "kruskal_minimal_spanning_tree.h"

#include "gtest/gtest.h"

TEST(MST, Kruskal) {
    int E[][3] = {{0, 1, -1}, {0, 2, 1}, {0, 3, 2}, {1, 4, 8}, {1, 3, 3}, {2, 3, 3}, {2, 1, 2},
        {2, 5, 1}, {3, 4, 2}, {3, 6, 4}, {3, 5, 7}, {4, 6, 12}, {5, 6, 3}};
    ASSERT_EQ(8, kruskal_minimal_spanning_tree(7, (sizeof(E)) / sizeof(E[0]), E));
}
