// =====================================
// File: src/main.c
// Project: Dice Rolling Simulator
// Author: Mobin Yousefi (GitHub: https://github.com/mobinyousefi-cs)
// Created: 2025-11-19
// License: MIT License (see LICENSE file for details)
// =====================================

#include <stdio.h>
#include "dice_simulator.h"

int main(void) {
    DiceSimulator sim;

    dice_simulator_init(&sim);
    dice_simulator_run(&sim);

    return 0;
}