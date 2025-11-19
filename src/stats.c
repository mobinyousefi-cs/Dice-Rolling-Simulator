// =====================================
// File: src/stats.c
// Project: Dice Rolling Simulator
// Author: Mobin Yousefi (GitHub: https://github.com/mobinyousefi-cs)
// Created: 2025-11-19
// License: MIT License (see LICENSE file for details)
// =====================================

#include "stats.h"

#include <stdio.h>

void stats_init(Stats *stats) {
    if (!stats) {
        return;
    }

    stats->total_rolls = 0;
    stats->sum         = 0;
    stats->min         = 0;
    stats->max         = 0;
}

void stats_update(Stats *stats, int value) {
    if (!stats) {
        return;
    }

    if (stats->total_rolls == 0) {
        stats->min = stats->max = value;
    } else {
        if (value < stats->min) {
            stats->min = value;
        }
        if (value > stats->max) {
            stats->max = value;
        }
    }

    stats->total_rolls++;
    stats->sum += value;
}

void stats_print(const Stats *stats) {
    if (!stats) {
        return;
    }

    if (stats->total_rolls == 0) {
        puts("No rolls recorded yet.");
        return;
    }

    const double mean = (double)stats->sum / (double)stats->total_rolls;

    puts("\n===== Statistics =====");
    printf("Total rolls: %lld\n", stats->total_rolls);
    printf("Sum of values: %lld\n", stats->sum);
    printf("Minimum value: %d\n", stats->min);
    printf("Maximum value: %d\n", stats->max);
    printf("Average value: %.3f\n", mean);
    puts("======================\n");
}