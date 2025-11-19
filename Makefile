// =====================================
// File: Makefile
// Project: Dice Rolling Simulator
// Author: Mobin Yousefi (GitHub: https://github.com/mobinyousefi-cs)
// Created: 2025-11-19
// License: MIT License (see LICENSE file for details)
// =====================================

CC      := gcc
CFLAGS  := -std=c11 -Wall -Wextra -pedantic -O2

SRC_DIR := src
OBJ_DIR := build

SRCS    := $(SRC_DIR)/main.c \
           $(SRC_DIR)/dice_simulator.c \
           $(SRC_DIR)/rng.c \
           $(SRC_DIR)/stats.c

OBJS    := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
TARGET  := dice_simulator

.PHONY: all clean dirs

all: dirs $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

dirs:
	@mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR) $(TARGET)
