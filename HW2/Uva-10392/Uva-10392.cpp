#include<cmath>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
void eratosthenes();
long long int factor(long long int num);
long long int ptr;
bool bo;
bool *npt = (bool*)malloc(80000*sizeof(bool));
int main(void)
{	

	long long int ptr;
	eratosthenes();
	while(1){
		scanf("%lld",&ptr);
		if(ptr<0)
		{
			break;
		}
		else
		{
		
				
			 factor(ptr);				
				
			
		}
	}
	return 0;
}

void eratosthenes()
{
	memset(npt,1,sizeof(npt));
	*(npt+2) = false;
	*(npt+3) = false;
	
	long long int i;
	for(i=2;i<=80000;++i)
	{
		if(*(npt+i))
			for(long long int j = i+1;j<80000;j+=i)
				*(npt+j) = false;
	}
}
long long int  factor(long long int num)
{
	long long int i,j,ptr;
	ptr = num;
	for(i=2,j = 0;i<80000;)
	{	
		if(ptr%i==0 && *(npt+i)==0)
		{
			ptr/=i;
			printf("    %lld\n",i);
			if(ptr%i==0)
			i--;
		}
		i++;
		
	}
	if(ptr>80000)
	{printf("    %lld\n\n",ptr);return 0;}	
	printf("\n");

	return j;
}
