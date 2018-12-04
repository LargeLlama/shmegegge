all: server.o
	@gcc -o shmegegge server.o

server.o: server.c
	@gcc -c server.c

client.o: client.c
	@gcc -c client.c

clean:
	@rm *.o
	@rm shmegegge

run:
	@./shmegegge

