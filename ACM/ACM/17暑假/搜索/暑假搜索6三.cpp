//最小生成树问题  	Highways

#if 0
#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;

const int MAX=501;
int a[MAX][MAX];
bool u[MAX];
int minn[MAX];

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		memset(a,0,sizeof(a));
		memset(u,1,sizeof(u));                   //全标记成蓝点 
		memset(minn,0x7f,sizeof(minn));
		int n;
		scanf("%d",&n);
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				scanf("%d",&a[i][j]);
		
		minn[1]=0;                              
		for(int i=1; i<=n; i++)	
		{
			int k=0;
			for(int j=1; j<=n; j++)
			{
				if(u[j]&&minn[k]>minn[j])        //找出与白点相连的最小的蓝点 
					k=j;
			}
			
			u[k]=0;                             //标记成白点 
			
			for(int j=1; j<=n; j++)
			{
				if(u[j]&&(a[k][j]<minn[j]))     //更改新的白点 ，与白点相连的蓝点的值 
					minn[j]=a[k][j];
			}
			
		}
		
		int end=0;
		for(int i=1; i<=n; i++)
		{
			if(minn[i]>end)
				end=minn[i];	
		}	
		cout<<end<<endl;
	}
	
}
#endif 




//最小生成树         Agri-Net

#if 0
#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;

const int MAX=600;
int a[MAX][MAX];
bool u[MAX];
int minn[MAX];

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)            // scanf()!=EOF 与 scanf() && n 有差么~？  what fuck?~! 
	{
		memset(a,0,sizeof(a));
		memset(u,1,sizeof(u));                   //全标记成蓝点 
		memset(minn,0x7f,sizeof(minn));
	
		
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				scanf("%d",&a[i][j]);
		
		int sum=0;
		minn[1]=0;                              
		for(int i=1; i<=n; i++)	
		{
			int k=0;
			for(int j=1; j<=n; j++)
			{
				if(u[j]&&minn[k]>minn[j])        //找出与白点相连的最小的蓝点 
					k=j;
			}
			
			u[k]=0;                             //标记成白点 
			sum+=minn[k];
			for(int j=1; j<=n; j++)
			{
				if(u[j]&&(a[k][j]<minn[j]))     //更改新的白点 ，与白点相连的蓝点的值 
					minn[j]=a[k][j];
			}
			
		}
		
		
			printf("%d\n",sum);
	}
	
	return 0;
}
#endif 





//弗洛伊德 算法 求最短路径问题 这里的问题问的是 i----->j ，路径里的最大距离，在所有的路径里，最小是多少？ 

// Frogger
#if 0
#include<iostream>
#include<cmath>
#include<iomanip>
#include<cstring>
using namespace std;
int main()
{
	int n,ans=0;
	while(cin>>n&&n)
	{
	
		double point[201][2]={0},mapp[201][201]={0};
	
		
		for(int i=0; i<n; i++)
			cin>>point[i][0]>>point[i][1];
		
		
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{
				mapp[i][j]=mapp[j][i]=sqrt((point[i][0]-point[j][0])*(point[i][0]-point[j][0])+(point[i][1]-point[j][1])*(point[i][1]-point[j][1]));
			}
		}
		
		for(int k=0; k<n; k++)
		{
			
			for(int i=0; i<n; i++)
			{
				for(int j=0; j<n; j++)
				{
					if(i!=j&&i!=k&&j!=k)
					{
						mapp[i][j]=min(mapp[i][j],max(mapp[i][k],mapp[k][j]));
					}
				}
			}
			
		}
		
		
		cout<<"Scenario #"<<++ans<<endl<<"Frog Distance"<<" = "<<fixed<<setprecision(3)<<mapp[0][1]<<endl<<endl; 
	}
}
#endif


//Shredding Company      分数字的题      what ?
//dfs     
#if 0
#include<iostream>
#include<cstring>
using namespace std;
int n,a[10],t[10],end[10];        //a 开始的数组   t一直变换的数组 end最后结果的数组 
int D=0,num,lenth;
string s;

