#include<cstdio>
#include<cstdlib>

using namespace std;

int num[10000];
int LIS[10000];
int seq;
void Find_LIS()
{
	int i,j;
	for(i=1;i<=seq;i++)
	{	
		LIS[i] = 1;
		for(j=1;j<i;j++)
			if(num[j]<num[i] && LIS[j]+1 > LIS[i])
				LIS[i] = LIS[j]+1;
	}
}	

int main(void)
{
	int max;
	while(scanf("%d",&seq)!=EOF)
	{
		for(int i=1;i<=seq;i++)
			scanf("%d",&num[i]);
		
		Find_LIS();
		max = LIS[1];
		for(int j=1;j<=seq;j++)
		{
			if(max < LIS[j])
				max = LIS[j];
		}
		printf("%d\n",max);
	}
	
	return 0;
}
