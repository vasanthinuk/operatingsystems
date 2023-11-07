#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>
#include<mqueue.h>


int main()
{
	struct mq_attr attr;
	attr.mq_maxmsg = 10;
	attr.mq_msgsize = 100;
	attr.mq_curmsgs = 0;
	mqd_t mqd;
	mqd = mq_open("/msgqueue",O_CREAT,0666,&attr);
	if(mqd < 0)
	{
		perror("Error:");
		exit(1);
	}
	printf("Message queue created\n");
	mq_close(mqd);
	return 0;
}
