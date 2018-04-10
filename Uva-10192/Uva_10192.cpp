#include<cstdio>
#include<cstdlib>
#include<string>
#include<iostream>
using namespace std;
string con_1,con_2;
int LCS[1000][1000];
void Find_LCS()
{
	int i,j,x,y;
	for(i=0,x=1;i<=con_1.length()-1;x++,i++)
	{
		for(j=0,y=1;j<=con_2.length()-1;y++,j++)
		{
			if(con_1[i] == con_2[j])
				LCS[x][y] = LCS[x-1][y-1]+1;
			
			if(con_1[i] != con_2[j] )
				if(LCS[x-1][y] > LCS[x][y-1])
					LCS[x][y] = LCS[x-1][y];
				else 
					LCS[x][y] = LCS[x][y-1];
		}	
	}
}

int main(void)
{
	int case_num=0;
	while(cin>>con_1>>con_2 && con_1!="#")
	{
		case_num++;
		
		Find_LCS();
		
		int i,j,max;
		for(i=1,max = LCS[1][1];i<=con_1.length();i++)
			for(j=1;j<=con_2.length();j++)
				if(max < LCS[i][j])
					max = LCS[i][j];
		
		printf("Case #%d:",case_num);
		printf(" you can visit ar most %d cities.\n",max);

	}
	
	return 0;
}
