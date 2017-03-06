/****************************************************/
/* DESCRIPTION : TCP Client main file               */
/*                                                  */
/* FILE NAME   : client.c                           */
/* VERSION     : 1.0                                */
/* AUTHOR      :SUBHRA PRAKASH GIRI                 */
/****************************************************/
#include <stdio.h>
#include "wrapper.h"
int main()
{
	Init();
	/*connect=Connect(SockFd,&ServerAddr);*/
        connect(SockFd,(struct sockaddr *)&ServerAddr,sizeof(ServerAddr));
	strcpy(buf,"SAI RAM");
	Send(SockFd,buf,BUF_SIZE,&ServerAddr);
	
	return 1;
}
