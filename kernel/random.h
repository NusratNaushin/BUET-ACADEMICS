//https://en.wikipedia.org/wiki/Xorshift
#ifndef RAND_H
#define RAND_H
#include "types.h"

uint64 SEED = 782003;

int rng(int n){
    uint64 x = SEED;
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;

    SEED = x;

    return x%n;
}

#endif