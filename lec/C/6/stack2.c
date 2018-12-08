#include <stdio.h>
#include <stdlib.h>

typedef struct __stack
{
        int data;
        struct __stack *link; //__stack 을 쓰는 이유는 구조체 정의가 안끝나서.
} stack;

stack *get_stack_node(void)
{
	stack *tmp =(stack *)malloc(sizeof(stack));
	tmp -> link = NULL;
	return tmp;
}

void push(stack **top, int data)
{
	stack *tmp = *top;
	
	*top = get_stack_node(); // main의 top이 heap의 구조체를 받음
	(*top)->data = data;
	(*top)->link = tmp; // top의 값인가 ?
}

int pop(stack **top)
{
	stack *tmp = *top; // 나중에 링크로 연결하기 위해 남겨놓을려고
	int num ;
	
	if(!tmp) // tmp 값이 없을때 NULL 일때
	{
		printf(" 스택이 텅 비었습니다.\n");
		return -1;
	}	
	// 값이 있을때
	
	num = (*top)->data;
	(*top) = (*top)->link;
	
	free(tmp);
	return num;

}

int main(void)
{
        int i;
        stack *top = NULL;

        for(i=1;i<=4;i++)
        {
                push(&top, i * 10);
        }


        for(i = 0; i < 5; i++)
        {
                printf("pop data = %d\n", pop(&top));
        }
        return 0;
}

