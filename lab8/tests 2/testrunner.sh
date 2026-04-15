#!/bin/bash
COMPILER=./k0

for dir in tests/k0 tests/kotlin tests/errors
do
  for file in $dir/*.kt
  do
    echo "===== Testing $file ====="
    $COMPILER "$file"
    echo
  done
done
