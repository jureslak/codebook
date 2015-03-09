#include "basics.h"

#include "gtest/gtest.h"

#include <tuple>

using std::make_tuple;
using std::tuple;

typedef complex<double> P;
enum ITYPE : char { OK, NO, EQ };

TEST(GeomBasicsTest, DotProduct) {
    ASSERT_DOUBLE_EQ(7,   dot({1, 2}, {1, 3}));
    ASSERT_DOUBLE_EQ(0,   dot({-1, 4}, {8, 2}));
    ASSERT_DOUBLE_EQ(0,   dot({0, 0}, {-100, 5443}));
    ASSERT_DOUBLE_EQ(-29, dot({-2, 5}, {7, -3}));
}

TEST(GeomBasicsTest, CrossProduct) {
    ASSERT_DOUBLE_EQ(0, cross({1, 1}, {2, 2}));
    ASSERT_DOUBLE_EQ(1, cross({1, 0}, {0, 1}));
    ASSERT_DOUBLE_EQ(-1, cross({0, 1}, {1, 0}));
    ASSERT_DOUBLE_EQ(-13, cross({-2, 3}, {3, 2}));
}

TEST(GeomBasicsTest, CrossProduct3) {
    ASSERT_EQ(0,  cross({1, 1}, {2, 2}, {3, 3}));
    ASSERT_EQ(-1, cross({1, 0}, {0, 0}, {0, 1}));
    ASSERT_EQ(1,  cross({0, 1}, {0, 0}, {1, 0}));
    ASSERT_EQ(-3, cross({-2, -2}, {-1, -1}, {0, -3}));
}

TEST(GeomBasicsTest, LeftTurn) {
    ASSERT_FALSE(left_turn({1, 1}, {2, 2}, {3, 3}));
    ASSERT_FALSE(left_turn({1, 0}, {0, 0}, {0, 1}));
    ASSERT_TRUE(left_turn({0, 1}, {0, 0}, {1, 0}));
    ASSERT_FALSE(left_turn({-2, -2}, {-1, -1}, {0, -3}));
}

TEST(GeomBasicsTest, Perpendicular) {
    vector<P> c = {{1, 2}, {-3, 8}, {-5, 6}, {12, -49}};
    for (P v : c) {
        P p = perp(v);
        ASSERT_DOUBLE_EQ(0, dot(p, v));
        ASSERT_GT(cross(v, p), 0);
    }
    ASSERT_EQ(P(0, 0), perp({0, 0}));
}

TEST(GeomBasicsTest, SignTest) {
    ASSERT_EQ(0, sign(0));
    ASSERT_EQ(1, sign(54));
    ASSERT_EQ(-1, sign(-23.4));
}

TEST(GeomBasicsTest, PolarAngle) {
    ASSERT_EQ(-1, polar_angle({0, 0}));
    ASSERT_DOUBLE_EQ(0, polar_angle({5, 0}));
    ASSERT_DOUBLE_EQ(M_PI/2, polar_angle({0, 21}));
    ASSERT_DOUBLE_EQ(M_PI, polar_angle({-78, 0}));
    ASSERT_DOUBLE_EQ(7*M_PI/4, polar_angle({56, -56}));
}

TEST(AreaTest, Triangle) {
    ASSERT_DOUBLE_EQ(1, area({0, 0}, {1, 0}, {1, 2}));    // ostri
    ASSERT_DOUBLE_EQ(-1, area({0, 0}, {0, 1}, {2, 1}));
    ASSERT_DOUBLE_EQ(0.5, area({0, 0}, {1, 0}, {1, 1}));  // pravi
    ASSERT_DOUBLE_EQ(-0.5, area({0, 0}, {0, 1}, {1, 1}));
    ASSERT_DOUBLE_EQ(2, area({1, 1}, {3, 2}, {-1, 2}));   // topi
    ASSERT_DOUBLE_EQ(-2, area({1, 3}, {3, 2}, {-1, 2}));
    ASSERT_DOUBLE_EQ(0, area({1, 1}, {2, 2}, {-1, -1}));  // izrojeni
    ASSERT_DOUBLE_EQ(0, area({-1, -1}, {2, 2}, {9, 9}));
}

