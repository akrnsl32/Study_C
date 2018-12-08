#include <stdio.h>
#include <stdbool.h>

//bool은 stdbool.h 헤더 파일을 포함해야만 사용할 수 있다,.
//또한 논리 자체를 표현할수 있어서 아래 보이듯이 
//false나 true 를 return 할수 있어서 꽤 유용하게 사용된다,
//최근 C 문법에 추가된 녀석중 하나임


#endif
bool is_it_even(int value)
{
	// 2로 나눈 나머지가 1이면 참 아니면 거짓
	// 즉 짝수면 true가 반환되고 홀수면 false가 반환됨
	if(value % 2)
		return false;

	return true;	
}

int main(void)
{
	//3 은 홀수 있으몰 flase가 반횐되어 else로 가게됨
	if(is_it_even(3)
		printf("이것은 짝수 입니다. \n");	
	else
		printf("이것은 홀수 .\n");
	
	return 0;
}
