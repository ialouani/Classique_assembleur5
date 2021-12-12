CFALGS= -std=c99



calculatrice_polonaise_inverse: exo1.c
	gcc $(CFLAGS) exo1.c -o calculatrice_polonaise_inverse
execution_test: calculatrice_polonaise_inverse
	./calculatrice_polonaise_inverse
temps_execution: temps_execution.sh
	./temps_execution.sh
#temps diminue car script.(deja appel au bash comparant avec
#normal execution sur le terminal ou il ré-appelera bash)
#make temps_execution + ce qu'on a ajoute(qst3)=>adaptation vrai
#temps d'execution.
clean:
	rm -f *.s~ *.sh~ *.c~ calculatrice_polonaise_inverse 
