#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

int dp[7490];
int v[5] = {1,5,10,25,50};
int dy_pro(int num);
int main(void)
{
	int num;
	while(1)
	{
		memset(dp,0,sizeof(dp));
		dp[0] =1;
		if(scanf("%d",&num)!=EOF)
		{
			printf("%d\n",dy_pro(num));	
		}
		else 
			break;
	
	}
}

int dy_pro(int num)
{
	int i,k;
	
	for(k=0;k<5;k++)
		for(i=v[k];i<=num;i++)
			if(dp[i-v[k]]>=1)
				dp[i]+=dp[i-v[k]];

	return dp[num];
}
