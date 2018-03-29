#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
bool visit[8][8];
bool dx[8],dy[8],ds1[15],ds2[15];
int board[8][8];
int ans,max;
void backtrack(int x, int y,int c);
int main(void)
{
	int k,i,j,l;
	scanf("%d",&k);
	for(i=0;i<k;i++)
	{	
		memset(visit,0,sizeof(visit));
		memset(board,0,sizeof(board));
		memset(dx,0,sizeof(dx));
		memset(dy,0,sizeof(dy));
		memset(ds1,0,sizeof(ds1));
		memset(ds2,0,sizeof(ds2));
		max = ans =0;
		for(j=0;j<8;j++)
		{
			for(l=0;l<8;l++)
			scanf("%d",&board[j][l]);	
		}
		backtrack(0,0,0);
		
		printf("%5d\n",max);	
	}
	
	
}

void backtrack(int x, int y, int c)
{
	if(y == 8) x++,y=0;
	
	if(x == 8 && c==8)
	{
		int i,j,ans=0;
		for(i=0;i<8;i++)
			for(j=0;j<8;j++)
				if( visit[i][j] == 1)
					ans+=board[i][j];
		if(max < ans)
			max = ans;	
		
		return;
	}
	else if(x ==8  && c!=8)
		return;
	int d1 = x+y, d2 = x+7-y;
	if(!dx[x] && !dy[y] && !ds1[d1] && !ds2[d2])
	{
		
		dx[x] = dy[y] = ds1[d1] = ds2[d2] = true;
		visit[x][y] = true;
		backtrack(x,y+1,c+1);
		
		dx[x] = dy[y] = ds1[d1] = ds2[d2] = false;;
	}
	
	visit[x][y] = false;
	backtrack(x,y+1,c);
	
	
}
