#include<cstdio>
#include<cstdlib>
using namespace std;

bool visit[6][6];
int ans[9];
void ini();
void backtrack(int begin,int x);
void print();
int main(void)
{
	
	ini();
	ans[0] = 1;
	backtrack(1,0);
	return 0;
}
void ini()
{
	int i,j;
	
	for(i=1;i<6;i++)
		for(j=1;j<6;j++)
			if( (i ==1 || i==2) && j==4)
			{}
			else if(i==4 && (j == 1 || j==2))
			{}
			else if(i == j)
			{}
			else
				visit[i][j] = true;
	
	return;
}

void backtrack(int begin,int x)
{
	if(x == 8)
	{
		print();
		return;
	}
	int i;
	for(i=1;i<6;i++)
	{
		if(visit[begin][i] == true)
		{
			visit[begin][i] = false;
			visit[i][begin] = false;
			ans[x+1] = i;
			backtrack(i,x+1);
			visit[begin][i] = true;
			visit[i][begin] = true;
		}
	}	
}


void print()
{
	int i;
	for(i=0;i<9;i++)
	printf("%d",ans[i]);
	printf("\n");
	
	return;
}
