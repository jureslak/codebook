#include "bigint.h"

#include "gtest/gtest.h"

#include <sstream>

using std::stringstream;

string to_str(int a) {
    stringstream ss;
    ss << a;
    return ss.str();
}

TEST(BigInt, ReadWrite) {
    string n = "13841324717864";
    Number<char> num(n);
    deque<char> expected = {4, 6, 8, 7, 1, 7, 4, 2, 3, 1, 4, 8, 3, 1};
    EXPECT_EQ(expected, num.data);
    EXPECT_EQ(n, num.to_string());

    n = "0000";
    expected = {};
    num = Number<char>(n);
    EXPECT_EQ(expected, num.data);
    EXPECT_EQ("0", num.to_string());

    n = "-0";
    expected = {};
    num = Number<char>(n);
    EXPECT_EQ(expected, num.data);
    EXPECT_EQ("0", num.to_string());

    n = "-1234";
    expected = {4, 3, 2, 1};
    num = Number<char>(n);
    EXPECT_EQ(expected, num.data);
    EXPECT_EQ(n, num.to_string());

    n = "+001234";
    expected = {4, 3, 2, 1};
    num = Number<char>(n);
    EXPECT_EQ(expected, num.data);
    EXPECT_EQ("1234", num.to_string());
}

TEST(BigInt, AddPositive) {
    Number<char> a("111111"), b("222222");
    EXPECT_EQ("333333", (a+b).to_string());
    Number<char> c(a);
    c += b;
    EXPECT_EQ("333333", c.to_string());

    a = Number<char>("1"), b = Number<char>("2345");
    EXPECT_EQ("2346", (a+b).to_string());
    EXPECT_EQ("2346", (b+a).to_string());

    a = Number<char>("1"), b = Number<char>("9999");
    EXPECT_EQ("10000", (a+b).to_string());
    EXPECT_EQ("10000", (b+a).to_string());

    a = Number<char>("465763412347891"), b = Number<char>("9999");
    c = b; c += a;
    EXPECT_EQ("465763412357890", (a+b).to_string());
    EXPECT_EQ("465763412357890", (b+a).to_string());
    EXPECT_EQ("465763412357890", c.to_string());
}

TEST(BigInt, Compare) {
    EXPECT_LT(Number<char>("111111"),  Number<char>("222222"));
    EXPECT_LT(Number<char>("-111111"), Number<char>("222222"));
    EXPECT_LT(Number<char>("-333333"), Number<char>("222222"));
    EXPECT_LT(Number<char>("99999"),   Number<char>("222222"));
    EXPECT_LT(Number<char>("-222222"), Number<char>("-111111"));
    EXPECT_LT(Number<char>("-100"),    Number<char>("-99"));
    EXPECT_LT(Number<char>("10"),      Number<char>("999"));
    EXPECT_LT(Number<char>("1234"),    Number<char>("4321"));
    EXPECT_EQ(Number<char>("111111"),  Number<char>("111111"));
    EXPECT_EQ(Number<char>("-0"),      Number<char>("0"));
    EXPECT_EQ(Number<char>("-0"),      Number<char>("-0"));
    EXPECT_EQ(Number<char>("0"),       Number<char>("0"));
    EXPECT_EQ(Number<char>("-100"),    Number<char>("-100"));
}

TEST(BigInt, Mult) {
    EXPECT_EQ("2468"            , (Number<char>("1234")     * 2).to_string());
    EXPECT_EQ("0"               , (Number<char>("1234434")  * 0).to_string());
    EXPECT_EQ("24690"           , (Number<char>("12345")    * 2).to_string());
    EXPECT_EQ("111105"          , (Number<char>("12345")    * 9).to_string());
    EXPECT_EQ("-2468"           , (Number<char>("-1234")    * 2).to_string());
    EXPECT_EQ("0"               , (Number<char>("-1234434") * 0).to_string());
    EXPECT_EQ("-24690"          , (Number<char>("-12345")   * 2).to_string());
    EXPECT_EQ("-111105"         , (Number<char>("-12345")   * 9).to_string());
    EXPECT_EQ("12321"           , (Number<char>("111")      * Number<char>("111"))      . to_string());  // NOLINT(*)
    EXPECT_EQ("56789"           , (Number<char>("1")        * Number<char>("56789"))    . to_string());  // NOLINT(*)
    EXPECT_EQ("21539387994915"  , (Number<char>("2332419")  * Number<char>("9234785"))  . to_string());  // NOLINT(*)
    EXPECT_EQ("-12321"          , (Number<char>("-111")     * Number<char>("111"))      . to_string());  // NOLINT(*)
    EXPECT_EQ("-56789"          , (Number<char>("-1")       * Number<char>("56789"))    . to_string());  // NOLINT(*)
    EXPECT_EQ("-21539387994915" , (Number<char>("-2332419") * Number<char>("9234785"))  . to_string());  // NOLINT(*)
    EXPECT_EQ("12321"           , (Number<char>("-111")     * Number<char>("-111"))     . to_string());  // NOLINT(*)
    EXPECT_EQ("56789"           , (Number<char>("-1")       * Number<char>("-56789"))   . to_string());  // NOLINT(*)
    EXPECT_EQ("21539387994915"  , (Number<char>("-2332419") * Number<char>("-9234785")) . to_string());  // NOLINT(*)
    EXPECT_EQ("-12321"          , (Number<char>("111")      * Number<char>("-111"))     . to_string());  // NOLINT(*)
    EXPECT_EQ("-56789"          , (Number<char>("1")        * Number<char>("-56789"))   . to_string());  // NOLINT(*)
    EXPECT_EQ("-21539387994915" , (Number<char>("2332419")  * Number<char>("-9234785")) . to_string());  // NOLINT(*)
    EXPECT_EQ("0"               , (Number<char>("2332419")  * Number<char>("0"))        . to_string());  // NOLINT(*)
    EXPECT_EQ("0"               , (Number<char>("0")        * Number<char>("-9234785")) . to_string());  // NOLINT(*)
    EXPECT_EQ("0"               , (Number<char>("0")        * Number<char>("-0"))       . to_string());  // NOLINT(*)
}

