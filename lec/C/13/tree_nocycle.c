#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct __tree
{
	int data;
	struct __tree *left;
	struct __tree *right;
} tree;

typedef struct __stack
{
	void *data;
	struct __stack *link;
} stack;

stack *get_stack_node(void)
{
	stack *tmp;
	tmp = (stack *)malloc(sizeof(stack));
	tmp->link = NULL;
	return tmp;
}

void *pop(stack **top)
{
	stack *tmp = *top;
	void *data = NULL;
	
	if(*top == NULL)
	{
		printf("stack is empty!\n");
		return NULL;
	}
	
	data = (*top)->data;
	*top = (*top)->link;
	free(tmp);
	
	return data;
}
void push(stack **top, void *data)
{
	if(data == NULL)
		return ;
	
	stack *tmp = *top;
	*top = get_stack_node();
	(*top)->data = malloc(sizeof(void *));
	(*top)->data = data;
	(*top)->link = tmp;
}

bool stack_is_not_empty(stack *top)
{
	if(top !=NULL)
		return true;
	else
		return false;
}

void print_tree(tree **root)
{
	tree **tmp = root;
	stack *top = NULL;
	
	push(&top, *tmp);
	
	while(stack_is_not_empty(top))
	{
		tree *t = (tree *)pop(&top);
		tmp = &t;
	
		printf("data = %d,\n ", (*tmp)->data);
	
		if((*tmp)->left)
			printf("left = %d,\n ", (*tmp)->left->data);
		else
			printf("left = NULL,\n ");
	
		if((*tmp)->right)
			printf("right = %d, \n", (*tmp)->right->data);
		else
			printf("right = NULL,\n ");
	
		push(&top, (*tmp)->right);
		push(&top, (*tmp)->left);
	
		//tmp = &(*tmp)->left;
		//*tmp = (tree *)pop(&top);
	}


}	
tree *make_tree_node(void)
{
	tree *tmp = (tree *)malloc(sizeof(tree));
	tmp->left = NULL;
	tmp->right = NULL;
	return tmp;
}


void tree_ins(tree **root, int data)
{
	tree **tmp = root;
	
	while(*tmp)
	{
		if((*tmp)->data > data)
			tmp = &(*tmp)->left;
		else if((*tmp)->data < data)
			tmp = &(*tmp)->right;
	}

	*tmp = make_tree_node();
	(*tmp)->data = data;

	
}
void pre_print_tree(tree *Rptr)
{	// 노드로 간주하기에
	
	if(Rptr != NULL)
	{	
		printf("Tree[] 의 값은 = %d \n",Rptr->data );
		pre_print_tree(Rptr->left);
		pre_print_tree(Rptr->right);		
	}
	else
		return;
}

tree *chg_node(tree *root)
{
	tree *tmp = root;

	if(!tmp->right)
		tmp = tmp->left;
	else if(!(tmp->left))
		tmp = tmp->right;

	free(tmp);

	return root;
}



void find_max(tree **root, int *num)
{
	tree **tmp = root;

	while(*tmp)
	{
		if((*tmp)->right)
			tmp = &(*tmp)->right;
		else
		{
			*num = (*tmp)->data;
			*tmp = chg_node(*tmp);
			break;
		}	
	}	

}


void dell_tree_node(tree **root, int data)
{
	tree **tmp = root;
	int num;
	
	//삭제할 노드를 찾는다
	while(*tmp)
	{	
		if((*tmp)->data > data)
			tmp = &(*tmp)->left;
		else if((*tmp)->data < data)
			tmp = &(*tmp)->right;
		else if((*tmp)->left && (*tmp)->right)
		{
			find_max(&(*tmp)->left, &num);
			(*tmp)->data = num;
			return ;		
		}
		else // 
		{
			(*tmp) = chg_node(*tmp);
			return ;
		}
		
	}
	printf("NOT Found \n");
}


int main(void)
{
	tree *root = NULL;
	int i;		
	int arr[11] = {20,10,30,50,70,60,40,90,80,100};

	for(i = 0; arr[i]; i++)
		tree_ins(&root,arr[i]);
	
	pre_print_tree(root);

	dell_tree_node(&root,50);

	//pre_print_tree(root);
	
	print_tree(&root);
	
	return 0;
}

