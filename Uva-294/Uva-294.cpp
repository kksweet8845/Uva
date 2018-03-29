#include<stdio.h>
#include<stdlib.h>
#include<cmath>
#include<cstring>
#define MAX 1000000
bool is_prime[MAX];
void eratosthenes()
{
	memset(is_prime,1,sizeof(is_prime));
	is_prime[0]= false;
	is_prime[1] = false;
	
	for(int i=2;i<=sqrt(MAX);++i)
	{
		if(is_prime[i])
		 	for(int j=i+i;j<MAX;j+=i)
				is_prime[j] = false;
	}
}
void ini(int arr[])
{
	int i;
	for(i=0;i<=1000000;i++)
	{
		arr[i] = 0;
	}
}
int main(void)
{
	int case_num,pri[1000000];
	eratosthenes();
	scanf("%d",&case_num);
	
	int i,j,x;
	long long int num1,num2,low,upper,k,max_num;
	int max,num,div =1;
	for(i=0;i<case_num;i++)
	{
		
		scanf("%Ld %Ld",&low,&upper);
		for(k=low,max=div,max_num=k;k<upper+1;k++)
		{	
			ini(pri);
			num = k;
			for(j=2;j<=num;j++)
			{
				if(num ==1)break;
				if(num%j == 0 && is_prime[j] == 1 )
				{
					num = num/j;
					pri[j]++;
					if(num%j == 0)
					{
						j--;
						
					}
				}
			}
			for(x =2,div =1;x<=10000;x++)
			{
				if(pri[x]>0)
				{
					div *=(pri[x]+1);
				}
			}
			if(max < div)
			{
				max_num = k;
				max = div;
			}
		}
		printf("Between %Ld and %Ld, %Ld has a maximum of %d divisors.\n",low,upper,max_num,max);
	}
	
	return 0;
}
