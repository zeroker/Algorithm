/* 

关于深搜问题是有一个大体的框架的，很经典。 
 
void dfs(int 当前状态)
	{
	      if(当前状态为边界状态)
	      {
	        记录或输出
	        return;
	      }
	      for(i=0;i<n;i++)		//横向遍历解答树所有子节点
	     {
	           //扩展出一个子状态。
	           修改了全局变量
	           if(子状态满足约束条件)
	            {
	              dfs(子状态)
	           }
	            恢复全局变量//回溯部分
	        }
	}

*/


//1. 跳马问题遍历问题  做了一边都没有  dfs

#if 0
#include<iostream>   //输入第一个数是例子的数    4 3    A1B3C1A2B4C2A3B1C3A4B2C4 
#include<string.h>              
using namespace std;

int dx[8][2]{{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}},p,q,ax[650],ay[650];
bool flag,vis[50][50]; 

int OK(int x,int y)
{
	if(x>=0 && x<p && y>=0 && y<q)
		return 1;
	else 
		return 0;
}

void dfs(int x,int y,int t)
{
	ax[t]=x;
	ay[t]=y;
	vis[x][y]=1;
	
	if(t==p*q-1)
	{
		flag=1;
		return;
	}
	
	for(int i=0; i<8; i++)
	{
		int bx=x+dx[i][0];
		int by=y+dx[i][1];
		
		if(OK(bx,by) && !vis[bx][by])
		{
			vis[bx][by]=1;
			dfs(bx,by,t+1);
			
			if(flag)
				return;
			vis[bx][by]=0;	
			
		}
		
	}
	 	
}

int main()
{
	int x,ans=0;
	cin>>x;

	while(x--)
	{
		memset(ax,0,sizeof(ax));
		memset(ay,0,sizeof(ay));
		memset(vis,false,sizeof(vis));
		flag=0;		

		cin>>p>>q;
        
        for(int i=0; i<p; i++)
        {
			for(int j=0; j<q; j++)
        	{
        		dfs(i,j,0);
        		if(flag)
        		{
        			break;
				}
			}
			
			if(flag)
        	{
        		break;
			}
	   }
		
		if(flag)
		{
			cout<<"Scenario #"<<++ans<<endl;
			
			for(int i=0; i<p*q; i++)
				cout<<char(ay[i]+'A')<<ax[i]+1;
			cout<<endl<<endl;	
		}
		else
			cout<<"impossible"<<endl<<endl;	 		    
				
			
	}	
	
	
}
#endif

 
//2. bfs 计算走了多少步    马走日字   还是棋盘是 8*8 随便给两个点 求出走的最少的步数（给的点的格式是 b2 c3） 

#if 0
#include<bits/stdc++.h>
using namespace std;
int f[8][2]={{1,-2},{1,2},{2,1},{2,-1},{-1,2},{-1,-2},{-2,1},{-2,-1}};
int step[8][8];
int starx,stary,endx,endy;

int ok(int x,int y)
{
	if(x>=0 && x<8 && y>=0 && y<8)
		return 1;
	else
		return 0;
}


int bfs()
{
	queue<int> q;
	int x,x1,y1,y;
	q.push(starx);
	q.push(stary);
	step[starx][stary]=0;
	
	while(!q.empty())
	{
		x=q.front();
		q.pop();
		y=q.front();
		q.pop();
		
		if(x==endx && y==endy)
			return step[x][y];
		else
			for(int i=0; i<8; i++)
			{
				if(ok(x+f[i][0],y+f[i][1]))
				{
					q.push(x+f[i][0]);
					q.push(y+f[i][1]);	
					step[x+f[i][0]][y+f[i][1]]=step[x][y]+1;
				}	
			}
					
	}
	
}

