# Quadratic Equation Solver: Engineering Edition

Solving $ax^2 + bx + c = 0$ might seem simple, but doing it correctly in production-grade C code requires handling floating-point errors, buffer overflows, and edge cases. This project is a demonstration of academic rigor applied to basic computational tasks.

## Why this isn't just a "homework" project
Most solvers fail when faced with IEEE 754 precision issues or invalid input. This implementation focuses on:

1. **Floating-Point Precision:** Uses epsilon-based comparisons ($\epsilon$) instead of direct equality checks. This correctly handles precision loss and ensures that values near zero (like `-0.0000000001`) don't break the logic.
2. **Automated Unit Testing:** Includes a dedicated test engine that reads test cases from an external file (`file.txt`). It automatically verifies coefficients against expected roots, making it easy to run regression tests after any code change.
3. **Bulletproof I/O:** The input parser is designed to stay alive. It handles non-numeric characters, extra spaces, and sudden EOF signals without entering infinite loops or crashing.
4. **State Management:** Uses a clear state machine to handle different equation types (linear, quadratic, infinite roots, or no roots) ensuring no "else" branches are left unhandled.

## Build System
The project is fully modular and uses a `Makefile` for clean compilation.

```bash
make            # Compile everything
./program.exe   # Run in interactive or test mode