//	Buy Tickets
/*

题意：插队问题；

关键：如何插入这几个节点，每个节点储存什么信息。

类型：很基本的单点更新线段树

思路：这题想到了就水了，数据逆着插入，最先插入的一个数据的位置明显是题目给定的位置，可以确定，然后插入的几个数根据的位置前面插入的数据来决定，

用sum[]数组表示改线段空位置的个数，满足 pos<=sum[rt<<1]（即左儿子的空位多于插入数的位置序号）就访问左儿子，否则访问右儿子

（访问右节点的时候注意pos要修改，改为pos-sum[rt]，即整个线段的第pos个空位，在下一个右儿子那的第pos-sum[rt]个空位）。


*/

#if 0
#include<iostream>
using namespace std;
const int MAXX=200000;
#define lson l,mid,id*2
#define rson mid+1,r,id*2+1
int sum[MAXX*4];
int ans[MAXX*4];
int pos[MAXX],val[MAXX];
void pushup(int id)
{
	sum[id]=sum[id*2]+sum[id*2+1];
}
void build(int l,int r,int id)
{
	sum[id]=r-l+1;
	if(l==r)
	{
		return ;
	}
	int mid=(l+r)/2;
	build(lson);
	build(rson);
}
void update(int num,int val,int l,int r,int id)           
{	
	if(l==r)
	{
		ans[id]=val;
		sum[id]--;
		return;
	}
	int mid=(l+r)/2;
	if(num<=sum[id*2])
	{
		update(num,val,lson);
	}
	else
	{
		update(num-sum[id*2],val,rson);
	}
	pushup(id);
} 
void print(int l,int r,int id)
{
	if(l==r)
	{
		cout<<ans[id]<<" ";
		return;
	}
	int mid=(l+r)/2;
	print(lson);
	print(rson);
}

int main()
{
	ios::sync_with_stdio(false);
	int n;
	while(cin>>n)
	{
		for(int i=0; i<n; i++)
		{
			cin>>pos[i]>>val[i];
		}
		build(1,n,1); 
		for(int i=n-1; i>=0; i--)
		{
			update(pos[i]+1,val[i],1,n,1);
		}
		print(1,n,1);
		cout<<endl;
	}
	
	
	
	
}
#endif



