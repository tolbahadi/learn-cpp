# C++ Compiler Overview

Keeping track of the common toolchains helps align personal practice with team and production environments.

## Apple Clang (`clang++`)
- **Default on macOS** via Xcode Command Line Tools (`clang --version` reports the Apple flavor).
- Front-end for the LLVM toolchain with strong diagnostics, fast iteration, and built-in static analysis.
- On macOS, invoking `g++` usually redirects to `clang++` unless GNU GCC is installed separately (e.g., via Homebrew).

## GNU GCC (`g++`)
- Dominant on Linux servers and many CI pipelines.
- Mature optimizer, wide architecture support, exhaustive warning flags.
- Installable on macOS (`brew install gcc`) when parity with Linux builds is needed. Binaries are typically versioned (`g++-14`).

## Microsoft Visual C++ (`cl.exe`)
- Standard compiler on Windows with Visual Studio/MSBuild.
- Tight Win32/COM integration and best-in-class debugging/profiling in the Microsoft ecosystem.
- Syntax/warning behavior can differ from Clang/GCC; cross-platform projects rely on continuous testing across `cl.exe`.

## Additional Toolchains
- **LLVM (upstream)**: Community Clang builds on Linux/Windows; `clang-cl` provides MSVC-compatible command line.
- **Intel oneAPI**: Performance-targeted compilers (`icx/icpx`) layered on LLVM.
- **NVIDIA NVCC**: Compiles CUDA C++, invoking host compilers (Clang/GCC/MSVC) under the hood.

## Choosing & Matching Compilers
- Match your team’s production compiler versions to catch ABI or warning differences early.
- Keep projects building cleanly under both Clang and GCC; add MSVC if Windows support is on the roadmap.
- Standardize warning flags (e.g., `-Wall -Wextra -pedantic`, `/W4 /permissive-`) and sanitizer support so practice mirrors production.

## Installing on macOS
- **Apple Clang**: `xcode-select --install` (Command Line Tools).
- **GNU GCC**: `brew install gcc` (makes `g++-XX` binaries available).
- **LLVM Clang**: `brew install llvm` (newer Clang with lld, clang-tidy, etc.).

Documenting this ensures teammates understand how builds are configured and which compilers to test against.
