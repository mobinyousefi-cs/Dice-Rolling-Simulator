// =====================================
// File: src/dice_simulator.c
// Project: Dice Rolling Simulator
// Author: Mobin Yousefi (GitHub: https://github.com/mobinyousefi-cs)
// Created: 2025-11-19
// License: MIT License (see LICENSE file for details)
// =====================================

#include "dice_simulator.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_BUFFER_SIZE 128

static void print_banner(void);
static void print_menu(const DiceSimulator *sim);
static int  read_int(const char *prompt, int min, int max, int *out_value);
static void handle_single_roll(DiceSimulator *sim);
static void handle_multi_roll(DiceSimulator *sim);
static void handle_update_config(DiceSimulator *sim);

void dice_simulator_init(DiceSimulator *sim) {
    if (!sim) {
        return;
    }

    sim->config.dice_count = 1;
    sim->config.sides      = 6;

    rng_init(&sim->rng);
    stats_init(&sim->stats);
}

void dice_simulator_run(DiceSimulator *sim) {
    if (!sim) {
        return;
    }

    print_banner();

    int running = 1;
    while (running) {
        print_menu(sim);

        int choice = 0;
        if (!read_int("Choose an option: ", 1, 5, &choice)) {
            puts("Input error. Exiting.");
            break;
        }

        switch (choice) {
            case 1:
                handle_single_roll(sim);
                break;
            case 2:
                handle_multi_roll(sim);
                break;
            case 3:
                handle_update_config(sim);
                break;
            case 4:
                stats_print(&sim->stats);
                break;
            case 5:
                running = 0;
                puts("Goodbye!");
                break;
            default:
                puts("Invalid choice. Please try again.");
                break;
        }
    }
}

static void print_banner(void) {
    puts("======================================");
    puts("        Dice Rolling Simulator         ");
    puts("======================================");
    puts("Simulate fair dice rolls using rand().");
    puts("--------------------------------------");
}

static void print_menu(const DiceSimulator *sim) {
    printf("\nCurrent configuration: %d dice, %d sides each\n",
           sim->config.dice_count,
           sim->config.sides);
    puts("--------------------------------------");
    puts("1) Roll once with current configuration");
    puts("2) Roll multiple times and collect stats");
    puts("3) Change dice configuration");
    puts("4) Show statistics so far");
    puts("5) Exit");
}

static int read_int(const char *prompt, int min, int max, int *out_value) {
    char buffer[INPUT_BUFFER_SIZE];
    int value;

    while (1) {
        if (prompt) {
            fputs(prompt, stdout);
        }

        if (!fgets(buffer, sizeof(buffer), stdin)) {
            return 0; // input error
        }

        // Remove trailing newline if present.
        buffer[strcspn(buffer, "\n")] = '\0';

        if (sscanf(buffer, "%d", &value) != 1) {
            puts("Please enter a valid integer.");
            continue;
        }

        if (value < min || value > max) {
            printf("Please enter a value between %d and %d.\n", min, max);
            continue;
        }

        if (out_value) {
            *out_value = value;
        }
        return 1;
    }
}

static void handle_single_roll(DiceSimulator *sim) {
    int total = 0;
    for (int i = 0; i < sim->config.dice_count; ++i) {
        int roll = rng_between(&sim->rng, 1, sim->config.sides);
        printf("Die %d: %d\n", i + 1, roll);
        total += roll;
        stats_update(&sim->stats, roll);
    }
    printf("Total: %d\n", total);
}

static void handle_multi_roll(DiceSimulator *sim) {
    int rolls = 0;
    if (!read_int("How many experiments? (1-100000): ", 1, 100000, &rolls)) {
        return;
    }

    for (int i = 0; i < rolls; ++i) {
        int total = 0;
        for (int j = 0; j < sim->config.dice_count; ++j) {
            int roll = rng_between(&sim->rng, 1, sim->config.sides);
            total += roll;
            stats_update(&sim->stats, roll);
        }

        // Optional: show progress for small experiments.
        if (rolls <= 20) {
            printf("Experiment %d: total = %d\n", i + 1, total);
        }
    }

    puts("Rolls completed.");
}

static void handle_update_config(DiceSimulator *sim) {
    int dice_count = 0;
    int sides      = 0;

    if (!read_int("Number of dice (1-10): ", 1, 10, &dice_count)) {
        return;
    }

    if (!read_int("Number of sides per die (2-100): ", 2, 100, &sides)) {
        return;
    }

    sim->config.dice_count = dice_count;
    sim->config.sides      = sides;

    printf("Configuration updated: %d dice, %d sides each.\n",
           dice_count, sides);
}