// 1003 让我们求的是总共有多少个顺序数对。
//有两种操作 一种是查询一个区域的顺序书对的个数，另一种是 改变一个区域的元素的位置（整体向左移动一位，最左边的移动到最右边） 
#if 0 
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std; 
const int MAXX=3000000+3;
typedef long long ll;
int c[MAXX];
int a[10003]; 
int lowbit(int x)
{
	return x&(-x);
}
void add(int x,int v)
{
	while(x<10001)
	{
		c[x]+=v;
		x+=lowbit(x); 
	}
}
ll query(int x)
{
	ll sum=0;
	while(x>0)
	{
		sum+=c[x];
		x-=lowbit(x);
	}
	return sum;
}

int main()
{
	int n;
	int m;
	char s[2];
	ios::sync_with_stdio(0);
	while(scanf("%d",&n)!=EOF)
	{
		ll sum=0;		
		memset(c,0,sizeof(c));
		for(int i=1; i<=n; i++)
		{
			scanf("%d",&a[i]);
			add(a[i],1);
			sum+=query(a[i]-1);
		}
		scanf("%d",&m);
		while(m--)
		{

			scanf("%c",&s);
			if(s[0]=='Q') 
				printf("%I64d\n",sum);
			else if(s[0]=='R')	
			{
				int l,r;
				scanf("%d%d",&l,&r);
				l++,r++;
				int temp=a[l];
				for(int i=l; i<r; i++)
				{
					a[i]=a[i+1];
					if(a[i]>temp)
						sum--;
					if(a[i]<temp)
						sum++;			
				}
				a[r]=temp;		
			}
							
		}
	}
	
}
#endif 

// 这个求 某个区间的和，每一个数，只能加一遍。 
//1004 
#if 0
#include<iostream>
#include<map>
#include<algorithm> 
using namespace std;
typedef long long ll;
const int MAX=30000+10;
const int MAXX=100100;

struct go
{
	int l,r,id;
	bool operator<(const go &a)const
	{
		if(r<a.r)
			return true;
		return false;	
	}
}a[MAXX];
ll num[MAX],c[MAX],ans[MAXX];
int last[MAX],n;

int lowbit(int x)
{
	return x&(-x);
}
void add(int x,ll v)
{
	for( ; x<=n; x+=lowbit(x))
	{
		c[x]+=v;
	}
}
ll query(int x)
{
	if(x==0)
		return 0;
	ll sum=0;
	for( ; x>0; x-=lowbit(x))
	{
		sum+=c[x];	
	}	
	return sum;
}

int main()
{
	ios::sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--)
	{
		int cnt=0;
		cin>>n;
		map<ll,int>mp;		
		c[0]=0;
		for(int i=1; i<=n; i++)
		{
			c[i]=last[i]=0;
			cin>>num[i];
			if(!mp[num[i]])
			{
				mp[num[i]]=++cnt;
			}
		}
		int m;
		cin>>m;
		for(int i=1; i<=m; i++)
		{
			ans[i]=0;
			a[i].id=i;
			cin>>a[i].l>>a[i].r;
			
		}
		sort(a+1,a+1+m);
		cnt=1;
		for(int i=1; i<=n&&cnt<=m; i++)
		{
			int t=mp[num[i]];
			{
				if(!last[t])
				{
					add(i,num[i]);
				}
				else
				{
					add(last[t],-num[i]);
					add(i,num[i]);
				}
				last[t]=i;
				while(a[cnt].r==i&&cnt<=m)
				{
					ans[a[cnt].id]=query(a[cnt].r)-query(a[cnt].l-1);
					cnt++;	
				}
			}
		}
		for(int i=1; i<=m; i++)
		{
			cout<<ans[i]<<endl;
		}
	}
	
}
#endif 


//10014 二维树状数组  三种操作
/*
BLACK x y 1将(x,y)为左上角，边长为l的正方形涂黑?

WHITE x y 1将(x,y)为左上角，边长为l的正方形涂白?

TEST x y 1问(x,y)为左上角，边长为l的正方形有多少个黑色格子?
*/ 
#if 0
#include<iostream>
using namespace std;
int a[105][105];
int query(int x,int y,int len)
{
	int cnt=0;
	for(int i=x; i<x+len; i++)
	{
		for(int j=y; j<y+len; j++)
		{
			if(a[i][j]==1)
			{
				cnt++;
			}
		}
	}
	return cnt;
}
void change(int x,int y,int v,int len)
{
	for(int i=x; i<x+len; i++)
	{
		for(int j=y; j<y+len; j++)
		{
			a[i][j]=v;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	while(n--)
	{
		int x,y,len;
		string s;
		cin>>s;
		if(s=="BLACK")
		{
			cin>>x>>y>>len;
			change(x,y,1,len);	
		}
		else if(s=="WHITE")
		{
			cin>>x>>y>>len;
			change(x,y,0,len);
		}
		else if(s=="TEST")
		{
			cin>>x>>y>>len;
			cout<<query(x,y,len)<<endl;
		}
	}
	
}
#endif 


//1013 N  
#if 1
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXX=100000+100;
int a[MAXX];
int c[MAXX];
int lowbit(int x)
{
	return x&(-x);	
} 
void add(int x,int v)
{
	for(; x<MAXX; x+=lowbit(x))
	{
		c[x]+=v;
	}
}
int query(int x)
{
	int sum=0;
	for(; x>0; x-=lowbit(x))
	{
		sum+=c[x];
	}
	return sum;
}
struct node
{
	int l,r,id;
	bool operator <(const node &a)const
	{
		return l<a.l;
	}
}node[MAXX];
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		int pos[MAXX];
		int ans[MAXX];
		int n,m;
		cin>>n>>m;
		for(int i=1; i<=n; i++)
		{
			cin>>a[i];
			pos[a[i]]=i;
		}
		pos[0]=pos[n+1]=n+10;
		for(int i=1; i<=m; i++)
		{
			cin>>node[i].l>>node[i].r;
			node[i].id=i;
		}
		sort(node+1,node+m+1);
		memset(c,0,sizeof(c));
		for(int i=1; i<=n; i++)
		{
			if(i<pos[a[i]-1]&&i<pos[a[i]+1])
				add(i,1);
			if(i>pos[a[i]-1]&&i>pos[a[i]+1])
				add(i,-1);	
		}
		int i=1;int j=1;
	//	cout<<"4564646"<<endl;
		while(j<=m)
		{
			while(node[j].l==i)
			{
				ans[node[j].id]=query(node[j].r);
				j++;
			}
			
			if(i<=n)
			{
				if(i>pos[a[i]-1]&&i>pos[a[i]+1])
					add(i,-1);
				else if(i<pos[a[i]-1]&&i<pos[a[i]+1])
				{
					add(i,-1);
					add(pos[a[i]-1],1);	
					add(pos[a[i]+1],1);		
				}
				else if(i<pos[a[i]+1])	 
				{
					add(i,-1);
					add(pos[a[i]+1],1);	
				}
				else if(i<pos[a[i]-1])	 
				{
					add(i,-1);
					add(pos[a[i]-1],1);	
				}
				i++;
			}	
		}
	//	cout<<"12312313"<<endl;
		for(int i=1; i<=m; i++)
		{
			cout<<ans[i]<<endl;
		}
	}
			 		                                                                                                                                                                              	
}
#endif 



































