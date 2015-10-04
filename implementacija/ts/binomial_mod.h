#ifndef IMPLEMENTACIJA_TS_BINOMIAL_MOD_H_
#define IMPLEMENTACIJA_TS_BINOMIAL_MOD_H_

#include "binomial.h"
#include "chinese_reminder_theorem.h"

#include <cassert>

int binomial_modp(int n, int k, int p);
int binomial_mod(int n, int k, int m);

#endif  // IMPLEMENTACIJA_TS_BINOMIAL_MOD_H_
