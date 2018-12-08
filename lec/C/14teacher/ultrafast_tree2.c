#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct __tree
{
	int data;
	int left_idx;
	int right_idx;
} tree;

typedef struct __tree_mamager
{
	int cur_idx;
	int elem_idx;
	int start_idx;
	tree *arr;
} tm;

void tree_ins(tm *m,int data)
{
	int idx = m->start_idx;
	
	while(m->arr[idx].data)
	{	
		if(m->arr[idx].data > data)
			idx = m->arr[idx].left_idx;
		else if(m->arr[idx].data < data)
			idx = m->arr[idx].right_idx;
	}
	
	m->arr[idx].data = data;
	m->elem_idx++;
	m->arr[idx].left_idx = ++m->cur_idx;
	m->arr[idx].right_idx = ++m->cur_idx;
}


void tree_init(tm *m)
{
	
	tree *tmp = (tree *)malloc(sizeof(tree) * 128);
	memset(tmp,0x0, sizeof(tree) * 128); //memset(동적할당 주소,자료형 * 갯수)
//	(*m)->arr = tmp;
//	(*m)->cur_idx = 0;
//	(*m)->start_idx = 0;
	(*m).arr = tmp;
	(*m).cur_idx = 0;
	(*m).start_idx = 0;
}



int main(void)
{
	int i;
	int arr[14] = {20,10,30,50,70,60,40,90,80,100};
	
	tm m = {0};
	
	tree_init(&m);
	
	for(i=0;i<arr[i];i++)
	{	
		tree_ins(m,arr[i]);
	}
	
	return 0;	
}
