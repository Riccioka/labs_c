#!/bin/bash

RED='tput setaf 1'
GREEN='tput setaf 2'
DEFAULT='tput sgr0'

success=0
error=1

if [ "$1" -lt 10 ]; then
    args_file=func_tests/data/neg_0"$1"_args.txt
    input_file=func_tests/data/neg_0"$1"_data.txt
else
    args_file=func_tests/data/neg_"$1"_args.txt
    input_file=func_tests/data/neg_"$1"_data.txt
fi

args=$(cat "$args_file")

eval ./app.exe ${args} > out.txt
rc=$?

if [ ${rc} -ne 0 ]; then
    echo "$input_file: $($GREEN)Passed $($DEFAULT)rc == ${rc}"
    eval rm out.txt
    exit ${success}
else
    echo "$input_file: $($RED)Failed $($DEFAULT)rc == ${rc}"
    eval rm out.txt
    exit ${error}
fi
