#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

bool adj[9][9];
int visit[9];
int low[9];
int t =0;
int ver_num;
int N;
int order[100];
void DFS(int pre,int cur);
void articulation_vertex();
int min(int x,int y);
void ini();
int main(void)
{
	while(scanf("%d",&N) == 1 && N != 0)
	{
		int h,f,dir[100];
		char ch;
		
		ini();
		while(1)
		{
			scanf("%d%c",&h,&ch);
			if(h == 0)
			break;
			while(scanf("%d%c",&f,&ch) == 2 )
			{
				adj[h][f] = adj[f][h] = true;
				order[f] = h;
				if(ch == '\n')
				break;
				
			}
		}
		articulation_vertex();
		
		printf("%d\n",ver_num);
		
	}	
	
	return 0;
}


void articulation_vertex()
{
	memset(visit,0,sizeof(visit));
	t = 0;
	ver_num = 0;
	
	for(int i =1; i<=N ;++i)
		if(!visit[i] && order[i] == i)
			DFS(i,i);
}

void DFS(int p,int i)
{
	visit[i] = low[i] =  ++t;
	
	int child = 0;
	bool ap = false;
	
	for(int j=1; j<=N; ++j)
		if(adj[i][j] && j!=p)
			if(visit[j])
			{
				low[i] = min(low[i],visit[j]);
			}
			else
			{
				child++ ;
				DFS(i,j);
				
				low[i] = min(low[i],low[j]);
				if(low[j] >= visit[i]) ap = true;
				
			}
			
	if((i == p && child > 1) || (i != p && ap))
		ver_num++;
		
}
int min(int x,int y)
{
	if(x > y)
		return y;
	else
		return x;	
}
void ini()
{
	int i;
	for(i = 1;i <=N ;i ++)
		order[i] = i;
	memset(adj,0,sizeof(adj));
}
