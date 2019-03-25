/*首先来说先段数可以解决什么问题呢？
可以解决 1.更新点，求一个区间的最值 / 求一个区间的和 
    。   2.更改区间，求点/ 求一个区间的和 
*/
 
// 功能 1. Q查询一段区间内的最大的值，U将第p个点更新位v 
#if 0
#include<iostream>
#include<stdio.h> 
#include<algorithm>
using namespace std;
#define lson l,m,id*2
#define rson m+1,r,id*2+1
const int MAXN=230000;
int maxx[MAXN*4];             //
void pushup(int id)
{
	maxx[id]=max(maxx[id*2],maxx[id*2+1]);
}

void build(int l,int r,int id)
{
	if(l==r)
	{
		scanf("%d",&maxx[id]);
		return;	
	}
	
		int m=(l+r)/2;
		build(lson);
		build(rson);
		pushup(id);
	
}

void update(int p,int val,int l,int r,int id)
{
	if(l==r)
	{
		maxx[id]=val;
		return;
	}
	int m=(l+r)/2;
	if(p<=m)
		update(p,val,lson);
	else
		update(p,val,rson);	
	pushup(id);
}

int query(int L,int R,int l,int r,int id)
{
	if(L<=l&&R>=r)
	{
		return maxx[id];
	}
	int m=(r+l)/2;
	int ret=0;
	if(L<=m)
	{
		ret=max(ret,query(L,R,lson));
	}
	if(R>m)
		ret=max(ret,query(L,R,rson));
	return ret;	
	
}

int main() 
{
	int n,m;
	while(~scanf("%d%d",&n,&m))
	{
		build(1,n,1);
		while(m--)
		{
			char s[3];
			int a,b;
			scanf("%s%d%d",s,&a,&b);
			if(s[0]=='Q')
				printf("%d\n",query(a,b,1,n,1));
			else
			update(a,b,1,n,1);		
		} 
	}
	
}
#endif 


//用结构体做
#if 0
#include<bits/stdc++.h>
using namespace std;
const int MAXN=22222222; 
struct point
{
	int l,r,maxx;
	
}a[MAXN];
void pushup(int id)
{                                              
	a[id].maxx=max(a[id*2].maxx,a[id*2+1].maxx);	
}                     
void build(int l,int r,int id)
{
	a[id].l=l;
	a[id].r=r;
	if(l==r)
	{
		scanf("%d",&a[id].maxx);
		return;
	}
	int m=(l+r)/2;
	build(l,m,id*2);
	build(m+1,r,id*2+1);
	pushup(id); 
}
void update(int p,int val,int id) 
{
	if(a[id].l==a[id].r)
	{
		a[id].maxx=val;
		return;
	}
	int m=(a[id].l+a[id].r)/2;
	if(p<=m)
	{
		update(p,val,id*2);
	}
	else
	{
		update(p,val,id*2+1);
	} 
	pushup(id);
}    
int query(int l,int r,int id)
{   
	if(a[id].l<=l&&a[id].r==r) 
		return a[id].maxx; 
		   
	int m=(a[id].l+a[id].r)/2;                                
	if(r<=m)
		return query(l,r,id*2);
	else if(l>m)
		return query(l,r,id*2+1);
	else 
		return query(l,m,id*2)+query(m+1,r,id*2+1);			
}
int main()
{
	int n,m;
	while(~scanf("%d%d",&n,&m))
	{
		build(1,n,1);  
		while(m--)          
		{
			int a,b;
			char s[3];
			scanf("%s%d%d",s,&a,&b);                                       
			if(s[0]=='Q')
			{
				printf("%d\n",query(a,b,1));
			}
			else
			{
				update(a,b,1); 
			}
		}
	}
	
}

#endif 

