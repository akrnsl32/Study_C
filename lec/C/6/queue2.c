#include <stdio.h>
#include <stdlib.h>

typedef struct __queue
{
	int data;
	struct __queue *link;
} queue;

queue *get_queue_node()
{
	queue *tmp =(queue *)malloc(sizeof(queue));
	tmp -> link = NULL;
	return tmp;
}



void enqueue(queue **head, int data)
{
	
	if(!(*head)) // 값이 없으면 하라고
	{
		*head = get_queue_node();
		(*head)->data = data;
		return ; //까먹질 마세요
	}
	enqueue(&(*head)->link,data);
	
} 

void print_queue(queue *head)
{
	queue *tmp = head;
	int i = 0;
	
	while(tmp)
	{
		printf("data[%d] =%d \n",i, tmp->data );
		i++;
		tmp = tmp->link;
	}
}

void search_delete(queue **head, int search_data)
{
	queue *del = *head;

	if((*head)->data == search_data)
	{
		printf("찾았습니다. %d \n",(*head)->data);
		*head = (*head)->link;
		free(del);	
	
		return ;	
	}
	search_delete(&(*head)->link, search_data);	
}

void dequeue(queue **head, int data)
{
	queue *tmp = *head;
	
	if((*head)->data == data)
	{
		printf("data = %d\n",(*head)->data);
		*head = (*head)->link;
		free(tmp);

		return;	
	}
	
	dequeue(&(*head)->link,data);
	
}


int main()
{
	queue *head = NULL;
	int i;
	int arr[5] = {10,30,20,40};
	
	
	for(i=1; i<5; i++)
	{
		enqueue(&head, i * 10);
	}

	//print_queue(head);
	
	for(i=0;i<4;i++)
	{
		dequeue(&head, arr[i]);
	}	

//	search_delete(&head, 30);
	
	//print_queue(head);	


	return 0;
}

