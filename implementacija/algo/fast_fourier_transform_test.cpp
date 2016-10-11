#include "fast_fourier_transform.h"

#include "gtest/gtest.h"

TEST(FFT, PolyMul) {
    // (1 + 2x)(1 + x) = 1 + 3x + 2x^2
    vector<int> res = multiply_poly({1, 2}, {1, 1});
    EXPECT_EQ(res, vector<int>({1, 3, 2}));

    res = multiply_poly({1, 2, 23, 7}, {1});
    EXPECT_EQ(res, vector<int>({1, 2, 23, 7}));
}

TEST(FFT, NumMul) {
    // 23 * 45 = 1035
    vector<int> res = multiply_integer({3, 2}, {5, 4});
    EXPECT_EQ(res, vector<int>({5, 3, 0, 1}));

    // 312384129734891234123948109234 * 123894189237489123749871239487
    // = 38702578484162967699101092724484653429146941043369650122958
    vector<int> a = {4, 3, 2, 9, 0, 1, 8, 4, 9, 3, 2, 1, 4, 3, 2, 1, 9, 8, 4, 3, 7, 9, 2, 1, 4, 8,
        3, 2, 1, 3};
    vector<int> b = {7, 8, 4, 9, 3, 2, 1, 7, 8, 9, 4, 7, 3, 2, 1, 9, 8, 4, 7, 3, 2, 9, 8, 1, 4, 9,
        8, 3, 2, 1};
    vector<int> expected = {8, 5, 9, 2, 2, 1, 0, 5, 6, 9, 6, 3, 3, 4, 0, 1, 4, 9, 6, 4, 1, 9, 2, 4,
        3, 5, 6, 4, 8, 4, 4, 2, 7, 2, 9, 0, 1, 0, 1, 9, 9, 6, 7, 6, 9, 2, 6, 1, 4, 8, 4, 8, 7, 5, 2,
        0, 7, 8, 3};
    EXPECT_EQ(multiply_integer(a, b), expected);
}
