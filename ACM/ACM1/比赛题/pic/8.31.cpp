//输入一个n，求出不大于n的最大的k，满许k^k<=n    

#if 0
#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	long long int num;	
	int b;
	double NUM;
	
	while(scanf("%lld",&num)&&num)
	{
		if(num==1)
		{
			cout<<1<<endl;
			continue;
		}
		NUM=log10(num); 
		
		for(long long int i=1; i<=num; i++)
		{
			double a=i*log10(i);
			if(a>NUM) 
			{
				b=i;
				break;
			
			}
		}
	
		printf("%d\n",b-1);
		
	}

}

#endif 






































