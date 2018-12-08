#include <stdio.h>
#include <time.h>
#include <stdlib.h>
//rand() 
int init_val(void)
{
	// 1~9까지 랜덤함수 rand 는 0~100?
	// 실제 난수 생성
	return rand() % 9  + 1;
	//return rand();
}

void check_num(int num)
{
	if(num ==0)
	{
		printf("num 은 0이다  \n ");	
	}
	//별도의 추가 조건을 걸어주기 위함
	else
	{
		if(num % 2 )
		{
			printf("num 은 홀수입니다. \n");
		}
		else
		{
			printf("num 은 짝수 \n");
		}
	}
}


int main(void)
{	
	int num;
	
	//일종의 난수 생성의 패턴
	srand(time(NULL));
	
	num = init_val();

	printf("num = %d\n",num);
	check_num(num);	
	return 0;
}
