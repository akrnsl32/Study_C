#include <stdio.h>

int fib(int n)
{
	if(n<=2)
	{	return 1; 	}
	
	return fib(n-1) + fib (n-2);
}

int main(void)
{	
	int res;
	res = fib(5);
	printf("fib(5) = %d\n",fib(7));	

	return 0;
}