void dfs(int sum,int x,int p, int len)                  // 0 a[0] 0 0
{ 
	//cout<<"123000"<<endl; 
	
	if(sum>n) 
		return;
	if(p==s.size())                       //搜到底      
	{
		sum+=x;
		t[len]=x;
		/*for(int i=1; i<=len; i++)  
		{
			cout<<t[i]<<" ";
		}*/
		//cout<<endl<<"*************************"<<endl;  
		
		if(sum>n) 
			return;
			
		if(sum>D) 
		{
			D=sum;
			num=1;
			lenth=len;
			
			for(int i=1; i<=lenth; i++)
			{
				end[i]=t[i];
			}
		}
		else
		if(sum==D)
		{
			num=2;		
		}	
		return;
		
	}
	

		
		dfs(sum,x*10+a[p+1],p+1,len); 
		t[len]=x;
		len+=1; 
		dfs(sum+x,a[p+1],p+1,len);  	
		t[len]=0;
			
}

int main()
{
	while(cin>>n>>s)
	{
		if(n==0&&s=="0")
			break;
			
		D=0; num=0;
		memset(a,0,sizeof(a));
		memset(end,0,sizeof(end));
		memset(t,0,sizeof(t));
			
		for(int i=1; i<=s.size(); i++)
		{
			a[i]=s[i-1]-'0';
		}
	
	
			
		dfs(0,a[1],1,1);
	       
		if(num==0) 
		{
			cout<<"error"<<endl; 
		} 
		else 
		if(num==2)
		{
			cout<<"rejected"<<endl;
		}
		else
		{
			cout<<D;
			for(int i=1; i<=lenth; i++)
			{
				cout<<" "<<end[i];
			}
			cout<<endl;
		} 
	
	}

}
#endif 






//换钱的问题   超时     SPFA
#if 0
#include<stdio.h>  
#include<string.h>  
#include<queue> 
using namespace std;
int n,m,s;
double v,dis[111];              //n种钱 ， m个站点   第s种  v这么多的钱 

double rate[111][111],cost[111][111];

int spfa(int start)
{
	bool in[111];
	memset(in,0,sizeof(in));
	memset(dis,0,sizeof(dis));
	dis[start]=v;
	
	queue<int> 	q;
	q.push(start);
	in[start]=1;
	while(!q.empty())
	{
		
		int now=q.front();
		q.pop();
		in[now]=0;
		
		for(int i=0; i<=n; i++)
		{
			if(dis[i]<(dis[now]-cost[now][i])*rate[now][i])
			{
				dis[i]=(dis[now]-cost[now][i])*rate[now][i];
				if(dis[start]>v)
					return 1;
			}
			if(in[i]==0)
			{
				q.push(i);
				in[i]=1;
			}
		}
		
	}
	return 0;
}


int main()
{
	while(~scanf("%d%d%d%lf",&n,&m,&s,&v))            // m个点 
	{
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=n; j++) 
			{
				if(i==j)
				{
					rate[i][j]=1;
					
				}
				else
				{
					rate[i][j]=0;
					
				}
				cost[i][j]=0;
			}
		}
		
		for(int i=0; i<m; i++)
		{
			int a,b;
			double rab,cab,rba,cba;
			scanf("%d%d%lf%lf%lf%lf",&a,&b,&rab,&cab,&rba,&cba); 
			rate[a][b]=rab;
			rate[b][a]=rba;
			cost[a][b]=cab;
			cost[b][a]=cba;
		}
		
		if(spfa(s))
		{
			 printf("YES\n");
			
		}
		else
		{
			printf("NO\n");
		}
		
		
	}
	return 0;
}

#endif


//不超时题解 
#if 0
#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
const int N = 110;
int n, m, s;
double dis[N], v, rate[N][N], cost[N][N];

