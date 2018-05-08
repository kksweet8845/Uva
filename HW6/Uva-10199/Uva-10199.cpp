#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<map>
using namespace std;

bool adj[20][20];
int visit[20];
int low[20];
int t =0;
int vertex,ver_num;
int N,C,R;
bool ans[20];
int order[100];
void DFS(int pre,int cur);
void articulation_vertex();
int min(int x,int y);
void ini();
int main(void)
{
        char s[31],s1[31];
	map<string,int> ind;
	map<string,int> :: iterator it;
	int case_num = 0;
	int u,v;
	while(1)
	{
		scanf("%d",&N);
		if(N == 0) break;
		
		ind.clear();
		ini();
		
		for(int i=1;i<=N;i++)
		{
			scanf("%s",s);
			ind[s] = i;
		}
		scanf("%d",&R);
		for(int i = 0;i<R;++i)
		{
			scanf("%s %s",s,s1);
			u = ind[s];
			v = ind[s1];
			adj[u][v] = adj[v][u] = true;	
		}
		vertex = 0;
		articulation_vertex();
		printf("City map #%d: %d camera(s) found\n",++case_num,ver_num);
		
		for(it = ind.begin();it!=ind.end();it++)
		{
			if(ans[it->second]) printf("%s\n",(it->first).c_str());
		}
		printf("\n");
		
	}

        return 0;
}


void articulation_vertex()
{
        memset(visit,0,sizeof(visit));
        t = 0;
        ver_num = 0;

        for(int i =1; i<=N ;++i)
                if(!visit[i])
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
        {
		      ans[i] = true;
			ver_num++;
	}
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
        //for(i = 1;i <=N ;i ++)
          //      order[i] = i;
        memset(adj,0,sizeof(adj));
	memset(ans,0,sizeof(ans));
	ver_num = 0;
}

