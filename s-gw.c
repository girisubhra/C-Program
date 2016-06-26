#include "headers.h"

int main ()
{
	u_char buffer[1500],buff[1000];
	int sock,length,paclength;
	
	struct sockaddr_in mme,sgw;

	bzero(&mme,sizeof(mme));	
	bzero(buffer,sizeof(buffer));
	bzero(buffer,sizeof(buff));
	length=sizeof(sgw);

	mme.sin_family=AF_INET;
	mme.sin_addr.s_addr=htonl(INADDR_ANY);
	mme.sin_port=htons(2123);

	if((sock=socket(PF_INET,SOCK_DGRAM,0))==-1)
	{
		perror("\nSocket Error: ");
		return -1;
	}

	if(bind(sock,(struct sockaddr *)&mme,sizeof(mme))==-1)
	{
		perror("\nBind error: ");
		return -1;
	}
	
		
	while(1) 
	{ 
		if(recvfrom(sock,buffer,sizeof(buffer),0,(struct sockaddr *)&sgw,&length)==-1)
		{
			perror("\nRecvFrom error: ");
			return -1;
		}
		printf("\nPacket from MME Received\n");
	
		k=(gtp *)buffer;
		printf("this is what i got -- message type: %d, teid : %X, seq_no : %X",k->m_type,ntohl(k->teid),ntohs(k->seq_no));
	
		if(k->m_type == 32)
		{
			printf("\nCreate session request received ");
			g=(gtp *)buff;
			g->flags=0x48;
			g->m_type=0x21;
			g->m_length=htons(8+sizeof(cause)+sizeof(paa)+sizeof(fteid)+sizeof(fteid)+sizeof(apn_rest)+sizeof(bearer_cont));
			g->teid=htonl(0x10c8eb);
			g->seq_no=htons(0x0001);
			g->spare=0x0000;
		
			nCause=(cause *)(buff+sizeof(gtp));		
			nCause->type=0x02;
			nCause->length=htons(2);
                	nCause->flags=0x00;
                	nCause->value=0x10;
                	nCause->flags1=0x00;

			nPaa=(paa *)(buff+sizeof(gtp)+sizeof(cause));
			nPaa->type=0x4f;
			nPaa->length=htons(5);
			nPaa->flags=0x00;
			nPaa->pdn_type=0x01;
			nPaa->pdn_addr=inet_addr("172.16.0.201");

			nFteid=(fteid *)(buff+sizeof(gtp)+sizeof(cause)+sizeof(paa));
			nFteid->type=0x57;
			nFteid->length=htons(9);
			nFteid->flags=0x00;
			nFteid->f_flags=0x8b;
			nFteid->teid_gre=htonl(0x64);
			nFteid->ip_addr=inet_addr("172.0.0.1");
		
			nFteid1=(fteid *)(buff+sizeof(gtp)+sizeof(cause)+sizeof(paa)+sizeof(fteid));
                	nFteid1->type=0x57;
                	nFteid1->length=htons(9);
                	nFteid1->flags=0x01;
                	nFteid1->f_flags=0x87;
                	nFteid1->teid_gre=htonl(0x01);
                	nFteid1->ip_addr=inet_addr("172.0.0.1");
	
			nApn_rest=(apn_rest *)(buff+sizeof(gtp)+sizeof(cause)+sizeof(paa)+sizeof(fteid)+sizeof(fteid));
			nApn_rest->type=0x7f;
			nApn_rest->length=htons(1);
			nApn_rest->flags=0x01;
			nApn_rest->rest_value=0xff;

			nBearer_cont=(bearer_cont *)(buff+sizeof(gtp)+sizeof(cause)+sizeof(paa)+sizeof(fteid)+sizeof(fteid)+sizeof(apn_rest));
			nBearer_cont->type=0x5d;
			nBearer_cont->length=htons(45);
			nBearer_cont->flags=0x00;
			nBearer_cont->eb_id.type=0x49;
			nBearer_cont->eb_id.length=htons(1);
			nBearer_cont->eb_id.flags=0x00;
			nBearer_cont->eb_id.eps_id=0x00;
			nBearer_cont->charging_char.type=0x5e;
			nBearer_cont->charging_char.length=htons(4);
			nBearer_cont->charging_char.flags=0x00;
			nBearer_cont->charging_char.value=htonl(0x00);
			nBearer_cont->ftid.type=0x57;
			nBearer_cont->ftid.length=htons(9);
			nBearer_cont->ftid.flags=0x00;
			nBearer_cont->ftid.f_flags=0x81;
			nBearer_cont->ftid.teid_gre=htonl(0x044c);
			nBearer_cont->ftid.ip_addr=inet_addr("22.22.22.24");
			nBearer_cont->ft_id.type=0x57;
                	nBearer_cont->ft_id.length=htons(9);
                	nBearer_cont->ft_id.flags=0x01;
                	nBearer_cont->ft_id.f_flags=0x85;
                	nBearer_cont->ft_id.teid_gre=htonl(0x044c);
                	nBearer_cont->ft_id.ip_addr=inet_addr("22.22.22.24");
			nBearer_cont->_cause.type=0x02;
			nBearer_cont->_cause.length=htons(2);
			nBearer_cont->_cause.flags=0x00;
			nBearer_cont->_cause.value=0x10;
			nBearer_cont->_cause.flags1=0x00;
	
  	        	paclength=4+ntohs(g->m_length);
                	if(sendto(sock,buff,paclength,0,(struct sockaddr *)&sgw,sizeof(sgw  ))==-1)
			{
                        	perror("\nSend: ");
                          	return -1;
                	}		
        		printf("\nCreate Session Response sent\n");
		} 		
		
		else if(k->m_type == 34)
		{
			printf("\nModify Bearer Request Received");
			g=(gtp *)buff;
			g->flags=0x48;
			g->m_type=0x23;
			g->m_length=htons(8+sizeof(cause)+sizeof(bearer_cont1));
			g->teid=htonl(0x10c8eb);
			g->seq_no=htons(0x0002);
			g->spare=0x0000;
	
			nCause=(cause *)(buff+sizeof(gtp));
			nCause->type=0x02;
			nCause->length=htons(2);
			nCause->flags=0x00;
			nCause->value=0x10;
			nCause->flags1=0x00;

			nBearer_cont1=(bearer_cont1 *)(buff+sizeof(gtp)+sizeof(cause));
                	nBearer_cont1->type=0x5d;
                	nBearer_cont1->length=htons(sizeof(ebi)+sizeof(cause)+sizeof(fteid));
                	nBearer_cont1->flags=0x00;
                	nBearer_cont1->eb_id.type=0x49;
                	nBearer_cont1->eb_id.length=htons(1);
                	nBearer_cont1->eb_id.flags=0x00;
                	nBearer_cont1->eb_id.eps_id=0x00;
                	nBearer_cont1->ftid.type=0x57;
                	nBearer_cont1->ftid.length=htons(9);
                	nBearer_cont1->ftid.flags=0x00;
                	nBearer_cont1->ftid.f_flags=0x81;
                	nBearer_cont1->ftid.teid_gre=htonl(0x044c);
                	nBearer_cont1->ftid.ip_addr=inet_addr("172.0.0.1");
                	nBearer_cont1->_cause.type=0x02;
                	nBearer_cont1->_cause.length=htons(2);
                	nBearer_cont1->_cause.flags=0x00;
                	nBearer_cont1->_cause.value=0x10;
                	nBearer_cont1->_cause.flags1=0x00;
	
			paclength=4+ntohs(g->m_length);
	
			//sleep(20);
			if(sendto(sock,buff,paclength,0,(struct sockaddr *)&sgw,sizeof(sgw  ))==-1)
			{
                		perror("\nSend: ");
                 		return -1;
         		}
        		printf("\nModify Bearer Response sent\n");
		}

        	else if(k->m_type == 68 && k->seq_no== htons(0x8003))
        	{
            		printf("\nBearer Resource command recieved");
			g=(gtp *)buff;
                	g->flags=0x48;
                	g->m_type=0x5f;
                	g->m_length=htons(8+sizeof(bearer_cont4)+sizeof(ebi)+sizeof(pti));
                	g->teid=htonl(0x10c8eb);
                	g->seq_no=htons(0x8003);
                	g->spare=0x0000;

	        	nEbi=(ebi *)(buff+sizeof(gtp));
			nEbi->type=0x49;
                	nEbi->length=htons(1);
                	nEbi->flags=0x00;
                	nEbi->eps_id=0x00;
		
			nPti=(pti *)(buff+sizeof(gtp)+sizeof(ebi));
			nPti->type=0x64;
                	nPti->length=htons(1);
                	nPti->flags=0x00;
                	nPti->value=0x00;
		
			nBearer_cont4=(bearer_cont4 *)(buff+sizeof(gtp)+sizeof(ebi)+sizeof(pti));
			nBearer_cont4->type=0x5d;
			nBearer_cont4->length=htons(sizeof(ebi)+sizeof(charg_char)+sizeof(fteid)+sizeof(fteid)+sizeof(bqos)+sizeof(tad));
			nBearer_cont4->flags=0x00;
			nBearer_cont4->eb_id.type=0x49;
                	nBearer_cont4->eb_id.length=htons(1);
                	nBearer_cont4->eb_id.flags=0x00;
                	nBearer_cont4->eb_id.eps_id=0x00;

			nBearer_cont4->charging.type=0x5e;
                	nBearer_cont4->charging.length=htons(4);
                	nBearer_cont4->charging.flags=0x00;
                	nBearer_cont4->charging.value=htonl(0x00);
                	nBearer_cont4->ftid.type=0x57;
                	nBearer_cont4->ftid.length=htons(9);
                	nBearer_cont4->ftid.flags=0x00;
                	nBearer_cont4->ftid.f_flags=0x81;
                	nBearer_cont4->ftid.teid_gre=htonl(0x044d);
                	nBearer_cont4->ftid.ip_addr=inet_addr("22.22.22.24");
                	nBearer_cont4->ft_id.type=0x57;
                	nBearer_cont4->ft_id.length=htons(9);
                	nBearer_cont4->ft_id.flags=0x01;
                	nBearer_cont4->ft_id.f_flags=0x85;
                	nBearer_cont4->ft_id.teid_gre=htonl(0x044d);
                	nBearer_cont4->ft_id.ip_addr=inet_addr("22.22.22.24");
		
			nBearer_cont4->b_qos.type=0x50;
			nBearer_cont4->b_qos.length=htons(22);
			nBearer_cont4->b_qos.flags=0x00;
			nBearer_cont4->b_qos.arp=0x01;
			nBearer_cont4->b_qos.qci=0x02;
			nBearer_cont4->b_qos.max_uplink=0x5050;
			nBearer_cont4->b_qos.max_downlink=0x9090;
			nBearer_cont4->b_qos.gr_uplink=0x5050;
			nBearer_cont4->b_qos.gr_downlink=0x6060;
		
			nBearer_cont4->tft1.type=0x54;
			nBearer_cont4->tft1.length=htons(9);
			nBearer_cont4->tft1.flags=0x00;
			nBearer_cont4->tft1.description=0x00;
			nBearer_cont4->tft1.tad_length=0x09;
			nBearer_cont4->tft1.tft=0x21;
			nBearer_cont4->tft1.p_filter.packet_id=0x00;
			nBearer_cont4->tft1.p_filter.precedence=0x00;
			nBearer_cont4->tft1.p_filter.length=0x03;
			nBearer_cont4->tft1.p_filter.component_id=0x50;
			nBearer_cont4->tft1.p_filter.port_type=htons(80);
			
                	printf("\nCreate Bearer Request Sent \n");
			paclength=4+ntohs(g->m_length);

                	if(sendto(sock,buff,paclength,0,(struct sockaddr *)&sgw,sizeof(sgw  ))==-1)
			{
                       		perror("\nSend: ");
                         	return -1;
                	}
        		printf("\nResponse sent\n");
        	}
	
		else if(k->m_type == 68 && k->seq_no== htons(0x8004))
		{
		
			printf("\nBearer Resource command for deletion recieved");
                	g=(gtp *)buff;
                	g->flags=0x48;
                	g->m_type=0x63;
                	g->m_length=htons(8+sizeof(ebi)+sizeof(pti));
                	g->teid=htonl(0x10c8eb);
                	g->seq_no=htons(0x8004);
                	g->spare=0x0000;

                	nEbi=(ebi *)(buff+sizeof(gtp));
                	nEbi->type=0x49;
                	nEbi->length=htons(1);
                	nEbi->flags=0x00;
                	nEbi->eps_id=0x01;

                	nPti=(pti *)(buff+sizeof(gtp)+sizeof(ebi));
                	nPti->type=0x64;
                	nPti->length=htons(1);
                	nPti->flags=0x00;
                	nPti->value=0x01;
		
                	paclength=4+ntohs(g->m_length);

                	if(sendto(sock,buff,paclength,0,(struct sockaddr *)&sgw,sizeof(sgw  ))==-1)
			{
                        	perror("\nSend: ");
                         	return -1;
                	}
			printf("\nDelete Bearer request sent \n");

		}
	
		else if(k->m_type == 36)
        	{
                	printf("\nDelete Session Request recieved");
                	g=(gtp *)buff;
                	g->flags=0x48;
                	g->m_type=0x25;
                	g->m_length=htons(8+sizeof(cause));
                	g->teid=htonl(0x10c8eb);
                	g->seq_no=htons(0x0004);
                	g->spare=0x0000;

			nCause=(cause *)(buff+sizeof(gtp));
			nCause->type=0x02;
			nCause->length=htons(2);
			nCause->flags=0x00;
			nCause->value=0x10;
			nCause->flags1=0x00;

			paclength=4+ntohs(g->m_length);
                	if(sendto(sock,buff,paclength,0,(struct sockaddr *)&sgw,sizeof(sgw  ))==-1)
			{
                        	perror("\nSend: ");
                         	return -1;
                	}
                	printf("\nDelete Session Response sent \n");
		}
	}
	return 0;
}


