TEST(AreaTest, Polygon) {
    ASSERT_DOUBLE_EQ(-1, area({{0, 0}, {0, 1}, {1, 1}, {1, 0}}));  // neg square
    ASSERT_DOUBLE_EQ(1, area({{0, 0}, {1, 0}, {1, 1}, {0, 1}}));   // pos square
    ASSERT_DOUBLE_EQ(0, area({{0, 0}, {1, 1}, {1, 1}, {2, 2}}));   // line
    ASSERT_DOUBLE_EQ(0, area({{0, 0}, {2, 2}, {0, 2}, {2, 0}}));   // intersects
    ASSERT_DOUBLE_EQ(4, area({{0, 0}, {4, 0}, {0, 2}}));           // triangle
}

TEST(LineTest, LineStruct) {
    L line1(1, -1, -1);
    L line2({0, 1}, {1, 2});
    ASSERT_EQ(line1, line2);
    ASSERT_DOUBLE_EQ(0, line1.value({3, 4}));
    ASSERT_EQ(P(1, -1), line1.normal());

    line1 = L(1, 0, 1);
    ASSERT_EQ(0, line1.value({1, 443}));

    line1 = L(0, 1, -1);
    ASSERT_EQ(0, line1.value({-443, -1}));
}

TEST(DistTest, DistToLine) {
    ASSERT_EQ(0, dist_to_line({0, 0}, L({0, 0}, {1, 1})));
    ASSERT_EQ(0, dist_to_line({0, 0}, {0, 0}, {1, 1}));

    ASSERT_EQ(1, dist_to_line({0, 0}, L({1, 0}, {1, 1})));
    ASSERT_EQ(1, dist_to_line({0, 0}, {1, 0}, {1, 1}));

    ASSERT_EQ(1, dist_to_line({0, 0}, L({1, -1}, {2, -1})));
    ASSERT_EQ(1, dist_to_line({0, 0}, {1, -1}, {2, -1}));

    ASSERT_DOUBLE_EQ(sqrt(2)/2, dist_to_line({0, 0}, L({-1, 0}, {0, 1})));
    ASSERT_DOUBLE_EQ(sqrt(2)/2, dist_to_line({0, 0}, {-1, 0}, {0, 1}));
}

TEST(DistTest, DistToSegment) {
    ASSERT_DOUBLE_EQ(0,         dist_to_segment({ 0, 0}, {0, 0}, {2, 2}));
    ASSERT_DOUBLE_EQ(1,         dist_to_segment({-1, 0}, {0, 0}, {2, 2}));
    ASSERT_DOUBLE_EQ(1,         dist_to_segment({ 0,-1}, {0, 0}, {2, 2}));  // NOLINT(*)
    ASSERT_DOUBLE_EQ(sqrt(2),   dist_to_segment({-1,-1}, {0, 0}, {2, 2}));  // NOLINT(*)
    ASSERT_DOUBLE_EQ(sqrt(2)/2, dist_to_segment({ 0, 1}, {0, 0}, {2, 2}));
    ASSERT_DOUBLE_EQ(sqrt(2),   dist_to_segment({ 0, 2}, {0, 0}, {2, 2}));
    ASSERT_DOUBLE_EQ(sqrt(2),   dist_to_segment({ 1, 3}, {0, 0}, {2, 2}));
    ASSERT_DOUBLE_EQ(sqrt(2),   dist_to_segment({ 3, 3}, {0, 0}, {2, 2}));
    ASSERT_DOUBLE_EQ(1,         dist_to_segment({ 3, 2}, {0, 0}, {2, 2}));
    ASSERT_DOUBLE_EQ(sqrt(2)/2, dist_to_segment({ 2, 1}, {0, 0}, {2, 2}));
    ASSERT_DOUBLE_EQ(sqrt(2),   dist_to_segment({ 2, 0}, {0, 0}, {2, 2}));
    ASSERT_DOUBLE_EQ(sqrt(2)/2, dist_to_segment({ 1, 0}, {0, 0}, {2, 2}));
    ASSERT_DOUBLE_EQ(0,         dist_to_segment({ 1, 1}, {0, 0}, {2, 2}));
    ASSERT_DOUBLE_EQ(0,         dist_to_segment({ 2, 2}, {0, 0}, {2, 2}));
}

