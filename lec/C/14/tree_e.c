#include <stdio.h>
#include <stdlib.h>

typedef struct __tree
{
	int data;
	struct __tree *left;
	struct __tree *right;
} tree;

tree *make_tree_node()
{
	tree *tmp = (tree *)malloc(sizeof(tree));
	tmp -> left = NULL;
	tmp -> right = NULL;
	return tmp;
}

void tree_add(tree **root, int data)
{
	tree **tmp = root;	
	
	while(*tmp)
	{
		if(((*tmp)->data) > data)
			tmp = (&(*tmp)->left);
		else if(((*tmp)->data)  < data)
			tmp = (&(*tmp)->right);
	}
	
	*tmp = make_tree_node();
	(*tmp) -> data = data;
}

void print_tree(tree *root)
{
        if(root)
        {
                printf("data = %4d ", root->data);

                if(root->left)
                        printf("Left = %4d ,",root->left->data);
                else
                        printf("Left = NULL ,");
                if(root->right)
                        printf("Right = %4d\n",root->right->data);
                else
                        printf("Right = NULL\n");

                print_tree(root->left);
                print_tree(root->right);
        }

}

void pre_print(tree **root)
{
	if(*root)
	{
		printf("data = %d\n",(*root)->data);
		pre_print(&(*root)->left);
		pre_print(&(*root)->right);
	}
}



int main(void)
{
	tree *root = NULL;
	int i;
	
	for(i=0;i<7;i++)
	{
		tree_add(&root,(i+1)*20);
	}
	
	pre_print(&root);
	

}
