#include<cstdio>
#include<cstdlib>

using namespace std;
int LIS[10000];
int num_seq[10000],length,ans[10000];
void Find_LIS()
{
	int i,j;
	for(i=1;i<=length;i++)
	{
		LIS[i] = 1;
		for(j=1;j<i;j++)
			if(num_seq[j]< num_seq[i] && LIS[j]+1 > LIS[i])
				LIS[i] = LIS[j]+1;
	}
}


int main(void)
{
	int i=1;
	while(scanf("%d",&num_seq[i++])!=EOF)
	{
		length = i;
	}
	Find_LIS();
	
	int k,j,max,max_index,diff;
	for(j=1,max = LIS[1];j<=length;j++)
		if(max < LIS[j])
			{
				max = LIS[j];
				max_index = j;
			}
		
	diff = max_index;
	ans[0] = num_seq[max_index];
	for(k=max_index,j=1;k>=1;k--)
	{
		if(num_seq[diff] > num_seq[k] && LIS[k] == LIS[diff]-1 )
		{
			diff = k;
			ans[j++] = num_seq[diff];	
		}
	}	
		
	printf("%d\n-\n",max);
	for(k=j-1;k>=0;k--)
	{
		printf("%d\n",ans[k]);
	}
	
	return 0;
}
