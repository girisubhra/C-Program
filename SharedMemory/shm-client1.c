#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
int main()
{
	int shmid;
    	key_t key = 0x01020204;
    	char *s,*shm;
    	shmid = shmget(key, 50, IPC_CREAT|0666);
    	if (shmid < 0) 
	{
        	fprintf(stderr, "failed to create shm segment\n");
        	perror("shmget");
        	return -1;
    	}

    	printf("found %d\n", shmid);

    	shm= shmat(shmid, NULL, 0);
    	if (shm ==(char *) -1) 
	{
        	fprintf(stderr, "failed to attach\n");
        	perror("shmat");
        	return -1;
    	}

    	printf("got %p\n", shm);

    	s=shm;
    	printf("Data %s\n",s);
    return 0;
}
