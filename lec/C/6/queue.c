#include <stdio.h>
#include <stdlib.h>

typedef struct __queue
{
        int data;
        struct __queue *link; //__stack 을 쓰는 이유는 구조체 정의가 안끝나서.
} queue;


queue *get_queue_node(void)
{
	queue *tmp = (queue *)malloc(sizeof(queue));
	tmp->link = NULL;
	return tmp;
}

void enqueue(queue **head,int data)
{

	if(!(*head))	//널일때
	{
		*head = get_queue_node();// heap 에 생성
		(*head)->data = data;
		return;	
	}
	enqueue(&(*head)->link,data);	//재귀	
}

void print_queue(queue *head)
{
	queue *tmp = head;
	int i = 0;
	
	while(tmp)
	{
		printf("data [%d] = %d  \n",i, tmp->data);
		i++;
		tmp  = tmp->link;
	}
}

int dequeue(queue **head)
{
	queue *tmp = *head;
	int num;

	if(!head) // head가 널이 아니면
	{
		printf("큐가 비어있다.\n");
		return -1;	
	}

	num = (*head)->data;
	*head = (*head) -> link;
	free(tmp);
	
	return num;

}
int cnt = 0;

void search_dequeue(queue **head, int num)
{
	cnt++;	

	if( (*head)->data == num  ) // 같으면 실행
	{
		queue *del = *head;
		printf(" %d , %d  를 찾았다  \n",num , (*head)->data);
		printf("몇번 ?  = %d \n", cnt);
		//링크 후 삭제
		*head = (*head)->link;
		free(del);		
	
		return ;
	}
	search_dequeue(&(*head)->link,num);	

}



int main(void)
{
	int i;
	queue *head = NULL;
	
	for(i=1;i<=4;i++)
        {
                enqueue(&head, i * 10);
        }

	print_queue(head);	

	search_dequeue(&head, 20);

	print_queue(head);
//	search_dequeue(&head, 40);
        return 0;

}
