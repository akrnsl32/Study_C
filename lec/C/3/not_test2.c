#include <stdio.h>

int and_not(int num)
{
	// 여기서 비트 필터링을 수행
	//1 << 4 = 16 -1 = 15
	//10000 - 00001 = 01111
	//~01111 = 11110000 ( 8비트 기준으로 )
	// n& 11110000
	// 하위 4비트는 무조건 걸러짐
	// 즉 16의 배수로 정렬함을 의미함
	
	// 1 << 16 = 4096 -1 = 4095
	// 1 0000 0000 0000 - 0000 0000 0001 = 0 1111 1111 1111
	// ~ 0 1111 1111 1111 = 1111 0000 0000 0000
	return num & ~((1<<12) -1);

}

int main(void)
{	
	int res = and_not(4096);
	printf("res = %d\n", res);
	res = and_not(8800);
	printf("res = %d\n", res);
	res = and_not(20000);
	printf("res = %d\n", res);
	res = and_not(50000);
	printf("res = %d\n", res);
	res = and_not(110000);
	printf("res = %d\n", res);

	return 0;
}
