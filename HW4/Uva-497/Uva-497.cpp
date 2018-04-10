#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
using namespace std;
int case_num,in_num,c[1000];
int LIS[1000],ans[1000];

void Find_LIS()
{
	int i,j;
	for(i=1;i<=in_num;i++)
	{
		LIS[i] = 1;
		for(j=1;j<i;j++)
		{
			if(c[j]<c[i] && LIS[j]+1>LIS[i])
				LIS[i] = LIS[j]+1;
		}
	}
}


int main(void)
{
	while(scanf("%d",&case_num)!=EOF)
	{
		int i;
		for(i=0;i<case_num;i++)
		{
			int j=1;
			while(cin>>c[j++])
			{
				in_num = j;
			}
			Find_LIS();
			
			int k,max,max_index,diff;
			for(k=1,max = LIS[1];k<=in_num;k++)
				if(max < LIS[k])
					{
						max = LIS[k];
						max_index = k;
					}
			diff = max_index;
			printf("Max hits: %d\n",max);
			ans[0] = c[max_index];
			for(k=max_index,j=1;k>=1;k--)
			{
				if(c[k]<c[diff] && LIS[k]==LIS[diff]-1)
				{
					diff = k;
					ans[j++] = c[k];
				}
			}
			
			for(k=j-1;k>=0;k--)
			{
				printf("%d\n",ans[k]);
			}
		}
	}
	return 0;
}
