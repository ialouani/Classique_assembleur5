all: exo.sh
	./exo.sh
clean:
	rm -f test *.s~ *.c~ *.sh~ *.o 
#tests suivant un boucle sur des elements en correspondance non ==0
#PAR CONVENTION (ASTUCE: convertir(*s) en typecast LONG LONG INT
#et pas de comparaison avec 0 dans ce cas direct..>>2 registre nul au passage
#(lea pas MIEUX direct), et!!::: mov r10,0 apres global fonction a l'interieur
#du target fonction (calculer ICI).//////  .
