#!/bin/bash

YELLOW='tput setaf 3'

eval func_tests/scripts/tests.sh
echo
echo "$($YELLOW)Coverage..."
cd ./out
