//00001 树状数组简单求和
#if 0
#include<iostream>
using namespace std;
int a[10000];
int lowbit(int x)
{
	return x&(-x);
}
void add(int i,int v)
{
	for( ; i<1000; i+=lowbit(i))
	{
		a[i]+=v;
	}
}

int query(int x)
{
	int sum=0;
	for( ; x>0; x-=lowbit(x))
	{
		sum+=a[x];
	}	
	return sum;
}

int main()
{
	for(int i=1; i<=5; i++)
	{
		int x;
		cin>>x;
		add(i,x);
	}
	cout<<query(5)<<endl;	
	
}
#endif 



// 1020                     求有几个逆序数 
#if 01 
#include<iostream>
#include<algorithm>
#include<cstring>
#include<stdio.h>
#include<cmath>

using namespace std;
const int MAXN=500000+50; 
int n;	
int b[MAXN];
int c[MAXN];


struct node
{
	int v,id;
	
	bool operator <(const node & a)const
	{
		return v<a.v;	
	}
			
}a[MAXN];

int lowbit(int x)
{
	return x&(-x);
}

void add(int x,int v)
{
	for( ; x<=MAXN	; x+=lowbit(x))
	{
		c[x]+=v;
	}
}

int sum(int x)
{
	int sum=0;
	for( ; x>0; x-=lowbit(x))
		sum+=c[x];
		
	return sum;	
}

int main()
{
	while(cin>>n&&n)
	{
		memset(c,0,sizeof(c));
		memset(b,0,sizeof(b));
		memset(a,0,sizeof(a));
		
		for(int i=1; i<=n; i++) 
		{
			scanf("%d",&a[i].v);
			a[i].id=i;
		}
		
		sort(a+1,a+n+1);
		b[a[1].id]=1;
		for(int i=2; i<=n; i++)
		{
			if(a[i].v==a[i-1].v)
				b[a[i].id]=b[a[i-1].id];
			else
				b[a[i].id]=i;	
		}
		
		long long int s=0;
		for(int i=1; i<=n; i++)
		{
			
		//	int temp=i-1-sum(b[i]); // int temp=sum(n)-sum(b[i]);	
			//add(b[i],1);
			add(b[i],1); 
			int temp=i-sum(b[i]);            
			s+=temp;
				
		}
	
		cout<<s<<endl;
	}
	
}
#endif



//1019       区间改变，区间求和 
#if 0
#include<iostream>
#include<cstring>
#include<stdio.h>

using namespace std;
const int MAXN=100000+50;
typedef long long ll;
ll  b[MAXN],c[MAXN];
ll  a[MAXN]; 

int lowbit(ll  x)
{
	return x&(-x);
}

void add_B(ll  *a,ll  x,ll  v)
{
	for( ; x>0; x-=lowbit(x))
		a[x]+=v;
}
ll sum_B(ll  *a,ll  x)
{
	ll  s=0;
	for(; x<MAXN; x+=lowbit(x))
	{
		s+=a[x];
	}
	
	return s;
}

void add_C(ll  *a,ll  x,ll v)
{
	for( ; x<MAXN; x+=lowbit(x))
	{
		a[x]+=v;
	}
	
}
ll sum_C(ll *a, ll x)
{
	ll s=0;
	for( ; x>0; x-=lowbit(x))
	{
		s+=a[x];
	}
	return s;
}

void add(ll x,ll v)
{
	add_B(b,x-1,v);
	add_C(c,x,v*x);
}
void go_add(ll a,ll b,ll v)
{
	add(b,v);
	add(a-1,-v);            //
}

ll sum(ll x)
{
	return sum_C(c,x)+sum_B(b,x)*x;
}
ll go_sum(ll a,ll b)
{
	return sum(b)-sum(a-1);
}

int main()
{


	ll n,t;
	char ssc;

	scanf("%lld%lld",&n,&t);
	
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	
	for(int i=3; i<=n+2; i++)
	{
		ll x;
		scanf("%lld",&x);
		go_add(i,i,x);
	}
	

	while(t--)
	{
		
		cin>>ssc;
		if(ssc=='Q')
		{
			ll ai,bi;
			
			scanf("%lld%lld",&ai,&bi);
			ai+=2;
			bi+=2;
	
			
			printf("%lld\n",go_sum(ai,bi));	
		}
		else if(ssc=='C')
		{
			ll ai,bi;
			ll v;
			scanf("%lld%lld%lld",&ai,&bi,&v);
			
			ai+=2;
			bi+=2;
			go_add(ai,bi,v);
		}

	}


}
#endif





