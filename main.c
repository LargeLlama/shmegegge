#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/shm.h>

int main()
{
	//declare the variables
	key_t key;
	int shm_id;
	char * contents;

	//initialize the variables
	key = ftok("file",'b');
	shm_id = shmget(key, 200, 0666 | IPC_CREAT);

	//error handling
	//NOTE: Strange error sometimes stating that permission is denied - fixed by running make and make run
	//as sudo and then you don't need to run it as sudo again - not sure why
	if(shm_id < 0)
	{
		perror("shmget");
		exit(1);
	}

	//set contents equal to whatever is already present
	contents = shmat(shm_id, (void *)0, 0);

	//if it is empty, let the user know the seg has been created
	//else, print out the contents
	if(!contents[0])
	{
		printf("No segment found, segment has been created!\n");
	}
	else
	{
		printf("Segment found! Contents:\n%s\n",contents);
	}

	//prompt to change contents and take user input
	printf("Do you want to change contents?('yes' and 'no' are the only valid options!)\n");

	char response[200];
	fgets(response, 200, stdin);

	//if yes, takes more user input on what they want to replace the contents with
	if (!strcmp(response,"yes\n"))
	{
		printf("Enter what you want to replace the contents\n");
		fgets(response, 200, stdin);
		//strip the newline
		response[strlen(response) - 1] = "\0";
		strcpy(contents, response);
	}

	//prompt to delete the contents
	printf("Do you want to delete contents?('yes' and 'no' are the only valid options!)\n");
	fgets(response, 100, stdin);

	//if yes, then delete them, otherwise just return 0 and finish the program
	if (!strcmp(response,"yes\n"))
	{
		shmdt( contents );
		shmctl(shm_id, IPC_RMID, NULL);
		printf("Contents have been deleted!\n");
	}

	return 0;
}