int main()
{
	char a[2],b[2];
	
	while(cin>>a>>b)
	{
		memset(step,0,sizeof(step));
		starx=a[0]-'a';
		stary=a[1]-'1';
		endx=b[0]-'a';
		endy=b[1]-'1';
		int doit=bfs();
		cout<<"To get from "<<a[0]<<a[1]<<"to "<<b[0]<<b[1]<<" takes "<<doit<<" knight moves."<<endl;
	}
	
	 
}

#endif 




//棋盘问题 
//经典深搜 尤其在return的条件限制的时候 

//搜索的时候有两个限制 1.到达边界 2.数量满足限制条件了 

#if 0
#include<iostream>
#include<cstring>
char a[10][10];
int flag[10],cnt,num,n,k;

void dfs(int i)
{
	if(num==k)
	{
		cnt++;
		return;              //
	}
    if(i==n)
		return;               
	for(int j=0; j<n; j++)
	{
		if(!flag[j]&&a[i][j]=='#')
		{
			num++;	
			flag[j]=1;
			dfs(i+1);
			
			num--;
			flag[j]=0;	
		}	
    }
	
	dfs(i+1);	 		
}

using namespace std;
int main()
{
	while(cin>>n>>k && n!=-1 && k!=-1)
	{
		memset(flag,0,sizeof(flag));
		cnt=0;
		num=0;
		
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
			{
				cin>>a[i][j];
	        }
	    
			dfs(0);	
			cout<<cnt<<endl;    
	
    }
}

#endif



//农民追牛问题
/* Walking: FJ can move from any point X to the points X - 1 or X + 1 in a single minute
* Teleporting: FJ can move from any point X to the point 2 × X in a single minute. 
*/

#if 0
#include<iostream>
#include<queue>
using namespace std;
queue<int> q;
bool flag[100005];
int rent[100005],n,k;

int bfs()
{
	int x;
	if(n==k)
		return 0;
	q.push(n);	
	
	while(!q.empty())
	{
		x=q.front();
		q.pop();
		
			if(!flag[x+1]  && x+1<=100005) 
			{
				q.push(x+1);
				flag[x+1]=1;
				rent[x+1]=rent[x]+1;			
			}
			if(x+1==k)
				break;
			
			if(!flag[x-1] && x-1>=0 )
			{
                q.push(x-1);	
				flag[x-1]=1;
				rent[x-1]=rent[x]+1;
				
			}
			if(x-1==k)
				break;
				
			if(!flag[2*x] && 2*x<=100005)
			{
		 
				q.push(x*2);	
				flag[x*2]=1;
				rent[x*2]=rent[x]+1;
				
			}
			if(x*2==k)
				break;
   
   }
   
    return rent[k];
  		
}	
	
int main()
{
	cin>>n>>k;
    cout<<bfs()<<endl;
}
#endif



// 0 1 问题
#if 0
#include<iostream>
#include<queue>
using namespace std;
void bfs(int n)
{
	queue<unsigned long long int> q;
	q.push(1);
	
	while(!q.empty())
	{
		unsigned long long int x=q.front();
		q.pop();
		
		if(x%n==0)
		{
			cout<<x<<endl;
			return;
		}
		
		q.push(x*10);
		q.push(x*10+1);	
			
	}	
}


int main()
{
	int n;
	
	while(cin>>n && n)
	{
		bfs(n);	
	}
	
}
#endif 







//变 素数问题  广搜也要记得标记 ，要不然重复的元素会压到队列       筛素数 

//用结构体做
#if 0
#include<iostream>
#include<cstring>
#include<queue>
#include<cmath>
using namespace std;

int prime[10000];
bool vis[10000];

void goprime()                               //dabiao
{
	prime[0]=prime[1]=0;prime[2]=1;
	for(int i=3; i<=10000; i++)
	{
		if(i%2==0)
		{
			prime[i]=0;
		}
		else
		{
			prime[i]=1;
		}
	}
	int k=sqrt(10000);
	for(int i=2; i<=k; i++)
	{
		if(prime[i])
		for(int j=i*i; j<=10000; j+=2*i)
		{
			prime[j]=0;
		}
		
	}
	
}

struct go
{
	int x,t;	
}a,b;

