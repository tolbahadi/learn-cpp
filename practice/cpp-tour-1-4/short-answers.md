# Short-Answer Check — A Tour of C++ Chapters 1–4

Quick-answer reflections captured on 2025-09-20 to reinforce material from chapters 1–4.

## Responses

1. **Why brace initialization avoids narrowing**  
   *Your answer:* Braces prevent implicit narrowing conversions; initialization fails if the types don’t match.  
   *Assessment:* ✅ Correct.

2. **When to choose `std::unique_ptr` vs `std::shared_ptr`**  
   *Your answer:* Use `unique_ptr` for exclusive ownership, `shared_ptr` when multiple consumers share an object.  
   *Assessment:* ✅ Correct.

3. **Practical benefit of `std::array<T, N>` over `T[N]`**  
   *Your answer:* Skipped (topic not covered yet).  
   *Assessment:* ⚠️ Pending; revisit after reading about `std::array`.

4. **Advantage of `enum class`**  
   *Your answer:* Enumerators stay scoped; names don’t leak into the outer scope.  
   *Assessment:* ✅ Correct (also blocks implicit conversions).

5. **Concrete win for `constexpr`**  
   *Your answer:* Declare `std::string` as `constexpr` when the literal is known; compiler allocates at compile time.  
   *Assessment:* ⚠️ Partially correct—requires C++20+ (earlier standards forbid `constexpr std::string`). Classic example: compute geometry constants or lookup tables with `constexpr` functions so values fold at compile time.

6. **Benefit of range-based `for` loops**  
   *Your answer:* No need for separate index or value variables.  
   *Assessment:* ✅ Correct—simplifies loops and avoids index mistakes.

## Follow-Up Ideas
- Revisit `std::array` in Chapter 5+ and update response 3.  
- Try writing a small `constexpr` utility (e.g., circumference) and confirm it folds at compile time with `static_assert`.
