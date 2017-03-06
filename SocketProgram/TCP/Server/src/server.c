/****************************************************/
/* DESCRIPTION : TCP Server main file               */
/*                                                  */
/* FILE NAME   : server.c                           */
/* VERSION     : 1.0                                */
/* AUTHOR      :SUBHRA PRAKASH GIRI                 */
/****************************************************/

#include <stdio.h>
#include "wrapper.h"
int main()
{
	Init();
	while(1)
        {
        	socklen_t CliLen;
                CliLen = sizeof(ClientAddr);
                conn=accept(sd,(struct sockaddr *)&ClientAddr,&CliLen);
                /*conn = Accept_Connection(sd,&ClientAddr);*/
                Recv(conn,buf,BUF_SIZE,&ClientAddr);
		printf("Received data is %s\n",buf);
        }
	return 1;
}
