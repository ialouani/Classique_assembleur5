#!/bin/bash
gcc -std=c99 -o test_dynamique exo2.c -ldl
echo "Entrez l'expression postfixe a evaluer: "
read -r expression
echo "Entrez la valeur de a: "
read -r a
echo "Entrez la valeur de b: "
read -r b
./test_dynamique $expression $a $b
