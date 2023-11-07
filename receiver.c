#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>
#include<mqueue.h>

#define MAX 100

int main(void)
{
	struct mq_attr attr;
	char buff1[MAX];
	int receive;
	mqd_t mqd;
	mqd = mq_open("/msgqueue",O_RDONLY,0666,&attr);
	if(mqd < 0)
	{
		perror("Error:");
		exit(1);
	}
	 
	receive = mq_receive(mqd,buff1,sizeof(buff1),NULL);
	if(receive < 0)
	{
		perror("Error:");
		exit(1);
	}
	printf("The data from sender to message queue is:%s\n",buff1);
	mq_close(mqd);
	return 0;
}
	
