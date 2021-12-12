#!/bin/bash
#compilateur_level0
gcc -std=c99 exo2.c -o compilateur_level0
echo "Entrez l'expression postfixe a evaluer: "
read -r expression
./compilateur_level0 $expression
