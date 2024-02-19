#!/bin/bash

RED='tput setaf 1'
GREEN='tput setaf 2'
DEFAULT='tput sgr0'

success=0
error=1

if [ "$1" -lt 10 ]; then
    args_file=func_tests/data/pos_0"$1"_args.txt
    input_file=func_tests/data/pos_0"$1"_data.txt
    output_file=func_tests/data/pos_0"$1"_out.txt
else
    args_file=func_tests/data/pos_"$1"_args.txt
    input_file=func_tests/data/pos_"$1"_data.txt
    output_file=func_tests/data/pos_"$1"_out.txt
fi

args=$(cat "$args_file")

eval ./app.exe ${args} > out.txt
rc=$?

output_test=out.txt

if [ ${rc} -ne 0 ]; then
    echo "$input_file: $($RED)FAILED $($DEFAULT)rc = ${rc}"
    eval rm out.txt
    exit ${error}
fi

f1=$output_test
f2=$output_file

f1_out=$(cat "$f1")
f2_out=$(cat "$f2")

if [[ "$f1_out" == "$f2_out" ]]; then
    exit 0
fi

res=$?

if [ "$res" -eq 0 ]; then
    echo "$input_file: $($GREEN)Passed $($DEFAULT)rc == ${rc}"
    eval rm out.txt
    exit ${success}
else
    echo "$input_file: $($RED)Failed $($DEFAULT)rc == ${rc}"
    eval rm out.txt
    exit ${error}
fi
