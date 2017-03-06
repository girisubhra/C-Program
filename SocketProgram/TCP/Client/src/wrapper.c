/****************************************************/
/* DESCRIPTION : C file for TCP Socket wrapper      */
/*               Functions.                         */
/* FILE NAME   : wrapper.c                          */
/* VERSION     : 1.0                                */
/* AUTHOR      :SUBHRA PRAKASH GIRI                 */
/****************************************************/

#include "wrapper.h"
int Init()
{

	ServerAddr.sin_family = AF_INET;
	ServerAddr.sin_port = htons(PORT_NO);
	ServerAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	memset((&ServerAddr.sin_zero),0,8);
	Create_Socket();
	return 1;
}
int Create_Socket()
{
        if((SockFd= socket(AF_INET, SOCK_STREAM, 0))==-1)
        {
                perror("socket");
        }
        return SockFd;

}
int Recv(int sd,int *buf,int len,struct sockaddr_in* from_addr)
{
        int Rcvdbytes;
        socklen_t Addrlen = sizeof(struct sockaddr);

        Rcvdbytes = recvfrom(sd,buf,len,0,(struct sockaddr *)from_addr, &Addrlen);
        if(Rcvdbytes == -1)
        {
                perror("recvfrom");
        }
        return Rcvdbytes;
}
int Send(int sd,char * buf,int len,struct sockaddr_in* to_addr)
{
        int Sntbytes;
	printf("Sending .....\n");
        Sntbytes = sendto(sd, buf, len, 0,(struct sockaddr *)to_addr, sizeof(struct sockaddr));
        if(Sntbytes == -1)
        {
                perror("sendto ERROR_DECOMP_TX");
        }
        return Sntbytes;
}

int Connect(int sd,struct sockaddr_in* ServerAddr)
{
	int ret;
	ret=connect(sd,(struct sockaddr*)&ServerAddr,sizeof(ServerAddr));
	return ret;
}
