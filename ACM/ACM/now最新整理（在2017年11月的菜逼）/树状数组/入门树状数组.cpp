//树状数组

//--->第一种类型 单点更改，区间求和 

//排兵布阵  hdu1166 
/*
1
10
1 2 3 4 5 6 7 8 9 10
Query 1 3
Add 3 6
Query 2 7
Sub 10 2
Add 6 3
Query 3 10
End 
 

Sample Output
Case 1:
6
33
59
*/
#if 0
#include<iostream>
using namespace std;
const int MAX=5000;
int a[MAX];
int N;
int lowbit(int x)
{
	return (x&(-x));
}

void  add(int x,int v)
{
	for(;x<=N;x+=(lowbit(x)))
	{
		a[x]+=v;	
	}	
}


int sum(int x)
{
	int summ=0;
	for(; x>0; x-=(lowbit(x)))
	{
		summ+=a[x];
	}
	return summ;
}

int query(int i,int j)
{
	int temp;
	temp=sum(j)-sum(i-1);
	return temp;
}

int main()
{
	//cout<<"1: 第x阵营加了多少"<<endl; 
	//cout<<"2: 第x阵营减了多少"<<endl; 
	//cout<<"3: i-->j一共多少人"<<endl;
	
	int ans;
	
	cin>>N;
	for(int i=1; i<=N; i++)
	{
		int v;
		cin>>v;
		add(i,v);	
	}
	
	
	while(1)
	{
		cin>>ans;
		if(!ans)
			break;
		else if(ans==1)
			{
				int i,v;
				cin>>i>>v;
				add(i,v);
			}
		else if(ans==2)
			{
				int i,v;
				cin>>i>>v;
				add(i,-v);	
			}
		else if(ans==3)		
			{
				int i,j;
				cin>>i>>j;
				cout<<query(i,j)<<endl;
			}
	}
	
	 
	
}

#endif



//左边比他小的数的 个数 
//试下1 2 3 4 5  
#if 0
#include<iostream>
#include<cstring>
using namespace std;
const int MAXX=10000;
int a[MAXX];
int c[MAXX];
int S_L[MAXX];
int S_R[MAXX];
int max_a;

int lowbit(int x)
{
	return x&(-x);
}

void add(int x,int v)
{
	for(; x<=max_a; x+=lowbit(x))
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
	int n;
    max_a=0;
	cin>>n;
	
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
		max_a=max(max_a,a[i]);
	}
	
	for(int i=1; i<=n; i++)
	{
		S_L[i]=sum(a[i]);
		add(a[i],1);	
	}
	
	memset(c,0,sizeof(c));            //把数反过来  就是右边小的数的个数  
	for(int i=n; i>=1; i--)
	{
		S_R[i]=sum(a[i]);
		add(a[i],1);          //标记   在后面的点看到前面的被标记了，说明这个数比他小，就要加起来。不过这厮用树状数组表示的，要向上更新点 
	}
	
	cout<<"the number of minner at left: "<<endl;
	for(int i=1; i<=n; i++)
		cout<<S_L[i]<<" ";
	cout<<endl;
	cout<<"the number of minner at right: "<<endl;
	for(int i=1; i<=n; i++)
		cout<<S_R[i]<<" ";
	cout<<endl;	
}

#endif 



//--------------------------------------->第一次了解的离散化，挺有意思 

//x的左边比他大的数的个数
//先求出小的 然后减就行                简单的离散化处理 
#if 0
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXX=1e6;
int M_L[MAXX];
int c[MAXX];
int b[MAXX];
int n;
int a_max;
int lowbit(int x)
{
	return x&(-x);
}

void add(int x,int v)
{
	for( ;x<=n; x+=lowbit(x))
	{
		c[x]+=v;
	}
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

struct node
{
	int v,id;
	bool operator <(const node &a)
	{
		return v<a.v;
	}
}a[MAXX];




int main()
{
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i].v;
		a[i].id=i;
	}
	sort(a+1,a+n+1); 
	
	b[a[1].id]=1;
	for(int i=2; i<=n; i++)
	{
		if(a[i].id==a[i-1].id)
			b[a[i].id]=b[a[i-1].id];
		else
			b[a[i].id]=i;		
	} 

	
	for(int i=1; i<=n; i++)
	{
		int temp=sum(b[i]);
		M_L[i]=i-1-temp;
		add(b[i],1);
	}
	
	for(int i=1; i<=n; i++)
		cout<<M_L[i]<<"  ";
	cout<<endl;	

}

