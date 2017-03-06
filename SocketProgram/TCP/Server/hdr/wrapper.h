/****************************************************/
/* DESCRIPTION : Header File for TCP Server         */
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
socklen_t CliLen;
socklen_t Addrlen;
char buf[200];
int sd,conn;
int Init();
int Create_Socket();
void Listen_Socket(int sd);
int Recv(int sd,char *buf,int len,struct sockaddr_in* from_addr);
int Bind_Socket(int sd, struct sockaddr_in* my_addr );
void Recev();
