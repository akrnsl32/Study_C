#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int cnt;
int j = 0;
	
typedef struct __Tree
{
	int data;
	struct __Tree *Llink;
	struct __Tree *Rlink;
} Tree;

Tree *get_tree_node(void)
{
	Tree *tmp =(Tree *)malloc(sizeof(Tree));
	tmp->Llink = NULL;
	tmp->Rlink = NULL;
	return tmp;
}

void insert_tree(Tree **Rptr,int data)
{
	++cnt;	

	if( *Rptr == NULL) // 처음뿐만이 아니라 노드가 생성되는 모든 부분
	{
		
		printf("data = %d 는 cnt %d \n",data,cnt );
		*Rptr = get_tree_node();
		(*Rptr)->data = data;		
		cnt = 0;
		return ;
	}
	if( *Rptr != NULL)
	{
		if(data < (*Rptr)->data)
		{
			insert_tree(&(*Rptr)->Llink,data);			
		}	
		if(data > (*Rptr)->data)
		{
			insert_tree(&(*Rptr)->Rlink,data);
		}
	}
	
}

void print_tree(Tree *root)
{
	if(root)
	{
		printf("data = %4d, \n " , root->data);

		if(root->Llink)		
		{
			printf("left = %4d \n ", root->Llink->data);
		}
		else
		{
			printf("left = NULL,\n ");
		}

		if(root->Rlink)
		{
			printf("right = %4d \n ", root->Rlink->data);
		}
		else
		{
			printf("right = NULL \n");
		}

		print_tree(root->Llink);
		print_tree(root->Rlink);
	}

}
void chg_node(Tree **root)
{
	Tree *tmp = *root;
	if(!((*root)->Llink))//Llink 가 널이면
	{	
		(*root) = (*root)->Rlink;
		return ;	
	}
	if(!((*root)->Rlink)) // Rlink 가 널이면
	{
		(*root) = (*root)->Llink;
		return ;		
	}
	free(tmp);
}


void find_max(Tree **root, int *max)
{
        if(*root)
        {
		if((*root)->Rlink)	
			find_max(&(*root)->Rlink , max);	
		else
		{	
			*max = (*root)->data;
			chg_node(root);		
		}
        }
}



void del_tree(Tree **root, int data)
{
	if(!(*root))
	{
		printf("there is no node! \n");
		return;
	}

	if((*root)->data > data)
		del_tree(&(*root)->Llink,data);
	else if((*root)->data < data)
		del_tree(&(*root)->Rlink,data);
	else if((*root)->Llink && ((*root)->Rlink))
	{
		int max;
		find_max(&(*root)->Llink, &max);
		(*root)->data = max;
	}
	else
		chg_node(root);
}






void delete_node(Tree *root , int num)
{
	Tree *tmp = root;
	if(root)
	{
		
		if(root->data == num)
		{	//삭제할 노드가 리프노드 일때
			if(root ->Llink == NULL && root -> Rlink == NULL)
			{
				free(root);
				return ;
			}
			//삭제할 노드가 자식노드 하나를 거느린 경우
			if(root -> Llink == NULL || root -> Rlink == NULL)
			{
				if(root -> Llink)
				{	
					root = root->Llink;
					printf("25 삭제중 \n");
					free(root);
					return ;
				}
				if(root -> Rlink)
				{	root = root -> Rlink;	
					free(root);
					return ;
				}
			}
			//삭제할 노드가 자식노드 두개를 거느린 경우
			if(root -> Llink !=NULL && root -> Rlink != NULL)
			{
				root ->data = root->Rlink->Llink->data;
				root->Rlink->Llink = root->Rlink->Llink->Rlink;
				free(root->Rlink->Llink);
				return ;
			}	
		}

		delete_node(root->Llink , num);
		delete_node(root->Rlink , num);
	}
	
	//return	;
}

void pre_print_tree(Tree *Rptr)
{	// 노드로 간주하기에
	
	if(Rptr != NULL)
	{	
		printf("Tree[%d] 의 값은 = %d \n",j,Rptr->data );
		j++;
		pre_print_tree(Rptr->Llink);
		pre_print_tree(Rptr->Rlink);		
	}
	else
		return;
}

void center_pre_print_tree(Tree *Rptr)
{
	if(Rptr != NULL)
	{	
		center_pre_print_tree(Rptr->Llink);
		printf("값은 %d \n ", Rptr->data);
		center_pre_print_tree(Rptr->Rlink);
	}	
	else return;
}

int main(void)
{
	//int j=0; // 트리 인덱스
	Tree *Rptr = NULL;
			
	int i ;
	int arr[13] = {50,100,25,26,27,17,23,15,20,75,80};
	int arr2[11] = {20,10,30,50,70,60,40,90,80,100};
	
	for(i=0;arr[i]; i++)
	{
		insert_tree(&Rptr,arr2[i]);	
	}

	
	
//	print_tree(Rptr);
	
	pre_print_tree(Rptr);
	
	del_tree(&Rptr,50);

	printf("*************************************************************************** \n");	
	
	//print_tree(Rptr);


	return 0;
}



