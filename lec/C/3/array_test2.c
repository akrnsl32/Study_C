#include <time.h>
#include <stdio.h>
#include <stdlib.h>

//1~9까지 난수 숫자 생성
int init_rand(void)
{
	int res;
	srand(time(NULL));
	res = rand() % 10 +1;
	printf("res =%d\n", res);
}

void init_arr(int arr[10] , int num)
{ 
	int i;
	for (

int main(void)
{
	
	int arr[100] = {0};	// 1, 배열 100개 선언
	
	init_arr(arr, init_rand()); 		//난수생성
}

