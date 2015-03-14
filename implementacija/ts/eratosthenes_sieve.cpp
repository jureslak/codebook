#include "eratosthenes_sieve.h"

void erastothenes_sieve(int n, vector<int>& is_prime, vector<int>& primes) {
    is_prime.resize(n);
    for (int i = 2; i < n+1; ++i) {
        if (is_prime[i] == 0) {
            is_prime[i] = i;
            primes.push_back(i);
        }
        size_t j = 0;
        while (j < primes.size() && primes[j] <= is_prime[i] && i * primes[j] <= n) {
            is_prime[i * primes[j]] = primes[j];
            j++;
        }
    }
}
