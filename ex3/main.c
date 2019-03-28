#include <stdio.h>

#include <stdlib.h>

#define MAX 255

struct stack{
	int data[MAX];
	int top; //创建堆栈结构体
};

typedef struct stack Stack;

void IniStack(Stack *s) //初始化堆栈顶部值为-1
{
	s->top = -1;
}

int IsEmpty(Stack *s) //判断是否为空，空时返回1，否则返回0
{
	if(s->top == -1) return 1; //1 for empty.
	else return 0;
}

void Push(Stack *s) //push函数
{
	if(s->top <= MAX - 1) 
	{
		s->top ++;
		printf("\n\nEnter Data To Push: ");
		scanf("%d", &(s->data[s->top])); //将数据存入堆栈顶部
	}
	else printf("\n\nPush Failed!");
}

void Pop(Stack *s) //pop函数
{
	if(s->top >= 0){
		printf("\n\nThe Poped Data: ");
		printf("%d\n", s->data[s->top]);
		s->top --;
	}
	else printf("\n\nPoped Failed!");
}

void ShowStackData(Stack *s) //显示堆栈数据
{
	int i;
	printf("\n\n\nStack Datas: "); 
	for (i = 0; i <= s->top; i++)
	{
		printf("\n\n");
		printf("		%d", s->data[s->top - i]); //按倒叙依次输出栈内数据
	}
	printf("\n\n");
	if(IsEmpty(s)) printf("\n\nStack Is Empty");
}

int main()
{
	Stack s;
	IniStack(&s);
	Push(&s);
	Push(&s);
	Push(&s);
	Push(&s);
	Push(&s);
	Pop(&s);
	Pop(&s);
	Push(&s);
	Pop(&s);
	Push(&s);
	ShowStackData(&s);
	
	return 0;
}
