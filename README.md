# Dice Rolling Simulator (C Project)

A modular, extensible, and fully interactive **Dice Rolling Simulator** written in C. This program simulates rolling one or multiple dice using the standard C `rand()` function and provides aggregate statistics such as minimum, maximum, sum, average, and total rolls.

Designed with clean architecture, separated modules, robust input handling, and well-structured code suitable for academic or production-quality C projects.

---

## Features

* Roll 1 to 10 dice per experiment
* Configurable number of sides (2–100)
* Single roll mode
* Multi-roll experiment mode (up to 100,000 runs)
* Real-time statistics:

  * Minimum observed value
  * Maximum observed value
  * Average value
  * Total rolls
  * Sum of all values
* Organized modular architecture:

  * `rng` module for random number generation
  * `stats` module for statistical tracking
  * `dice_simulator` module for the interactive system
* Clean and portable ANSI C (C11)

---

## Project Structure

```
dice-rolling-simulator/
│
├── Makefile                 # Build automation
├── LICENSE                  # MIT License
├── README.md                # Project documentation
│
└── src/
    ├── main.c               # Entry point
    ├── dice_simulator.c     # Core interactive logic
    ├── dice_simulator.h
    ├── rng.c                # Random number utilities
    ├── rng.h
    ├── stats.c              # Statistics module
    └── stats.h
```

---

## Build & Run

### 1. Compile the project

```bash
make
```

This creates the executable:

```
./dice_simulator
```

### 2. Run the program

```bash
./dice_simulator
```

---

## Requirements

* GCC or Clang
* Make (optional but recommended)
* C11-compatible environment

---

## How It Works

The simulator uses:

* `rand()` seeded with `time(NULL)` (in `rng.c`)
* Uniform integer generation in `[min, max]`
* Aggregation logic inside `stats.c`
* Interactive menu-driven loop in `dice_simulator.c`

This modular separation ensures clean maintainability and extensibility.

---

## Example Output

```
======================================
        Dice Rolling Simulator
======================================
Simulate fair dice rolls using rand().
--------------------------------------

Current configuration: 1 dice, 6 sides each
1) Roll once with current configuration
2) Roll multiple times and collect stats
3) Change dice configuration
4) Show statistics so far
5) Exit
Choose an option:
```

---

## License

This project is released under the **MIT License**. See the `LICENSE` file for details.

---

## Author

**Mobin Yousefi**
Master’s Student in Computer Science
GitHub: [https://github.com/mobinyousefi-cs](https://github.com/mobinyousefi-cs)