//1001           入门二维的树状数组题 
#if 0
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int MAXN = 1010;
int a[MAXN][MAXN];

int lowbit(int x)
{
    return x & (-x);
}

void add(int x, int y, int v)
{
    for(int i = x; i <= MAXN; i += lowbit(i))
        for(int j = y; j <= MAXN; j += lowbit(j))
            a[i][j] += v;
}

int sum(int x, int y)
{
    int s = 0;
    for(int i = x; i > 0; i -= lowbit(i))
        for(int j = y; j > 0; j -= lowbit(j))
            s += a[i][j];
    return  s;
}

int main()
{
    int T, n, x1, x2, y1, y2, v, cas=0;
    char ch[3];
    scanf("%d", &T);
     while(T--)
    {
        memset(a, 0, sizeof(a));
   		 for(int i = 1; i < MAXN; ++i)
        	for(int j = 1; j < MAXN; ++j)
            		add(i, j, 1);
            		
        scanf("%d", &n);
        printf("Case %d:\n", ++cas);
        
        while(n--)
        {
            scanf("%s", ch);
            if(ch[0] == 'A')
            {
                scanf("%d%d%d", &x1, &y1, &v);
                add(x1+1, y1+1, v);
            }
            else if(ch[0] == 'S')
            {
                scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
                ++x1;
                ++x2;
                ++y1;
                ++y2;
                
                if(x1 > x2)
                    swap(x1, x2);
                if(y1 > y2)
                    swap(y1, y2);
                    
                int temp;
                temp=sum(x2,y2)-sum(x1-1,y2)-sum(x2,y1-1)+sum(x1-1,y1-1);
                printf("%d\n",temp);
            }
            else if(ch[0] == 'D')
            {
                scanf("%d%d%d",&x1,&y1,&v);
                ++x1;
                ++y1;
                
                int temp;
                temp=sum(x1,y1)-sum(x1-1,y1)-sum(x1,y1-1)+sum(x1-1,y1-1);
                if(v > temp)
                    v = temp;
                    
                add(x1, y1, -v);
            }
            else if(ch[0] == 'M')
            {
                scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &v);
                ++x1;
                ++x2;
                ++y1;
                ++y2;
                
                int temp;
                temp=sum(x1,y1)-sum(x1-1,y1)-sum(x1,y1-1)+sum(x1-1,y1-1);
                if(v > temp)
                    v = temp;
                add(x1, y1, -v);
                add(x2, y2, v);
            }
        }
    }
    return 0;
}
#endif



//1006             //没有做出来的一道简单题    
//题意： 求某个区间的和，但是这个区间重复的数字只能 加一遍               这样不知道为什么不对 
// 得用离线化做 
#if 0
#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=500000+50;
const int MAXX=1000000+100;
ll a[MAXN];
ll b[MAXN];
ll vis[MAXX][2];
 
 
ll lowbit(ll x)
{
	return x&(-x);
}
void add(ll *ai, ll x,ll v)
{
	for( ;x<=MAXN; x+=lowbit(x))
	{
		ai[x]+=v;
	}
} 

ll sum(ll *ai ,ll x)
{
	ll s=0;
	for( ; x>0; x-=lowbit(x))
	{
		s+=ai[x];
	}
	return s;
}

int main()
{
	ll T;
	scanf("%lld",&T);
	while(T--)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(vis,0,sizeof(vis));
		ll n,x;
		scanf("%lld",&n);
		
		for(int i=1; i<=n; i++) 
		{
			scanf("%lld",&x);                         
			add(a,i,x);
			
			if(!vis[x][0]) 
			{
				vis[x][0]++;
			}
			else if(vis[x][0]==1) 
			{
				add(b,i,x);
			}  
			             
		}
		
		ll m;                  
		scanf("%lld",&m);                                
		while(m--)                                         //m次查询       
		{                           
			ll x1,y1,s=0,temp;
			                       
			scanf("%lld%lld",&x1,&y1);                         
			temp=sum(a,y1)-sum(a,x1-1);
			s=sum(b,y1)-sum(b,x1);
			
			ll end=temp-s;
			printf("%lld\n",end);	
								
		}
			
	}
	
}

#endif


// 1006 离线化
#if 0
#include<iostream>
#include<cstring>
#include<algorithm>
#include<stdio.h>
using namespace std;
typedef long long ll;
struct len
{
	int l,r,id;
	bool operator<(const len b)const
	{
		return r<b.r;
	}
}b[200010];                   