TEST(DistTest, GreatCircleDist) {
    double R = 6371.0;
    ASSERT_DOUBLE_EQ(M_PI*R,  great_circle_dist({0, 0}, {0, M_PI}));
    ASSERT_DOUBLE_EQ(M_PI*R,  great_circle_dist({0, 0}, {0, -M_PI}));
    ASSERT_DOUBLE_EQ(M_PI/2*R, great_circle_dist({0, 0}, {M_PI/2, 0}));
    ASSERT_DOUBLE_EQ(M_PI/2*R, great_circle_dist({0, 0}, {-M_PI/2, 0}));

    double s1 = 46.042300 / 180 * M_PI, d1 = 14.489936 / 180 * M_PI;
    double s2 = -32.653336 / 180 * M_PI, d2 = -70.010834 / 180 * M_PI;

    // FMF do Aconkagua (using Google)
    ASSERT_NEAR(12166, great_circle_dist({s1, d1}, {s2, d2}), 1);
}

TEST(ContainsTest, PointInRect) {
    int x = 2, y = 1;
    for (int signx = -1; signx <= 1; signx += 2) {
        for (int signy = -1; signy <= 1; signy += 2) {  // vse kombinacije dolocevalnih
            P p1(signx*x, signy*y), p2(-signx*x, -signy*y);  // tock
            for (int i = -x-1; i <= x + 1; ++i) {
                for (int j = -y-1; j <= y + 1; ++j) {  // vse tocke okrog pravokotnika
                    if (abs(i) == x + 1 || abs(j) == y + 1)  // cez rob
                        ASSERT_FALSE(point_in_rect(P(i, j), p1, p2));
                    else
                        ASSERT_TRUE(point_in_rect(P(i, j), p1, p2));
                }
            }
        }
    }
}

TEST(ContainsTest, PointInTriangle) {
    P a(0, 0), b(1, 0), c(0, 1);
    ASSERT_TRUE(point_in_triangle({0, 0},     a, b, c));
    ASSERT_TRUE(point_in_triangle({0, 1},     a, b, c));
    ASSERT_TRUE(point_in_triangle({1, 0},     a, b, c));
    ASSERT_TRUE(point_in_triangle({0.5, 0.5}, a, b, c));
    ASSERT_TRUE(point_in_triangle({0.2, 0.2}, a, b, c));
    // orientation swap
    ASSERT_TRUE(point_in_triangle({0, 0},     a, c, b));
    ASSERT_TRUE(point_in_triangle({0, 1},     a, c, b));
    ASSERT_TRUE(point_in_triangle({1, 0},     a, c, b));
    ASSERT_TRUE(point_in_triangle({0.5, 0.5}, a, c, b));
    ASSERT_TRUE(point_in_triangle({0.2, 0.2}, a, c, b));
    // outside
    ASSERT_FALSE(point_in_triangle({1, 1},     a, c, b));
    ASSERT_FALSE(point_in_triangle({2, 0},     a, c, b));
    ASSERT_FALSE(point_in_triangle({0, 2},     a, c, b));
    ASSERT_FALSE(point_in_triangle({-1, 0},    a, c, b));
    ASSERT_FALSE(point_in_triangle({0, -1},    a, c, b));
    // orientation swap
    ASSERT_FALSE(point_in_triangle({1, 1},     a, b, c));
    ASSERT_FALSE(point_in_triangle({2, 0},     a, b, c));
    ASSERT_FALSE(point_in_triangle({0, 2},     a, b, c));
    ASSERT_FALSE(point_in_triangle({-1, 0},    a, b, c));
    ASSERT_FALSE(point_in_triangle({0, -1},    a, b, c));
}

