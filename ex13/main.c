#include <stdio.h>
#include <stdlib.h>

int Qlist[12] = {12,11,10,9,8,7,6,5,4,3,2,1};
int Slist[12] = {12,11,10,9,8,7,6,5,4,3,2,1};

void QuickSort(int left, int right)
{
	int key = Qlist[left];
	int low = left;
	int high = right;
	int temp;
	if(left >= right) return;
		
	while(low != high)
	{
		while(Qlist[high] >= key && low < high) high--;
		while(Qlist[low] <= key && low < high) low++;
		if(low < high)
		{
			temp = Qlist[low];
			Qlist[low] = Qlist[high];
			Qlist[high] = temp;
		}
	}
	temp = Qlist[low];
	Qlist[low] = Qlist[left];
	Qlist[left] = temp;
	QuickSort(left, low-1);
	QuickSort(low + 1, right);
	
}

void SelectionSort(int startpos)
{
	int min = Slist[startpos]; //sp = 10
	int minn;
	int i;
	int temp;
	if (startpos >= 11) return;
	for(i = startpos ; i <= 11; i++)
	{
		if(Slist[i] < min)
		{
			min = Slist[i];
			minn = i;
		}
		else;
	}
	if(min < Slist[startpos])
	{
		temp = Slist[startpos];
		Slist[startpos] = Slist[minn];
		Slist[minn] = temp;
	}
	
	
	SelectionSort(startpos+1);
	
	
}

int main()
{
	QuickSort(0, 11);
	SelectionSort(0);
	
	printf("QuickSort: ");
	int i;
	for(i = 0; i < 12; i++)
	{
		printf("  %d", Qlist[i]);
	}printf("\n");
	
	printf("SelectionSort: ");
	int ii;
	for(ii = 0; ii < 12; ii++)
	{
		printf("  %d", Slist[ii]);
	}printf("\n");
	
	printf("\n\nClass: WangLuo172		Name: WuZhaoXi		No: 201709603040\n\n");
	return 0;
}
