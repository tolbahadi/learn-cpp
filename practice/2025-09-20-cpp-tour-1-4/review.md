# Chapter 1–4 Refresher — *A Tour of C++*

Readable cheat sheet covering the core ideas from the opening chapters. Skim the code, internalize the idioms.

---

## 1. Writing Modern C++: Values First

### Brace Initialization
- Prefer `{}` to avoid narrowing conversions.
- Works for aggregates, containers, and constructor calls.

```cpp
int exact{42};          // OK
// int narrowed{3.14};  // error: narrowing
std::vector<int> nums{1, 2, 3};
```

### Type Deduction with `auto`
- Reduces verbosity, keeps iterator-heavy code aligned with templates.
- Use explicit types when it aids readability (e.g., public APIs).

```cpp
std::unordered_map<std::string, int> scores{{"alice", 10}, {"bob", 7}};
for (auto& [name, score] : scores) {
    score += 1;
}
```

### `constexpr` and Compile-Time
- Mark expressions/functions for compile-time evaluation when possible.
- `constexpr` variables are implicitly `const`.

```cpp
constexpr double pi{3.141592653589793};
constexpr double circle_area(double r) {
    return pi * r * r;
}
static_assert(circle_area(1.0) > 3.14);
```

## 2. References, Pointers, and Ownership Intent

### References vs Pointers
- References must bind to valid objects and cannot be reseated.
- Pointers can be null, manipulated, and reseated.

```cpp
int x{10};
int& ref{x};     // alias
int* ptr{&x};    // can be null, arithmetic allowed
```

### `const` Placement
- `int* const p` → pointer is const.
- `const int* p` / `int const* p` → pointee is const.
- `const int* const p` → both const.

### Smart Pointers
- `std::unique_ptr<T>`: sole ownership. Move-only.
- `std::shared_ptr<T>`: shared ownership with ref counting.
- `std::weak_ptr<T>`: non-owning observer.

```cpp
auto owned = std::make_unique<Widget>();
use(owned.get());             // raw pointer for APIs
std::unique_ptr<Widget> other = std::move(owned);  // transfer ownership
```

RAII principle: resources acquired in constructor, released in destructor.

## 3. Enumerations and Strong Typing

### Classic vs Scoped Enums

```cpp
enum ColorOld { red, green, blue };           // unscoped, leaks names, implicit int
enum class Color { red, green, blue };        // scoped, no implicit conversions
```

Scoped enums prevent mixing unrelated enumerators and require explicit casts to underlying types.

### Type Aliases with `using`
Keeps signatures readable, especially for templates.

```cpp
using StringVec = std::vector<std::string>;
StringVec names{"Ada", "Bjarne"};
```

## 4. Namespaces and Modular Design

- Use namespaces to avoid symbol collisions.
- Inline namespaces or nested namespaces organize APIs.

```cpp
namespace math::statistics {
    double mean(std::span<const double> values);
}
```

## 5. Core Containers & Algorithms

### `std::vector`
- Default dynamic array; amortized `O(1)` push_back.
- Remember `reserve()` to avoid reallocations when size known.

```cpp
std::vector<double> temps;
temps.reserve(365);
```

### `std::array`
- Fixed-size array with STL interface and stack allocation.

```cpp
std::array<int, 3> coords{1, 2, 3};
```

### Iteration Patterns

```cpp
for (const auto& item : items) { /* ... */ }        // range-based for
std::for_each(items.begin(), items.end(), func);    // algorithm-based
```

`<algorithm>` is a power booster: `std::sort`, `std::find`, `std::accumulate`, `std::minmax_element`, `std::nth_element`, etc.

### Example: median via `std::nth_element`

```cpp
double median(std::vector<double> values) {
    if (values.empty()) throw std::invalid_argument("median: empty");

    auto middle = values.begin() + values.size() / 2;
    std::nth_element(values.begin(), middle, values.end());

    if (values.size() % 2 != 0) return *middle;

    auto lower = std::max(values.begin(), middle - 1);
    return (*lower + *middle) / 2.0;
}
```

## 6. Functions, Defaults, and Overloads

### Function Signatures
- Prefer passing large objects by const reference.
- Return values by value unless sharing references intentionally.

```cpp
std::string greet(const std::string& name) {
    return "Hello, " + name;
}
```

### Default Arguments vs Overloads
- Defaults belong in headers, avoid duplicate defaults across overloads.

```cpp
void log(std::string_view msg, LogLevel level = LogLevel::Info);
```

## 7. Error Handling Basics

- Use exceptions for recoverable errors; handle locally where remediation exists.
- For logic errors (programmer mistakes), consider assertions.

```cpp
try {
    auto value = compute();
} catch (const std::runtime_error& ex) {
    std::cerr << "runtime error: " << ex.what() << '\n';
}
```

## 8. `TempStats` Highlights (practice exercise)

- Token-based input parsing with `std::istringstream`.
- Filtering invalid data and throwing when statistics are requested on empty datasets.
- STL algorithms for mean/median/min/max calculations.

Key idioms used:

```cpp
// Copy and partially order to compute median without full sort
auto temps_copy = temps;
auto right_mid = temps_copy.begin() + temps_copy.size() / 2;
std::nth_element(temps_copy.begin(), right_mid, temps_copy.end());

// Filter sentinel values while reading
std::string token;
while (in >> token) {
    if (token == "q" || token == "quit") break;
    double value = std::stod(token);
    if (value >= absolute_zero) temps.push_back(value);
}
```

## 9. Standard Headers to Remember
- `<vector>`, `<array>`, `<string>`, `<string_view>`
- `<algorithm>`, `<numeric>`
- `<utility>` for `std::pair`, `std::move`
- `<memory>` for smart pointers
- `<stdexcept>` for exception types
- `<span>` (C++20) for non-owning views

## 10. Mindset Moving Forward
- Prefer expressive types & RAII; reduce raw pointers.
- Adopt `auto` for template-heavy code, explicit types at module boundaries.
- Lean on STL algorithms before writing manual loops.
- Compile with warnings (`-Wall -Wextra -pedantic`) and sanitizers when available.
- Practice writing small classes with clear invariants (constructors + destructor enforcing RAII).

Stay consistent: read code, write code, review frequently.
