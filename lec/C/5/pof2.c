#include <stdio.h>

//void (*)(void)
//리턴 함수이름 인자를 보이드



void test(void)
{
	printf("test\n");
}

//int (*p)[3] vs int *p[3]



//void (*)(void) test_test(void)
//

void (* test_test(void))(void)
{
	printf("test_test\n");
	return test;

}


int main(void)
{//함수의 주소값을 담는 변수

	test_test()(); //첫번째 함수가 끝나고 return test가 test()다시 실행
	
	return 0;


}
