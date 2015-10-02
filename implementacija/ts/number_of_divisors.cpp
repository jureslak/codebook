#include "number_of_divisors.h"

int number_of_divisors(int n) {
    int tau = 1;
    int i = 2;
    while (i * i <= n) {
        int p = 0;
        while (n % i == 0) {  // i je prafaktor n, s potenco p
            n /= i;
            p++;
        }
        tau *= p + 1;
        i++;
    }
    if (n > 1) tau *= 2;
    return tau;
}
