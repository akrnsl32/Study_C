#include <time.h>
#include <stdio.h>
#include <stdlib.h>
//					전역변수 알기위한 
void init_arr(int (*arr)[2])
{
	int i ,j;
	
	srand(time(NULL));

	for(i = 0; i< 2; i++)
	{
		for(j = 0; j < 2; j++)
		{
			arr[i][j] = rand() % 9 +1;
			printf("arr[%d][%d] = %d\n", i , j , arr[i][j]);
		}
	}
}

int (* cant_ret_arr(void))[2]
{
	int arr[2][2] = {0};
	
	init_arr(arr);
	
	return arr;
}

void test(void)
{
	printf("test \n");
}

// int (*)[2] arr_ret(void)
int (* arr_ret(void))[2]
{
	//static 은 선언된 함수 내에서만 전역 변수처럼 동작
	static int arr[2][2] = {0};
	
	init_arr(arr);

	return arr;
}

//int (*)[2] arr_ret(void) arr_pof(void (*p)(void) )

// int (*)[2] arr_ret(void) arr_pof(void (*p)(void) )
// int (*)[2] (*)	(void) arr_pof(void (*p)(void) )
// int (* arr_pof(void (*p)(void)))(void)
        


int main(void)
{
	int (*p)[2] = NULL;

	p = arr_ret();
	printf("p[0][0] = %d\n",p[0][0]);	
	
#if 0
	// int(* cant_ret_arr*(void)) [2]
	p = cant_ret_arr();	
	printf("p[0][0] = %d\n",p[0][0]);
	
	//printf("arr = 0x%x\n",arr); //함수내에서만의 전역변수이기에 접근불가능
	return 0;
#endif	
}



