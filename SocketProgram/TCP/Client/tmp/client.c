#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{
	int sockfd,retval;
	int len,sbytes;
	char buf[200];
	//socklen_t servlen;
	struct sockaddr_in servaddr;

	sockfd = socket(AF_INET,SOCK_STREAM,0);
	servaddr.sin_family= AF_INET;
	servaddr.sin_port=htons(8000);
	servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
	memset((&servaddr.sin_zero),0,8);
	
	retval=connect(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
	strcpy(buf,"SAI BABA");
	sbytes=sendto(sockfd,buf,8,0,(struct sockaddr *)&servaddr,sizeof(struct sockaddr));
}
