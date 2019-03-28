#include <stdio.h>
#include <stdlib.h>
#define MAX 6
#define viod void
#define ture true
#define raer rear

struct Queue{
	int data[MAX];
	int front;
	int rear;  //定义队列结构体
};

typedef struct Queue queue;

void IniQueue(queue *q)
{
	q->front = q->rear = 0; //初始化队列头尾的值为0
}

int IsEmpty(queue *q) 
{
	if (q->front == 0 && q->rear == 0) //若头尾同为0则返回1表示队列为空，否则返回0；
		return 1; // 1 for empty;
		else return 0;
}

int IsFull(queue *q)
{
	if (((q->rear)+1)%MAX == q->front) //若尾指针+1于头指针相等则返回1表示队列已满，否则返回0；
	return 1; //true for full.
	else return 0;
	
}

int GetQueueLength(queue *q) //获取队列长度
{
	if(IsFull(q)) return MAX; //如队列已满则返回队列最大长度
	else return ((q->rear - q->front)+MAX)%MAX; //由于数据总是在front正向数至rear之间，因此非满时返回rear与front之差加上最大长度再模除最大长度的值
}

void Insert(queue *q)//插入函数
{
	fflush(stdin);//清空输入缓冲区
	if(!IsFull(q)){
		printf("\n\nPlease Enter The Data: ");
		int data = 0;
		scanf("%d", &data);
		q->data[(q->rear)%MAX] = data; 
		q->rear = (q->rear+1)%MAX; // 为尾指针指向的区域赋值并使指针后移
	}
	else printf("\n\nInsert Failed!");
}

void Remove(queue *q) //删除函数
{
	if(!IsEmpty(q)){
		printf("\n\nThe Front Data %d Has Been Removed.", q->data[q->front]);
		q->front = (q->front+1)%MAX; //头指针后移
	}
	else printf("\n\nRemove Data Failed!");
}

void ShowData(queue q) //显示队列数据
{
	int i;
	printf("\n\nThe Data Of The Queue: ");
	for(i = q.front; i != q.rear; i = (1+i)%MAX ){ //循环计数时i从front累加到rear，进制为队列长度
		printf(" %d ", q.data[i]); 
	}
}

int main()
{
	queue q;
	IniQueue(&q);
	Insert(&q);
	Insert(&q);
	Insert(&q);
	Insert(&q);
	Insert(&q);
	ShowData(q);
	Remove(&q);
	Remove(&q);
	Remove(&q);
	ShowData(q);
	Insert(&q);
	Insert(&q);
	printf("\n\nThe Queue Length Is: %d \n\n", GetQueueLength(&q));
	ShowData(q);
	printf("\n\nClass: WangLuo172		Name: WuZhaoXi		No: 201709603040\n\n");
	
	return 0;
}
