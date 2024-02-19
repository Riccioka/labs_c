#!/bin/bash

count=0
files=$(find func_tests/data -name '\pos*args.txt')

echo "POSITIVE TESTS:"
for _ in $files; do
    count=$(( count + 1 ))
    eval ./func_tests/scripts/pos_tests.sh "$count"
done

count=0
files=$(find func_tests/data -name '\neg*args.txt')
echo "NEGATIVE TESTS:"
for _ in $files; do
    count=$(( count + 1 ))
    eval ./func_tests/scripts/neg_tests.sh "$count"
done
