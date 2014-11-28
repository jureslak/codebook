#ifndef IMPLEMENTACIJA_TS_GCD_H_
#define IMPLEMENTACIJA_TS_GCD_H_

int gcd(int a, int b) {
    int t;
    while (b != 0) {
        t = a % b;
        a = b;
        b = t;
    }
    return a;
}

#endif  // IMPLEMENTACIJA_TS_GCD_H_
