#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

int main()
{
	int key = 1234;
	int shm_id = shmget(key, 200 * sizeof(char), 0666);

	if (shm_id < 0)
	{
		printf("Error in accessing shared memory block\n");
		exit(1);
	}

	printf("This is the client\n");

}
