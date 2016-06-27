/*Q.Write a C program to create a segmentation fault. */

# include <stdio.h> 
# include <string.h> 
int main () 
{ 
 
	char * str1 = "Wang"; 
 	char * str2 = "Lei"; 
 
	printf ("%s \n", strcat (str1, str2)); 
 
	return 0; 
} 

