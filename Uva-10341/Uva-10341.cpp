#include<cstdio>
#include<cstdlib>
#include<cmath>
double func(double);
double binary_search();
double p,q,r,s,t,u;
double ans;
int main(void)
{
	while(scanf("%lf %lf %lf %lf %lf %lf",&p,&q,&r,&s,&t,&u)!=EOF)
	{
		ans = binary_search();
		if(ans==2)
			printf("No solution\n");
		else
			printf("%.4lf\n",ans);
	}
	return 0;
}

double func(double x)
{
	double val;
	
	val = p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u;
	
	return val;
}

double binary_search()
{
	double left = 0,right = 1,middle;
	bool flag = 0;
	if(func(0.1)>func(0.2))
		flag = 0;
	else
		flag = 1;
	if(func(0) >0 && func(1) > 0)
		return 2;
	else if(func(0) < 0 && func(1) < 0)
		return 2;
	while(left < right)
	{
		 middle = (left+right)/2;
		if(func(middle) < 0 && flag)
		{
			left = middle;
		}
		else if(func(middle) > 0 && flag)
		{
			right = middle;
		}
		else if(func(middle) < 0 && !flag)
		{
			right = middle;
		}
		else if(func(middle) > 0 && !flag)
		{
			left = middle;
		}
		
		if(abs(func(middle))<0.00000001)
			break;
	}
		
	return middle;

}
