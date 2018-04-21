#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
using namespace std;
int dis[1000];
int w[100][100];
int source;
int N,T;
bool check;
void BellmanFord();
bool ini();
void Relax(int x,int y);
int main(void)
{	while(1)
	{
		
		check =	ini();
		if(check == 0)
			break;
		BellmanFord();
		printf("%d\n",dis[1]);
	}
	return 0;
}
bool ini()
{
	memset(dis,0,sizeof(dis));
	memset(w,0,sizeof(w));
	if(scanf("%d %d",&N,&T)==EOF)
		return 0;
	source = N;
	int i,j,l_1,l_2,d;
	for(i=0;i<T;i++)
	{
		scanf("%d %d %d",&l_1,&l_2,&d);
		w[l_1][l_2] = d;
		w[l_2][l_1] = d;
	}
	
	return 1;
}
void BellmanFord()
{
	dis[source] =0;
	int i;
	for(i=1;i<=N;i++)
		if(i!=source)
			dis[i] = INT_MAX;
	int x,y;
	for(i=0;i<N-1;i++)
		for(x=1;x<=N;x++)
			for(y=1;y<=N;y++)
				if(dis[x]!=INT_MAX && w[x][y]!=0)
					Relax(x,y);
	
}
void Relax(int x,int y)
{
	if(dis[x]+w[x][y]<dis[y])
		dis[y] = dis[x]+w[x][y];
}
