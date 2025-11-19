// =====================================
// File: src/rng.h
// Project: Dice Rolling Simulator
// Author: Mobin Yousefi (GitHub: https://github.com/mobinyousefi-cs)
// Created: 2025-11-19
// License: MIT License (see LICENSE file for details)
// =====================================

#ifndef RNG_H
#define RNG_H

/**
 * Lightweight wrapper around C's rand()/srand() facilities.
 * This allows us to centralize seeding and distribution in one place.
 */
typedef struct {
    int initialized; /**< Non-zero once the RNG has been seeded. */
} Rng;

/**
 * Initialize the RNG using the current time as a seed.
 */
void rng_init(Rng *rng);

/**
 * Generate an integer uniformly in [min, max].
 * Precondition: min <= max.
 */
int rng_between(Rng *rng, int min, int max);

#endif // RNG_H