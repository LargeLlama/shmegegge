all: server.o
	@gcc -o shmegegge server.o

server.o: server.c
	@gcc -c server.c

clean:
	@rm *.o
	@rm shmegegge

run:
	@./shmegegge

