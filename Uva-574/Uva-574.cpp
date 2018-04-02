#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
bool seq[12];
int sum_org,num,times,text[12];
int real_num[12];
char ans[500][13],t[13];
void backtrack(int sum,int index,int digit);
void print();
int check();
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
		memset(ans,0,sizeof(ans));
		times = 0;
		backtrack(0,0,0);
		if(times == 0)
			printf("NONE\n");
	}
	return 0;
}

void backtrack(int sum,int index,int digit)
{
	int i;
	if(sum == sum_org)
	{
		if(check())
		{
			print();
			strcpy(ans[times],t);
		}
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
				text[digit] = real_num[i];
				backtrack(sum+real_num[i],i+1,digit+1);
				seq[i] = true;
				text[digit] = 0;
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

int check()
{
	int i,j;
	for(i=0;i<12;i++)
	{
		t[i] = text[i] + 48;
	}
	for(i=0;i<times;i++)
	{
		if(!strcmp(t,ans[i]))
		{
			return 0;	
		}
		
	}
	
	return 1;
}
