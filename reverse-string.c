/*write a function to reverse a string. */
/* string_reverse ­ */ 
#include <stdio.h> 
 
int string_length(char s[]) 
{ 
	int i; 
 
 	for (i = 0; s[i]; i++) 
 	; 
 	
	return i; 
} 
 
/* Function reverse */ 
void string_reverse(char s[]) 
{ 
 	int i, j; 
 
 
	for (i = 0, j = string_length(s)-1; i<j; i++, j--) 
	{ 
 		int tmp = s[i]; 
 	
		s[i] = s[j]; 
 		s[j] = tmp; 
 	} 
} 
int main() 
{ 
 
	char s[] = "Subhra Prakash Giri"; 
 
	string_reverse(s); 
 	printf("%s\n", s); 
} 

