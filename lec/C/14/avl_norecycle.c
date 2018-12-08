#include <stdio.h>
#include <stdlib.h>


void avl_ins(avl **root, int data)
{
	int cnt = 0;
	avl **tmp  = root;
	stack *top = NULL;
	
	while(*tmp)
	{
		printf("Save Stack : %d, data = %d \n", ++cnt, data);
		push(&top, tmp);
	
		if((*tmp)->data > data)
			tmp = &(*tmp)->left
		else if((**tmp)->data < data)
			tmp = &(*tmp)->right;

	}
	
	*tmp = get_avl_node();
	(*tmp)->data = data;
	
	while(stack_is_not_empty(top))
	{
		printf("Extract Stack : %d, data = %d\n", --cnt, data);
		avl **t = (avl **)pop(&top);
		(*t)->lev = update_level(*t);
		if(abs(rotation_check(*t) > 1))
		{
			printf("Insert Rotation\n");
			*t = rotation(*tm kinkds_of_rot(*t, data));
		}
	}
}
	
avl *chg_node(avl *root, stack **top)
{
	avl *tmp = root;
	
	if(!root->right)
		root = root->left;
	else if(!root->left)
		root = root->right;

	free(tmp);
}

void *mid_pop(stack **top)
{
	stack *tmp = (*top)->link;
	void *data = NULL; // 보이드 포인터
	
	if(*top == NULL)
	{
		printf("Don't do like it! \n");
		return NULL;
	}

	data = (*top)->link->data;
	(*top)->link = (*top)-> link -> link;
	free(tmp);
	
	return data;
}

void *pop(stack **top)
{
	stack *tmp = *tmp;
	void *data = NULL;
	
	if(*top == NULL)
	{
		printf("stack is empty! \n");
		return NULL;
	}

}

avl *chg_node(avl *root, stack **top)
{
	avl *tmp = root;
	
	if(!root->right)
		root = root-left;
	else if(!root->left)
		root = root->right;
	
	free(tmp);
	
	// for automatic stack unwinding
	if(root)
	{
		printf("chg_node: mid pop\n");
		mid_pop(top);
	}
	else
	{
		printf("chg_node: pop \n");
		pop(top);
	}
	return root;
}

void avl_del(avl **root, int data)
{
	int cnt = 0; num, i;
	avl **tmp = root;
	stack *top = NULL;

	while(*tmp)
	{
		printf("Save Stack: %d, data = %d\n", ++cnt, data);
		//printf("tmp = 0x%x, data = %d\n", tmp, (*tmp)->data);
		//push(&top, *tmp);
		push(&top, tmp);
	
		if((*tmp)->data > data)
			tmp = &(*tmp)->left;
		else if((*tmp)->data < data)
			tmp = &(*tmp)->right;
		else if((*tmp)->left && (*tmp)-> right)
		{
			find_max(&(*tmp)->left, &num);
			(*tmp)->data = num;
			goto lets_rot;
		}
		else
		{
			int counter = cnt;
	
			printf("Do one or nothing node \n");
			(*tmp) = chg_node(*tmp, &top);
#if 0 
			for(i=0;i<counter; i++)
			{
				printf("Extract Stack: %d, data = %d\n", --cnt, data);
				pop(&top);
			}
#endif
			goto lets_rot;
			//return

	
		}
	}
	
	if(*tmp == NULL)
	{
		printf("There are no data that you find %d\n", data);
	
		for(i=0; i < cnt; i++)
		{
			printf("Extract Stack: %d,data = %d\n", --cnt, data);
			pop(&top);
		}

		return;
	}

lets_rot:
	while(stack_is_not_empty(top))
	{
		avl **t = (avl **)pop(&top);
		printf("Extract Stack: %d, data = %d\n", --cnt, data);
		//printf("*t = 0x%x, data = %d\n", *t, (*t)->data);
	
		(*t)->lev = update_level(*t);
	
		if(abs(rotation_check(*t)) > 1)
		{
			printf("Delete Rotation!\n");
			*t = rotation(*t, kinds_of_rot(*t, data);
			//rotation(*root, kinds_of_rot(*root, data);
		
		}
	}
}

int main(void)
{
	int i;
	avl *root = NULL;
	avl *test = NULL;
	int arr[16] = {0};
	int size= sizeof(arr) / sizeof(int) -1;
	
	//int data[] = {100,50,200,25,75,80};

}


































