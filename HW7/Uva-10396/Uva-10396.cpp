#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;

const int V = 100,E = 1000;
int satellite,outpost,edge;
struct Edge{int a,b;double c;} e[E];
bool operator<(Edge e1,Edge e2){return e1.c<e2.c;}
int S[100][2];
double dis[100][100];
int p[V];
int init(){for(int i=0;i<V;++i)p[i] = i;}
int find(int x){return x == p[x]? x:(p[x] = find(p[x]));}

void Union(int x,int y){p[find(x)] = find(y);}
void set_dis()
{
	int i,j;
	for(i=0,edge = 0;i<outpost;++i)
		for(j=i+1;j<outpost;++j)
		{
			dis[i][j] = dis[j][i] = sqrt(pow((S[i][0]-S[j][0]),2)+pow((S[i][1]-S[j][1]),2));
			e[edge].a = i;
			e[edge].b = j;
			e[edge].c = dis[i][j];
			edge++;
		}
}
void Kruskal()
{
	init();
	sort(e,e+E);
	
	int i,j;
	for(i=0,j=0;i<satellite-1 && j<edge;++i)
	{
		while(find(e[j].a) == find(e[j].b)) j++;
		
		Union(e[j].a,e[j].b);
		
		printf("起點 %d ",e[j].a);
		printf("終點 %d ",e[j].b);
		printf("權重 %f \n",e[j].c);
		
		j++;
	}
	
	if(i == V-1) printf("得到最小生成樹\n");
	else
	printf("得到最小生成森林\n");
}

int main(void)
{
	int case_num;
	while(scanf("%d",&case_num) != EOF)
	{
		for(int i = 0;i<case_num;i++)
		{
			scanf("%d %d",&satellite,&outpost);
			for(int j = 0;j < outpost;++j)
			{
				scanf("%d %d",&S[j][0],&S[j][1]);
			}
			set_dis();
			Kruskal();
		}
	}
}