TEST(IntersectionTest, LineLine) {
    ITYPE tip;
    P p;
    tie(tip, p) = line_line_intersection(L({0, 0}, {1, 1}), L({0, 3}, {1, 4}));
    ASSERT_EQ(NO, tip);  // paralel
    tie(tip, p) = line_line_intersection(L({0, 0}, {0, 1}), L({3, 3}, {3, 4}));
    ASSERT_EQ(NO, tip);  // paralel
    tie(tip, p) = line_line_intersection(L({0, 0}, {1, 0}), L({3, 3}, {4, 3}));
    ASSERT_EQ(NO, tip);  // paralel
    tie(tip, p) = line_line_intersection(L({0, 0}, {1, 1}), L({3, 3}, {4, 4}));
    ASSERT_EQ(EQ, tip);  // equal
    tie(tip, p) = line_line_intersection(L({0, 0}, {0, 1}), L({0, 3}, {0, 4}));
    ASSERT_EQ(EQ, tip);  // equal
    tie(tip, p) = line_line_intersection(L({0, 0}, {1, 0}), L({3, 0}, {4, 0}));
    ASSERT_EQ(EQ, tip);  // equal
    tie(tip, p) = line_line_intersection(L({1, 1}, {2, 3}), L({3, 5}, {4, 7}));
    ASSERT_EQ(EQ, tip);  // equal
    tie(tip, p) = line_line_intersection(L({-1, 4}, {-2, 6}), L({3, -4}, {2, -2}));
    ASSERT_EQ(EQ, tip);  // equal
    tie(tip, p) = line_line_intersection(L({1, 4}, {1, 5}), L({1, -2}, {1, -6}));
    ASSERT_EQ(EQ, tip);  // equal
    tie(tip, p) = line_line_intersection(L({0, 0}, {1, 0}), L({1, 1}, {2, 2}));
    ASSERT_EQ(OK, tip);
    ASSERT_EQ(P(0, 0), p);
    tie(tip, p) = line_line_intersection(L({0, 0}, {0, 1}), L({1, 1}, {2, 2}));
    ASSERT_EQ(OK, tip);
    ASSERT_EQ(P(0, 0), p);
    tie(tip, p) = line_line_intersection(L({1, 0}, {0, 1}), L({1, 1}, {2, 2}));
    ASSERT_EQ(OK, tip);
    ASSERT_EQ(P(0.5, 0.5), p);
}

TEST(IntersectionTest, LineSegment) {
    ITYPE tip;
    P p;

    vector<P> points = {{0, 0}, {1, 0}, {1, 1}, {0, 1}, {-1, 1},
                        {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
    vector<P> second_line_points = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}};
    for (P& p2 : second_line_points) {  // point on edge
        L line({0, 0}, p2);
        for (P& t1 : points) {
            tie(tip, p) = line_segment_intersection(line, t1, {0, 0});
            if (t1 == p2 || t1 == -p2 || t1 == P(0, 0)) {
                ASSERT_EQ(EQ, tip);
            } else {
                ASSERT_EQ(OK, tip);
                ASSERT_EQ(P(0, 0), p);
            }
        }
        tie(tip, p) = line_segment_intersection(line, {1, 2}, {-1, -2});  // normal intersection
        ASSERT_EQ(OK, tip);
        ASSERT_EQ(P(0, 0), p);

        tie(tip, p) = line_segment_intersection(line, {-10, 1}, {10, 1});  // normal intersection
        if (p2.imag() != 0) {
            ASSERT_EQ(OK, tip);
            ASSERT_EQ(P(p2.real(), 1), p);
        } else {
            ASSERT_EQ(NO, tip);
        }

        tie(tip, p) = line_segment_intersection(line, {-1, 2}, {-1, 3});  // normal intersection
        ASSERT_EQ(NO, tip);
    }
}

