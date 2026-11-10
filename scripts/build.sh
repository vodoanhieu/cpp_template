#!/bin/bash
set -e
echo "==> Configuring and Building Project (Release Mode)..."
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build
echo "==> Build finished successfully!"
