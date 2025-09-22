# Learn C++ Notes

## Focus Areas
- Refresh core modern C++ concepts: RAII, move semantics, smart pointers, STL containers/algorithms, concurrency primitives
- Practice with C++20/23 features your team relies on (concepts, ranges, coroutines, modules, constexpr)
- Build muscle memory around memory management, ownership patterns, and tooling (sanitizers, linters, cmake/build flows)

## Rust As A Complement
- Rust guarantees memory safety without a GC via ownership, lifetimes, and the borrow checker; once it compiles, many bugs are ruled out
- Cargo, crates.io, and first-class build/testing tooling make dependency and project management straightforward
- Pattern matching, traits, async/await, and fearless concurrency are built in, with consistent edition upgrades
- Learning curve spikes early; expect to invest time encoding invariants in types and appeasing the compiler

## Compared With Modern C++
- Modern C++ offers enormous flexibility and zero-cost abstractions but depends on discipline and tooling to maintain safety
- Legacy compatibility and multiple paradigms can introduce complexity and footguns, especially across large teams
- You can write safe C++, but the compiler will not enforce the same invariants Rust does by default

## Learning Strategy
1. Prioritize modern C++ proficiency to stay effective with your current team
   - Deep dive into idiomatic patterns (RAII, smart pointers, value semantics) and standard library facilities
   - Explore newer language features actively used in your codebase to reduce onboarding friction
2. Layer Rust learning afterward via a focused side project or utility
   - This highlights the conceptual contrasts instead of blending models
   - Use it to evaluate Rust’s tooling and safety benefits for future greenfield work

## When To Reach For Each Language
- C++: Integrating with legacy systems, needing absolute control/compatibility, working in existing C++-heavy ecosystems
- Rust: Building new components where correctness, safety, and modern tooling outweigh integration friction

Keep iterating on examples, katas, and mini-projects to internalize patterns in both ecosystems.

## Practice Archive
- 2025-09-20 — *A Tour of C++* ch. 1–4 refresh (quiz, short answers, temperature stats exercise): `practice/cpp-tour-1-4/`

## Next Up
- Deepen familiarity with `std::array`, ranges, and additional C++20 features as you advance past chapter 4
- Capture future practice sets under `practice/` with dated subfolders for quick reference
