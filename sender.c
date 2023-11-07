#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<mqueue.h>
#include<string.h>

#define MAX 100

int main(void)
{
	struct mq_attr attr;
	mqd_t mqd;
	int send;
	int get;
	char buff[MAX];
	mqd = mq_open("/msgqueue",O_WRONLY,0666,&attr);
	if(mqd < 0)
	{
		perror("Error:");
		exit(1);
	}

	printf("Enter a message into message queue:\n");
	fgets(buff,MAX,stdin);
	buff[strlen(buff) -1] = '\0';

	send = mq_send(mqd,buff,strlen(buff),0);//sending a message to message queue
	if(send < 0)
	{
		perror("Error:");
		exit(1);
	}

	printf("The data entered into the message queue is:%s\n",buff);
	get = mq_getattr(mqd,&attr);

	if(get < 0)
	{
		perror("Error:");
		exit(1);
	}

	printf("Number of messages is:%ld\n",attr.mq_maxmsg);
	printf("The message size in message queue is:%ld\n",attr.mq_msgsize);
	printf("The no. of msgs in message queue is:%ld\n",attr.mq_curmsgs);
	mq_close(mqd);
	return 0;
}



