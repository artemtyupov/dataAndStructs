CC := gcc

CFLAGS := -std=c99 -Wall -Werror -pedantic -g3

OFILES := task.o io.o

main.exe : main.o $(OFILES)
	$(CC) -o main.exe main.o $(OFILES)
	
main.o : main.c head.h
	$(CC) $(CFLAGS) -c main.c

task.o : task.c head.h
	$(CC) $(CFLAGS) -c task.c

io.o : io.c head.h
	$(CC) $(CFLAGS) -c io.c

clean :
	rm *.o *.exe *.creator.user.*
