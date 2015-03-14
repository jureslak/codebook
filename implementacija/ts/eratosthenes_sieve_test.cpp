#include "eratosthenes_sieve.h"

#include "gtest/gtest.h"

TEST(PrimeTest, ErastothenesSieve) {
    vector<int> is_prime;
    vector<int> primes;
    erastothenes_sieve(100, is_prime, primes);

    vector<int> is_prime_expected = {
        0, 0, 2, 3, 2, 5, 2, 7, 2, 3, 2, 11, 2, 13, 2, 3, 2, 17, 2, 19, 2, 3, 2, 23, 2, 5, 2, 3, 2,
        29, 2, 31, 2, 3, 2, 5, 2, 37, 2, 3, 2, 41, 2, 43, 2, 3, 2, 47, 2, 7, 2, 3, 2, 53, 2, 5, 2,
        3, 2, 59, 2, 61, 2, 3, 2, 5, 2, 67, 2, 3, 2, 71, 2, 73, 2, 3, 2, 7, 2, 79, 2, 3, 2, 83, 2,
        5, 2, 3, 2, 89, 2, 7, 2, 3, 2, 5, 2, 97, 2, 3};
    vector<int> primes_expected = {
        2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89,
        97 };
    ASSERT_EQ(is_prime_expected, is_prime);
    ASSERT_EQ(primes_expected, primes);
}
