/***************************************************************************************/ 
/* DESCRIPTION :This  program  will  implement a macro to clear a particular bit       */							
/* of a number. 								       */
/* AUTHOR : SUBHRA PRAKASH GIRI                                                        */ 
/* DATE   : 02­Nov­2012								       */ 
/* VERSION: 1.0 								       */ 
/***************************************************************************************/ 
 
# include <stdio.h> 
#define bitclear(var,bitpos) ((var)&= ~(1<<(bitpos))) 
 
int main() 
{ 
 
	int var = 10; 
 
	bitclear(var,3); 
 
	printf("%d \n",var); 
} 


