#include<stdio.h>
int main()
{
	unsigned int a=0xffff;
	~a;
	printf("%x\n",a);
}
