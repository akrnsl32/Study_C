#include <stdio.h>
int cnt;

int fact(int n)
{	
	cnt++;
	int first = 1;

	if ( n<1)
		return 1;

	while(n > 0)
	{	first *= n -- ; }

	return first;
}

int main(void)
{
	int res;
	res = fact(5);
	printf("res = %d\n", res);

	printf("cnt = %d\n", cnnt);
	return 0;
}
