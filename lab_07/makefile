CC := gcc

CFLAGS := -std=c99 -Wall -Werror -pedantic -g3

OFILES := tree.o hash.o

main.exe : main.o $(OFILES)
	$(CC) -o main.exe main.o $(OFILES)
	
main.o : main.c methods.h
	$(CC) $(CFLAGS) -c main.c

tree.o : tree.c methods.h
	$(CC) $(CFLAGS) -c tree.c

hash.o : hash.c methods.h
	$(CC) $(CFLAGS) -c hash.c

clean :
	rm *.o *.exe *.creator.user.*
