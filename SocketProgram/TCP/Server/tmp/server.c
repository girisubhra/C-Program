#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{
	int sockfd,confd,retval;
	int len,rbytes,sbytes;
	char buf[200];
	socklen_t clilen;
	struct sockaddr_in cliaddr,servaddr;

	sockfd = socket(AF_INET,SOCK_STREAM,0);
	servaddr.sin_family= AF_INET;
	servaddr.sin_port=htons(8000);
	servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
	memset((&servaddr.sin_zero),0,8);
	
	retval=bind(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
	listen(sockfd,5);
	while(1)
	{
		clilen=sizeof(cliaddr);
		confd=accept(sockfd,(struct sockaddr *)&cliaddr,&clilen);
		rbytes=recvfrom(confd,buf,len,0,(struct sockaddr *)&cliaddr,&clilen);
		printf("received messages is %s\n",buf);
	}
}
