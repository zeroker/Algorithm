//3.31
#if 0
#include<iostream>
#include<cstring>
using namespace std;
int n,v,a[1002],c[1002],f[1002];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	
		cin>>n>>v;
		
		for(int i=1; i<=n; i++)
		cin>>a[i];
		for(int i=1; i<=n; i++)
		cin>>c[i];
		
		memset(f,0,sizeof(f));
		for(int i=1; i<=n; i++)
		{
			for(int vi=v;vi>=a[i];vi--) 
			{
			if(f[vi-a[i]]+c[i]>f[vi])
			f[vi]=f[vi-a[i]]+c[i] ;
			}
			
		}
		
		cout<<f[v]<<endl;
	}
	
}
#endif
// 这个题求 组合数问题 虽然简单  但是没掌握  没掌握 很蛋疼的啊 
//3.32
#if 0 
#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,m;
  while(cin>>n>>m && n+m)
  {
     int value[1001],
  	
  }	
	
}
#endif 
//百度帖代码
#if 0
#include<bits/stdc++.h>
using namespace std;

const int MAX=100000;
int dp[MAX];
int c[MAX],w[MAX];
int v;

void ZeroOnePack(int cost,int wei)//01
{
    int i;
    for(i = v;i>=cost;i--)
    {
        dp[i] = max(dp[i],dp[i-cost]+wei);
    }
}

void CompletePack(int cost,int wei)//完全
{
    int i;
    for(i = cost;i<=v;i++)
    {
        dp[i] = max(dp[i],dp[i-cost]+wei);
    }
}

void MultiplePack(int cost,int wei,int cnt)//多重
{
    if(v<=cnt*cost)//如果总容量比这个物品的容量要小，那么这个物品可以直到取完，相当于完全背包
    {
        CompletePack(cost,wei);
        return ;
    }
    else//否则就将多重背包转化为01背包
    {
        int k = 1;
        while(k<=cnt)
        {
            ZeroOnePack(k*cost,k*wei);
            cnt = cnt-k;
            k = 2*k;
        }
        ZeroOnePack(cnt*cost,cnt*wei);
    }
}

