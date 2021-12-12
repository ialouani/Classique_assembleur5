#!/bin/bash
touch file
gcc -std=c99 exo1.c
time ./a.out > file
line1=$(head -n 3 file)
line2=$(head -n 4 file)
line3=$(head -n 5 file)
read -r line1<file
read -r line2<file
read -r line3<file
rm -f a.out file
