#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

//난수 생성 1~9까지 난수 생성
int init_rand(void)
{
	int res;
	srand(time(NULL));
	res =  rand() % 10 +1;	// 난수 10이하로 res에 넣기
	printf("res = %d\n", res);
		
	return res;
}

//배열 초기화// 난수로 배열의 값을 초기화 
void init_arr(int arr[100], int num)// 난수로 배열의 값을 초기화 
{
	int i;	// for 반복 인자
	int cnt = (100/num) +9;	//반복할 횟수	//100/난수 + 9 , 9를더하면 1~9까
	// 겹칩일이 없다
	int number= 0;
	for(i=0; i< 100; i++)
	{
		if( i % cnt == 0)
		{
			cnt --;
			number ++;
			arr[i] = number;
		}
		else
		{	
			arr[i] = number;
		}
	}
}
//배열  출력
void print_arr(int arr[100], int len)
{
	int i ;
	
	for(i=0;i<len;i++)
	{
		printf("arr[%d] = %d\n",i , arr[i]);
	}
}


int main(void)
{	//int형 배열 0으로 초기화
	//int 는 데이터 타입이고 
	//[]배열의 개수
	//
	
	int arr[100] = {0};	//100개 만들었고
	int nansu = init_rand();
	
	init_arr(arr, nansu);	//난수를 갯수로 
	print_arr(arr,sizeof(arr)/sizeof(int));
	printf("난수눈? %d \n", nansu);
	return 0;
}