ll a[50010]; 
ll v[50010];                  
ll s[200010];					
int first[1000010];                  

int lowbit(int x)
{
	return x&(-x);
}
void add(int x,ll v)
{
	for( ; x<=50010; x+=lowbit(x))
	{
		a[x]+=v;
	}
}
ll sum(int x)
{
	ll s=0;
	for( ; x>0; x-=lowbit(x))
	{
		s+=a[x];
	}
	return s;
}

int main() 
{
	int T;	
	scanf("%d",&T);
	
	while(T--)
	{
		int n,m,x;
		
		memset(first,0,sizeof(first));
		memset(s,0,sizeof(s));
		memset(v,0,sizeof(v));
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		
		scanf("%d",&n);
		for(int i=1; i<=n; i++)
		{
			scanf("%lld",&v[i]);
			add(i,v[i]);
			if(!first[v[i]])
			{
				first[v[i]]=i;
			}
		}
		scanf("%d",&m);
		for(int i=1; i<=m; i++)
		{
			scanf("%d%d",&b[i].l,&b[i].r);
			b[i].id=i;
		}
		
		sort(b+1,b+m+1);
		

		int R=1;
		
		for(int i=1; i<=m; i++)
		{
			for(int j=R; j<=b[i].r; j++)
			{
				if(first[v[j]]!=j)
				{
					add(first[v[j]],-v[j]);
					first[v[j]]=j;
				}
			}
			
			R=b[i].r;
			s[b[i].id]=sum(b[i].r)-sum(b[i].l-1);
		}
		
		for(int i=1; i<=m; i++)
		{
			printf("%lld\n",s[i]);
		}
		
	}
	
	
} 
#endif



//1002 c            硬做，没用树状数组，超时的代码                                                                                                
#if 0
#include<iostream>
#include<cstring>
#include<map>
#include<cstdio>
using namespace std;
typedef long long ll;
const int MAXN=100000+50;
const int MAXX=1000000007;
int a[MAXN];

int main()
{
	ll n;
	
	while(scanf("%lld",&n)&&n)	
	{                                                                                                       
	    map<ll,ll> mp;                                                                      
		ll cnt=0,x,s=0,mid,num;
		bool flag=0;
		
		for(ll i=1; i<=n; i++)
		{
			scanf("%lld",&x);
			if(!mp.count(x))                                                                                        
			{
				cnt++;
				a[cnt]=x;
			}
			else
				mp[x]=i;
		}
		mid=cnt/2;
	
		for(ll i=1; i<=cnt; i++)
		{
			 num=1; 
			 flag=0;                      
			if(i<=mid)
			{
				int ans=cnt+1;
				for(int j=1; j<=i; j++)
				{
					ans--;
					num*=ans;
					if(!flag&&num>=i)
					{
						flag=1;
						num/=i;
					}
					else if(num>MAXX)
						num%=MAXX;
				}
			}
			else if(i>mid)
			{
				int ans=cnt+1;
				for(int j=1; j<=cnt-i; j++)
				{
					ans--;
					num*=ans;
					if(!flag&&num>=i)
					{
						flag=1;
						num/i;
					}
					else if(num>MAXX)
						num%=MAXX;
				}
			}
	
			s+=num;
			if(s>MAXX)
				s%=MAXX;
		
		} 
		
		printf("%lld\n",s); 
	}
	
}
#endif

// c 1002     TLE????
#if 0
#include<iostream>
#include<algorithm>
#include<string.H>
#include<stdio.H>
using namespace std;
typedef long long ll;
const int MAXX=1000000007;
const int MAXN=100000+10;
int b[MAXN];
int a_1[MAXN];
int n;

int lowbit(int x)
{
	return x&(-x);
}
void add(int x,ll v)
{
	for( ; x<=n ;x+=lowbit(x))
	{
		b[x]=(b[x]+v)%MAXX;
		
	}	
}
int sum(int x) 
{
	int s=0;
	for( ; x>0; x-=lowbit(x))
	{
		s=(s+b[x])%MAXX;
	}

	return s;
}
struct node
{
	int v,id;
	bool operator<(const node ai)const
	{
		return v<ai.v;
	}
}a[MAXN];


