/*자료구조의 학습의 의의
	sw 개발자에게 있어서 머리속 생각을 프로그램 코드로 
	바꾸는 것이 무엇보다 중요하다.
	 이것이 불가능하다면 단순한 코더가 되고	
	이것이 가능해진다면 비로소 그 때 SW개발자가 될 수 있다.	
	
	자료구조를 학습하는 이유는 머리속에서 생각한 내용을 코드로 변환하는
	훈련을 하는 일련의 절차라고 보면 된다.		
	
	익숙해지면 이후에는
	생각한 대부분의 모든 것들을 프로그램 코드로 바꿀 수 있다.

*/
#include <stdio.h>
#include <stdlib.h>

typedef struct __stack
{
	int data;
	struct __stack *link; //__stack 을 쓰는 이유는 구조체 정의가 안끝나서.
} stack;

stack *get_stack_node(void)
{
	stack *tmp = (stack *)malloc(sizeof(stack));
	tmp -> link = NULL;
	
	return tmp;
}

void push(stack **top, int data)
{
	stack *tmp = *top;// top 안에는 null top 안의 값이있음
	*top = get_stack_node(); // *top 은 메인에 있는 top이구나
	(*top)->data=data; // () 는 연산자 우선순위 왜냐면 ->가 연산이 
	(*top)->link = tmp;

}

void print_stack(stack *top)
{
	stack *tmp = top;	
	
	while(tmp)// 5000 - 4000 - 3000 - 2000 -1000 - 0 
	{
		printf("tmp->data = %d\n", tmp->data);
		tmp = tmp -> link;
	}
}

int pop(stack **top)
{	
	 
	stack *tmp = *top;// top 안에는 null top 안의 값이있음
	int tmp_data;

	if (!tmp) 
	{	
		printf("Stack 이 텅비어 있다. \n");
		return 0;
	}
	
	tmp_data = (*top) -> data;
	*top = (*top) -> link;
	
	free(tmp);
	
	return tmp_data;

	

}

int main(void)
{
	int i;
	stack *top = NULL;
	
	for(i=1;i<=4;i++)
	{
		push(&top, i * 10);
	}
	
	print_stack(top); //top = 6000
	
	for(i = 0; i < 5; i++)
	{
		printf("pop data = %d\n", pop(&top));	
	}
	return 0;
}
