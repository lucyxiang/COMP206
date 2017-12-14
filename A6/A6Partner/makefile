ass6: main.o producer.o consumer.o
	gcc -o ass6 main.o producer.o consumer.o
main.o: main.c
	gcc -c main.c
producer.o: producer.o main.h
	gcc -c producer.c
consumer.o: consumer.o main.h
	gcc -c consumer.c
clean:
	rm *.o
	rm TURN.txt
	rm DATA.txt
	rm ass6