void bfs()
{
	queue<go> q;
	q.push(a);
	
	while(!q.empty())
	{
		go it;
		it=q.front();
		q.pop();
		 
		if(it.x==b.x)
		{
			cout<<it.t<<endl;
			return;
		}
		
		int x1,x2,x3,x4;
		x1=it.x/1000;
		x2=it.x%1000/100;
		x3=it.x%100/10;
		x4=it.x%10;
		go its;
		
		for(int i=1; i<10; i++)
		{
			if(x1!=i)
			{
				int x=i*1000+x2*100+x3*10+x4;
				if(prime[x] && !vis[x])
				{
					vis[x]=1;
					its.x=x;
					its.t=it.t+1;
					q.push(its);
				}
			}
		}
		
		for(int i=0; i<10; i++)
		{
			if(x2!=i)
			{
				int x=x1*1000+i*100+x3*10+x4;
				if(prime[x] && !vis[x])
				{
					vis[x]=1;
					its.x=x;
					its.t=it.t+1;
					q.push(its);
				}
			}
		}
		
		for(int i=0; i<10; i++)
		{
			if(x3!=i)
			{
				int x=x1*1000+x2*100+i*10+x4;
				if(prime[x] && !vis[x])
				{
					vis[x]=1;
					its.x=x;
					its.t=it.t+1;
					q.push(its);
				}
			}
		}
		
		for(int i=0; i<10; i++)
		{
			if(x4!=i)
			{
				int x=x1*1000+x2*100+x3*10+i;
				if(prime[x] && !vis[x])
				{
					vis[x]=1;
					its.x=x;
					its.t=it.t+1;
					q.push(its);
				}
			}
		}
			
	} 
	
	cout<<"Impossible"<<endl;
	return;
}


int main()
{
	int n;
	cin>>n;
	goprime();
	
	while(n--)
	{
		memset(vis,0,sizeof(vis));
		cin>>a.x>>b.x;
		a.t=b.t=0;
		vis[a.x]=1;
		bfs();
	}
}
#endif 
 




//三D地下城 搜索问题（求步数）
//用深搜做了好久没做出来，广搜有发现小问题有好多，好久才AC 

//3D 经典三体广搜走路线问题 

#if 0
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int l,c,r,step[50][50][50],ei,ej,ek,si,sj,sk;
char a[50][50][50];
bool flag[50][50][50],flag1;

