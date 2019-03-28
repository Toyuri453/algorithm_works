#include <stdio.h>
#include <stdlib.h>

struct BiTree{
	int data;
	struct BiTree *lchild;
	struct BiTree *rchild;
};

typedef struct BiTree *Bitree;

void CreateBTree(Bitree *t)
{
	char ch;
	scanf("%c", &ch);
	if(ch == '@')
	{
		*t = NULL;
	}
	else{
		*t = (Bitree)malloc(sizeof(Bitree));
		(*t)->data = ch;
		CreateBTree(&(*t)->lchild);
		CreateBTree(&(*t)->rchild);
	}
}

void PreShowBiTree(Bitree t){
	if(t == NULL) return;
	printf("%15c", t->data);
	PreShowBiTree((t->lchild));
	PreShowBiTree((t->rchild));
}

void InShowBiTree(Bitree t){
	if(t == NULL) return;
	InShowBiTree((t->lchild));
	printf("%c", t->data);
	InShowBiTree((t->rchild));
}

void PostShowBiTree(Bitree t){
	if(t == NULL) return;
	PostShowBiTree((t->lchild));
	PostShowBiTree((t->rchild));
	printf("%15c", t->data);
}

int main()
{
	Bitree t;
	CreateBTree(&t);
	printf("PreOrder: ");PreShowBiTree(t);printf("\n\n");
	printf("InOrder: ");InShowBiTree(t);printf("\n\n");
	printf("PostOrder: ");PostShowBiTree(t);printf("\n\n");
	//abc@@de@g@@f@@@
		
	
	return 0;
}
