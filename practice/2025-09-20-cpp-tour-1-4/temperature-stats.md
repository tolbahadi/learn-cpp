# Temperature Stats Exercise

Context: reinforces key ideas from *A Tour of C++* Chapters 1–4 (types, initialization, functions, standard library basics).

Write a small C++ program that:

- Reads a list of `double` temperatures from standard input until EOF (or until the user types `q`/`quit`).
- Stores values in a `std::vector<double>`.
- Computes and prints:
  - Count (`std::size`).
  - Mean.
  - Median (sort a copy or use `std::nth_element`).
  - Min/Max (`std::minmax_element`).
- Handles the "no data" case gracefully.

## Requirements

- Use brace initialization wherever possible to avoid narrowing.
- Prefer `auto` when iterators or long type names are involved, but declare obvious types explicitly (for example, `double mean{}`).
- Avoid manual `new`/`delete`; just use standard containers.
- Wrap computations in small helper functions (for example, `compute_mean(const std::vector<double>&)`).
- For diagnostics, use references where appropriate (`const std::vector<double>& temps`), not raw pointers.
- Add `constexpr double absolute_zero_celsius{-273.15};` and reject any temperature below it with a printed warning; skip it instead of storing it.

## Stretch Goals

1. Accept temperatures along with a unit (`C` or `F`) and normalize to Celsius using `constexpr` conversion helpers.
2. Replace sorting with `std::ranges` plus `std::span` and compare the structure to the baseline solution.

Compile with something like `g++ -std=c++20 -Wall -Wextra -pedantic stats.cpp -o stats` and run with sample inputs to validate behavior.
