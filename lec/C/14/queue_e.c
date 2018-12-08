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
	//메인의 큐 헤더부분은 내가 수정해주지 않아도 항상 일정하다
	// 왜? 재귀가 끝나면 항상 원래대로 돌아가기 때문에
	// main 의 queue 헤더는 항상 2000인 상태로 마무리 된다.	

	if(!(*head)) 
	{
		*head = make_queue_node();
		(*head)->data = data;
		return ;
	}

	inqueue(&((*head)->link) , data);

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
