#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
bool seq[12];
int sum_org,num,times;
int real_num[12];
void backtrack(int sum,int index);
void print();
int main(void)
{
	int i;
	while(1)
	{
		memset(real_num,0,sizeof(real_num));
		memset(seq,1,sizeof(seq));
		scanf("%d %d",&sum_org,&num);
		if(sum_org+num == 0)
			break;
		for(i =0;i<num;i++)
		scanf("%d",&real_num[i]);
		printf("Sums of %d:\n",sum_org);
		backtrack(0,0);
		if(times == 0)
			printf("NONE\n");
	}
	return 0;
}

void backtrack(int sum,int index)
{
	int i;
	if(sum == sum_org)
	{
		print();
		times++;
		return; 
	}
	else if(sum < sum_org)
	{
		for(i=index;i<num;i++)
		{	
			if(seq[i] == true)
			{
				seq[i] = false;
				backtrack(sum+real_num[i],index+1);
				seq[i] = true;
			}
		}	
	}
	else if(sum > sum_org)
		return;
	
	
}


void print()
{
	int i,sum =0;
	for(i=0;i<num;i++)
	{
		if(seq[i] == false)
		{	
			printf("%d",real_num[i]);
			sum += real_num[i];
		if( i!=num-1 && sum!=sum_org)
			
			printf("+");
		}
	}
	printf("\n");
}
