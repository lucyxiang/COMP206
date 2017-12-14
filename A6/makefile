program: producer.o consumer.o main.o
	gcc -o program producer.c consumer.c main.c
producer.o: producer.c
	gcc -c producer.c
consumer.o: consumer.c
	gcc -c consumer.c
main.o: main.c
	gcc -c main.c
backup:
	cp *.c/home/project/backup
