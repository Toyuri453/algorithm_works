#include<stdio.h>

#define MAXSIZE 255
#define Elemtype int

struct Triple {
	Elemtype i;
	Elemtype j;
	Elemtype data;
};

typedef struct Triple triple;

int a[4][4] = {{1,0,0,0},{0,0,3,0},{0,1,0,0},{0,0,1,0}};

//triple b[MAXSIZE];

triple *CreateMatx(int a[4][4]){
	triple matx[MAXSIZE];
	int m, n = 0;
	int k = 1;
	printf("ROW  COL  DAT");
	for(m = 0; m < 4; m++)
	{
		for(n = 0; n < 4; n++)
		{
			if (a[m][n] != 0)
			{
				matx[k].i = m+1;
				matx[k].j = n+1;
				matx[k].data = a[m][n];
				printf("\n  %d   %d   %d   \n\n",matx[k].i, matx[k].j, matx[k].data);
				k++;

			}
		}
	}
	return matx;

}

void Reverse(triple a[])
{
	int t;
	for(t = 1; t < 5; t++ )
	{
		//printf("%d^^%d^^%d^^\n\n",a[t].i, a[t].j, a[t].data);
	};
	int col[5] = {0}; //1 1 2 0
	int row[5] = {0}; //1 1 1 1
	int k;
	int temp;
	for(k = 1; k < 5; k++)
	{
		col[a[k].i] += 1;
		row[a[k].j] += 1;
		//printf("%d && %d\n\n",a[k].i,a[k].j);
		temp = a[k].i;
		a[k].i = a[k].j;
		a[k].j = temp;
		
	}
	//int m = 0; //print count
	int n = 1;//row
	printf("\n\n\nROW  COL  DAT");
	while(n <= 4)
	{
		//for(m = 0; m < row[n]; m++ )
		//{
			
			int q = 1;
			//int count = 0;
			for(q = 1; q < 5; q++)//bianli
			{
				if(a[q].i == n) printf("\n   %d   %d   %d  \n\n", a[q].i, a[q].j, a[q].data);
				//count ++;
				//if(count == row[n]) goto next;
				
			}
		//}
		n++;
	}
	
	
}



int main(){
	
	triple *b = CreateMatx(a);
	Reverse(b);
		printf("\n\nClass: WangLuo172		Name: WuZhaoXi		No: 201709603040\n\n");
	return 0;
	
}

//1 0 0 0   1 0 0 0  1,1,3  1,1,3
//0 0 3 0   0 0 1 0  2,3,3  3,2,3
//0 1 0 0   0 3 0 1  3,2,1  2,3,1
//0 0 1 0   0 0 0 0  4,3,1  3,4,1