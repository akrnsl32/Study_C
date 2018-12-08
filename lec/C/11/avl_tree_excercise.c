#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define LL	2
#define LR	3
#define RL	4
#define RR	5
	
#define ABS(n)		(n<0)? (-n) : (n)

typedef struct __avl
{
	int data;	
	int lev;
	struct __avl *left;
	struct __avl *right;

} avl;
	
avl *avl_make_node(void)
{
	avl *tmp = (avl *)malloc(sizeof(avl));
	tmp->left = NULL;
	tmp->right = NULL;
	tmp->lev = 1;	
	return tmp;
}

int chg_lev(avl *root)
{
	int left = root->left > 0 ? root->left->lev : 0;
	int right = root->right >0? root->right->lev : 0;
	
	if(left>right)
		return left+1;

	return right+1; 
}

int check_lev(avl *root)
{
	int right = root->right > 0 ? root->right->lev : 0;
	int left  = root->left > 0  ? root->left->lev : 0;
	
	return right-left;
}
	
int check_rotation(avl *root, int data)
{
	if(check_lev(root) < 0)
	{
		if(check_lev(root->left) > -1 && root->left->data < data)
			return LR;
		return LL;
	}
	else
	{
		if(check_lev(root->right) < -1 && root->right->data >data)
			return RL;
		return RR;		
	}
}
avl *ll_rot(avl *p, avl *c)
{
	p->left = c->right;
	c->right = p;
	chg_lev(p);
	chg_lev(c);
	
	return c;
}
	
avl *rr_rot(avl *p, avl *c)
{
	p->right = c->left;
	c->left = p;
	chg_lev(p);
	chg_lev(c);

	return c;
}



avl *lr_rot(avl *p, avl *c)
{
	rr_rot(c,c->right);
	ll_rot(p,c);
	chg_lev(p);
	chg_lev(c);
	
	return c;
}
	
avl *rl_rot(avl *p, avl *c)
{
	ll_rot(c,c->left);
	rr_rot(p,c);
	chg_lev(p);
	chg_lev(c);
	
	return c;
}
	

avl *rotation(avl *root,int reb)
{
	switch(reb)
	{
		case LL:
			printf("LL Rot\n");
			return ll_rot(root,(root)->left);
			break;
		case LR:
			printf("LR Rot\n");
			return lr_rot(root,(root)->left);
			break;
		case RL:
			printf("RL Rot\n");
			return rl_rot(root,(root)->right);
			break;
		case RR:
			printf("RR Rot\n");
			return rr_rot(root,(root)->right);
			break;
	}
}

void avl_ins(avl **root, int data)
{
	if(!(*root))
	{
		*root = avl_make_node();
		(*root)->data = data;//괄호안해주면 화살표연산이 먼저라규
		return ;
	}
	if((*root)->data > data)
		avl_ins(&(*root)->left,data);
	else
		avl_ins(&(*root)->right,data);
	

	(*root)->lev=chg_lev(*root);
	
	if((ABS(check_lev(*root)))>1)
		*root = rotation(*root,check_rotation((*root),data));

}

void print_avl(avl *root)
{
	if(root)
	{
		printf("data = %3d, ", root->data);

		if(root->left)
			printf("left = %3d, ", root->left->data);
		else
			printf("left = NULL, ");

		if(root->right)
			printf("right = %3d\n", root->right->data);
		else
			printf("right = NULL\n");

		print_avl(root->left);
		print_avl(root->right);
	}
}


int main(void)
{
	
	int i;
	int data[20] = {45, 17, 2, 62, 57, 73, 52, 65, 76, 69, 63, 64, 71};
	int d2[10] = {10, 20, 30, 40, 50};

	avl *root = NULL;
	avl *test = NULL;

	printf("default data : ");
	for(i = 0; data[i]; i++)
		printf("%2d ", data[i]);

//	for(i = 0; data[i]; i++)
//		avl_ins(&root, data[i]);

	for(i = 0; d2[i]; i++)
		avl_ins(&test, d2[i]);

	printf("\nAfter Insert :\n");
//	print_avl(root);

	print_avl(test);

	return 0;
}




