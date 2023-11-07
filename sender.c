#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/stat.h>
#include<stdlib.h>

#define MAX 100

int main()
{
	int res;
	int n;
	res = mkfifo("fifo1",0777);
	if(res < 0)
	{
		perror("Error:");
		exit(1);
	}
	n = open("fifo1",O_WRONLY);
	write(n,"Helloworld",7);
	printf("Sender process having PID %d sent the data\
	n",getpid());
	return 0;
}


