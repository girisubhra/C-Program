/****************************************************/
/* DESCRIPTION : C file for TCP Socket wrapper      */
/*		 Functions.                         */
/* FILE NAME   : wrapper.c                          */
/* VERSION     : 1.0                                */
/* AUTHOR      :SUBHRA PRAKASH GIRI                 */
/****************************************************/
#include "wrapper.h"
int Init()
{
	
	printf("init success\n");
	ServerAddr.sin_family = AF_INET;
	ServerAddr.sin_port = htons(PORT_NO);
	ServerAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	memset((&ServerAddr.sin_zero),0,8);
        sd = Create_Socket();
	Bind_Socket(sd,&ServerAddr);
	Listen_Socket(sd);
	printf("init success\n");
	return 1;
}
int Create_Socket()
{
	int SockFd=0;

	printf("Socket creation success\n");
        if((SockFd= socket(AF_INET, SOCK_STREAM, 0))==-1)
        {
                perror("socket");
        }
	printf("Socket creation success\n");
        return SockFd;

}
int Bind_Socket(int sd, struct sockaddr_in* my_addr )
{
	int retval;

        if((retval = bind(sd,(struct sockaddr *)my_addr, sizeof(struct sockaddr))==-1))
        {
                perror("bind  under test");
        }
	printf("bind success\n");
        return retval;
}
void Listen_Socket(int sd)
{
	listen(sd,5);
	printf("listen success\n");
}


int Accept_Connection(int sd,struct sockaddr_in *ClientAddr)
{
	CliLen = sizeof(ClientAddr);
	
	printf("Pre Accept \n");
	conn=accept(sd,(struct sockaddr *)&ClientAddr,&CliLen);
		
	printf("Accept Success\n");
	return 1;
}

int Recv(int sd,char *buf,int len,struct sockaddr_in* from_addr)
{
        int Rcvdbytes;
        Addrlen = sizeof(struct sockaddr);
        Rcvdbytes = recvfrom(sd,buf,len,0,(struct sockaddr *)from_addr, &Addrlen);
	if(Rcvdbytes == -1)
        {
                perror("recvfrom");
        }
        return Rcvdbytes;
}
void Recev()
{
printf("hello recv\n");
}
