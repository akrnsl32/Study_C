#include <stdio.h>

int fib(int n)
{
	int first=1, second=1, tmp;
	
	
	if(n<=2)
	{	return 1;	}
	
	n -= 2;
	
	// n = 5, 3  1 + 1 = 2 
	// n = 4, 2 1 + 2 = 3
	// n = 3, 1 2 + 3 = 5
	while(n--)
	{
		tmp = first + second;
		first = second;
		second = tmp;	
	}
	return tmp;

}

int main(void)
{
	int res;
	res =fib(5);
	printf("res = %d\n", res);

	return 0;
	
}
