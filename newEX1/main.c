#include <bits/stdc++.h>

using namespace std;

struct SList {
	int data[255];
	int len ;
};

typedef struct SList List;

void CreatListData(List &L)
{
	int i = 0;
	int count = 0;
	printf("Please Enter How Many Data You Want To Input: ");
	scanf("%d", &count);
	printf("\n\n");
	printf("Please Enter Data: ");
	for(i = 0; i < count; i++){
		scanf("%d", &L.data[i]);
	}
	L.len = i;
	
}

void ShowData(List &L)
{
	printf("The Data Is: ");
	int i = 0;
	for (i = 0; i < L.len; i++)
	{
		printf("%d", L.data[i]);
		printf("  ");
	}
		
}

void Insert(List &L)
{
	printf("\n\nPlease Enter The Data You Want To Insert: ");
	int insert = 0;
	int flag = 0;
	scanf("%d", &insert);
	int i = 0;
	for(i = 0; (L.data[i] < insert)&& i <= L.len; i++){};
	flag = i;
	L.len ++;
	int count = L.len;
	for (; count >= flag; count --)
	{
		L.data[count+1] = L.data[count]; 
	}
	L.data[flag] = insert;
	
}

int Query(List &L)
{
	printf("\n\nPlease Enter The Data You Want To Query: ");
	int query= 0;
	scanf("%d", &query);
	int i;
	for(i = 0; L.data[i] != query; i++){};
	if((i < L.len)||((i == L.len)&&(L.data[i] == L.data[L.len])))
	{
		printf("\n\nThe Data Is The ");
		printf("%d", i);
		printf(" Numbers In The List.");
		return true;
	}
	else{
		printf("\n\nCant Find This Data In The List!");
		return false;
	}
}

void RemoveData(List &L)
{
	printf("\n\nPlease Enter The Data You Want To Delete: ");
	int del = 0;
	scanf("%d", &del);
	
	
		

}
int main()
{
	List L;
	CreatListData(L);
	ShowData(L);
	Insert(L);
	ShowData(L);
	return 0;
}
