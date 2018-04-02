#include<stdio.h>
#include<stdlib.h>

void backtrack(int digit,int index);
#define N 5
int range;
bool visit[500];
int num[500],ans[500];
int main(void)
{
	
	while(1)
	{
		scanf("%d",&range);
		if(range == 0)
		break;
		
		for(int i=0;i<range;i++)
		{
			scanf("%d",&num[i]);
		}
		for(int i=0;i<500;i++)
		visit[i] = false;
		for(int j=0;j<=range-6;j++)
		backtrack(0,j);
		printf("\n");
		
	}


	return 0;
}


void backtrack(int digit, int index)
{
	visit[index] = true;
	ans[digit] = num[index];
	
	for(int i=index+1;i<range;++i)
	{
		if(visit[i] == false)
		{
			backtrack(digit+1,i);
		}
	}
	
	if(digit == N)
	{
		printf("%d",ans[0]);	
		for(int i=1;i<N+1;++i)
			printf(" %d",ans[i]);
		
		printf("\n");
		
	}

	visit[index] = false;
	return;
}
