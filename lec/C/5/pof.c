#include <stdio.h>

//void (*)(void)
//리턴 함수이름 인자를 보이드



void test(void)
{
	printf("test\n");
}

int main(void)
{//함수의 주소값을 담는 변수

	void (*p)(void) = test;
	p();
	
	return 0;


}
