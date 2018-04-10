#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

int LCS[101][101];
int t_1[101],t_2[101];
int t_1_length,t_2_length;
void Find_LCS()
{
	int i,j;
	for(i=1;i<=t_1_length;i++)
	{
		for(j=1;j<=t_2_length;j++)
		{
			if(t_1[i] == t_2[j])
				LCS[i][j] = LCS[i-1][j-1]+1;
			
			if(t_1[i] != t_2[j])
				if(LCS[i-1][j] > LCS[i][j-1])
					LCS[i][j] = LCS[i-1][j];
				else 
					LCS[i][j] = LCS[i][j-1];
		}
	}
}
int main(void)
{	
	int case_num=0; 
	while(scanf("%d %d",&t_1_length,&t_2_length)==2 && t_1_length && t_2_length)
	{
		memset(LCS,0,sizeof(LCS));
		case_num++;
		for(int i = 1;i<=t_1_length;i++)
		scanf("%d",&t_1[i]);
		for(int j=1;j<=t_2_length;j++)
		scanf("%d",&t_2[j]);
		
		Find_LCS();
		
		int i,j,max;
		for(i=1,max = LCS[1][1];i<=t_1_length;i++)
			for(j=1;j<=t_2_length;j++)
				if(max < LCS[i][j])
					max = LCS[i][j];
		printf("Twin Towers #%d\n",case_num);
		printf("Number of Tiles : %d\n\n",max);
	}	
	
	return 0;
}










