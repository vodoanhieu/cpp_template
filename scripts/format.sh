#!/bin/bash
set -e
echo "==> Auto formatting C++ code with clang-format..."
clang-format -i include/my_lib/*.hpp src/*.cpp tests/*.cpp
echo "==> Formatting completed!"