CFLAGS= -std=c99
ASSEMBLY_FLAGS= -felf64
all: test2_execution
generateur_compilateur_level1: exo2.sh
	./exo2.sh
calcule.o: generateur_compilateur_level1 calcule.s
	yasm $(ASSEMBLY_FLAGS) calcule.s
test1: calcule.o calcule.c
	gcc $(CFLAGS) -o test1 calcule.o calcule.c
test2_execution: test1 exo3.sh
	./exo3.sh
clean:
	rm -f compilateur_level0 *.o *.c~ *.s~ *.sh~ test1
