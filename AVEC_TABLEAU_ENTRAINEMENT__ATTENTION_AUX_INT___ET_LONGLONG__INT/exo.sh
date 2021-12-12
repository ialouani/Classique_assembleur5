#!/bin/bash
gcc -std=c99 exo_dernier.c -o test -ldl
echo "Entrez l'expression post-fixe voulu: "
read -r expression
./test $expression
