#include <stdio.h>
#include <stdlib.h>

struct ListNode{
	int data;
	struct ListNode *next; //建立结构体
};

typedef struct ListNode Node;

Node* CreatList() //链表创建函数
{
	Node *head = NULL; //建立头节点
	head = malloc(sizeof(Node)); //申请新空间
	head->next = NULL;
//	Node *temp = NULL;
//	temp = malloc(sizeof(Node));
//	head->next = temp;
//	int a = 999;
//	temp->data = a;
//	temp->next = NULL;
	return head;
}


void AddData(Node *head) // (尾)插入函数
{
	Node *temp = NULL;
	temp = malloc(sizeof(Node));
	temp = head;     //申请临时节点
	while(1)
	{
		if(temp->next != NULL)
		{
			temp = temp->next; //遍历至链表尾部
		}
		else break;
	}
	temp->next = malloc(sizeof(Node)); //为新节点申请空间
	printf("\n\nEnter Data: ");
	int data;
	scanf("%d", &data);
	temp->next->data = data; // 将新的数据插入到尾节点之后
	temp->next->next = NULL; 
}

void ShowList(Node *head) //显示链表数据
{
	Node *temp = malloc(sizeof(Node));
	temp = head;
	printf("\n\nThe Data Of The List Is: ");
	while(temp->next != NULL)
	{
		printf(" %d", temp->next->data);//遍历链表并打印数据域
		temp = temp->next;
	}
}

void DelData(Node *head) //删除函数
{
	Node *temp = NULL;
	temp = malloc(sizeof(Node));
	temp = head->next;
	printf("\n\nEnter The Data To Delete: ");
	int data = 0;
	scanf("%d", &data);
	while((temp->data != data))
	{
		temp = temp->next; //遍历直到目标数据所在的节点
	}
	temp->data = temp->next->data; //将目标节点的下一个节点的数据赋给目标节点
	temp->next = temp->next->next; //将目标节点的next指针改为目标节点下一个节点的next指针
	
	
}

int main()
{
//	Node *head = NULL;
//	head = (Node*)malloc(sizeof(Node));
//	AddData(&head);
	Node *head = CreatList();
	//printf("%d",head->next->data);
	AddData(head);
	AddData(head);
	AddData(head);
	AddData(head);
	AddData(head);
	ShowList(head);
	DelData(head);
	ShowList(head);
	printf("\n\nClass: WangLuo172		Name: WuZhaoXi		No: 201709603040\n\n");
	return 0;
}
