#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#define MAX 1000000
bool visit[500];
int seq[500];
int ans[500];
bool is_prime[MAX];
void backtrack(int x);
void ini();
void eratosthenes();
void print();
int length,th;

int main(void)
{
	eratosthenes();
	ini();
	while(scanf("%d",&length)!=EOF)
	{	th++;
		memset(visit,0,sizeof(visit));
		memset(ans,0,sizeof(ans));
		ans[0] = 1;
		ans[length] = 1;
		printf("Case %d:\n",th);
		backtrack(1);
		printf("\n");
	}
	
	return 0;
}
void ini()
{
	int i;
	for(i=0;i<500;i++)
		seq[i] = i;
}
void backtrack(int x)
{
	if( x == length)
	{
		if(is_prime[ans[length -1] + ans[length]])
		{	
			print();
			return;
		}
		else
			return;
	}
	int i;
	for(i=2;i<=length;i++)
		if(is_prime[i+ans[x-1]] && visit[i] == false)
		{
			ans[x] = i;
			visit[i] = true;
			backtrack(x+1);
			visit[i] = false;
		}		
	
	
}

void eratosthenes()
{
	memset(is_prime,1,sizeof(is_prime));
	is_prime[0] = false;
	is_prime[0] = false;
	int i,j;
	
	for(i=2;i<sqrt(MAX);i++)
		for(j=i+i;j<MAX;j=j+i)
			if(is_prime[j])
				is_prime[j] = false;
	
}

void print()
{
	int i;
	for(i=0;i<length;i++)
	printf("%d ",ans[i]);
	printf("\n");
	
}