TEST(IntersectionTest, SegmentSegment) {
    ITYPE tip, etip;
    P r, er, p1, p2, q1, q2;
    vector<tuple<P, P, P, P, ITYPE, P>> data {
        make_tuple(P(0, 0),   P(2, 0),   P(0, 1),   P(0, 5),    NO, P()),
        make_tuple(P(0, 0),   P(2, 0),   P(-1, -1), P(0, 1),    NO, P()),
        make_tuple(P(0, 0),   P(2, 0),   P(2, 3),   P(1, 0.3),  NO, P()),
        make_tuple(P(0, 0),   P(2, 0),   P(0, -1),  P(1, -0.3), NO, P()),
        make_tuple(P(0, 0),   P(2, 0),   P(3, -1),  P(3, 1),    NO, P()),
        make_tuple(P(0, 0),   P(2, 0),   P(3, 0),   P(3, 0),    NO, P()),
        make_tuple(P(0, 0),   P(0, 2),   P(1, 0),   P(5, 0),    NO, P()),  // transpose
        make_tuple(P(0, 0),   P(0, 2),   P(-1, -1), P(1, 0),    NO, P()),
        make_tuple(P(0, 0),   P(0, 2),   P(3, 2),   P(0.3, 1),  NO, P()),
        make_tuple(P(0, 0),   P(0, 2),   P(-1, 0),  P(-0.3, 1), NO, P()),
        make_tuple(P(0, 0),   P(0, 2),   P(-1, 3),  P(1, 3),    NO, P()),
        make_tuple(P(0, 0),   P(0, 2),   P(0, 3),   P(0, 5),    NO, P()),
        make_tuple(P(0, 0),   P(2, 0),   P(1, -1),  P(1, 1),    OK, P(1, 0)),  // OK
        make_tuple(P(1, -1),  P(1, 1),   P(0, 0),   P(2, 0),    OK, P(1, 0)),
        make_tuple(P(1, 0),   P(0, 2),   P(0, 0),   P(1, 2),    OK, P(0.5, 1)),
        make_tuple(P(0, 10),  P(2, 20),  P(2, 10),  P(0, 20),   OK, P(1, 15)),
        make_tuple(P(0, 0),   P(2, 0),   P(0, -1),  P(0, 1),    EQ, P(0, 0)),
        make_tuple(P(0, 0),   P(2, 0),   P(-1, 0),  P(1, 0),    EQ, P(1, 0)),
        make_tuple(P(0, 0),   P(2, 0),   P(-2, 0),  P(0, 0),    EQ, P(0, 0)),
        make_tuple(P(0, 0),   P(2, 0),   P(0, 0),   P(0, 2),    EQ, P(0, 0)),
        make_tuple(P(0, 0),   P(2, 0),   P(0, 0),   P(1, 3),    EQ, P(0, 0)),
        make_tuple(P(0, 0),   P(2, 0),   P(1, 0),   P(1, 2),    EQ, P(1, 0)),
        make_tuple(P(0, 0),   P(2, 0),   P(2, 0),   P(2, 2),    EQ, P(2, 0)),
        make_tuple(P(0, 0),   P(2, 0),   P(2, 0),   P(4, 2),    EQ, P(2, 0)),
        make_tuple(P(0, 0),   P(2, 0),   P(2, 0),   P(4, 0),    EQ, P(2, 0)),
        make_tuple(P(0, 0),   P(2, 0),   P(1, 0),   P(2, 0),    EQ, P(1, 0)),
        make_tuple(P(0, 0),   P(2, 0),   P(2, 0),   P(4, -2),   EQ, P(2, 0)),
        make_tuple(P(0, 0),   P(2, 0),   P(2, 1),   P(2, -1),   EQ, P(2, 0)),
        make_tuple(P(0, 0),   P(2, 0),   P(2, 0),   P(2, -2),   EQ, P(2, 0)),
        make_tuple(P(0, 0),   P(2, 0),   P(1, 0),   P(1, -2),   EQ, P(1, 0)),
        make_tuple(P(0, 0),   P(2, 0),   P(0, 0),   P(0, -2),   EQ, P(0, 0)),
        make_tuple(P(0, 0),   P(2, 0),   P(0, 0),   P(-2, -2),  EQ, P(0, 0)),
        make_tuple(P(0, 0),   P(2, 0),   P(0, 0),   P(-2, 2),   EQ, P(0, 0)),
        make_tuple(P(0, 0),   P(2, 0),   P(0, 0),   P(2, 0),   EQ, P(0, 0)),
    };

    for (auto t : data) {
        tie(p1, p2, q1, q2, etip, er) = t;
        tie(tip, r) = segment_segment_intersection(p1, p2, q1, q2);
        ASSERT_EQ(etip, tip) << p1 << p2 << q1 << q2;
        ASSERT_EQ(er, r) << p1 << p2 << q1 << q2;
    }
}

