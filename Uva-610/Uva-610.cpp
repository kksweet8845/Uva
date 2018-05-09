#include<cstdio>
#include<cstdlib>
#include<cstring>

void DFS(int p,int i);
void bridge();
void ini();
int min(int x,int y);

int adj[100][100];
int visit[100];
int low[100];
int t;
int N,R,b_num;
int ans[100][2];

int main(void)
{
	int c_1,c_2,times = 0;
	while(scanf("%d %d",&N,&R) == 2 && (N!=0 && R!=0))
	{
		ini();
		times++;
		for(int i = 0;i<R;i++)
		{
			scanf("%d %d",&c_1,&c_2);
			adj[c_1][c_2]++;
		}
		bridge();
		
		printf("%d\n\n",times);
		
		for(int i=1;i<=b_num;++i)
		{
			printf("%d %d\n",ans[i][0],ans[i][1]);
		}
		printf("#\n");
		
		
	}

	return 0;
}


void DFS(int p,int i)
{
	visit[i] = low[i] = ++t;
	
	for(int j =1;j<=N;++j)
		if(adj[i][j] > 0)
			if(!visit[j])
			{
				DFS(i,j);
				
				low[i] = min(low[i],low[j]);
				if(low[j]> visit[i])
				{
					ans[b_num++][0] = i;
					ans[b_num][1] = j;
				}
			}
			else if(j != p || (j == p && adj[i][j] >= 2))
			{
				low[i] = min(low[i],low[j]);
			}
}


void bridge()
{
	memset(visit,0,sizeof(visit));
		
	t =0;
		
	for(int i=1;i<=N;i++)
		if(!visit[i])
			DFS(i,i);
}

int min(int x,int y)
{
	if(x<y)
		return x;
	else 
		return y;
}
void ini()
{
	memset(adj,0,sizeof(adj));
	memset(low,0,sizeof(low));
	memset(ans,0,sizeof(ans));
	b_num =0;
}
