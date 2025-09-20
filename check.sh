#!/bin/bash
set -e

echo "=== check.sh starting ==="

# Compile
gcc -Wall -Werror -std=c99 -o bin/ex2q1 src/ex2q1.c -lm
gcc -Wall -Werror -std=c99 -o bin/ex2q2 src/ex2q2.c -lm

# Run testcases for ex2q1
echo "Running testcases for ex2q1..."
for input in Testcases/1-*-input.txt; do
    output="${input/-input.txt/-student.txt}"
    echo "  Test: $input -> $output"
    ./bin/ex2q1 < "$input" >| "$output" || true
    diff -u "${input/-input.txt/-output.txt}" "$output"
done

# Run testcases for ex2q2
echo "Running testcases for ex2q2..."
for input in Testcases/2-*-input.txt; do
    output="${input/-input.txt/-student.txt}"
    echo "  Test: $input -> $output"
    ./bin/ex2q2 < "$input" >| "$output" || true
    diff -u "${input/-input.txt/-output.txt}" "$output"
done

echo "=== check.sh finished ==="