TEST(ContainsTest, PointInPoly) {
    vector<P> p = {{0, 0}, {1, 0}, {1, 1}, {0, 1}};
    ASSERT_EQ(NO, point_in_poly({2, 2}, p));
    ASSERT_EQ(EQ, point_in_poly({0, 0}, p));
    ASSERT_EQ(OK, point_in_poly({0.5, 0.5}, p));

    // to je tak zavit polž
    p = {{6, 4}, {7, 4}, {7, 1}, {8, 1}, {8, 5}, {5, 5}, {5, 0}, {2, 0}, {2, 8},
         {11, 8}, {11, 1}, {12, 1}, {12, 9}, {1, 9}, {1, 0}, {0, 0}, {0, 10}, {13, 10},
         {13, 0}, {10, 0}, {10, 7}, {3, 7}, {3, 1}, {4, 1}, {4, 6}, {9, 6}, {9, 0}, {6, 0}};

    ASSERT_EQ(EQ, point_in_poly({0, 8}, p));
    ASSERT_EQ(EQ, point_in_poly({0, 10}, p));
    ASSERT_EQ(EQ, point_in_poly({0, 0}, p));
    ASSERT_EQ(EQ, point_in_poly({9, 0}, p));
    ASSERT_EQ(EQ, point_in_poly({7, 8}, p));
    ASSERT_EQ(EQ, point_in_poly({3, 5}, p));
    ASSERT_EQ(EQ, point_in_poly({5, 5}, p));
    ASSERT_EQ(NO, point_in_poly({-1, -1}, p));
    ASSERT_EQ(NO, point_in_poly({5.5, 4.5}, p));
    ASSERT_EQ(NO, point_in_poly({11.5, 1.5}, p));
    ASSERT_EQ(NO, point_in_poly({6.5, 8.5}, p));
    ASSERT_EQ(OK, point_in_poly({0.5, 0.5}, p));
    ASSERT_EQ(OK, point_in_poly({5.5, 5.5}, p));
    ASSERT_EQ(OK, point_in_poly({11.5, 0.5}, p));
    ASSERT_EQ(OK, point_in_poly({6.5, 7.5}, p));
    ASSERT_EQ(OK, point_in_poly({6.5, 9.5}, p));
}

TEST(GetCircle, 3Points) {
    P p;
    double r;
    tie(p, r) = get_circle({0, 0}, {1, 1}, {0, 2});
    ASSERT_EQ(P(0, 1), p);
    ASSERT_EQ(1, r);

    tie(p, r) = get_circle({cos(1), sin(1)}, {cos(2), sin(2)}, {cos(3), sin(3)});
    ASSERT_EQ(P(0, 0), p);
    ASSERT_EQ(1, r);

    tie(p, r) = get_circle({cos(1), sin(1)}, {cos(-2), sin(-2)}, {cos(-3), sin(-3)});
    ASSERT_EQ(P(0, 0), p);
    ASSERT_EQ(1, r);

    tie(p, r) = get_circle({0, 0}, {1, 1}, {2, 2});
    ASSERT_EQ(0, r);
}

TEST(GetCircle, 2PointsRadius) {
    P p = get_circle(P(-1, 0), P(1, 0), 1.0);
    ASSERT_DOUBLE_EQ(0, p.real());
    ASSERT_DOUBLE_EQ(0, p.imag());
    p = get_circle(P(-1, 0), P(1, 0), sqrt(2));
    ASSERT_DOUBLE_EQ(0, p.real());
    ASSERT_DOUBLE_EQ(1, p.imag());
    p = get_circle(P(1, 0), P(-1, 0), sqrt(2));
    ASSERT_DOUBLE_EQ(0, p.real());
    ASSERT_DOUBLE_EQ(-1, p.imag());
}
