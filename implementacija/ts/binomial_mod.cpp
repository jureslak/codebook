#include "binomial_mod.h"

int binomial_modp(int n, int k, int p) {
    if (k < 0 || k > n) return 0;
    if (k == 0 || k == n) return 1;
    int r = 1;
    while (n > 0) {
        int ni = n % p, ki = k % p;
        r *= binomial(ni, ki);  // če imaš zračunano vnaprej, uporabi tisto
        r %= p;  // sicer pa delaj modulo tudi znotraj binomial
        n /= p;
        k /= p;
    }
    return r;
}

// funkcija je tu bolj za demonstracijo, v praksi racunaj vse rezultate po modulih
int binomial_mod(int n, int k, int m) {  // prafaktorjev in sele na koncu rekunstruiraj
    if (m == 1) return 0;
    if (k < 0 || k > n) return 0;
    if (k == 0 || k == n) return 1;
    vector<pair<int, int>> mods;
    int i = 2;
    while (i * i <= m) {
        int p = 0;
        while (m % i == 0) {  // i je prafaktor n, s potenco p
            m /= i;
            p++;
        }
        assert(p <= 1 && "Invalid number, numbers containing prime powers not supported.");
        if (p == 1) mods.emplace_back(binomial_modp(n, k, i), i);

        i++;
    }  // kar ostane mora biti praštevilo ali 1
    if (m != 1) mods.emplace_back(binomial_modp(n, k, m), m);

    return chinese_reminder_theorem(mods);
}
