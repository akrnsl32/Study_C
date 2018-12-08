#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

typedef struct __queue queue;

struct __queue
{
	int data;
	queue *link;

//함수포인터
	void (*q)(queue **,int); //리턴 함수이름 자료형 // q.q(&head,30)
	queue (*(*get_q)(void)); // q. queue (*)(*get_q)void
	void (*dq)(queue **,int);	//q.dq(&head,data); 값을 변경해야할일이 있으면 더블포인터
	void (*pq)(queue *);		//q.pq(head) 참조만 하고싶으면 포인터
};

void enque(queue **, int);
void deque(queue **, int);
void print_queue(queue *);
queue *make_queue_node(void);


queue *make_queue_node(void)
{
	queue *tmp = (queue *)malloc(sizeof(queue));

	tmp -> q = enque;
	tmp -> dq = deque;
	tmp -> pq = print_queue;
	tmp -> get_q = make_queue_node;

	tmp -> link = NULL;
	return tmp;
}

void dequeue(queue **head, int data)
{
	queue *tmp = *head;
	
	if((*head)->data == data);
	{
		// printf("data= %d\n", (*head)->data);
		*head = (*head)->link;
		free(tmp);
	
		return ;
	}
	(**head).dq(&(*head)->link, data);
}

void enque(queue **head, int data)
{
	cout <<  "enqueue called" << endl;
	
	if(!(*head))
	{
		*head = make_queue_node();
	
		(*head)->data  = data;
		return;
	}
	
	(**head).q(&(*head)->link, data);
}

void print_queue(queue *head)
{
	queue *tmp = head;
	
	while(tmp)
	{
		cout << "data =" <<tmp->data << endl;
		tmp = tmp ->link;
	}
}


int main(void)
{
	int i = 0 ;
	int arr[5] = {10,20,30,40};
	
	queue *head = (queue *)malloc(sizeof(queue));

	head->q = enque;	//구조체 인자를 함수포인터로 연결 
	head->get_q = make_queue_node;	
	head->data = 10;
	head->dq = deque;	
	head->pq = print_queue;
	head->link = NULL;

	for(i = 2; i< 6; i++)
	{
		(*head).q(&head,i * 10);
	}
	
	(*head).pq(head);

	for(i = 0; i < 2; i++)
		(*head).dq(&head, arr[i]);
	
	cout << "After Delete" << endl;
	(*head).pq(head);
	
		
	return 0;
} 
