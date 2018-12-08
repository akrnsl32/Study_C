#include <stdio.h>

// shift d연산은 정수형에서만 사용가능




int mult(int num)
{	
//	return num << 1;
	return num*num;
}

int main(void)
{
	int res;
	int num1 = 3;
	
	res = mult(num1);
	printf("res = %d \n",res);

	return 0;	

}
