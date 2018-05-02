#include<cstdio>
#include<cstdlib>
#include<climits>
#include<cmath>
#include<cstring>
void BellmanFord();
void Relax(int x,int y);
bool ini();
void distance(int x,int y);
double dis[100];
int w[100][100];
double p[100][2];
int source,x,y,stone_num,end;
int main()
{
	int i=0;
	while(ini())
	{
		i++;
		BellmanFord();
		printf("Scenario #%d\n",i);
		printf("Frog Distance = %lf\n\n",dis[end]);
		
	}
	
	return 0;
	
}

bool ini()
{
	memset(dis,0,sizeof(dis));
	memset(w,0,sizeof(w));
	memset(p,0,sizeof(p));
	if(scanf("%d",&stone_num)==1 && stone_num != 0)
	{
		int i,j;
		for(i=1;i<=stone_num;++i)
		{
			scanf("%lf %lf",&p[i][0],&p[i][1]);
		}
		
		for(i=1;i<=stone_num;++i)
			for(j=1;j<=stone_num;++j)
				if(w[i][j] == 0 && w[j][i] == 0)
					distance(i,j);
		source = 1;
		end = 2;
		
	}
	
	if(stone_num == 0)
		return 0;
	else 
		return 1;
}

void BellmanFord()
{
	int i;
	for(i=1;i<=stone_num;i++)
	dis[i] = 1000;
	
	dis[source] = 0;
	
	int x,y;
	
	for(i=0;i<stone_num-1;++i)
		for(x = 1;x<=stone_num;++x)
			for(y = 1;y<=stone_num;++y)
					if(dis[x] != 1000 && w[x][y] != 0)
						Relax(x,y);
}
void Relax(int x,int y)
{
	if(dis[x] + w[x][y] < dis[y])
		dis[y] = dis[x] + w[x][y];
}
void distance(int  x,int  y)
{
	if(w[x][y] !=0 || w[y][x] !=0)
	return;
	
	double x1,x2,y1,y2;
	x1 = p[x][0];
	y1 = p[x][1];
	x2 = p[y][0];
	y2 = p[y][1];
	double diss;
	
	diss = sqrt((pow((x1-x2),2)+pow((y1-y2),2)));
	
	if(x!=2)
		w[x][y] = diss;
	else
		w[x][y] = 0;	

	
	



}
