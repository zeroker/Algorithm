

// 思维方式！！！ 还有读题读了半天都没有！  E - Scales 
#if 0
#include<iostream>
#include<stdio.h>
using namespace std;
#define MAX 50000+50

long long int w[MAX],s[MAX],c[MAX];

int main()
{
	int n;
	long long int minn=0x7fffffff;
	while(~scanf("%d",&n)&&n)
	{
		minn=0x7fffffff;
		long long int sum=0;
		for(int i=1; i<=n; i++)
		{
		
			scanf("%lld%lld",&w[i],&s[i]);
			sum+=w[i];
		}
		
		
		for(int i=1; i<=n; i++)
		{
			long long int ew=sum;
			long long int risk=0;
			
			ew=sum-w[i];
			risk=ew-s[i];
			
			if(minn>risk)
				minn=risk;
				
		}
		printf("%lld\n",minn);
		
	}
	
}

#endif




//别人说它是个水题  我擦  一个水 深搜都没有？？？！！！ E - Scales  poj 
#if 0
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
#define MAX 1000+50

int n,c;
int a[MAX];
int maxx;
bool vis[MAX];
int sum;
void dfs(int i) 
{
	cout<<sum<<" <----sum"<<endl;
	if(sum<c)
	{
		if(sum>maxx)
			maxx=sum;
		
	}
	
	 if(sum>=c)
	{
		return;
	}
	else
	{
		if(!vis[i])
		{
			vis[i]=1;
			sum+=a[i];
			//num=a[i]; 
			
			i++;
			dfs(i);
			vis[i]=0;
			sum-=a[i];
			//i--;
		}			
	}
	
}

int main()
{
	while(~scanf("%d%d",&n,&c)&&n&&c)
	{
		maxx=0;
		//memset(vis,0,sizeof(vis));
		memset(a,0,sizeof(a));
		
		for(int i=1; i<=n; i++)
			scanf("%d",&a[i]);
			
		sort(a,a+n);
		
		dfs(1);	
		printf("%d\n",maxx);
	}
}

#endif












































