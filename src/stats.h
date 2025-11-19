// =====================================
// File: src/stats.h
// Project: Dice Rolling Simulator
// Author: Mobin Yousefi (GitHub: https://github.com/mobinyousefi-cs)
// Created: 2025-11-19
// License: MIT License (see LICENSE file for details)
// =====================================

#ifndef STATS_H
#define STATS_H

/**
 * Aggregate statistics for a stream of integer values.
 */
typedef struct {
    long long total_rolls; /**< Number of samples observed. */
    long long sum;         /**< Sum of all sample values.   */
    int       min;         /**< Minimum sample value.       */
    int       max;         /**< Maximum sample value.       */
} Stats;

void   stats_init(Stats *stats);
void   stats_update(Stats *stats, int value);
void   stats_print(const Stats *stats);

#endif // STATS_H

