#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<iostream>
using namespace std;

string pro[102],pro2[102],b="#";
int LCS[102][102];

int main(void)
{
	int e=0;
	while(1)
	{
		memset(LCS,0,sizeof(LCS));
		int i=1;
		while(1)
		{
			cin >> pro[i];
			if(cin.eof())
			{
				e=1;
				break;
			}
			
			if(pro[i] == b)
			break;
			i++;
			
		}	
		int j=1;
		if(e==1)
			break;
		while(1)
		{
			cin >> pro2[j];
			if(cin.eof())
			{
				e=1;
				break;
			}
			
			if(pro2[j] == b)
				break;
			j++;
		}
		if(e==1)
			break;
		int case_x,case_y;
		for(case_x=1;case_x <i ;case_x++)
		{
			for(case_y=1;case_y<j;case_y++)
			{
				if(pro[case_x] == pro2[case_y] && !LCS[case_x][0] && !LCS[0][case_y])
				{
					for(int x=1;x<i;x++)
					if(pro[x] == pro[case_x])
					LCS[x][0] = 1;
					for(int y=1;y<j;y++)
					if(pro2[y] == pro[case_y])
					LCS[0][case_y] = 1;
					
					cout<<pro[case_x] <<" ";
				}
			}
		}
		
		
		
	}
	return 0;
}
