#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<wait.h>

//#define READ_END 0
//#define WRITE_END 1
#define MAX 100

int main()
{
	pid_t pid;
	int fd[2];
	char buff[] = "Hi Vasanthi";
	char buff1[MAX];
	int num = pipe(fd);
	if(num < 0)
	{
		perror("Error:");
		exit(1);
	}
	pid = fork();
	if(pid < 0)
	{
		perror("Error:");
		exit(1);
	}
	else if(pid > 0)
	{
		printf("Parent process created\n");
		printf("Parent process id is:%d\n",getppid());
		printf("Child process id is:%d\n",getpid());
		close(fd[0]);
		write(fd[1],buff,sizeof(buff));
		printf("The message from parent is:%s\n",buff);
		close(fd[1]);
	}

	else
	{
	
		printf("Child process created\n");
		printf("Child process id is:%d\n",getpid());
		printf("The parent process id is:%d\n",getppid());
		close(fd[1]);
		read(fd[0],buff1,MAX);
		printf("The message read by child is:%s\n",buff1);
		close(fd[0]);
	}
	return 0;
}
		