#endif 


//---------------------------------------------------------------------------------》 
//说一下 区间更新，求单点是多大
/* 
总结一下吧，这两天从没有现在这么清晰。 
重要的是理解我们设的b数组的含义： 
如果我们把区间1-i,每一个元素都加上v,那么b[i]=v,他代表的是从1-i这个区间每个元素加了多大。（同时要向下更新b数组///因为期间的b数组也有这种含义） 
那么我们进行了n次区间更改之后，我们要 求第 位置是x的数是多大？（我们在进行区间更新的时候初始化为0了，所以我们直接求更新的时候在这个位置增加了多大就行了）
我们前面说过了 b[x]的含义是1-x每一个元素加了多大,同理b[MAXN]代表1-MAXN每一个元素加了多大。所以x=b[x]+.....b[MAXN]; 
 
*/
 
#if 0
#include<iostream>
using namespace std;
const int MAXN=1000;
int b[MAXN];
int l,r;
int lowbit(int x)
{
	return x&(-x);
}
void add(int x,int v)
{
	for(; x>0; x-=lowbit(x))
		b[x]+=v;
}

int query(int x)
{
	int sum=0;
	for(; x<=MAXN; x+=lowbit(x))
		sum+=b[x];
		
	return sum;	
}


int main()
{
	while(1)
	{
		int v;
		cin>>l>>r>>v;   //区间   /区间加的值 v 
		add(r,v);
		add(l-1,-v);
		
		cout<<"point:"<<endl;  //输入查询的点 
		int x;
		cin>>x;
		cout<<query(x)<<endl;
	}
	
}

#endif


//----------------------------------------------------------------------------------------------------------->
//说一下区间更新，区间求和 


//  自己写的啊 ，不行 不行  too young  
#if 0
#include<iostream>
#include<cstring>
using namespace std;
int l,r;
const int MAXN=100;
int b[MAXN],c[MAXN];
int lowbit(int x)
{
	return x&(-x);
}
//b
void add_B(int x,int v)
{
	
	for(; x>0; x-=lowbit(x))
		b[x]+=v;
	//cout<<"bbbbbbbbbbbbbbbb++"<<endl;	
	
}
int sum_B(int x)
{
	int sum=0; 
	for(; x<=MAXN; x+=lowbit(x))
		sum+=b[x];
	//cout<<"bbbbbbbbbbbbbsum..."<<endl;	
	return sum;	
}
//c
void add_C(int x,int v)
{
	for(; x<=MAXN; x+=lowbit(x))
		c[x]+=v;
	//cout<<"cccccccccccccc++"<<endl;	
} 

int sum_C(int x)
{
	int sum=0;
	for( ; x>0; x-=lowbit(x))
		sum+=c[x];
	//cout<<"cccccccccccccccccccccccsum..."<<endl;	
	return sum;	
	
}

int main() 
{
	while(1)
	{
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		int v;
		cin>>l>>r>>v; 

			
		add_B(r-1,v); //xia            
		add_B(l-1,-v);//
		
		
		add_C(r,v);                                        
		add_C(l-1,-v);
		

		cout<<"yours:"<<endl;
		
		int ri,li;
		cin>>li>>ri;
		
		//cout<<"sum_B:(ri)"<<sum_B(ri)<<endl;
		
		cout<<sum_B(ri)<<endl;
		
		cout<<sum_B(ri)*ri-sum_B(li-1)*(li-1)+sum_C(ri)-sum_C(li-1)<<endl;
	}
		
}
 
#endif 


//  这个和给的课件差不多  ，但是课件写的确实挺好  
#if 0 
#include<iostream>
#include<cstring>
using namespace std;
const int MAXN=1000;
int b[MAXN],c[MAXN];
int lowbit(int x)
{
	return x&(-x);
}

