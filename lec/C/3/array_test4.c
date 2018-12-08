#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

//난수 생성 1~9까지 난수 생성
int init_rand_num(int arr[])
{
	int i;
	for(i=0; i<100;i++)
		arr[i] = rand() % 9 + 1;
}

// 11개의 테이블 , 생성된 100개의 난수테이블 비교
void make_freq_table(int ft[], int fn[])
{
	int i;

	for(i = 0; i < 100; i++)
	{
		ft[fn[i]]++;
	}
}

//배열  출력
void print_arr(int arr[], int len)
{
	int i, flag = 1 ;
	
	for(i=1;i<len+1;i++)
	{
		printf("%3d ", arr[i-1]);//%3d 3칸 뛰고 출력
		
		if(!(i%10))
		{
			printf("\n");
		}
	}
}

/*void sort(int freq_table[100],int size,int max_tab[4])
{
	int tmp_table[11] = {0};
	int i = 0;
	int j = 0;
	
	for(i ; i<=size; i++)
	{
		for(j ; j<=size; j++)
		{
			if(freq_table[i] > freq_table[j])
			{	freq_table[i] = freq_table[i];	}
			else
			{	freq_table[i] = freq_table[j];	} 
		}
	
	}
}*/

bool check_dup(int max_tab[], int ft[], int len)
{
	int i, j;
		
	for(i=0; i< len; i++)
	{
		for(j=i+1;j<len;j++)
		{
			if(max_tab[i] == max_tab[j])
			{	//ft 배열을 0으로 초기화   40byte
				memset(ft, 0x0, 40);
				return true;
			}
		}
	}	
	return false; //반복을 멈춰라
}

void make_max_tab(int max_tab[], int freq_tab[])
{
	int i, j, key, len = 10;
	
	//삽입 정렬 알고리즘
	// 데이터의 개수가 적을때 빠름
	// 데이터의 개수가 정해져 있을 경우엔
	// quick sort 도 빠름

	for(i = len -1; i>0; i--)
	{
		key = freq_tab[i-1];
		
		for(j = i; freq_tab[j] > key; j++)
			freq_tab[j - 1] = freq_tab[j];
		freq_tab[j - 1] = key;
	}

	printf("max freq_tab: ");
		
	for(i = 0; i< 11; i++)
		printf("%3d", freq_tab[i]);

	printf("\n");
	
	for( i  = 0; i< 4; i++)	//i < 4 까지 바꿔줌 4개를 출력하기 위해
		max_tab[i] = freq_tab[i];
}

int main(void)
{
	int freq_num[100] = {0}; //100개 배열
	int freq_tab[11] = {0};	//1~10까지의 갯수 배열//삽입정렬하기위해서 데이
				//터 넘어가는것을 방지하기 위해 ?
	int max_tab[5] = {0};	//배열의 갯수도 4개에서 5개로 끝을 널로 만들기 
				// 위해 

	srand(time(NULL));
	
	while(check_dup(max_tab, freq_tab, 4))
	{
		init_rand_num(freq_num);
		printf("Print Random Number\n");
		print_arr(freq_num, 100);
	
		printf("Print Frequency Table \n");
		make_freq_table(freq_tab, freq_num);
		print_arr(freq_tab, 10);

		printf("Print Max Number\n");
		make_max_tab(max_tab, freq_tab);
	}
	
	printf("Successful to avoid redundancy!\n");
	print_arr(max_tab, 4);
	printf("\n");
		
	return 0;	

	
}