bool spfa(int start)
{
    bool inq[110];
    memset(inq, 0, sizeof(inq));
    memset(dis, 0, sizeof(dis));
    dis[start] = v;
    queue<int> Q;
    Q.push(start);
    inq[start] = true;
    while(!Q.empty())
    {
        int x = Q.front();
        Q.pop();
        inq[x] = false;
        for(int i = 0; i <= n; i++)
        {
            if(dis[i] < (dis[x] - cost[x][i]) * rate[x][i])
            {
                dis[i] = (dis[x] - cost[x][i]) * rate[x][i];
                if(dis[start] > v)
                    return true;
                if(!inq[i])
                {
                    Q.push(i);
                    inq[i] = true;
                }
            }
        }
    }
    return false;
}

int main()
{
    int i, j;
    while(~scanf("%d%d%d%lf",&n,&m,&s,&v))
    {
        int a, b;
        double rab, rba, cab, cba;
        for(i = 1; i <= n; i++)
            for(j = 1; j <= n; j++)
            {
                if(i == j)
                    rate[i][j] = 1;
                else
                    rate[i][j] = 0;
                cost[i][j] = 0;
            }
        for(i = 0; i < m; i++)
        {
            scanf("%d%d%lf%lf%lf%lf",&a,&b,&rab,&cab,&rba,&cba);
            rate[a][b] = rab;
            rate[b][a] = rba;
            cost[a][b] = cab;
            cost[b][a] = cba;
        }
        if(spfa(s))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
#endif




//负权回路问题           Wormholes 
#if 0
#include<iostream>
#include<cstring>
using namespace std;
int n,m,no,k;   //点，路，黑洞 
struct lu
{
	int a,b,t;
}mapp[10000];
int dis[10000];         

void ford_one()
{
		memset(dis,0x7f,sizeof(dis));
		dis[1]=0; 
		int a,b,t;
		for(int i=1; i<=n-1; i++)
		{	
			bool flag=0;
			for(int j=1; j<=k; j++)
			{
				a=mapp[j].a; 
				b=mapp[j].b;
				t=mapp[j].t;
				
				if(dis[b]>dis[a]+mapp[j].t)
				{
					dis[b]=dis[a]+mapp[j].t;
					flag=1;
				}
			}
			if(flag==0)
				break;
		}
}

int ford_two()
{
	int a,b,t;
	
	    
		for(int j=1; j<=k; j++)
		{
			a=mapp[j].a; b=mapp[j].b;t=mapp[j].t;
			if(dis[b]>dis[a]+mapp[j].t)
				return 1;
		}
	
	return 0;
}


int main()
{
	int T;

	cin>>T;
	while(T--)
	{
		
		cin>>n>>m>>no; 
		k=0;
		for(int i=1; i<=m; i++) 
		{
			int aa,bb,xx;
			cin>>aa>>bb>>xx;
			k++;
			mapp[k].a=aa;
			mapp[k].b=bb;
			mapp[k].t=xx;
			k+=1;
			mapp[k].a=bb;
			mapp[k].b=aa;
			mapp[k].t=xx;
		}
		
		for(int i=1; i<=no; i++)
		{
			int aa,bb,xx;
			cin>>aa>>bb>>xx;
			k+=1;
			mapp[k].a=aa;
			mapp[k].b=bb;
			mapp[k].t=-xx;
		 
		}
		
		ford_one();
		
		if(ford_two())
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
	
}
#endif 


//用SPFA 做的  wrong
 
#if 0
#include<bits/stdc++.h>
using namespace std;

int n,m,no,k;   //点，路，黑洞 
struct lu
{
	int a,b,t;
}mapp[10000];

int dis[10000];         
bool in[10000];

int spfa()
{
	dis[1]=0;
	in[1]=1;	
	queue<int> q;
	q.push(1);
	
	while(!q.empty()) 
	{
		int now=q.front();
		q.pop();
		in[now]=0;
		
		for(int i=1; i<=k; i++)
		{	
			if(now==mapp[i].a) 
			{
				int a,b,t;
				a=mapp[i].a;
				b=mapp[i].b;
				t=mapp[i].t;
			
				if(dis[b]>dis[a]+t);
				{
					dis[b]=dis[a]+t;
				}
				if(in[b]==0) 
				{
					q.push(b);
					in[b]=1;
				}
			}
			if(dis[1]<0)
				return 1;	
				
		}
		
		
	}
	return 0;
	
}

int main()
{
	int T;

	cin>>T;
	while(T--)
	{
		memset(dis,0x7f,sizeof(dis));
		memset(in,0,sizeof(in));
		cin>>n>>m>>no; 
		k=0;
		
		for(int i=1; i<=m; i++) 
		{
			int aa,bb,xx;
			cin>>aa>>bb>>xx;
			k++;
			mapp[k].a=aa;
			mapp[k].b=bb;
			mapp[k].t=xx;
			k+=1;
			mapp[k].a=bb;
			mapp[k].b=aa;
			mapp[k].t=xx;
		}
		
		for(int i=1; i<=no; i++)
		{
			int aa,bb,xx;
			cin>>aa>>bb>>xx;
			k+=1;
			mapp[k].a=aa;
			mapp[k].b=bb;
			mapp[k].t=-xx;
		 
		}
		
		if(spfa()==1)
		{
			cout<<"YES"<<endl;
		}
		else
			cout<<"NO"<<endl;
		
	}
	
	
}
#endif



//	昂贵的聘礼 

#if 1   
#include<bits/stdc++.h>
using namespace std;
int k,dis[1000];
int m,n;     //m 的差别， n 个东西 
int l,r;        
struct node
{
	int s,e,x;
}a[1000];

int high[1000];

void ford() 
{
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=k; j++)
		{
			int s,e,x;
			s=a[i].s;
			e=a[i].e;
			x=a[i].x;
			if(high[s]>=l&&high[s]<=r&&high[e]>=l&&high[e]<=r)
			{
				if(dis[e]>dis[s]+x)
				{
					dis[e]=dis[s]+x;
				}
			}
				
		}	
	}	
	
	cout<<dis[1]<<endl;
}


int main()
{
	memset(dis,0x7f,sizeof(dis));                    
	cin>>m>>n;
	k=0;
	for(int i=1; i<=n; i++)        
	{
		int c,h,num;             //价值，主人的等级，可以交换的物品的个数 
		
		cin>>c>>h>>num;
		dis[i]=c;
		high[i]=h;
		
		if(num==0)
		{
			int e,x;
			cin>>e>>x;
			k++;
			a[k].s=a[k].e=i;
			a[k].x=0;	
		}
		for(int j=1; j<=num; j++)
		{
			int e,x;
			cin>>e>>x;
			
			k++;                  //从 下标1 开始 存储路径 
			a[k].e=i;
			a[k].s=j;
			a[k].x=x;
		}
	}
	
	l=high[1]-m;
	r=high[1]+m;
	ford();
}
#endif












//Truck History           最小生成树问题，prime 
#if 0
#include<iostream>
#include<cstring>
using namespace std;
int mapp[3000][3000];
int minn[3000],n;
bool u[3000];

void prime()
{
	
	minn[1]=0;
                       
	for(int i=1; i<=n; i++)           // 
	{
		int k=0;
		for(int j=1; j<=n; j++)             //找出与白点 连接权值最小的蓝点 k  
		{
			if(!u[j]&&minn[k]>minn[j])
			{
				k=j;
			}
		}
		u[k]=1;           //k 蓝点 
		
		for(int j=1; j<=n; j++)
		{
			if(!u[j]&&mapp[k][j]<minn[j])
				minn[j]=mapp[k][j];	
		} 
	} 
}

int main()
{
	while(cin>>n&&n)
	{
		string s[3000];
		memset(mapp,0,sizeof(mapp));
		memset(minn,0x7f,sizeof(minn));
		memset(u,0,sizeof(u));
		for(int i=1; i<=n; i++)
		{
			cin>>s[i];	
		}	
	
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=n; j++)
			{
				int x=0;
				for(int k=0; k<7; k++)
				{
					if(s[i][k]!=s[j][k])
						x++;
				}
				mapp[i][j]=x;
			}
		}
	
		int sum=0;
		prime();
		for(int i=1; i<=n; i++)
		{
			sum+=minn[i];
		}
		cout<<"The highest possible quality is 1/"<<sum<<"."<<endl;		
    }	                      

}
#endif




















