void add_B(int *a,int x,int v)
{
	for( ; x>0; x-=lowbit(x))
		a[x]+=v;
}
int sum_B(int *a,int x)
{
	int s=0;
	for(; x<MAXN; x+=lowbit(x))
	{
		s+=a[x];
	}
	
	return s;
}

void add_C(int *a, int x,int v)
{
	for( ; x<MAXN; x+=lowbit(x))
	{
		a[x]+=v;
	}
	
}
int sum_C(int *a, int x)
{
	int s=0;
	for( ; x>0; x-=lowbit(x))
	{
		s+=a[x];
	}
	return s;
}

void add(int x,int v)
{
	add_B(b,x-1,v);
	add_C(c,x,v*x);
}
void go_add(int a,int b,int v)
{
	add(b,v);
	add(a-1,-v); //
}

int sum(int x)
{
	return sum_C(c,x)+sum_B(b,x)*x;
}
int go_sum(int a,int b)
{
	return sum(b)-sum(a-1);
}

int main()
{
	while(1)
	{
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		int ai,bi,v;
		int r,l;
		cin>>r>>l>>v;
		r+=10;l+=10;

		cin>>ai>>bi;
		ai+=10;bi+=10;
		go_add(r,l,v);
		cout<<go_sum(ai,bi)<<endl;
	}
	
}


#endif


// 二维类型  给你（x1,y1）和（x2,y2），进行两种操作，add,sum. add是在一个点上加上一个数，sum是求以这两个点为对角线的矩形里，所有点的和。 
#if 1
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;  
const int MAXN=1000+20;
int a[MAXN][MAXN];

int lowbit(int x)
{
	return x&(-x);
}

void add(int x,int y,int v)
{
	for(int i=x; i<=MAXN; i+=lowbit(i))
	{
		for(int j=y; j<=MAXN; j+=lowbit(j))
		{
			a[i][j]+=v;
		}
	}
}

int sum(int x,int y)
{
	int s=0;
	for(int i=x; i>0; i-=lowbit(i))
	{
		for(int j=y; j>0; j-=lowbit(j))
		{
			s+=a[i][j];
		}
	}
	return s;
}
	
int main()
{
	int x1,y1,x2,y2,v,x,y,T,n;
	char ch[5];
	
	scanf("%d",&T);
	int cas=0;
	
	while(T--)
	{
		memset(a,0,sizeof(a)); 
		for(int i=1; i<=MAXN; i++)
		{
			for(int j=1; j<=MAXN; j++)
			{
				add(i,j,1);
			} 
		}
	
		printf("Case %d:\n",++cas);
	
		scanf("%d",&n);
		while(n--)
		{
			
		scanf("%s",&ch);
			if(ch[0]=='A')
			{
				scanf("%d%d%d",&x,&y,&v);
				x++;
				y++;
				add(x,y,v);
			}
			else if(ch[0]=='S')
			{
			
				scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
				x1++;
				y1++;
				x2++;
				y2++;
				if(x1>x2)
				{
					int t=x1;
					x1=x2;
					x2=t;
				} 
				if(y1>y2)
				{
					int t=y1;
					y1=y2;
					y2=t;
				}
				int temp=sum(x2,y2)+sum(x1-1,y1-1)-sum(x1-1,y2)-sum(x2,y1-1);
				printf("%d\n",temp);
			}
			else if(ch[0]=='D')                             
			{
			
				scanf("%d%d%d",&x,&y,&v);
				x++;
				y++;
				int temp=sum(x,y)+sum(x-1,y-1)-sum(x,y-1)-sum(x-1,y);
				if(temp<v)
					v=temp;
				add(x,y,-v);
			}
			else if(ch[0]=='M')
			{
				scanf("%d%d%d%d%d",&x1,&y2,&x2,&y2,&v);
				x1++;
				y1++;
				x2++;
				y2++;
				int temp=sum(x1,y1)+sum(x1-1,y1-1)-sum(x1,y1-1)-sum(x1-1,y1);
				if(temp<v)
					v=temp;
				add(x1,y1,-v);
				add(x2,y2,v);
				
			}
		
		}	
	}
	return 0;
}

#endif
















































































