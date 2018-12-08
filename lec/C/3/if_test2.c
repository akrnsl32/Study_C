#include <stdio.h>
#include <stdbool.h>

#if 0
sdlkjfsdflkjsdflkj
#endif

bool is_it_even(int value)
{	
	
	if(value %2 == 0)
	{
		return true;
	}
	else
		return false;
}

int main(void)
{
	if(is_it_even(3))
	{
		printf("이것은 짝수입입니다. \n");
	}
	else
	{	printf("이것은 홀수입입니다. \n");	
	
	}
	
	return 0;	
}

