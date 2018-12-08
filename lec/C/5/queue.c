#include <stdio.h>
#include <stdlib.h>

typedef struct __queue
{
	int data;
	struct __queue *link; //__stack 을 쓰는 이유는 구조체 정의가 안끝나서.
} queue;


void inqueue(queue **head, int data)
{
	
}

int dequeue(queue *head)
{
	queue *tmp = head;		
	int num;
	

	if(!tmp)
	{
		printf("queue 가 비어있다 . \n");
		return 0;
	}

	num = (*head) -> data; 
	*head = (*head) -> link;

	free(tmp);
	return num;
	
	
	
}


int main(void)
{
	int i;
	queue *head = NULL;
	
	for(i=1;i<=4;i++)
	{
		inqueue(&head, i * 10);
	}
	
	
	for(i = 0; i < 5; i++)
	{
		printf("inqueue data = %d\n", dequeue(&head));	
	}
	return 0;

}
