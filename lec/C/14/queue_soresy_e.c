#include <stdio.h>
#include <stdlib.h>

typedef struct __queue
{
	int data;
	struct __queue *link;

} queue;

queue *make_queue_node()
{
	queue *tmp = (queue *)malloc(sizeof(queue));
	tmp -> link = NULL;
	return tmp;
}

void inqueue(queue **head, int data)
{
	queue **tmp = head;

	if(!(*head)) 
	{
		*head = make_queue_node();
		(*head)->data = data;
		return ;
	}
	
	while(*tmp)
		tmp = &(*tmp)->link;
	*tmp = make_queue_node();
	(*tmp)->data = data;

}

void dequeue(queue **head)
{
	queue *tmp = *head;
	if(!(*head))
	{
		printf("큐가 비었습니다! \n");
		return ;
	}

	printf("data = %d \n",(*head)->data);
	*head = (*head)->link;
	free(tmp);
}


int main(void)
{
	queue *head = NULL;
	
	inqueue(&head,10);
	inqueue(&head,20);
	inqueue(&head,30);
	
	dequeue(&head);	
	dequeue(&head);
	dequeue(&head);
	dequeue(&head);
	dequeue(&head);
	
	return 0;
}
