CC := gcc

CFLAGS := -std=c99 -g3

OFILES := car.o mio.o
	
main.exe : main.o $(OFILES)
	$(CC) -o main.exe main.o $(OFILES)

main.o : main.c car.h mio.h
	$(CC) $(CFLAGS) -c main.c

mio.o : mio.c mio.h
	$(CC) $(CFLAGS) -c mio.c	
	
car.o : car.c car.h mio.h
	$(CC) $(CFLAGS) -c car.c
	
clean :
	rm *.o *.exe *.creator.*
