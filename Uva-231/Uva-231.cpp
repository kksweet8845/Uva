#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
int LIS[1000];
int m[1000];
int missile;
void Find_LIS()
{
	int i,j;
	for(i=1;i<missile;i++)
	{
		LIS[i] = 1;
		for(j=1;j<i;j++)
		{
			if(m[j]>m[i] && LIS[j]+1>LIS[i])
				LIS[i]=LIS[j]+1;
		}
	}
}

int main(void)
{
	int case_num =0,end;
	while(1)
	{
		case_num++;
		int i=1;
		memset(m,0,sizeof(m));
		while(scanf("%d",&m[i]) && m[i++]!=-1)
		{
			missile = i;
			
		}
		if(m[1]==-1)
			break;
		
		memset(LIS,0,sizeof(LIS));
		
		Find_LIS();
		
		int j,max;
		for(j=1,max = LIS[1];j<missile;j++)
			if(max < LIS[j])
				max = LIS[j];
		
		printf("Test #%d:\n",case_num);
		printf("  maximum possible interceptions: %d\n\n",max);
		
		
	}
	
	return 0;
}
