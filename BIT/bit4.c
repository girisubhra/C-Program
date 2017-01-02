#include<stdio.h>
int main()
{
	unsigned int a,b,c,d,e,f;
	a = b = c = d = e = f = 32;
	a <<= 2;
	b >>= 2;
	c ^= 2;
	d |= 2;
	e &= 2;
//	f ~= 2;
	printf("a=%x b=%x c=%x d=%x e=%x \n",a,b,c,d,e);
} 
