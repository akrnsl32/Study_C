#include <stdio.h>
#include <time.h>	//난수 시간생성하기위한 헤더
#include <stdlib.h>	//난수 함수 사용하기 위한 헤더
#include <stdbool.h>	//bool 함수


int init_num(void)
{	// 1~ 33 까지의 난수생성
	return rand() % 33 +1;	
}

bool check_num(int num, int c1, int c2)
{	
	// ! 는 관게연산자 not
	// && 는 관계연산자 뭉
	// 주의 : 비트 연산자 아님

	if(!(num % c1) || !(num % c2))
		return true;

	return false;	
}

int main(void)
{	
	int num;
	
	srand(time(NULL));

	num = init_num();

	printf("num = ? %d\n", num);

		

	if(check_num(num, 2, 3))
	{
		printf("이것은 2 혹은  3의 배수 \n");
	}
	else
	{
		printf("이것은 2혹은  3의 배수가 아님\n");
	}

	return 0;
}
