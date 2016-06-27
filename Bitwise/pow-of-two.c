/*******************************************************************************************/
/* DESCRIPTION  :This  program  will  implement  a  macro  to  check if  a  particular     */ 
/*               number is power of two or not.                                            */ 
/* AUTHOR       : SUBHRA PRAKASH GIRI                                                      */ 
/* DATE         : 02­Nov­2012                                                              */ 
/* VERSION      : 1.0                                                                      */
/*******************************************************************************************/ 

# include <stdio.h> 
# define POWER_OF_TWO(x) ((x&(x-1) == 0) ? 1:0) 
 
int main() 
{ 
	int var = 10; 
	if(POWER_OF_TWO(var))
		printf("The number is power of two \n");
	else
		printf("The number is not power of two \n");
} 
