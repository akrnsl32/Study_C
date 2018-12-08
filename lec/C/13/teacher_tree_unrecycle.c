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
    stack *tmp = (stack *)malloc(sizeof(stack));
    tmp->link = NULL;

    return tmp;
}

tree *get_node(void)
{
    tree *tmp = (tree *)malloc(sizeof(tree));
    tmp->left = NULL;
    tmp->right = NULL;

    return tmp;
}

void *pop(stack **top)
{
    stack *tmp = *top;
    void *data = NULL;
    print_tree(&root);
   
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
        return;

    stack *tmp = *top;
    *top = get_stack_node();
    (*top)->data = malloc(sizeof(void *));
    (*top)->data = data;
    (*top)->link = tmp;
}

bool stack_is_not_empty(stack *top)
{
    if(top != NULL)
        return true;
    else
        return false;
}

void ins_tree(tree **root, int data)
{
    tree **tmp = root;

    while(*tmp)
    {
        if((*tmp)->data > data)
            tmp = (&(*tmp)->left);
        else if((*tmp)->data < data)
            tmp = (&(*tmp)->right);
    }

    *tmp = get_node();
    (*tmp)->data = data;
}

tree *chg_node(tree *root)
{
        tree *tmp = root;

        if(!root->right)
                root = root->left;
        else if(!root->left)
                root = root->right;

        free(tmp);

    return root;
}


void find_max(tree **root, int *max)
{
    tree **tmp = root;

    while(*tmp)
    {
        if((*tmp)->right)
            tmp = &(*tmp)->right;
        else
        {
            *max = (*tmp)->data;
            *tmp = chg_node(*tmp);
            break;
        }
    }
   
}

 //선생님 답
void del_tree(tree **root, int data)
{
    tree **tmp = root;
    int num;

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
            return;
        }
        else
        {
            (*tmp) = chg_node(*tmp);
            return;
        }
    }

    printf("NOT Found\n");
}
/*
// 없는 데이터가 들어오면 없다고 표시가 안댐.
void del_tree(tree **root, int data)
{
    tree **tmp = root;

    while(*tmp)
    {
        if((*tmp)->data > data)
            tmp = (&(*tmp)->left);
        else if((*tmp)->data < data)
            tmp = (&(*tmp)->right);
        else if((*tmp)->left && (*tmp)->right)
        {
            int max;
            find_max(&(*tmp)->left, &max);
            (*tmp)->data = max;
        }
        else
            chg_node(tmp);
    }
}
*/
#if 0
void print_tree(tree *root)
{
    if(root)
    {
        printf("data = %d\n", tmp->data);
        print_tree(root->left);
        print_tree(root->right);   
    }
   
}
#endif

/* //재귀함수 사용한 프린트
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
*/
void print_tree(tree **root)
{
    tree **tmp = root;
    stack *top = NULL;

    push(&top, *tmp);
   
    while(stack_is_not_empty(top))
    {
        tree *t = (tree *)pop(&top);
        tmp = &t;

        printf("data = %d, ", (*tmp)->data);

        if((*tmp)->left)
            printf("left = %d, ", (*tmp)->left->data);
        else
            printf("left = NULL, ");
   
        if((*tmp)->right)
            printf("right = %d\n", (*tmp)->right->data);
        else
            printf("right = NULL\n");

        push(&top, (*tmp)->right);
        push(&top, (*tmp)->left);
    }
}

int main(void)
{
    tree *root = NULL;
//    int data[11] = {20, 10, 30, 50, 70, 40, 90, 60, 80, 100};
    int data[9] = {10, 5, 25, 2, 7, 9, 4, 27};
    int i;
   
    for(i = 0; data[i]; i++)
        ins_tree(&root, data[i]);

    print_tree(&root);

    del_tree(&root, 10);
   
    print_tree(&root);
    return 0;
}
