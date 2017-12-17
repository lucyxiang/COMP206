program: list.o main.o
	gcc -o program list.o main.o
main.o: main.c list.h
	gcc -c main.c
list.o: list.c list.h
	gcc -c list.c
