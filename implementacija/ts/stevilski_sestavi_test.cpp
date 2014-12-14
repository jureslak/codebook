#include "stevilski_sestavi.h"

#include "gtest/gtest.h"

#include <string>
#include <tuple>
#include <vector>

using std::pair;
using std::stoi;
using std::tuple;
using std::get;
using std::vector;

TEST(StevilskiSestaviTest, ConvertIntegerDecimal) {
    vector<pair<int, string>> test_data {
        {0, "0"}, {1, "1"}, {9, "9"}, {45, "45"}, {23434, "23434"},
        {1000000, "1000000"}, {999999, "999999"}};
    for (size_t j = 0; j < test_data.size(); ++j) {
        ASSERT_EQ(convert_int(test_data[j].first, 10), test_data[j].second);
    }
}

TEST(StevilskiSestaviTest, ConvertIntegerBinary) {
    vector<pair<int, string>> test_data {
        {0, "0"}, {1, "1"}, {4, "100"}, {15, "1111"}, {64, "1000000"}};
    for (size_t j = 0; j < test_data.size(); ++j) {
        ASSERT_EQ(convert_int(test_data[j].first, 2), test_data[j].second);
    }
}

// STEVILSKI_SESTAVI_ZNAKI dependant!
TEST(StevilskiSestaviTest, ConvertIntegerHex) {
    vector<pair<int, string>> test_data {
        {0, "0"}, {1, "1"}, {10, "A"}, {15, "F"}, {64, "40"}};
    for (size_t j = 0; j < test_data.size(); ++j) {
        ASSERT_EQ(convert_int(test_data[j].first, 16), test_data[j].second);
    }
}

struct FractionTestData {
    int stevec, imenovalec, baza;
    string rezultat;
};

// STEVILSKI_SESTAVI_ZNAKI dependant!
TEST(StevilskiSestaviTest, ConvertFraction) {
    vector<FractionTestData> test_data {
        {15,   5,   3,  "10"},
        {1,    3,   30, "0.A"},
        {104,  300, 30, "0.AC"},
        {9872, 870, 30, "B.A(C)"},
        {81,   112, 15, "0.(AC)"},
        {643,  42,  6,  "23.1(50)"},
        {636,  42,  6,  "23.(05)"},
        {141,  7,   17, "13.(274E9C)"}};
    for (const FractionTestData& item : test_data) {
        ASSERT_EQ(convert_fraction(item.stevec, item.imenovalec, item.baza),
                  item.rezultat);
    }
}
