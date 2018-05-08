#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<queue>
using namespace std;

bool adj[27][27];
bool visit[27];
int N,component;
void BFS();

int main(void)
{
	int case_num;
	char test;
	char data[27];
	bool check =false;
	int h,f;
	while(scanf("%d%c",&case_num,&test) != EOF)
	{
		cin.getline(data,sizeof(data));		
		for(int i = 0;i< case_num;++i)
		{
			check = false;
			while(1)
			{
				cin.getline(data,sizeof(data));
				if(data[0] == '\n')
				cin.getline(data,sizeof(data));
				if(data[0] != '\n' && data[0] != ' ')
				{
					N = data[0] - 64;
					while(1)
					{
						cin.getline(data,sizeof(data));
						if(data[0] == '\0')
						{
							check = true;
							break;
						}
						h = data[0] - 64;
						f = data[1] - 64;
						adj[h][f] = adj[f][h] = true;
					}
					if(check)
					break;
				}
			}
			BFS();
			printf("%d\n",component);	
		}
	}
}


void BFS()
{
	queue<int> q;
	component = 0;
	for(int i = 0; i<=N;++i)
		visit[i] = false;
	
	for(int k = 1;k	<= N; ++k)
		if(!visit[k])
		{
			q.push(k);
			visit[k] = true;
			
			while(!q.empty())
			{
				int i = q.front();
				q.pop();
				
				for(int j =1;j<=N;++j)
					if(adj[i][j] && !visit[j])
					{
						q.push(j);
						visit[j] = true;
					}
			}
			
			component++;	
		}
}
