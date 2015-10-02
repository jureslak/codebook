#include "binomial_mod.h"

int binomial_modp(int n, int k, int p) {
    int r = 1;
    while (n > 0) {
        int ni = n % p, ki = k % p;
        r *= binomial(ni, ki);  // če imaš zračunano vnaprej, uporabi tisto
        r %= p;                 // sicer pa delaj modulo tudi znotraj binomial
        n /= p;
        k /= p;
    }
    return r;
}

int binomial_mod(int n, int k, int m) {
    if (m == 1) return 0;
    vector<pair<int, int>> mods;
    int i = 2;
    while (i * i <= m) {
        int p = 0;
        while (m % i == 0) {  // i je prafaktor n, s potenco p
            m /= i;
            p++;
        }
        if (p > 1) throw "Invalid number, primer powers not supported.";
        if (p == 1) {
            mods.emplace_back(binomial_modp(n, k, p), p);
        }
    }
    return chinese_reminder_theorem(mods);
}