//Count Color  1-n这个区间，两个操作，第一个操作 C ，把{a,b}区间的值改成C，第二个操作P：[查询区间有几种数字c]. 
#if 0
#include<cstring>
#include<iostream>
#include<cstdio> 
using namespace std;
const int MAXX=100010;
int sum[35];
int n,num,m;
struct node                  //
{
	int l,r,s;	
}t[MAXX*4];
void build(int l,int r,int id)      //
{
	t[id].l=l;
	t[id].r=r;
	t[id].s=1;
	if(l==r)
	{
		return ;	
	}
	int mid=(l+r)/2;
	build(l,mid,id*2);
	build(mid+1,r,id*2+1); 
}
void update(int l,int r,int val,int id)
{
	if(t[id].s==val)
		return;
	if(t[id].l==l && t[id].r==r)
	{
		t[id].s=val;
		return;		
	}
	if(t[id].s!=-1)
	{
		t[id*2].s=t[id*2+1].s=t[id].s;                    
		t[id].s=-1;	
	}
	int mid=(t[id].l+t[id].r)/2;
	if(l>mid)
	{
		update(l,r,val,id*2+1);	
	}
	else if(r<=mid)
	{
		update(l,r,val,id*2);	
	}
	else
	{
		update(l,mid,val,id*2); 
		update(mid+1,r,val,id*2+1); 	
	}	
	
}
void query(int l,int r,int id)
{
	if(t[id].s!=-1)
	{
		sum[t[id].s]=1;
		return;	
	}
	else
	{
		int mid=(t[id].l+t[id].r)/2;
		if(l>mid)
		{
			query(l,r,id*2+1);
		}
		else
		if(r<=mid)
		{
			query(l,r,id*2);
		}
		else
		{
			query(l,mid,id*2);
			query(mid+1,r,id*2+1);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	int a,b,c;
	
	while((~scanf("%d%d%d",&n,&num,&m))&&n&&num&&m)
	{
		
		build(1,n,1);
	
		while(m--)
		{
		//	cout<<"8989"<<endl;
			int ans=0;
			char s[3];
			scanf("%s",&s);
			if(s[0]=='C')
			{
				scanf("%d%d%d",&a,&b,&c);
				update(a,b,c,1);
			}
			else
			if(s[0]=='P')
			{
			
				memset(sum,0,sizeof(sum));
				scanf("%d%d",&a,&b);
				query(a,b,1);            
				for(int i=1; i<=num; i++)
				{
					if(sum[i])
						ans++;
				}
				printf("%d\n",ans);
			}
		}
	}
	
}
#endif




//小明系列问题——小明序列  
#if 0
#include<bits/stdc++.h>
using namespace std;
#define  lson  id*2, l, mid
#define  rson  id*2+1, mid + 1, r
const int N = 100005;
int len[N*4];
int pos, val;
int ql,qr;
void build(int id,int l,int r) 
{
    len[id] = 0;
    if(l == r)  return ;
    int mid=(l+r)/2;
    build(lson);
    build(rson);
}
void pushup(int id) s
{
    len[id] = max(len[id*2], len[id*2+1]);
}
void update(int id,int l,int r) 
{
    if(l == r) {
        len[id] = max(len[id], val);
        return ;
    }
    int mid=(l+r)/2;
    if(pos <= mid)  
		update(lson);
    else  
	  update(rson);
    pushup(id);
}
int query(int id,int l,int r) 
{
    if(ql <= l && r <= qr)  
		return len[id];
    int mid=(l+r)/2;
    int res = 0;
    if(ql <= mid)   
		res=max(res,query(lson));
    if(qr > mid)   
		 res=max(res,query(rson));
    return res;
}

int dp[N], num[N];

int main() 
{
	ios::sync_with_stdio(false);
    int n,d;
    while(cin>>n>>d)
	{
        int mm=0, ans=0;
        for(int i=1; i<=n; ++i) 
		{
            cin>>num[i]; 
            ++num[i];
            mm=max(mm,num[i]);
        }
        build(1,1,mm);
        for(int i=1; i<=n; ++i) 
		{
            if(i-d-1>=1) 
			{        
                pos=num[i-d-1];
                val=dp[i-d-1];
                update(1,1,mm);
            }
            if(num[i]==1)    
				dp[i]=1;
            else 
			{
                ql=1;
                qr=num[i]-1;
                dp[i]=query(1,1,mm)+1;
            }
            ans=max(ans,dp[i]);
        }
       	cout<<ans<<endl;
    }
    return 0;
}
#endif

//HDU1823-Luck and Love-二维线段树(模板) 
#if 1
#include<bits/stdc++.h> 
using namespace std;
const int N=5005;
int n,a,b;
float seg[N][N*4];     
void Build_2(int l,int r,int deep,int rt)       //  
{
    seg[deep][rt]=-1.0;
    if(l==r) return;
    int mid=(l+r)/2;
    Build_2(l,mid,deep,rt*2);
    Build_2(mid+1,r,deep,rt*2+1);
}
void Build(int l,int r,int rt)      // 
{
    Build_2(0,1000,rt,1);
    if(l==r) return;
 	int mid=(l+r)/2;
    Build(l,mid,rt*2);
	Build(mid+1,r,rt*2+1);
}
void Insert_2(int act,float love,int l,int r,int deep,int rt)  // 
{
    seg[deep][rt]=max(love,seg[deep][rt]);
    if(l==r) 
		return;
    int mid=(l+r)/2;
    if(act<=mid) 
		Insert_2(act,love,l,mid,deep,rt*2);
    else 
		Insert_2(act,love,mid+1,r,deep,rt*2+1);
    seg[deep][rt]=max(seg[deep][rt*2],seg[deep][rt*2+1]);
}
void Insert(int h,int act,float love,int l,int r,int rt)       // 
{
    Insert_2(act,love,0,1000,rt,1);
    if(l==r) 
		return;
    int mid=(l+r)/2;
    if(h<=mid) 
		Insert(h,act,love,l,mid,rt*2);
    else 
		Insert(h,act,love,mid+1,r,rt*2+1);
}
float Query_2(int L,int R,int l,int r,int rt,int deep)     //  
{
    if(L<=l&&R>=r) 
		return seg[deep][rt];
    int mid=(l+r)/2;
    if(R<=mid) 
		return Query_2(L,R,l,mid,rt*2,deep);
    else if(L>mid) 
		return Query_2(L,R,mid+1,r,rt*2+1,deep);
    else
		 return max(Query_2(L,R,l,mid,rt*2,deep),Query_2(L,R,mid+1,r,rt*2+1,deep));
}
float Query(int h1,int h2,int L,int R,int l,int r,int rt)      //  
{
    if(h1<=l&&h2>=r) 
		return Query_2(L,R,0,1000,1,rt);
    int mid=(l+r)/2;
    if(h2<=mid) 
		return Query(h1,h2,L,R,l,mid,rt*2);
    else if(h1>mid) 
		return Query(h1,h2,L,R,mid+1,r,rt*2+1);
    else
		 return max(Query(h1,h2,L,R,l,mid,rt*2),Query(h1,h2,L,R,mid+1,r,rt*2+1));
}
int main()
{
    int n;
    while(~scanf("%d",&n)&&n)
	{
        Build(100,200,1);
        char ch[5];
        while(n--)
		{
            scanf("%s",&ch);
            if(ch[0]=='I')
			{
                int h;
                float x,y;
                scanf("%d%f%f",&h,&x,&y);
                Insert(h,(int)(x*10),y,100,200,1);
            }
			else
			{
                int h1,h2;
                float x1,x2;
                scanf("%d%d%f%f",&h1,&h2,&x1,&x2);
                if(h1>h2)
				{
					int temp=h1; 
					h1=h2;
					h2=temp; 
				}
                if(x1>x2)
				{
					float temp=x1;
					x1=x2;
					x2=temp;
				}
                float ans=Query(h1,h2,(int)(x1*10),(int)(x2*10),100,200,1);
                if(ans==-1.0) 
					printf("-1\n");
                else 
					printf("%.1lf\n",ans);
            }
        }
    }   
    return 0;
}

#endif 


























