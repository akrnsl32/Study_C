#include <stdio.h>

//void (*)(void)
//리턴 함수이름 인자를 보이드



void test(void)
{
	printf("test\n");
}
//void (*)(void) test_test(void)
//

int num_test(void)
{
	printf("num_test\n");
	return 7;
}

// int (*)(void) test_test(*p)(void))
int (* test_test(void (*p)(void)))(void)//1 (void) = (test) 인자값
{
	printf("test_test\n");
	p();//2 = test() 함수의 주소값
	return num_test;
}
/*
int (*)(void) test_test(void (*p)(void))
int (*)(void) (*) (void (*)(void)) // 함수에 인자 안에도 함수주소값이 들어가게
void (*)(void) - 인자매개변수
int (*)(void) (*) (void (*)(void)) // 프로토 타입
	pof_test(void (*p)(void))
int (*)(void) (* pof_test(void (*p)(void)))(void

int (*)(* pof_test(void (*p)(void___(void (*)(void)))(void)


*/
//int (* test_test(void (*p)(void)))(void)
//int (* (* pof_test(void (*p)(void))) (void (*)(void)))(void)


//int (*p)(void) * test_test(void)
//int (* test_test (*p)(void)



int (* (* pof_test(void (*p)(void))) (void (*)(void)))(void)
{
	printf("pof_test\n");
	p();
	return test_test;
}


int main(void)
{//함수의 주소값을 담는 변수

	int res = pof_test(test)(test);
	printf("res = %d\n", res);
	
	return 0;

}
