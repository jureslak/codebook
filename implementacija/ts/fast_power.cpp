#include "implementacija/ts/fast_power.h"

int fast_power(int g, int n) {
    int r = 1;
    while (n > 0) {
        if (n & 1) {
            r *= g;
        }
        g *= g;
        n >>= 1;
    }
    return r;
}
