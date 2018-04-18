CC := gcc

CFLAGS := -std=c99 -Wall -Werror -pedantic -g3

OFILES := automat.o queue.o tick.o

main.exe : main.o $(OFILES)
	$(CC) -o main.exe main.o $(OFILES)
	
main.o : main.c automat.h queue.h tick.h
	$(CC) $(CFLAGS) -c main.c

automat.o : automat.c queue.h
	$(CC) $(CFLAGS) -c automat.c

queue.o : queue.c
	$(CC) $(CFLAGS) -c queue.c
	
tick.o : tick.c queue.h automat.h
	$(CC) $(CFLAGS) -c tick.c
	
test.o : test.c automat.h queue.h tick.h
	$(CC) $(CFLAGS) -c test.c

clean :
	rm *.o *.exe *.creator.user.*