int main()
{
	while(~scanf("%d",&n)!=EOF)
	{		
		memset(b,0,sizeof(b));
		memset(a,0,sizeof(a));
		memset(a_1,0,sizeof(a_1));
		
		for(int i=1; i<=n; i++)
		{
			scanf("%d",&a[i].v); 
			a[i].id=i;	
		}	
		
		sort(a+1,a+n+1);
		
		a_1[a[1].id]=1;
		for(int i=2; i<=n; i++)
		{
			if(a[i].v==a[i-1].v)
				a_1[a[i].id]=a_1[a[i-1].id];
			else
				a_1[a[i].id]=i;	
		}

		for(int i=1; i<=n; i++)
		{
			int s=sum(a_1[i]);
			add(a_1[i],s+1);
		}
		
		int end=sum(n);
		printf("%d\n",end);	
		
	}
}

#endif

//1002 c            一个dp题    dp规律： f(n)=f(1)+.......f(n-1)+1; 
#if 0            //AC代码 
#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
using namespace std;
const int MAXN = 100005;
const int MAXX = 1000000007;
int n;
int aa[MAXN],b[MAXN]; 
struct node
{
    int id,v;
    bool operator<(const node ai)const
    {
    	return v<ai.v;
	}
	
}a[MAXN];

int Lowbit(int x)
{
    return x&(-x);
}

void add(int x,int v)
{
    for(int i=x; i<=n; i+=Lowbit(i))
    {
        b[i]+=v;
        b[i]%=MAXX;
    }
}

int sum(int x)
{
    int s = 0;
    for(int i=x; i>0; i-=Lowbit(i))
    {
        s+=b[i];
        s%=MAXX;
    }
    return s;
}


int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        memset(aa,0,sizeof(aa));
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i].v);
            a[i].id = i;
        }
        
        sort(a+1,a+n+1);
        aa[a[1].id]=1;
        for(int i=2;i<=n;i++)
        {
            if(a[i].v != a[i-1].v)
                aa[a[i].id] = i;
            else
                aa[a[i].id] = aa[a[i-1].id];
        }
        
        for(int i=1;i<=n;i++)
        {
            int x=sum(aa[i]);
            add(aa[i],x+1);
        }
        printf("%d\n",sum(n));
    }
    return 0;
}
#endif 








 
//求第几大的数        用二分  +树状数组 
#if 0
#include<iostream>
#include<cstring>
using namespace std;
const int MAXX=100010;
int a[MAXX];
int c[MAXX];
int M_L[MAXX];
int M_R[MAXX];
int max_a;

int lowbit(int x)
{
	return x&(-x);
}

void add(int x,int v)
{
	for(; x<=MAXX; x+=lowbit(x))
		c[x]+=v;
}

int sum(int x)
{
	int sum=0;
	for(; x>0; x-=lowbit(x))
	{
		sum+=c[x];
	}
	return sum;
}

int main()
{
	int n,m;
   	char ch;
	cin>>n>>m;
	
	cnt=0;
	while(n--) 
	{
		cin>>ch;
		if(ch=="I")
		{
			cin>>a[++cnt];	
			memset(c,0,sizeof(c)); 
			M_L[cnt]=cnt-1-sum(a[cnt]);
			add(a[cnt],1);	
			
			memset(c,0,sizeof(c));  
			M_R[cnt]=cnt-1-sum(a[cnt]);
			add(a[cnt],1);    
		}
			
	}
}

#endif 



// 队列的函数 
#if 0
#include<iostream>
#include<queue>
#include<stdio.h>
using namespace std;
const int MAXX=100010;
int a[MAXX];
int main()
{

	int n,k,x;
	while(~scanf("%d%d",&n,&k)&&n&&k)
	{
		char ch[3];
		priority_queue< int, vector<int>, greater<int> > q;
		while(n--) 
		{ 
			scanf("%s",&ch);
		
			if(ch[0]=='I')
			{
				scanf("%d",&x);
				q.push(x);	
				
				if(q.size()>k)
					q.pop();
				
			}
			else if(ch[0]=='Q')
			{
				
				printf("%d\n",q.top());
				
			
			}
		
		}
	}
	
}
#endif 


//二维 更改区间求点的问题
// 	Q 1006
#if 0          
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int T,n,m;
const int MAXN=1010; 
int tree[MAXN][MAXN];
int lowbit(int x)
{
	return x&(-x);
}
void add(int x,int y,int v)
{
	for(int i=x; i>0; i-=lowbit(i))
	{
		for(int j=y; j>0; j-=lowbit(j))
		{
			tree[i][j]+=v;	
		}	
	}	
}

int sum(int x,int y)
{
	int s=0;
	for(int i=x; i<=n+10; i+=lowbit(i))
	{
		for(int j=y; j<=n+10; j+=lowbit(j))
		{
			s+=tree[i][j];
		}
	}
	return s;
}