//Just a Hook 
//修改区间求和   输入 a,b,s ;把区间里的元素全部换成s,然后最后输出a,b区间的元素和。 
//另开一个数组 存一个点上的值。 
//  one1.0
#if 0
#include<iostream>
using namespace std;
const int MAXX=1e5;
int sum[MAXX*4];
int setv[MAXX*4];
#define lson l,m,id*2
#define rson m+1,r,id*2+1
void pushup(int id)
{
	sum[id]=sum[id*2]+sum[id*2+1];	
} 
void pushdown(int id,int num)
{
	if(setv[id])
	{
		setv[id*2+1]=setv[id*2]=setv[id];
		sum[id*2]=(num-num/2)*setv[id];
		sum[id*2+1]=num/2*setv[id];
		setv[id]=0;	
	}		
} 
void build(int l,int r,int id)
{
	setv[id]=0;
	sum[id]=1;
	if(l==r)
		return;
	int m=(l+r)/2;
	build(lson);
	build(rson);
	pushup(id);	
}
void update(int ql,int qr,int val,int l,int r,int id)
{
	if(ql<=l&&qr>=r)
	{
		setv[id]=val;
		sum[id]=(r-l+1)*val;
		return;	
	}	
	pushdown(id,r-l+1);
	int m=(l+r)/2;
	if(ql<=m) 
		update(ql,qr,val,lson); /////
	if(qr>m)
		update(ql,qr,val,rson);	
	pushup(id);
} 
int query(int ql,int qr,int l,int r,int id)
{
	if(ql<=l&&qr>=r)
	{
		return sum[id];
	}
	pushdown(id,r-l+1);            ///
	int m=(l+r)/2;
	int ret=0;
	if(ql<=m)   
	{
		ret+=query(ql,qr,lson);
	}
	if(qr>m)
	{
		ret+=query(ql,qr,rson);
	}
	return ret;		
} 

int main()
{
	while(1)
	{
		int a,b,n,val;
		cin>>n;	
		build(1,n,1);
		char s;
		while(1)
		{
			cin>>s;
			if(s=='k')
				break;
			if(s=='q')
			{
				cin>>a>>b;
				cout<<query(a,b,1,n,1)<<endl;
			}
			else
			{
				cin>>a>>b>>val;
				update(a,b,val,1,n,1);
			}
		}	
	}	
}
#endif 
 
 
 
                         
//修改区间求和   //on2.
#if 0 
#include<iostream>
using namespace std;
const int MAXX=1e6;
int setv[MAXX*4],sum[MAXX*4];
#define lson l,m,id*2
#define rson m+1,r,id*2+1
void pushup(int id) 
{
	sum[id]=sum[id*2]+sum[id*2+1];
}
void pushdown(int id,int num)
{
	if(setv[id])
	{
		setv[id*2]=setv[id*2+1]=setv[id];
		sum[id*2]=(num-num/2)*setv[id];
		sum[id*2+1]=(num/2)*setv[id];
		setv[id]=0;
	}
} 
void build(int l,int r,int id) 
{
	setv[id]=0;                    ////这里容易漏 
	sum[id]=1; 
	if(l==r) return; 
	int m=(l+r)/2; 
	build(lson);
	build(rson);
	pushup(id);	
}
void update(int ql,int qr,int val,int l,int r,int id)
{
	if(ql<=l&&qr>=r) 
	{
		setv[id]=val;               /// 这里要注意 
		sum[id]=(r-l+1)*val;
		return;// 
	}
	pushdown(id,r-l+1);             
	int m=(l+r)/2;
	if(ql<=m)
		update(ql,qr,val,lson);          //更新常犯的错误 
	if(qr>m)
		update(ql,qr,val,rson);
	pushup(id);		
		
}
int query(int ql,int qr,int l,int r,int id)
{
	if(ql<=l&&qr>=r)
	{
		return sum[id];
	}
	pushdown(id,r-l+1);            
	int m=(l+r)/2; 
	int ret=0;
	if(ql<=m) 
		ret+=query(ql,qr,lson);  
	if(qr>m)
		ret+=query(ql,qr,rson);	 
	return ret;
}

int main()
{
	int a,b,val,n;
	char s;
	cin>>n;
	build(1,n,1);
	while(cin>>s)
	{
		
		if(s=='q')
		{
			cin>>a>>b;
			cout<<query(a,b,1,n,1)<<endl;
		}
		else 
		{
			cin>>a>>b>>val;
			update(a,b,val,1,n,1);             /////////
		}
	}
		
}

#endif 































