int f[6][3]={{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};

int ok(int k,int i, int j)
{
	if(k>=0&&k<l&&i>=0&&i<r&&k>=0&& k<c) 
		return 1;
	else
		return 0;	
}

void bfs(int z,int x,int y)
{
	queue<int> q;	
	q.push(z);
	q.push(x);
	q.push(y);
	
   	while(!q.empty()) 
	{
	
		int ai,aj,ak;
		ak=q.front();
		q.pop();
		ai=q.front();
		q.pop();
		aj=q.front();
		q.pop();
		
		if(ak==ek && ai==ei && aj==ej)
		{
			cout<<step[ak][ai][aj]<<endl;
			flag1=1;
			return;
		}
		
		for(int i=0; i<6; i++) 
		{
			int	ki=ak+f[i][0];
			int ii=ai+f[i][1];
			int ji=aj+f[i][2];
			if(ki==ek && ii==ei && ji==ej)
			{
				cout<<"Escaped in "<<step[ak][ai][aj]+1<<" minute(s)."<<endl;
				flag1=1;
				return;
			}
            
			if(a[ki][ii][ji]=='.' && ok(ki,ii,ji) && flag[ki][ii][ji]==0)
			{
				flag[ki][ii][ji]=1;
				q.push(ki);
				q.push(ii);
				q.push(ji);
				step[ki][ii][ji]=step[ak][ai][aj]+1;
			}
		}
	}
	
}


int main()
{
	
	while(cin>>l>>r>>c && l+r+c)
	{		
		memset(step,0,sizeof(step));
		memset(a,0,sizeof(a));
		memset(flag,0,sizeof(flag));
		flag1=0,ek=0,ei=0,ej=0,si=sj=sk=0;
		
		for(int k=0; k<l; k++)
			for(int i=0; i<r; i++)
				for(int j=0; j<c; j++)
				{
					cin>>a[k][i][j];
					if(a[k][i][j]=='S')
					{
						sk=k;
						si=i;
						sj=j;
					}
					
					if(a[k][i][j]=='E')
					{
						ek=k;
						ei=i;
						ej=j;
					}
					
				 } 
		flag[sk][si][sj]=1;		 
		bfs(sk,si,sj);
		
		if(flag1==0)
			cout<<"Trapped!"<<endl;
		
	}
	
}
#endif 







//深搜 有问题                    
#if 0
#include<bits/stdc++.h>
using namespace std;
int l,c,r;
char a[50][50][50];
bool flag[50][50][50],flag1;

int f[6][3]={{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};

int ok(int k,int i, int j)
{
	if(k>=0&&k<l&&i>=0&&i<r&&k>=0&& k<c)
		return 1;
	else
		return 0;	
}

void dfs(int dir1,int dir2,int dir3,int t)
{
	if(a[dir1][dir2][dir3]=='E')
	{
		flag1=1;
		cout<<"Escaped in "<<t<<" minute(s)."<<endl;
		return;
	}
	else
	{
		for(int i=0; i<6; i++)
		{
			int x,y,z;
			z=dir1+f[i][0];
			x=dir2+f[i][1];
			y=dir3+f[i][2];
		
		
			if(a[z][x][y]=='.' && !flag[z][x][y] && ok(z,x,y))
			{
				flag[z][x][y]=1;
				dfs(z,x,y,t+1);
			}
			
			flag[z][x][y]=0;
		}
		
	}
	
}

int main()
{
	int x,y,z;
	while(cin>>l>>r>>c && l+r+c)
	{
		flag1=0;
		memset(flag,0,sizeof(flag));
		memset(a,0,sizeof(a));
		
		for(int k=0; k<l; k++)
		{
			for(int i=0; i<r; i++)
			{
				for(int j=0; j<c; j++)
				{
					cin>>a[k][i][j];
					if(a[k][i][j]=='S')
					{
						x=i;
						y=j;
						z=k;
					}
				}
			}
		}
		
		dfs(z,x,y,0);
		if(flag==0)
		{
			cout<<"Trapped!"<<endl;
		}
	}
	
}
#endif 










//模拟题 洗扑克 Shuffle'm Up    看看洗几次会达到预定的顺序（洗的方式是第一张s2组的在下，第二张s1组的在上，依次，如果不是预期的，再把s12的下边的一半当成s1，上边的一半当成s2） 
 

#if 0
#include<iostream>
using namespace std;
int it;
int main()
{
	int T;
	cin>>T;
	
	while(T--)
	{	
		int ans=0,cnt=0;
		string s1,s2,s12,es12,flag;
		int n;
		cin>>n;
		
		cin>>s1>>s2>>es12;
		for(int i=0; i<n; i++)
		{
			flag+=s2[i];
			flag+=s1[i];
		}
		
		while(1)
		{
			ans++;
			
			for(int i=0; i<n; i++)
			{
				s12+=s2[i];
				s12+=s1[i];
			}
		//	cout<<ans<<": "<< s12<<endl;
			if(s12==flag)
			{
				cnt++;
				if(cnt>=2)
				{
					cout<<++it<<" "<<-1<<endl;
					break;
				}
			}
			
			if(s12==es12)
			{
				cout<<++it<<" "<<ans<<endl;
				break;
			}
			else
			{
				s1="";s2="";
				for(int i=0; i<n; i++)
				{
					s1+=s12[i];
				}	
				for(int i=n; i<2*n; i++)
				{
					s2+=s12[i];
				}
				
				s12="";
			}
			
		}
			
	}	
	
}

#endif

















