int main()
{
    int n;
    while(~scanf("%d%d",&n,&v),n+v)
    {
        int i;
        for(i = 0;i<n;i++)
        scanf("%d",&c[i]);
        for(i = 0;i<n;i++)
        scanf("%d",&w[i]);
        memset(dp,0,sizeof(dp));
        for(i = 0;i<n;i++)
        {
            MultiplePack(c[i],c[i],w[i]);
        }
        int sum = 0;
        for(i = 1;i<=v;i++)
        {
            if(dp[i]==i)
            {
                sum++;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}


#endif 





//3.33   罗方块           //终于知道没有好好巩固知识 好好啊学习有多么的蛋疼了吧 
#if 0
#include <iostream>
#include <algorithm>
using namespace std;
struct Cuboid
{
    int l,w,h;
}cd[181];
int dp[181];


// sort比较函数
bool cmp( Cuboid cod1,Cuboid cod2 )
{
    if( cod1.l==cod2.l )    return cod1.w<cod1.w;
    return cod1.l<cod2.l;
}
int main()
{
    int i,j,n,len,t_num=1;
    int z1,z2,z3;
    while( cin>>n && n )
    {
        len=0;
        // 每组数都可以变换为6种长方体
        for(i=0;i<n;++i)
        {
            cin>>z1>>z2>>z3;
            cd[len].l=z1,cd[len].w=z2,cd[len++].h=z3;
            cd[len].l=z1,cd[len].w=z3,cd[len++].h=z2;
            cd[len].l=z2,cd[len].w=z1,cd[len++].h=z3;
            cd[len].l=z2,cd[len].w=z3,cd[len++].h=z1;
            cd[len].l=z3,cd[len].w=z1,cd[len++].h=z2;
            cd[len].l=z3,cd[len].w=z2,cd[len++].h=z1;
        }

        sort(cd,cd+len,cmp);
        dp[0]=cd[0].h;
        
        // 构建dp数组
        int max_h;
        for(i=1;i<len;++i)
        {
            max_h=0;
            for( j=0;j<i;++j )
            {
                if( cd[j].l<cd[i].l && cd[j].w<cd[i].w )
                    max_h=max_h>dp[j]?max_h:dp[j];
            }
            dp[i]=cd[i].h+max_h;
        }
        
        // 再次搜索 所有dp中最大值
        max_h=0;
        for(i=0;i<len;++i)
            if( max_h<dp[i] )
                max_h=dp[i];
        // 输出
        cout<<"Case "<<t_num++<<": maximum height = "<<max_h<<endl;
    }
    return 0;
}

#endif




//3.34 经典的多重背包问题  悼念四川题 
#if 0
#include<bits/stdc++.h>
using namespace std; 
int main()
{
	int value[105],weight[105],numb[105],f[105];
	int t;
	cin>>t;
	while(t--)
	{
		memset(f,0,sizeof(f));
		int m,n;
		cin>>m>>n;
		
		for(int i=1; i<=n; i++)
		cin>>value[i]>>weight[i]>>numb[i];
		
		for(int i=1; i<=n; i++) 
		{
			for(int j=1; j<=numb[i]; j++)
			{
				for(int v=m; v>=value[i]; v--)
				f[v]=max(f[v],f[v-value[i]]+weight[i]);
			}
		}
		
		cout<<f[m]<<endl;
	}
	
}
#endif 


//3.35
#if 1
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int MAX = 999999;
int val[111],time[111],dp[111][1111];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m,l;
        scanf("%d%d%d",&n,&m,&l);
        int i,j,k;
        for(i = 0; i<n; i++)
            scanf("%d%d",&time[i],&val[i]);
        for(i = 0; i<=m; i++)
        {
            for(j = 0; j<=l; j++)
            {
                if(i==0)
                    dp[i][j] = 0;
                else
                    dp[i][j] = -MAX;//价值可能为负数
            }
        }
        for(i = 0; i<n; i++)//状态转移
        {
            for(j = m; j>=1; j--)
            {
                for(k = l; k>=time[i]; k--)
                {
                    dp[j][k] = max(dp[j][k],dp[j-1][k-time[i]]+val[i]);
                }
            }
        }
        if(dp[m][l]<0)
            dp[m][l] = 0;
        printf("%d\n",dp[m][l]);
    }

    return 0;
}


#endif






//3.36 求概率的问题  
//第一次遇见这样的带乘法的： 状态转移方程：dp[j]=min(dp[j],dp[j-a[i]]*(1.0–b[i])); 
#if 0
#include<iostream>
using namespace std;
#define SIZE 11111
double dp[SIZE];
double Min(double x,double y)
{
    return x<y?x:y;
}
int main()
{
    int i,j;
    int n,m,a[SIZE];
    double b[SIZE];
    while(cin>>n>>m,n+m)
    {
        for(i=0;i<m;i++)
            scanf("%d %lf",&a[i],&b[i]);
        fill(dp,dp+11111,1);/*概率通通赋值为1*/  
        for(i=0;i<m;i++)  
        {
            for(j=n;j>=a[i];j--)
            {
                dp[j]=Min(dp[j],dp[j-a[i]]*(1-b[i]));
            }
        }
        printf("%.1lf%%\n",(1-dp[n])*100);    
    }
    return 0;
}

#endif

//3.38  自己打表 和 3.36完全一样的题目 
#if 0
#include<bits/stdc++.h>
using namespace std;
double min(double x,double y)
{
	return x<y?x:y;
}
double dp[10005];
int main()
{
	ios::sync_with_stdio(false);
  	int n,m;
  	int a[10005]={0};
  	double b[10005]={0};
  	while(cin>>n>>m && n+m)
  	{
  	 for(int i=0; i<m; i++)
  	  cin>>a[i]>>b[i];

	  fill(dp,dp+10005,1);   
	  
	  for(int i=0; i<m; i++)
	  {
	  	for(int j=n; j>=a[i]; j--)
	  	{
	  	 	dp[j]=min(dp[j],dp[j-a[i]]*(1-b[i]));
	    }
	  }	
	  
	  cout<<fixed<<setprecision(1)<<double(1.0-dp[n])*100<<"%"<<endl;	
	     
	}
	
	
}
#endif 

//3.37 打饭   潜在的背包问题， 如果不是在这个专题里 根本看不出来 
#if 0 
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while(cin>>n && n)
	{
		int a[1001];
		for(int i=1; i<=n; i++)
		cin>>a[i];
    	sort(a+1,a+n+1);
    	
		int m,k;
		cin>>m;
		if(m<5)
		cout<<m<<endl;
		else
	{
	     int f[1001]={0};
	     for(int i=1; i<=n; i++)
	     {
	     	for(int j=m-5; j>=a[i]; j--)
	     	{
	     	 if(f[j]<f[j-a[i]]+a[i])
			  f[j]=f[j-a[i]]+a[i];	
			}
		 }
	  
	    cout<<m-a[n]-f[m-5]<<endl;
	}
	
   }
}
#endif 



















