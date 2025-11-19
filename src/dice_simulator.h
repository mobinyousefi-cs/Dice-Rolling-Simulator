// =====================================
// File: src/dice_simulator.h
// Project: Dice Rolling Simulator
// Author: Mobin Yousefi (GitHub: https://github.com/mobinyousefi-cs)
// Created: 2025-11-19
// License: MIT License (see LICENSE file for details)
// =====================================

#ifndef DICE_SIMULATOR_H
#define DICE_SIMULATOR_H

#include "rng.h"
#include "stats.h"

/**
 * Represents the configuration for rolling dice.
 */
typedef struct {
    int dice_count;   /**< Number of dice to roll in one experiment. */
    int sides;        /**< Number of sides on each die.              */
} DiceConfig;

/**
 * High-level simulator context that owns RNG and statistics.
 */
typedef struct {
    DiceConfig config; /**< Current dice configuration. */
    Rng        rng;    /**< Pseudo-random generator.   */
    Stats      stats;  /**< Aggregate statistics.      */
} DiceSimulator;

/**
 * Initialize the simulator with default configuration.
 * Default: 1 die, 6 sides.
 */
void dice_simulator_init(DiceSimulator *sim);

/**
 * Interactive main loop: shows the menu, processes user input,
 * performs rolls, and prints statistics.
 */
void dice_simulator_run(DiceSimulator *sim);

#endif // DICE_SIMULATOR_H