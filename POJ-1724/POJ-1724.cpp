#include<cstdio>
#include<cstdlib>
#include<climits>
#include<cstring>

int source,city_num,toll,road_num;
int dis[100][2];
int len[100][100];
int mon[100][100];
void BellmanFord();
void Relax(int x,int y);
bool ini();



void BellmanFord()
{
	int i;
	dis[source][0] = 0;
	dis[source][1] = 0;
	for(i=2;i<=city_num;++i)
		dis[i][0] = INT_MAX;
	
	int x,y;
	for(i=1;i<=city_num-1;++i)
		for(x=1;x<=city_num;++x)
			for(y=1;y<=city_num;++y)
				if(dis[x][0]!=INT_MAX && len[x][y]!=0)
					Relax(x,y);
				
	
		
}

void Relax(int x,int y)
{
	if(dis[x][0]+len[x][y]<dis[y][0] && dis[x][1] + mon[x][y] < toll)
	{
		dis[y][0] = dis[x][0] + len[x][y];
		dis[y][1] = dis[x][1] + mon[x][y];
	}
}
bool ini()
{
	memset(dis,0,sizeof(0));
	memset(len,0,sizeof(0));
	memset(mon,0,sizeof(0));
	source = 1;
	int i=0,j;
	
	if(scanf("%d",&toll)==EOF)
		return 0;
	else
	{	
		scanf("%d",&city_num);
		scanf("%d",&road_num);
		while(i<road_num)
		{	
			int c_1,c_2,length,money;
			scanf("%d %d",&c_1,&c_2);
		
			scanf("%d %d",&length,&money);
			len[c_1][c_2] = length;
			mon[c_1][c_2] = money;
		
			i++;
		}
	
		return 1;
	}
}



int main(){
	
	if(ini()!=0)
	{
		BellmanFord();
		printf("%d\n",dis[city_num][0]);
		
	}
	else
	{
		return 0;
	}
	
}


