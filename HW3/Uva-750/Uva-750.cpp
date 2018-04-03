#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

bool board[9][9];
bool dx[9],dy[9],mx1[16],mx2[16];
int case_num,case_x,case_y,times;
void backtrack(int x,int y,int c);
void print();
int main(void)
{
	scanf("%d",&case_num);
	int i;
	for(i=0;i<case_num;i++)
	{
		memset(board,0,sizeof(board));
		memset(dx,0,sizeof(dx));
		memset(dy,0,sizeof(dy));
		memset(mx1,0,sizeof(mx1));
		memset(mx2,0,sizeof(mx2));
		times = 0;
		scanf("%d %d",&case_x,&case_y);
		dx[case_x] = dy[case_y] = mx1[case_y+case_x-1] = mx2[case_x+8-case_y] = true;
		printf("SOLN       COLUMN\n");
		printf(" #      1 2 3 4 5 6 7 8\n\n");
		board[case_x][case_y] = true;
		backtrack(1,1,1);
		printf("\n");
	}
	
	return 0;
}


void backtrack(int x,int y,int c)
{
	if(x == 9) {
		x = 1, y++;
	}
	
	if(y == 9){
		if(c!=8)return;
		times++;
		print();
		
		return;
	}
	int i,m_1=x+y-1,m_2=x+8-y;
  

	if(!dx[x] && !dy[y] && !mx1[m_1] && !mx2[m_2])
	{
		dx[x] = dy[y] = mx1[m_1] = mx2[m_2] = true;
		board[x][y] = true;
		backtrack(x+1,y,c+1);
		dx[x] = dy[y] = mx1[m_1] = mx2[m_2] = false;
	}
	
	
	if(x != case_x && y != case_y)	
	{
		board[x][y] = false;
		backtrack(x+1,y,c);
	}
	else 
	{
		backtrack(x+1,y,c);
	}
	
}


void print()
{
	int i,j;
	if(times <10)
	printf(" %d",times);
	else
	printf("%d",times);
	
	for(i=0;i<6;i++)
	printf(" ");
	
	for(i=1;i<9;i++)
		for(j=1;j<9;j++)
			if(board[j][i] == true)
			{
				printf("%d",j);
				if(i!=8)
				printf(" ");	
			}	
	printf("\n");
	
	
}
