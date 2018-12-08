#include <stdio.h>

int my_func(int a, int b, int c, int d)
{
	
	return a + b + c +d;
}
int func2(int *array, int len)
{
	int i;
	int sum = 0;
	for(i=0;i < len/sizeof(int);i++)
	{
		sum += array[i];
	}
	return sum;
}


int main(void)
{
	int res;
	
	int a = 1 , b = 2, c =3 , d =4;
	
	res = my_func(a,b,c,d);	
	

	printf("res = %d\n", res);
	return 0;
	
}