// pylint: disable
TEST(BigInt, MultKaratsuba) {
    EXPECT_EQ("12321"           , karatsuba(Number<char>("111")      , Number<char>("111"))      . to_string());  // NOLINT(*)
    EXPECT_EQ("56789"           , karatsuba(Number<char>("1")        , Number<char>("56789"))    . to_string());  // NOLINT(*)
    EXPECT_EQ("21539387994915"  , karatsuba(Number<char>("2332419")  , Number<char>("9234785"))  . to_string());  // NOLINT(*)
    EXPECT_EQ("-12321"          , karatsuba(Number<char>("-111")     , Number<char>("111"))      . to_string());  // NOLINT(*)
    EXPECT_EQ("-56789"          , karatsuba(Number<char>("-1")       , Number<char>("56789"))    . to_string());  // NOLINT(*)
    EXPECT_EQ("-21539387994915" , karatsuba(Number<char>("-2332419") , Number<char>("9234785"))  . to_string());  // NOLINT(*)
    EXPECT_EQ("12321"           , karatsuba(Number<char>("-111")     , Number<char>("-111"))     . to_string());  // NOLINT(*)
    EXPECT_EQ("56789"           , karatsuba(Number<char>("-1")       , Number<char>("-56789"))   . to_string());  // NOLINT(*)
    EXPECT_EQ("21539387994915"  , karatsuba(Number<char>("-2332419") , Number<char>("-9234785")) . to_string());  // NOLINT(*)
    EXPECT_EQ("-12321"          , karatsuba(Number<char>("111")      , Number<char>("-111"))     . to_string());  // NOLINT(*)
    EXPECT_EQ("-56789"          , karatsuba(Number<char>("1")        , Number<char>("-56789"))   . to_string());  // NOLINT(*)
    EXPECT_EQ("-21539387994915" , karatsuba(Number<char>("2332419")  , Number<char>("-9234785")) . to_string());  // NOLINT(*)
    EXPECT_EQ("0"               , karatsuba(Number<char>("2332419")  , Number<char>("0"))        . to_string());  // NOLINT(*)
    EXPECT_EQ("0"               , karatsuba(Number<char>("0")        , Number<char>("-9234785")) . to_string());  // NOLINT(*)
    EXPECT_EQ("0"               , karatsuba(Number<char>("0")        , Number<char>("-0"))       . to_string());  // NOLINT(*)
}
// pylint: enable

TEST(BigInt, BruteForce) {
    for (int i = -1213; i < 1887; i = (i < 0) ? i / 2 : (i+1) * 2) {
        for (int j = -3543; j < 6267; j = (j < 0) ? j / 2 : (j+1) * 2) {
            string si = to_str(i), sj = to_str(j);
            string mij = to_str(i*j), aij = to_str(i+j), rij = to_str(i-j), dij = to_str(j-i);
            bool b = i < j, bb = j < i;
            ASSERT_EQ(mij, (Number<char>(si) * Number<char>(sj)).to_string());
            ASSERT_EQ(aij, (Number<char>(si) + Number<char>(sj)).to_string());
            ASSERT_EQ(rij, (Number<char>(si) + -Number<char>(sj)).to_string());
            ASSERT_EQ(dij, (Number<char>(sj) + -Number<char>(si)).to_string());
            ASSERT_EQ(mij, karatsuba(Number<char>(si), Number<char>(sj)).to_string());
            ASSERT_EQ(b,   Number<char>(si) < Number<char>(sj));
            ASSERT_EQ(bb,  Number<char>(sj) < Number<char>(si));
        }
    }
}

TEST(BigInt, AddGeneral) {
    EXPECT_EQ("1324", (Number<char>("1325") + Number<char>("-1")).to_string());
    EXPECT_EQ("1324", (Number<char>("-1") + Number<char>("1325")).to_string());
    EXPECT_EQ("-1324", (Number<char>("-1325") + Number<char>("1")).to_string());
    EXPECT_EQ("-1324", (Number<char>("1") + Number<char>("-1325")).to_string());
    EXPECT_EQ("-1326", (Number<char>("-1325") + Number<char>("-1")).to_string());
    EXPECT_EQ("259", (Number<char>("988") + Number<char>("-729")).to_string());
}
