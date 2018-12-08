#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int rand_init(void)
{

	srand(time(NULL));
	return rand() % 10 +1;

}

void while_test(int num)	
{
	int cnt = 0;

	while(num--)
	{
		cnt++;
	}
	printf("cnt = %d\n", cnt);
}



void find_even(int num)
{
	int cnt = 1;
	while(cnt <= num)
	{
		if (!(cnt % 2))	//cnt == 0 이라면
		{
			printf("%4d", cnt);
		}

		//cnt++;
	}
}

int main(void)
{
	int num = rand_init();	// 난수가 num 에 들어가고

	printf("num = %d\n", num); // 난수 출력
	

	while_test(num);	// while 문에 난수 입력
	find_even(num);
	return 0;
}