int main()
{
	cin>>T;
	while(T--)	
	{
		memset(tree,0,sizeof(tree));
		int x1,y1,x2,y2;
		char ch[3];
		scanf("%d%d",&n,&m);
			
		while(m--)
		{
			scanf("%s",&ch);	
			if(ch[0]=='C')
			{
				//cin>>x1>>y1>>x2>>y2;
				scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
				add(x2,y2,1);
				add(x1-1,y1-1,1);  
				add(x1-1,y2,-1); 
				add(x2,y1-1,-1);    
			} 
			else if(ch[0]=='Q')
			{
				//cin>>x1>>y1;
				scanf("%d%d",&x1,&y1); 	
				int end=sum(x1,y1);	                      
				if(end%2)
					printf("1\n");                     
				else
					printf("0\n");	                       
			}

		}
		printf("\n");	
	}
	
}

#endif 


//F 三维问题，区间修改，单点查询，但是正方体的三维问题，真的很难想。。 
#if 0
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXX=110;
int a[MAXX][MAXX][MAXX];
int n,m;
int lowbit(int x)
{               
	return x&(-x);
} 
void add(int x,int y,int z,int v)
{
	for(int i=x; i>0; i-=lowbit(i))
	{
		for(int j=y; j>0; j-=lowbit(j))
		{
			for(int k=z; k>0; k-=lowbit(k))
			{
				a[i][j][k]+=v;
			}
		}
	}
}

int query(int x,int y,int z)
{
	int sum=0;
	for(int i=x; i<=n; i+=lowbit(i))
	{
		for(int j=y; j<=n; j+=lowbit(j))
		{
			for(int k=z; k<=n; k+=lowbit(k))
			{
				sum+=a[i][j][k];	
			}
		}
	}
	return sum;
}

int main()
{
	while(~scanf("%d%d",&n,&m) &&n&&m)
	{
		memset(a,0,sizeof(a));
		int x1,y1,z1,x2,y2,z2;	
		while(m--)
		{
			int num;
			scanf("%d",&num);
			if(num==1)
			{
				scanf("%d%d%d%d%d%d",&x1,&y1,&z1,&x2,&y2,&z2);
				add(x2,y2,z2,1);
				add(x1-1,y2,z2,-1);
				add(x2,y1-1,z2,-1);
				add(x2,y2,z1-1,-1);
				add(x1-1,y1-1,z2,1);
				add(x1-1,y2,z1-1,1);
				add(x2,y1-1,z1-1,1);
				add(x1-1,y1-1,z1-1,-1);
					
			}
			else if(num==0)
			{
				scanf("%d%d%d",&x1,&y1,&z1);
				int end=query(x1,y1,z1);
				if(end%2)
				{
					printf("1\n");
				}
				else 
				{
					printf("0\n");
				} 
					
			}		
		} 
			
	}	
}
#endif    




//1017 Q  给你n,然后给你n-1个数，分别是第二个数到第n个数的前面有多少个比它小的数。
//直接暴力解决的啊  看了饶齐写的 简直是完美的暴力，
/*
这道题目只给出了在i之前且比位于第i个位置的值小的值有多少个，
我们在纸上分析用例可知，最后一个数的值肯定是a[n]+1.
然后我们从后往前推，且初始化一个数组vis[n]为全1。
vis[i]==1表示当前值为i的数还没出现。首先我们推出最后一个数的值为a[n]+1，
所以我们标记vis[a[n]+1]=0，接着我们推n-1的值，假设a[n-1]=3，
那么就是在n-1的数之前有3个还未出现的数比它小，那么我们从vis[1]开始扫描，
找到第4个1的位置就是a[n-1]的值。然后把这第4个1的位置vis[x]标记0.接下去找n-2位置的值，以此类推即可。
*/ 
#if 0 
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXX=8000+10;
int a[MAXX];
int b[MAXX];
int vis[MAXX];
int main()
{
	int n;
	while(~scanf("%d",&n)&&n)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(vis,0,sizeof(vis));

		for(int i=2; i<=n; i++)
		{
			scanf("%d",&a[i]);
		}
		b[n]=a[n]+1; 
		vis[a[n]+1]=1;
		for(int i=n-1; i>=1; i--)
		{
			int num=0;
			for(int j=1; j<=n; j++)
			{
				if(!vis[j])
				{
					num++;
				}
				if(num==a[i]+1)
				{
					b[i]=j;
					vis[j]=1;
					break;
				}
			}
		}
		
		for(int i=1; i<=n; i++)
		{
			printf("%d\n",b[i]);
		}
	}
	
}
#endif




































