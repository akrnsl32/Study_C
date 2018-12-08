#include <stdio.h>

int main(void)
{
	//선언은 위에서
	int i , j, cnt = 0 ;
	
	/*이중초기화
		for문의 초기화 파트에서
		여러 변수를 동시에 초기화 할수 있음	
	*/
	//for ( i =0 ,j=3; i!=j; j--, i++)
	
	for ( i =0 ,j=3; i!=j; j--)
	{
		printf("cnt = %d\n" , cnt++);	
	}

	return 0;
}
