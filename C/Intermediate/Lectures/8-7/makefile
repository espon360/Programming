all: minmax2

minmax2: minmax2.o mymath.o mymath2.o
	 gcc -o minmax2 minmax2.o mymath.o mymath2.o

minmax2.o: minmax2.c
	 gcc -c minmax2.c

mymath.o: mymath.c
	 gcc -c mymath.c

mymath2.o: mymath2.c
	 gcc -c mymath2.c
     
clean:
	 rm minmax2.o mymath.o mymath2.o minmax2


