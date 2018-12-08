#include <stdio.h>

int main(void)
{
	int num1 =3;
	float num2 = 7.0f;
	double num3 =3.3;
	
	printf("num2 * num3 = %.1lf\n", num2 * num3);	//%.1lf 소수점 첫번째
	printf("num2 / num3 = %lf\n", num2 / num3);
	printf("num1 %% 7 = %d\n", num1 % 7);	// %d 와 헷가릴ㄹ까봐
	printf("num1 %% 2 = %d\n", num1 % 2);	//연산시 % 는 %%으로 사용
	
	return 0;
}
