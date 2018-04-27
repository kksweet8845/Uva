#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

int den[31][101];

int nest[100][101],nest_len[1000];
void Find_nest(int list,int demension)
{
	int i,j,val,l,n;
	for(i=1,l=1,n=0;i<=list;l++,i++)
	{
		nest[l][n++] = i;	
		for(j=1;j<=list;j++)
		{
			for(int k=1,val=0;k<=demension;k++)
			{
				if(den[j][k] < den[i][k])
				{
					val++;
				}
			}
			
			if(val == demension || val == 0)
			
		}
	}
	
}

int main(void)
{
	int list,demension;
	while(scanf("%d %d",&list,&demension)!=EOF)
	{
		for(int i=1;i<=list;i++)
		{
			for(int j=1;j<=demension;j++)
				scanf("%d",&den[i][j]);
		}
		
		for(int k = 1;k<=list;k++)
			sort(den[k]+1,den[k]+(demension+1));
		
			
		
		
	}
}

