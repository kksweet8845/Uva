#include<cstdio>
#include<cstdlib>
#include<cstring>


void DFS(int p,int i);
int min(int x,int y);
void bridge();
void ini();
int adj[100][100];
int visit[100];
int low[100];
int t,N;
int ans[100][2];
int bridge_num;

int main(void)
{
	int server,num,con_server;
		while(scanf("%d",&N) == 1 && N!= 0)
		{
			ini();
			for(int i = 0;i<N;++i)
			{
				scanf("%d (%d)",&server,&num);
				for(int j =0;j<num;++j)
				{
					scanf("%d",&con_server);
					adj[server][con_server]++;
				}
			}
			
			bridge();
			
			printf("%d critical links\n",bridge_num);
			for(int i = 1;i <= bridge_num;++i)
			{
				printf("%d - %d\n",ans[i][0],ans[i][1]);
			}
			printf("\n");
			
		}
		printf("0 critical links");
	
	return 0;
}


void DFS(int p,int i)
{
	visit[i] = low[i] = ++t;
	
	for(int j=0;j<N;++j)
		if(adj[i][j] > 0)
			if(!visit[j])
			{
				DFS(i,j);
				low[i] = min(low[i],low[j]);
				if(low[j]>visit[i])
				{
					ans[++bridge_num][0] = i;
					ans[bridge_num][1] = j;
				}	
			
			}
			else if(j != p || ( j == p && adj[i][j] >= 2))
			{
				low[i] = min(low[i],visit[j]);
			}



}

void bridge()
{
	
	memset(visit,0,sizeof(visit));
	
	t = 0;
	
	for(int i=0;i<N;i++)
		if(!visit[i])
			DFS(i,i);
	
}

void ini()
{
	memset(adj,0,sizeof(adj));
	memset(visit,0,sizeof(visit));
	memset(low,0,sizeof(low));
	memset(ans,0,sizeof(ans));
	bridge_num = 0;
	
	
}
int min(int x,int y)
{
	if(x<y)
		return x;
	else 	
		return y;	
}
