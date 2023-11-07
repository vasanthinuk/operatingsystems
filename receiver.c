#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main()
{
	int res, n;
	char buffer[100];
	res = open("fifo1",O_RDONLY);
	n = read(res,buffer,100);
	printf("Reader process having PID is %d started\n",getpid());
	printf("Data received by receiver %d is:%s\n",getpid(),buffer);
	return 0;
}
