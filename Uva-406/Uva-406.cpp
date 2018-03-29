#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#define MAX 1000000
bool is_prime[MAX];
void eratosthenes(){
 memset(is_prime,1,sizeof(is_prime));
	is_prime[0] = false;
	is_prime[1] = true;
		
		for(int i =2 ;i<=sqrt(MAX);++i)
		if(is_prime[i])
			for(int j =i+i;j<MAX;j+=i)
				is_prime[j] = false;
}

int main(void)
{
	int N,C,pri_num[10000]={0},j=0,i=0,pos;
	eratosthenes();	
	while(scanf("%d %d",&N,&C)!=EOF)
	{	
		
		j=0;
		i=0;
		while(1){
			if(j<=N && is_prime[j]==1)
			     pri_num[i++] = j;
			if(j>N)
				break;
			
			j++;
		}
		if(N<=2*C)
		{
			printf("%d %d: ",N,C);
			for(j=0;j<i;j++)
				printf("%d ",pri_num[j]);
			printf("\n");
		}
		else{
		if(i%2 == 0)
		{
			pos = i/2-C;
			printf("%d %d: ",N,C);
			for(j=0,i=pos;j<2*C;i++,j++)
				printf("%d ",pri_num[i]); 
			printf("\n");
			
		}
		else
		{
			pos = (i-1)/2-(C-1);
			printf("%d %d: ",N,C);
			for(j=0,i=pos;j<2*C-1;i++,j++)
				printf("%d ",pri_num[i]);
			printf("\n");
		}
		
		}	
	}
	return 0;
}
