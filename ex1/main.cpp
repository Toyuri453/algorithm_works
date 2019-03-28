#include <bits/stdc++.h>
#include <stdlib.h>

using namespace std;

struct SList {
	int data[255];
	int len ;
};

typedef struct SList List;

void CreatListData(List &L) //创建单向表
{
	int i = 0;
	int count = 0;
	printf("Please Enter How Many Data You Want To Input: "); // 输入数据个数
	scanf("%d", &count);
	printf("\n\n");
	printf("Please Enter Data: ");
	for(i = 0; i < count; i++){
		scanf("%d", &L.data[i]);
	}
	L.len = i;
	printf("len: %d", L.len); // 打印表的长度
	
}

void ShowData(List &L) // 显示表中元素
{
	printf("\n\nThe Data Of The List Is: ");
	int i = 0;
	for (i = 0; i < L.len; i++)
	{
//		printf("\n!!%d", L.len);
//		printf("##%d", L.data[L.len]);
//		printf("**%d", i);
		printf("%d", L.data[i]);
		printf("  ");
	}
	//cout << "\n\nlen: " << L.len;
		
}

void Insert(List &L) // 插入函数
{
	printf("\n\nPlease Enter The Data You Want To Insert: ");
	int insert = 0;
	int flag = 0; //存储目标数据在表中的位置
	scanf("%d", &insert);
	//printf("###%d", insert);
	int i = 0;
	for(i = 0; (L.data[i] < insert)&& i <= L.len; i++){if(i == L.len) break;}; //遍历寻找合适的插入位置
	flag = i;
	L.len ++;
	int count = L.len;
	for (; count >= flag; count --) // 插入位置之后的数据依次后移
	{
		L.data[count+1] = L.data[count]; 
	}
	L.data[flag] = insert;
//	printf("@@%d", L.data[flag]);
//	printf("@@%d", L.data[i]);
	
}

int Query(List &L) //查询函数
{
	printf("\n\nPlease Enter The Data You Want To Query: ");
	int query= 0;
	scanf("%d", &query);
	int i;
	for(i = 0; L.data[i] != query; i++){if(i > L.len ) break;}; // 遍历寻找目标数据
	if((i < L.len)||((i == L.len)&&(L.data[i] == L.data[L.len]))) // 当遍历至尾部时额外判断尾部数据是否为目标数据
	{
		printf("\n\nThe Data Is The ");
		printf("%dth", i);
		printf(" Numbers In The List.");
		return true;
	}
	else{
		printf("\n\nCant Find This Data In The List!");
		return false;
	}
}

void RemoveData(List &L) // 删除函数
{
	printf("\n\nPlease Enter The Data You Want To Delete: ");
	int del = 0;
	scanf("%d", &del);
	int i = 0;
	for(i = 0; L.data[i] != del; i++){if(i > L.len ) break;} //遍历寻找
	if((i < L.len)||((i == L.len)&&(L.data[i] == L.data[L.len])))
	{
		for(; i < L.len; i++)
		{
			L.data[i] = L.data[i+1]; // 被删除数据之后的数据依次前移
		}
		L.len --; 
	}
	else{
		printf("\n\nCant Find This Data In The List!");
	}

}
int main()
{
	List L;
	CreatListData(L);
	ShowData(L);
	Insert(L);
	//printf("^^%d", L.data[L.len]);
	ShowData(L);
	RemoveData(L);
	ShowData(L);
	printf("\n\nClass: WangLuo172		Name: WuZhaoXi		No: 201709603040\n\n");
	return 0;
}
