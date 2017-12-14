all: p1 p2 p3
	gcc -o program *.o
p1: main.c database.c menu.h	#have menu.h bc its used in main.c so if make change to menu.h, want gcc to re-compile main.c
	gcc -c main.c database.c

p2: menu.c divide+conquer.c database.h p3.h #p3.h bc it requires p3's files
	gcc -c menu.c divide+conquer.c

p3: fact.c fib.c csv.c library.c #easy bc doesn't depend on anything
	gcc -c fact.c fib.c csv.c library.c

bacbup:		#copy files int ./mybackup folder, create if necessary
	mkdir -p mybackup #-p so won't compain (will preceed to next line) if mybackup already exists
	cp *.c mybackup
	cp *.h mybackup

clean:		#removes all *.o
	rm *.o
