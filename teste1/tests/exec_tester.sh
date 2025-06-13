#!/bin/bash

if [ -z "$1" ]; then
  echo "Erro: Você deve fornecer um valor para BUFFER_SIZE."
  echo "Uso: ./run_tests.sh <BUFFER_SIZE>"
  exit 1
fi

BUFFER_SIZE=$1

RESULTS_DIR="results"
cc -Wall -Werror -Wextra -D BUFFER_SIZE=${BUFFER_SIZE} -I ../. tester_gnl.c ../get_next_line.c ../get_next_line_utils.c -o gnltester
valgrind --leak-check=full -s ./gnltester && ./gnltester > ${RESULTS_DIR}/buffersize${BUFFER_SIZE}_text.txt

