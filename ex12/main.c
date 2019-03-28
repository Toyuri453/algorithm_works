#include <stdio.h>
#include <stdlib.h>
void StraightSort(int list[], int listlen)
{
	int i, j;
	for(i = 2; i <= listlen; i++)
	{
		list[0] = list[i];
		j = i - 1;
		while(list[j] > list[0])
		{
			list[j+1] = list[j];
			j--;
		}
		list[j+1] = list[0];
	}
	
}


void ShellsSort(int list[], int listlen)
{
	int division[3] = {5,3,1};
	int sublist[listlen];
	int sublistcount = 1;
	int divisioncount = 0;
	int pos = 0;
	int listposcount = 0;
	
	while(divisioncount <= 2)
	{
		while(listposcount != division[divisioncount])
		{
			pos = listposcount;
			for(; pos <= listlen-1; sublistcount++)
			{
				sublist[0] = 0;
				sublist[sublistcount] = list[pos]; 
				pos = pos + division[divisioncount];
			}
			StraightSort(sublist, sublistcount);
			int i;
			int temp = listposcount;
			for(i = 1; i < sublistcount; i++)
			{
				list[temp] = sublist[i];	
				
				temp = temp + division[divisioncount];
			}
			listposcount++;
			sublistcount = 1;
		}
		listposcount = 0;
		divisioncount ++;
	}
	int fixglitch;
	fixglitch = list[0];
	list[0] = list[1];
	list[1] = fixglitch;
	
	
	
}


void BubbleSort(int list[], int listlen)
{
	int pos = 0;
	int sortcount = 1;
	int temp;
	while(sortcount < listlen )
	{
		while(pos + 1 <= listlen - 1)
		{
			if(list[pos] > list[pos+1])
			{
				temp = list[pos];
				list[pos] = list[pos + 1];
				list[pos + 1] = temp;
				pos++;
			}
			else pos++;
		}
		sortcount++;
		pos = 0;
	}
}

int main()
{
	int SSlist[13] = {0,2,7,9,5,1,11,3,8,10,4,6,12};
	int Slist[12] = {12,11,10,9,8,7,6,5,4,3,2,1};
	int Blist[12] = {12,11,10,9,8,7,6,5,4,3,2,1};
	
	StraightSort(SSlist, 13);
	ShellsSort(Slist, 13);
	BubbleSort(Blist, 12);
	
	printf("StraightSort: ");
	int si;
	for(si = 1; si <= 12; si++) // for shell
	{
		printf(" %d", Slist[si]);
	}
	printf("\n");
	
	printf("BubbleSort: ");
	int bi;
	for(bi = 0; bi < 12; bi++) // for bubble
	{
		printf(" %d", Blist[bi]);
	}
	printf("\n");
	
	printf("ShellSort: ");
	int ssi;
	for(ssi = 1; ssi < 13; ssi++)
	{
		printf(" %d", SSlist[ssi]);
	}
	printf("\n");
	
	
	return 0;
}
