// =====================================
// File: src/rng.c
// Project: Dice Rolling Simulator
// Author: Mobin Yousefi (GitHub: https://github.com/mobinyousefi-cs)
// Created: 2025-11-19
// License: MIT License (see LICENSE file for details)
// =====================================

#include "rng.h"

#include <stdlib.h>
#include <time.h>

void rng_init(Rng *rng) {
    if (!rng) {
        return;
    }

    if (!rng->initialized) {
        /* Seed the global rand() generator once. */
        srand((unsigned int)time(NULL));
        rng->initialized = 1;
    }
}

int rng_between(Rng *rng, int min, int max) {
    if (!rng) {
        return min; // Best-effort fallback.
    }

    if (!rng->initialized) {
        rng_init(rng);
    }

    const int range = max - min + 1;
    const int r     = rand() % range;  /* Uses C's rand() as required. */
    return min + r;
}