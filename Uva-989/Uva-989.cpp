#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

int board[9][9];
int size,times;
#define SIZE size*size
void backtrack(int x,int y);
void print();
bool check(int x,int y,int num);
bool check_nine(int x,int y,int num,int x_ref,int y_ref);
int main(void)
{
	int i,j,k;
	while(1)
	{
		if(scanf("%d",&size)!=EOF)
		{
			
			memset(board,0,sizeof(board));
			for(i=0;i<SIZE;i++)
				for(j=0;j<SIZE;j++)
					scanf("%d",&board[i][j]);
			times = 0;
			backtrack(0,0);	
			if(times == 0)
				printf("NO SOLUTION\n\n");
		}
		else
			break;
	}
}


void backtrack(int x,int y)
{
	int i;
	
	if(y == SIZE ) y = 0,x++;
	
	if(x == SIZE && times==0) 
	{
		print();
		times++;
		return;
	}
	
	if(board[x][y] == 0 && times == 0)
	{
		for(i=1;i<=SIZE;i++)
		{
			board[x][y] = i;
			if(check(x,y,i))
			backtrack(x,y+1);
			
			board[x][y] = 0;
		}
	}
	else if(times == 0)
	{
		backtrack(x,y+1);
		
	}
	
		
	
	
	
}

void print()
{
	int i,j;
	for(i=0;i<SIZE;i++)
	{
		for(j=0;j<SIZE;j++)
		{
				printf("%d",board[i][j]);
				if(j!=SIZE-1)
					printf(" ");
		}
			printf("\n");
	}	
	
	printf("\n");
}
bool check(int x,int y,int num)
{
	int i,j;
	for(i=0;i<SIZE;i++)
		if(board[i][y] == num && i!=x)
			return 0;
	
	for(j=0;j<SIZE;j++)
		if(board[x][j] == num && j!=y )
			return 0;
	
	if(x>=0 && x<size)
	{
		if(y>=0 && y < size)
		{
			if(!check_nine(0,0,num,x,y))
				return 0;
		}
		else if(y>=size && y < size*2)
		{
			if(!check_nine(0,size,num,x,y))
				return 0;
		}
		else if(y >= size*2)
		{
			if(!check_nine(0,size*2,num,x,y))
				return 0;
		}
	}
	else if(x >=size &&  x <size*2)
	{
	
		if(y>=0 && y < size)
		{
			if(!check_nine(size,0,num,x,y))
				return 0;
		}
		else if(y>=size && y <size*2)
		{
			if(!check_nine(size,size,num,x,y))
				return 0;
		}
		else if(y >= size*2)
		{
			if(!check_nine(size,size*2,num,x,y))
				return 0;
		}
	}
	else if(x >= size*2)
	{
		if(y>=0 && y < size)
		{
		
			if(!check_nine(size*2,0,num,x,y))
				return 0;
		}
		else if(y>=size && y <size*2)
		{
			if(!check_nine(size*2,size,num,x,y))
				return 0;
			
		}
		else if(y >= size*2)
		{
			if(!check_nine(size*2,size*2,num,x,y))
				return 0;
		}
	
	}
		
	return 1;
	
	
	
	
}

bool check_nine(int x,int y ,int num,int x_ref,int y_ref)
{
	int i,j;
	
	for(i=x;i<x+size;i++)
		for(j=y;j<y+size;j++)
			if(board[i][j] == num && i!=x_ref && j!=y_ref)
				return 0;
	
	return 1;
}
