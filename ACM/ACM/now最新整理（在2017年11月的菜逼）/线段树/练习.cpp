//1004 
//点更新，点查询  	 Q查询一段区间内的最大的值，U将第p个点更新位v 
#if  0 
#include<bits/stdc++.h>
using namespace std;
#define lson l,m,id*2
#define rson m+1,r,id*2+1
const int MAXN=22222222;
int mxx[MAXN*4];
void pushup(int id)
{
	mxx[id]=max(mxx[id*2],mxx[id*2+1]);
}
void build(int l,int r,int id) 
{
	if(l==r)
	{
		scanf("%d",&mxx[id]); 
		return ;
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
		mxx[id]=val;
		return;
	}
	int m=(l+r)/2;
	if(p<=m)              
		update(p,val,lson);
	else
		update(p,val,rson);	
	pushup(id);                                                            
}
int query(int L,int R, int l,int r,int id)
{
	if(L<=l&&r<=R)
	{
		return mxx[id];
	}
	
	int m=(l+r)/2;
	int ret=0;
	if(L<=m)
		ret=max(ret,query(L,R,lson));
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
			{
				printf("%d\n",query(a,b,1,n,1));
			}
			else
			{
				update(a,b,1,n,1);
			}
		}
	}		
}

#endif 



//Just a Hook 
//修改区间求和   输入 a,b,s ;把区间里的元素全部换成s,然后最后输出a,b区间的元素和。 
#if 0
#include<iostream>
#include<cstring>
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
	int a,b,val,n,T,num,cas=0;
	int s;	
	scanf("%d",&T);
	while(T--)
	{
		memset(setv,0,sizeof(setv));
		memset(sum,0,sizeof(sum));
		scanf("%d%d",&n,&num);
		build(1,n,1);
		while(num--)
		{
			scanf("%d%d%d",&a,&b,&s);
			update(a,b,s,1,n,1);
		}
		cout<<"Case "<<++cas<<": The total value of the hook is "<<query(1,n,1,n,1)<<"."<<endl;
	}
	
}
#endif 



//Billboard  数据量超级大 
//给你一个黑板，给出你高和宽H,W,再给出你NUM个广告，让你求出每一个广告所在的行是第几行（有个条件就是：每一个广告能靠坐上边的就靠左上边） 
#if 0
#include<iostream>
using namespace std;
#define lson l,m,id*2
#define rson m+1,r,id*2+1
const int MAXN=200100;
int maxx[MAXN*4];
int idp[MAXN*4];
int cnt;
void pushup(int id) 
{
	maxx[id]=max(maxx[id*2],maxx[id*2+1]);
}
void build(int l,int r,int id,int val) 
{
	
	if(l==r)
	{
		idp[id]=++cnt;
		maxx[id]=val;                 
		return;
	}	
	int m=(l+r)/2; 
	build(lson,val);
	build(rson,val);
	pushup(id);
		
} 
int update(int l,int r,int id,int val)
{
	if(maxx[id]<val)
		return -1;
	if(l==r)
	{
		maxx[id]-=val;
		return idp[id];
	}
	int m=(l+r)/2;
	int ret=0;
	if(maxx[id*2]>=val)
	{
		ret=update(lson,val);
	}
	else if(maxx[id*2+1]>=val)
	{
		ret=update(rson,val);
	}
	pushup(id);
	return ret;
}

int main()
{	
	int h,w,num,val,n;
	while(~scanf("%d%d%d",&h,&w,&num))
	{
		cnt=0;
		n=min(h,num);
		build(1,n,1,w);
		while(num--)
		{ 
			scanf("%d",&val);
			printf("%d\n",update(1,n,1,val));
		}	
	}
}
#endif 






















































