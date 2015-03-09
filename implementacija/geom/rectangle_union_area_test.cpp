#include "rectangle_union_area.h"

#include "gtest/gtest.h"

#include <utility>

using std::pair;

typedef complex<int> P;

TEST(RectangleUnionArea, RectangleUnionArea) {
    vector<pair<P, P>> p = {{{0, 0}, {2, 2}}, {{0, 0}, {0, 0}}};
    vector<vector<int>> r = {
        {8, 8, 8, 8, 8},
        {8, 7, 6, 7, 8},
        {8, 6, 4, 6, 8},
        {8, 7, 6, 7, 8},
        {8, 8, 8, 8, 8}};
    for (int i = -2; i <= 2; ++i) {
        for (int j = -2; j <= 2; ++j) {
            p[1] = {{i, j}, {i+2, j+2}};
            ASSERT_EQ(r[i+2][j+2], rectangle_union_area(p)) << p[1].first;
        }
    }

    p = {{{0, 0}, {2, 2}}, {{0, 0}, {0, 0}}};
    ASSERT_EQ(4, rectangle_union_area(p));

    p = {{{0, 0}, {2, 2}}, {{0, 0}, {0, 2}}};
    ASSERT_EQ(4, rectangle_union_area(p));

    p = {{{0, 0}, {0, 2}}, {{2, 0}, {2, 2}}};
    ASSERT_EQ(0, rectangle_union_area(p));

    p = {{{-1, -2}, {-1+2, -1+6}},  // sample case kolaž brez rezanja
         {{-2,  2}, {-2+8,  2+1}},
         {{ 5,  0}, { 5+1,  0+1}},
         {{ 5,  2}, { 5+2,  2+2}},
         {{ 5,  5}, { 5+3,  5+4}},
         {{ 0,  5}, { 0+6,  5+1}},
         {{ 2,  1}, { 2+2,  1+7}}};
    ASSERT_EQ(51, rectangle_union_area(p));
}
