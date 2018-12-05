all: main.o
	@gcc -o shmegegge main.o

main.o: main.c
	@gcc -c main.c

clean:
	@rm *.o
	@rm shmegegge

run:
	@./shmegegge

