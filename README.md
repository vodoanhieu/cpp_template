# C++ Engineering Template

Production-ready C++ project template using Modern CMake, CTest and clang-format.

## Requirements

- CMake 3.16 or newer
- GCC, Clang or MSVC with C++17 support
- clang-format

## Directory Structure

- `include/`: Public interface headers (`.hpp`).
- `src/`: Core implementation source files (`.cpp`).
- `tests/`: Automated unit tests returning a non-zero exit code on failure.
- `scripts/`: Shell automation scripts (`build.sh`, `test.sh`, `format.sh`).
- `CMakeLists.txt`: Strict build configuration with target-level compiler warnings.

## Build and Run

### Method 1: Automation Scripts
Grant execution permission once:
```bash
chmod +x scripts/*.sh
```

Format the source code:
```bash
./scripts/format.sh
```

Configure and build the project in Release mode:
```bash
./scripts/build.sh
```

Run the automated tests:
```bash
./scripts/test.sh
```

Check formatting without modifying source files:
```bash
cmake --build build --target format-check
```

Run the main application:
```bash
./build/main_app
```

### Method 2: Manual CMake Commands

Configure the project:
```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
```

Build all targets:
```bash
cmake --build build
```

Run the application:
```bash
./build/main_app
```

Run the test suite:
```bash
ctest --test-dir build --output-on-failure
```

Check formatting:

```bash
cmake --build build --target format-check
```