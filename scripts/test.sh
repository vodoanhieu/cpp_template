#!/bin/bash
set -e
echo "==> Running Automated Unit Tests..."
ctest --test-dir build --output-on-failure
