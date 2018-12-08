#include <stdio.h>

void init_arr(int (*arr)[2])// (*arr)[2]
{
	int i, j, cnt = 1;

	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 2; j++)
		{
			arr[i][j] = cnt++;
		}	
	}
}

void print_arr(int (*arr)[2])//괄호 추가 [2]
{
	int i, j;
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 2; j++)
		{
			printf("arr[%d][%d] = %d\n", i , j, arr[i][j]);
		}	
	}	
}

void init_pnt_arr(int **pnt_arr , int (*arr)[2] ) //
{
	int i;
	
	for(i = 0; i < 3; i++)
	{
		pnt_arr[i] = arr[i];
	}
}

void test_arr_pnt(int (*p)[3])
{
	int i, j;
	
	for(i=0; i<2; i++)
	{
		for(j = 0; j < 3; j++)
		{	
			printf("p[%d][%d] = %d\n", i, j, p[i][j]);
		}
	}
}
void test_arr_func(int (*p)[2])//(*p)[2]
{
	printf("**p= %d\n", **p);
	printf("*(*p+1) = %d\n", *(*p +1));//**두개는 어차피 값을 나타내
	printf("*(*p+3) = %d\n", *(*p +3));//**하지만 *p 는 int 4바이트씩 증가
	printf("**p+1) = %d\n", **(p +1));
	printf("**p+2) = %d\n", **(p +2));//p는 int[2] 포인터 라서 8씩 증가


}


int main(void)
{

	int i ;

	int arr[3][2] = {0};	// * int (*)[2] arr *
	/* ([],[]), ([],[]),([],[]) 	

	*/
	
	

	int *pnt_arr[3] = {0};	// 포인터 배열
				// 데이터 타입 : (int *)[] *  
	int (*p)[3] = NULL;	// 배열 포인터
				// 데이터 타입: (int (*)[3]) *
				// int형 인덱스 3개짜리 데이터형식의 포인터

	init_arr(arr);		//12 ,34 , 56
	print_arr(arr);
	
	init_pnt_arr(pnt_arr, arr);	

	for(i = 0; i < 3; i++)
	{
		printf("*pnt_arr[%d] = %d\n",i , *pnt_arr[i]);
	}


	p = arr;


	printf("p[0] = %d\n", *p[0]);	// 포인터 *p[0]
	printf("p[1] = %d\n", *p[1]);	// 포인터 *p[1]

	test_arr_pnt(p);	

	test_arr_func(arr);//arr
		
	
	return 0;
}
