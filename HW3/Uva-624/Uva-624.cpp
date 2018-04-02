#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
bool seq[20],check;
int N,seq_num[20],sum_real,diff,pre[20],pre_num,e;
void backtrack(int digit,int index ,int sum);
void print();

int main(void)
{
	int i;
	while(1)
	{
		if(scanf("%d",&sum_real) !=EOF)
		{
			scanf("%d",&N);
			for(i=0;i<N;i++)
			{
				scanf("%d",&seq_num[i]);
			}
			
			memset(seq,1,sizeof(seq));
			pre_num = 0;
			memset(pre,0,sizeof(pre));
			diff = sum_real;
			e =0;
			check = false;
			backtrack(0,0,0);
		}
		else
			break;
	}	
	
	return 0;
}



void backtrack(int digit,int index,int sum)
{
	int i;
	if(sum == sum_real)
	{
		if(e==0)
		{
			print();
			e =1;
		}
		check = true;	
		return;
	}
	else if(sum < sum_real)
	{
		
		for(i=digit;i<N;i++)
		{
			seq[i] = false;
			if(abs(sum_real-seq_num[i]-sum) < diff)
			{
				diff = abs(sum_real - seq_num[i]-sum);
				int k,j;
				for(k=0,j=0;k<N;k++)
				{
					if(seq[k] == false)
					{
						pre[j++] = seq_num[k];
						pre_num = j;
					}
				}
			}

			
			backtrack(i+1,index+1,sum+seq_num[i]);
			seq[i] = true;
		}
	}
	else if(sum > sum_real)
	{
		return;
	}
	
	if(index == 0 && i == N && check == false)
	{
		int x,pre_sum = 0;
		for(x = 0;x<pre_num;x++)
		{
			printf("%d ",pre[x]);
			pre_sum += pre[x];
		}
		
		printf("sum:%d\n",pre_sum);
	}
	
}

void print()
{
	int i,sum=0;
	for(i=0;i<N;i++)
	{
		if(seq[i] == false)
		{
			printf("%d ",seq_num[i]);
			sum+=seq_num[i];
		}
	}
	printf("sum:%d\n",sum);
}

