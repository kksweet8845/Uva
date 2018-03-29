#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;

class mul{
	public:
		mul(){
		answer =0;
		}
		mul(long long int a,long long int b){
		mul_[0] = a;
		mul_[1] = b;
		answer = 0;
		work();
		
		
	
		}
	void work(){
	long long int i=0,j=0,num;
	num = mul_[1];
	while(1){
		
		uni[i] = num%10;
		i++;
		num = num/10;
		if(num <10)
		{
			uni[i] = num;
			break;
		}
	}
	while(1)
	{	
		ans[j] = (uni[j]*mul_[0])*pow(10.0,j);
		answer = answer + ans[j];
		j++;
		if(j==i+1)
			break;
		
		
	}
	
	}
	int check(unsigned long long int num){
	int i=0;	
	while(1){
	num = num/10;
	i++;
	if(num==0)
		return i;
		
	}
	
	}
	void print()
	{
		long long int i,dig,j,dig_mul_1,dig_mul_2;
		dig = check(answer);
		dig_mul_1 = check(mul_[0]);
		dig_mul_2 = check(mul_[1]);
		for(i=0;i<2;i++)
		{
			for(j=0;j<(answer==0? (dig_mul_1>=dig_mul_2? dig_mul_1:dig_mul_2):dig)-(mul_[i]==0? 1:check(mul_[i]) );j++)
				printf(" ");
			printf("%Ld",mul_[i]);
			if(i != 1)printf("\n");
		}
		printf("\n");
		
		for(i=0;i<dig-(dig_mul_1>=dig_mul_2? dig_mul_1:dig_mul_2);i++)
		printf(" ");
		for(i=0;i<(dig_mul_1>=dig_mul_2? dig_mul_1:dig_mul_2);i++)
		{
			
			printf("-");
		}
		printf("\n");
		if(check(mul_[1])==1)goto end;
		if(mul_[0]==0 || mul_[1] ==0)goto end;
		
		for(i=0;i<check(mul_[1]);i++)
		{
			for(j=0;j<dig-check(ans[i]);j++)
				printf(" ");
			ans[i]=ans[i]/pow(10.0,i);
			if(ans[i] == 0) continue;
			printf("%Ld",ans[i]);
			printf("\n");
		}
		
		for(i=0;i<dig;i++)
			printf("-");
		printf("\n");
		end:;
		if(answer ==0)
		{
			for(i=0;i< (dig_mul_1>=dig_mul_2? dig_mul_1:dig_mul_2)-1;i++)
			printf(" ");
			printf("%Ld",answer);
			printf("\n\n");
		}
		else
		{
		printf("%Ld",answer);
		printf("\n\n");
		}
			
	}
	
	
	private:
	long long int uni[100],ans[100];
        unsigned long long int answer;
	unsigned long long int mul_[2];
};


int main(void)
{
	long long int mul_1,mul_2;
		
	while(1){
	
	if(scanf("%Ld",&mul_1)==1)
	{
		if(scanf("%Ld",&mul_2)==1)
		{
			mul muler(mul_1,mul_2);
			muler.print();
		}
	}
	else
		break;
	
	
	}
	return 0;
}
