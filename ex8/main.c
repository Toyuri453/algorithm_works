#include <stdio.h>
#include <stdlib.h> //InOrder And PostOrder

struct BiTree{
	int data;
	struct BiTree *lchild;
	struct BiTree *rchild;
};

typedef struct BiTree *Bitree;

struct stack{
	Bitree data[255];
	int top; //
};

typedef struct stack Stack;


int IsEmpty(Stack s) //
{
	if(s.top == -1) return 1; //1 for empty.
	else return 0;
}

void Push(Stack *s, Bitree t) //
{
	if(s->top <= 255 - 1) 
	{
		s->top ++;
		s->data[s->top] = t; //
	}
	else printf("\n\nPush Failed!");
}

Bitree Pop(Stack *s) 
{

		s->top --;
		return s->data[s->top];
		

	
}



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

void InTraverse(Bitree T)

{

     Bitree p;

     Stack S;

     S.top = -1;;

     Push(&S,T);  // 

      while (!IsEmpty(S))

     {

            while (p=S.data[S.top]&&p){

			Push(&S,p->lchild);  }  

           p=Pop(&S);
            if (!IsEmpty(S))

           {

                p=Pop(&S);    
                printf( "%c\t" ,p->data);  

                Push(&S,p->rchild);

           }

     }

}

int main()
{
	Bitree t;
	CreateBTree(&t);
	InTraverse(t);
	return 0;
}
//abc@@de@g@@f@@@