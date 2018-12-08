#include <stdio.h>
#include <stdlib.h>

#define LL	2
#define LR	3
#define	RL	4
#define	RR	5


typedef struct __avl
{
	int data;
	int lev;
	struct __avl *left;
	struct __avl *right;

} avl;

avl *get_avl_node(void)
{
	avl *tmp = (avl *)malloc(sizeof(avl));
	tmp->left = NULL;
	tmp->right = NULL;
	tmp->lev = 0;

	return tmp;
}	
	
int chg_lev(avl **root)
{
	int left, right;
	
	left = root->left > 0 ? root->left->lev : 0;
	right = root->right > 0 ? root->right->lev : 0;
	
	if(left >right)
		return left + 1 ;
	
	return right +1;

}

//리턴값이 뭘까 
int check_rotation(avl *root,int data)
{
	if(check_lev(root) < 0)
	{
		if(check_lev(root->left) > -1 && root->left->data < data)
			return LR;
		return LL;		
	}
	else
	{
		if(check_lev(root->right) < 1 && root->right->data >data)
			return RL;
		return RR;
	}
	
	return 0;
}

avl *ll_rot(avl *p, avl *c)
{
	p->left = c->right;
	c->right = p;
	p->lev = chg_lev(p);
	c->lev = chg_lev(c);
	
}
	
avl *lr_rot(avl *p,avl *c)
{	
	c = rr_rot(c, c->right);
	return ll_lot(p,c);
}
	
avl *rl_rot(avl *p,avl *c)
{
	c = ll_rot(c, c->left);
	return rr_rot(p,c);
}

avl *rr_rot(avl *p, avl *c)
{
	p->right = c->left;
	c->left = p;
	p->lev = chg_lev(p);
	c->lev = chg_lev(c);
}
// 
avl *rotation(avl **root, int ret)
{
	switch(ret)
	{
		case LL	ll_rot(root,root->left);
			break;
		case LR lr_rot(root,root->left);
			break;
		case RL rl_rot(root,root->right);
			break;
		case RR rr_rot(root,root->right);
			break;
	
	}
	
}

int check_lev(avl *root)
{
	int right = root->right > 0 ? root->right->lev : 0; 
	int left = root->left > 0 ? root->left->lev : 0;
	
	return right - left;
}


void avl_ins(avl **root, int data)
{
	if(!(*root))
	{
		*root = get_avl_node();
		(*root)->data = data;
		return;		
	}
	
	if((*root)->data > data)
		avl_ins(&(*root)->left, data);
	else
		avl_ins(&(*root)->right, data);
						//마지막 노드에 값을 넣은 
	(*root)->lev = chg_lev(*root);

	if((ABS(check_lev(*root))) > 1)
		*root = rotation(*root, check_rotation(*root, data));
}

int main(void)
{
	int i;
	int data[20] = {45, 17, 2, 62,57,73,52,65,76,69,63,64,71};
	int d2[10] = {10,20,30,40,50,44,41,17};

	avl*root = NULL;
	avl*test = NULL;
	
	printf("default data : ");
	for(i = 0; data[i]; i++)
		printf("%2d", data[i]);
	
	for(i=0; data[i]; i++)
	{
		avl_ins(&root, data[i]);
		//print_avl(root);
		//usleep(1000000);
		//sleep(1);
	}
	
	for(i


	return 0;
}
