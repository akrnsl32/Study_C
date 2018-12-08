#include <time.h>
#include <stdio.h>
#include <stdlib.h>
//난수 생성
int init_rand(void)
{
	int res;
	srand(time(NULL));
	res =  rand() % 10 +1;	// 난수 10이하로 res에 넣기
	printf("res = %d\n", res);
		
	return res;
}

//배열 초기화// 난수로 배열의 값을 초기화 
void init_arr(int arr[10], int num)// 난수로 배열의 값을 초기화 
{
	int i;
	
	for(i=0; i< num; i++)
	arr[i] = i;
}
//배열  출력
void print_arr(int arr[10], int len)
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
	
	int arr[10] = {0};
	
	// init_rand() 가 3을 가지고 왔다고 가정
	// init_arr(arr,3) 과 같은 결과
	// **** 배열의 이름은 주소다 ******	
	//엄밀하게 배열의 이름은 시작주소 인데
	// 기계어에서 봤듯이 모든 개념은 주소 개념으로 보는게 좋음
	init_arr(arr, init_rand());
	print_arr(arr,sizeof(arr)/sizeof(int));
	
	return 0;
}
