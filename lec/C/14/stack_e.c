#include <stdio.h>
#include <stdlib.h>

typedef struct __stack
{
	int data;
	struct __stack *link;

} stack;

stack *make_stack_node()
{
	stack *tmp = (stack *)malloc(sizeof(stack));
	tmp->link = NULL;
	return tmp;
}

void push(stack **top, int data)
{
	stack *tmp = NULL;
	tmp = make_stack_node();
	tmp->data = data;
	tmp->link = *top;
	//top = tmp;
	*top = tmp;
	
	return ;
}



void pop(stack **top)
{
	stack **tmp1 = top; // tmp1 = 1000
	stack *tmp2 = *top; // tmp2 = 4000

	printf("data = %d\n",(*top)->data);
	*top = (*top)->link;

	//free(*tmp1);	//free(3000);
	free(tmp2); //free(4000);

	//*top = tmp->link
	return ;
	
}



int main(void)
{
	stack *top = NULL;
	
	push(&top,10);
	push(&top,20);
	push(&top,30);
	
	pop(&top);
	pop(&top);
	pop(&top);
	
	return 0;

}
