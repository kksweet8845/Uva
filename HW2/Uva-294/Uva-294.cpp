#include<stdio.h>
#include<stdlib.h>
#include<cmath>
#include<cstring>
#define MAX 1000000
bool *pch= (bool*)malloc(MAX*sizeof(bool));
bool is_prime[MAX];
long long int *npt =(long long int *) malloc(MAX*sizeof(long long int));
void eratosthenes()
{
	memset(pch,1,MAX*sizeof(bool));
	*pch= false;
	*(pch +1) = false;
	long long int i,j;
	for(i=2;i<=MAX;++i)
	{
		if(*(pch + i))
		 	for( j=i+i;j<=MAX;j+=i)
				*(pch +j) = false;
	}
}
void ini()
{
	 long long int i;
	for(i=0;i<MAX;i++)
	{
		*(npt+i) = 0;
	}
}
int main(void)
{
	int case_num;
	eratosthenes();
	scanf("%d",&case_num);
	
	long long int i,j,x;
	long long int low,upper,k,max_num;
      	long long int max,num,div =1;
	for(i=0;i<case_num;i++)
	{
		
		scanf("%Ld %Ld",&low,&upper);
		for(k=low,max=div,max_num=k;k<upper+1;k++)
		{	
			ini();
			num = k;
			for(j=2;j<=k/2;j++)
			{
				if(num ==1)break;
				if(num%j == 0 && *(pch+j) == true )
				{
					num = num/j;
					*(npt+j) = (*(npt +j))+1;
					if(num%j == 0)
						--j;
					
				}
			}
			for(x =2,div =1;x<k/2;x++)
			{
				if(*(npt+x)>0)
				{
					div *=(*(npt+x)+1);
				}
			}
			if(max < div)
			{
				max_num = k;
				max = div;
			}
		}
		printf("Between %Ld and %Ld, %Ld has a maximum of %Ld divisors.\n",low,upper,max_num,max);
	}

	return 0;
}
