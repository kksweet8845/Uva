#include<stdio.h>
#include<stdlib.h>

int seq;
long long int find(int num);
int main(void)
{
	

	printf("The 1500'th ugly number is %Ld",find(1500));
			
		
return 0;	
}

long long int find(int num)
{
	long long int i,k;
	int prime[3]={2,3,5};
	int th;
	for(k=2,seq=1;seq!=num;k++)
	{	th =0;
		i =k;
		while(1)
		{
			if(i%prime[th]==0 && i!=1)
			{
				i=i/prime[th];
			}
			else if(i%prime[th+1]==0 && i!=1)
			{
				i=i/prime[th+1];	
			}
			else if(i%prime[th+2]==0 && i!=1)
			{
				i=i/prime[th+2];
			}
			else if(i!=1)
			{
				break;
			}
			else if(i==1)
			{
				seq++;
				break;
			}
			
			
		}
	}
	return k;
	
}
