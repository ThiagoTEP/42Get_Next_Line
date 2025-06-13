#!/bin/bash

if [ -z "$1" ]; then
  echo "Erro: Você deve fornecer um valor para BUFFER_SIZE."
  echo "Uso: ./run_tests.sh <BUFFER_SIZE>"
  exit 1
fi

BUFFER_SIZE=$1

RESULTS_DIR="results"
cc -Wall -Werror -Wextra -D BUFFER_SIZE=${BUFFER_SIZE} -I ../. tester_gnl_bonus.c ../get_next_line_bonus.c ../get_next_line_utils_bonus.c -o gnltester_bonus
valgrind --leak-check=full -s ./gnltester_bonus && ./gnltester > ${RESULTS_DIR}/buffersize${BUFFER_SIZE}_text.txt