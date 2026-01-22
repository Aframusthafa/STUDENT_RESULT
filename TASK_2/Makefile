CC = gcc
CFLAGS = -Wall

input.o: input.h input.c
	$(CC) $(CFLAGS) -c input.c -o input.o

validation.o: validation.h validation.c
	$(CC) $(CFLAGS) -c validation.c -o validation.o

computation.o: computation.h computation.c
	$(CC) $(CFLAGS) -c computation.c -o computation.o

input: input.o validation.o computation.o
	$(CC) $(CFLAGS) input.o validation.o computation.o output.c -o input



all: input 

clean:
	rm -f *.o input 