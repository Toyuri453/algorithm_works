#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char string[255];

char ipts[255];

int next[255];

int GetString(char s[]) //
{
	int i = 0;
	int ic = 0;
	printf("\n\nEnter String Length: ");
	scanf("%d", &ic);
	fflush(stdin);
	for(i = 0; i < ic; i++)
	{
		scanf("%c", &s[i]);
	};
	return i;
}

int SimpleMatching(char s[], int slen, char ipts[]) // return target
{
	fflush(stdin);
	//char ipts[255];
	printf("Enter The String Want To Matching: ");
	int i = 0;
	//char ch;

		while(scanf("%c", &ipts[i]))
		{
			if(ipts[i] =='\n') break;
			else i++;
			//printf("%d", i);
		}

	int iptslen = 0;
		iptslen = i;
		
		//GET FIRST MATCHED CHARACTOR
		int target = 0;
		//int temp_target = 0;
		while(target < slen)
		{
			for( ; ipts[0] != s[target]; target++){};
			int i = 0;
			for( ; ipts[i] == s[target+i]; ++i)
			{
				if(ipts[i] != s[target + i])
				{
					break;
				}
				else if(i == iptslen - 1 && ipts[i] == s[target + i])
				{
					printf("\n\nString Matched!\n\n");
					return target;
				}
				else;
				
			};target ++;
		
		}
		return -1;
		
}

void GetNext(char s[], int slen, int next[])
{
	next[0] = 0;
	int m,n;
	for (m = 1,n = 0; m < slen; ++m)
	{
		while(n > 0 && s[m] != s[n])
			n = next[n-1];
			if (s[m] == s[n])
			{
				n++;
			}
			next[m] = n;
	}

}

void KmpMatching(char s[], char ipts[], int next[])
{
    int n,m;
    int i,q;
    n = strlen(s);
    m = strlen(ipts) - 1;
	//printf("%d^^^^^%d", n, m);
    GetNext(ipts, m, next);
    for (i = 0,q = 0; i < n; ++i)
    {
        while(q > 0 && ipts[q] != s[i])
			//printf("^^^\n\n");
            q = next[q-1];
        if (ipts[q] == s[i])
        {
            q++;
        }
        if (q == m) // 
        {
            printf("2. Kmp Matching: The String Starts From The %d Charactors Of The Origin String.\n\n",(i-m+1)+1);
        }
    }    
}


int main(){

	
	int slen = GetString(string);
	printf("1. Simple Matching: The String Starts From The %d Charactors Of The Origin String.\n\n", SimpleMatching(string, slen, ipts)+1);
	//GetNext(string, slen, next);
	KmpMatching(string, ipts, next);
	

	
	return 0;
}
