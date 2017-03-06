/****************************************************/
/* DESCRIPTION : Header File for TCP Client         */
/* FILE NAME   : wrapper.h                          */
/* VERSION     : 1.0                                */
/* AUTHOR      :SUBHRA PRAKASH GIRI                 */
/****************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_NO 8000
#define BUF_SIZE 200
#define SERVERIP 127.0.0.1
struct sockaddr_in ServerAddr;
struct sockaddr_in ClientAddr;
int SockFd;
char buf[200];

int Init();
int Create_Socket();
int Recv(int sd,int *buf,int len,struct sockaddr_in* from_addr);
int Send(int sd,char * buf,int len,struct sockaddr_in* to_addr);
int Connect(int sd,struct sockaddr_in* ServerAddr);
