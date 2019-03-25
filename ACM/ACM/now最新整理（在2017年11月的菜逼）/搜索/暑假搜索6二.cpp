//广搜 打印路径问题  
//特别新的就是广搜打印出路径来了 
//主要是怎么走理清思路，不要重复。 
#if 0                             //Pots
#include<iostream>
#include<queue>

using namespace std;
struct go
{
	int  x,y,t;
	string s;
};

int m,n,c;
bool vis[105][105];
bool flag=0;
void sprint(string s)
{
	for(int i=0; i<s.size(); i++)
	{
		if(s[i]=='1')
			cout<<"FILL(1)"<<endl;
		else
		if(s[i]=='2')
			cout<<"FILL(2)"<<endl;
		else
		if(s[i]=='3')
			cout<<"POUR(2,1)"<<endl;
		else
		if(s[i]=='4')
			cout<<"POUR(1,2)"<<endl;
		else
		if(s[i]=='5')
			cout<<"DROP(1)"<<endl;
		else
		if(s[i]=='6')
			cout<<"DROP(2)"<<endl;					
	}
	
}


void bfs()
{
	queue<go> q;
	go p;
	p.t=1;
	p.x=m;
	p.y=0;
	p.s='1';
	q.push(p);
	p.t=1;
	p.x=0;
	p.y=n;
	p.s='2';
	q.push(p);
	
	while(!q.empty())
	{
		go now;
		now=q.front();
		q.pop(); 
		
		if(now.x==c||now.y==c)
		{
			cout<<now.t<<endl;
			sprint(now.s);
			flag=1;
			return;
		}
		
		if(now.x<m)                //自来水加水 
		{
			go a;
			a.x=m;
			a.y=now.y;
			
			if(vis[a.x][a.y]==0)
			{
				a.t=now.t+1;
				vis[a.x][a.y]=1;
				a.s=now.s+'1';
				q.push(a);
			}
			
			if(now.y>0)         //水桶加水 
			{
				int cx=m-now.x;
				if(now.y>=cx)
				{
					a.x=m;
					a.y=now.y-cx;
				}
				else
				{
					a.x=now.x+now.y;
					a.y=0;
				}
				if(vis[a.x][a.y]==0)
				{
					a.t=now.t+1;
					vis[a.x][a.y]=1;
					a.s=now.s+'3';
					q.push(a);
				}
			}
		}
		
		if(now.y<n)       //自来水加水 
		{
			go a;
			a.x=now.x;
			a.y=n;
			
			if(vis[a.x][a.y]==0)
			{
				a.t=now.t+1;
				vis[a.x][a.y]=1;
				a.s=now.s+'2';
				q.push(a);
			}
			
			if(now.x>0)    //水桶加水 
			{
				int cy=n-now.y;
				if(now.x>=cy)
				{
					a.y=n;
					a.x=now.x-cy;
				}
				else
				{
					a.y=now.x+now.y;
					a.x=0;	
				}
				if(vis[a.x][a.y]==0)
				{
					a.t=now.t+1;
					vis[a.x][a.y]=1;
					a.s=now.s+'4';
					q.push(a);	
				}	
			}	
		}
		
		if(now.x>0)     //倒水 
		{
			go a;
			a.x=0;
			a.y=now.y;	
			if(vis[a.x][a.y]==0)
			{
				a.t=now.t+1;
				vis[a.x][a.y]=1;
				a.s=now.s+'5';
				q.push(a);	
			}	
		}
		if(now.y>0)  //倒水 
		{
			go a;
			a.y=0;
			a.x=now.x;
			if(vis[a.x][a.y]==0)
			{
				a.t=now.t+1;
				vis[a.x][a.y]=1;
				a.s=now.s+'6';
				q.push(a);	
			}		
		}		
	}
}

int main()
{
	cin>>m>>n>>c;
	vis[0][0]=1;
	bfs();
	if(flag==0)
	{
		cout<<"impossible"<<endl;
	}
}
#endif




//数独问题 !!!!!多敲几遍要         

#if 0                      //Sudoku
#include<iostream>
using namespace std;
int a[15][15],cnt;
bool flag=0;

int ok(int x,int y,int k)
{
	for(int i=0; i<9; i++)
	{
		if(a[x][i]==k)
			return 0;
		if(a[i][y]==k)
			return 0;	
	}
	
	int sx=x-x%3;
	int sy=y-y%3;
	for(int i=sx; i<sx+3; i++)
	{
		for(int j=sy; j<sy+3; j++)
		{
			if(a[i][j]==k)
				return 0;
		}
	}
	return 1;
}


void dfs(int num)
{
	
	bool flag1=0;
	int x,y;

	if(num==cnt)  
	{
		for(int i=0; i<9; i++)
		{
			for(int j=0; j<9; j++)
			{
				cout<<a[i][j];
			}
			cout<<endl;
		}
		flag=1;
		return;
	}
	if(flag)
		return;
    
	for(int i=0; i<9; i++)
	{
		for(int j=0; j<9; j++)
		{
			if(a[i][j]==0)
			{
				flag1=1;
				x=i;y=j;
				break;
			}
		}
		if(flag1)
			break;
	}
			
		for(int k=1; k<=9; k++)
		{
			if(ok(x,y,k))
			{
				a[x][y]=k;
				dfs(num+1);
				a[x][y]=0;
			}
		
		}		
}

int main()
{
	int N;
	char c;
	cin>>N;
	
	while(N--)
	{
		flag=0;
		cnt=0;
		
		for(int i=0; i<9; i++)
		{
			for(int j=0; j<9; j++)
			{
				cin>>c;
				a[i][j]=c-'0';
				if(a[i][j]==0)
					cnt++;	 
			}
		}
	
		dfs(0);

		
	}
		
}
#endif 

// 搜索有方向的问题 
//用有三种搜索的方法                   
#if 0                  //Children of the Candy Corn
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
bool vis[50][1000];
char mapk[50][1000];
int sx,sy,ex,ey,m,n;
int f[5][2]={{0,0},{-1,0},{0,1},{1,0},{0,-1}}; //上右下左 
struct node
{
	int x,y,t;	
};
int ok(int x,int y)
{
	if(x>=0&&x<m && y>=0&&y<n)
	{
		if(mapk[x][y]=='#')
			return 0;
		else
			return 1;	
	}
	else
		return 0; 
}
void l_s(int x,int y,int pre,int step)      
{
	int d[5];
	if(x==ex&&y==ey)
	{
		cout<<step+1<<" ";
		return;
	}
	
	if(pre==1)
	{
		d[1]=4,d[2]=1,d[3]=2,d[4]=3;	
	} 
	else
	{                                                      //上 右 下 左 
		if(pre==2)
		{
			d[1]=1,d[2]=2,d[3]=3,d[4]=4;
		}
		else
		{
			if(pre==3)
			{
				d[1]=2,d[2]=3,d[3]=4,d[4]=1; 
			}
			else
			{
				if(pre==4)
				{
					d[1]=3,d[2]=4,d[3]=1,d[4]=2;	
				}	
			} 
		}
	}
	
	for(int i=1; i<=4; i++)
	{
		int a,b;
		a=x+f[d[i]][0];
		b=y+f[d[i]][1];
		if(ok(a,b))
		{
			l_s(a,b,d[i],step+1);	
			break;
		}		
		
	}
	
}

void r_s(int x,int y,int pre,int step)      
{
	int d[5];
	if(x==ex&&y==ey)
	{
		cout<<step+1<<" ";
		return;
	}
	
	if(pre==1)
	{
		d[1]=2,d[2]=1,d[3]=4,d[4]=3;	
	} 
	else
	{                                                      //上 右 下 左 
		if(pre==2)
		{
			d[1]=3,d[2]=2,d[3]=1,d[4]=4;
		}
		else
		{
			if(pre==3)
			{
				d[1]=4,d[2]=3,d[3]=2,d[4]=1; 
			}
			else
			{
				if(pre==4)
				{
					d[1]=1,d[2]=4,d[3]=3,d[4]=2;	
				}	
			} 
		}
	}
	
	for(int i=1; i<=4; i++)
	{
		int a,b;
		a=x+f[d[i]][0];
		b=y+f[d[i]][1];
		if(ok(a,b))
		{
			r_s(a,b,d[i],step+1);	
			break;
		}		
		
	}
	
}



void bfs()
{
	queue<node> q;
	
	node now,next;
	now.t=0;
	now.x=sx;
	now.y=sy;
	vis[sx][sy]=1;
	q.push(now);
	
	while(!q.empty())
	{
		
		now=q.front();
		q.pop();
		
		if(now.x==ex&&now.y==ey)
		{
			cout<<now.t+1<<endl;
			return;
		}
		else
		{
			for(int i=0; i<4; i++)
			{
				next.x=now.x+f[i][0];
				next.y=now.y+f[i][1];
				if(ok(next.x,next.y) && !vis[next.x][next.y])
				{
					vis[next.x][next.y]=1;
					next.t=now.t+1;

					q.push(next);
				}
			}
		}
	}
}


int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		
		memset(vis,0,sizeof(vis));
		memset(mapk,0,sizeof(mapk));
		cin>>n>>m;
		for(int i=0; i<m; i++)
		{
			for(int j=0; j<n; j++)
			{
				cin>>mapk[i][j];
				if(mapk[i][j]=='S')
				{
					sx=i; sy=j;
				}
				else
				if(mapk[i][j]=='E')
				{
					ex=i;
					ey=j;
				}
			}
		}
		for(int i=1; i<=4; i++)
		{
			int x,y;
			x=sx+f[i][0];
			y=sy+f[i][1];
			if(mapk[x][y]=='.')
			{
				l_s(sx,sy,i,0);
				r_s(sx,sy,i,0);
				break;
			}
		}
		bfs();
		
	}
	
}
#endif 




//推冰球问题  （记得是求最小的步数） 
#if 0                 //Curling 2.0  
#include<iostream>
#include<cstring>
using namespace std;
int m,n,mapk[25][25]={555},sx,sy,ex,ey,mmin=1000;
int f[4][2]={{-1,0},{0,1},{1,0},{0,-1}};              //上右下左  
bool ff;

int judge(int x,int y)
{
	if(x>=0&&x<m&&y>=0&&y<n)
	{
		return 1;
	}
	else
	{
		return 0;
	}
	
}

void dfs(int x,int y,int step) 
{

	
	if(step>10)
	{
		return;
	}
	
	if(x==ex&&y==ey)
	{
		if(step<mmin)
			mmin=step;
		ff=1;
		return;
	}
	else
	{
		for(int i=0; i<4; i++) 
		{
			int nextx,nexty;
			bool flag=0;
			nextx=x;
			nexty=y;
			
			if(mapk[nextx+f[i][0]][nexty+f[i][1]]==0)	//前面必须有空	
			{
				while(judge(nextx,nexty)&&flag==0)      //向前一直走 一直到边界位置 
				{
					nextx+=f[i][0];                     
					nexty+=f[i][1];
					if(nextx==ex&&nexty==ey)             
					{
						if(step+1<mmin)
							mmin=step+1;
						ff=1;
						return;
					}
					else
					if(mapk[nextx][nexty]==1)           //碰到了墙  
					{
						flag=1;
						mapk[nextx][nexty]=0;
						dfs(nextx-f[i][0],nexty-f[i][1],step+1); //后退一步进行搜索 
						mapk[nextx][nexty]=1;                 
					
					}
				}
				
			}
			
		}
	}
	
	
}


int main()
{
	while(cin>>n>>m&&n+m)
	{
		bool flag1=0;
		memset(mapk,555,sizeof(mapk));
		ff=0;mmin=1000;
		for(int i=0; i<m; i++)
		{
			for(int j=0; j<n; j++)
			{
				cin>>mapk[i][j];
				if(mapk[i][j]==2)
				{
					sx=i;
					sy=j;
					mapk[i][j]=0;	
				}
				else
				if(mapk[i][j]==3)
				{
					ex=i;
					ey=j;
					mapk[i][j]=0;	
				}	
			}	
		}
		
		for(int i=0; i<4; i++)
		{
			int nextx,nexty;
			nextx=sx+f[i][0];
			nexty=sy+f[i][1];
			if(mapk[nextx][nexty]==0&&judge(nextx,nexty))
			{
				flag1=1;
				break;
			}
		}
		
		if(flag1)
		{
			dfs(sx,sy,0);
			if(ff==0)
			{
				cout<<-1<<endl;
			}
			else
			{
				if(mmin>10)
				{
					cout<<"-1"<<endl;
				}
				else
					cout<<mmin<<endl;	
			} 
		}
		else
		{
			cout<<-1<<endl;
		}
	
	
	}
	 
}
#endif






//What fuck!!!!? 
//分成两组 求第一组的每一个点到第二个组的每一个点的距离的最大值是多少 
//刚开始都是在第二组，     没有被标记的一组 

#if 0                //Network Saboteur  
#include<iostream>
#include<cstring>
using namespace std;
bool vis[25];
int map[25][25],maxx,n;

void dfs(int x,int sum)
{
	int mx=sum;
	vis[x]=1;
	
	for(int j=0; j<n; j++)
	{
		if(vis[j]==0)
		{
			mx+=map[x][j];	
		}
		else
		{
			mx-=map[x][j];
		}
	
	}
		
	if(mx>maxx)
		maxx=mx;
	if(mx>sum)
	{
		for(int k=x+1; k<n; k++)
		{
			dfs(k,mx);
			vis[k]=0;
		}
			
	}	
	
}

int main()
{
	
	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cin>>map[i][j];
		}
	}
	dfs(0,0);
	cout<<maxx<<endl;
	
}

#endif



//  频道问题  和最少染几种颜色问题 差不多
//  给出若干个方块 相连的方块颜色不能相同，求最少用多少颜色涂这几个方块（这个题和这个涂颜色的题意相同） 
#if 0
#include<iostream>
#include<cstring>
using namespace std;
int mapk[30][30],n;
int color[30]={555}; 

void dfs(int x)
{
	if(x==n)
	{
		int top=0;
		for(int i=0; i<n; i++)
		{
			if(color[i]>top)
				top=color[i];
		}
		if(top>1)
		cout<<top+1<<" channels needed."<<endl;
		else
		{
			cout<<top+1<<" channel needed."<<endl;
		}
	
		return;
	}
	else
	{
		
		for(int k=0; k<n; k++)             //点 x 选颜色 
		{	
			bool flag1=0;
			for(int j=0; j<n; j++)
			{
				if(mapk[x][j]==1)
				{
					if(k==color[j])
					{
						flag1=1;
						break;
					}
				}
			}
			if(flag1==0)
			{
				color[x]=k;
				break;
			}
			
		}
		dfs(x+1);
		color[x]=555; 
	}
}

int main()
{
	while(cin>>n&&n)
	{
		memset(mapk,0,sizeof(mapk));
		memset(color,555,sizeof(color));
	

		for(int i=0; i<n; i++)
		{
			string s;
			cin>>s;
			for(int k=2; k<s.size(); k++)
			{
				int j=s[k]-'A';
				mapk[i][j]=1;
			}
		}
		
		dfs(0);
	
	}
	
}
#endif 










#if 1
#include<bits/stdc++.h>
using namespace std;
const int MAX=1000000;
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
		memset(u,1,sizeof(u));
		memset(minn,0x7f,sizeof(minn));
		int n;
		cin>>n;
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				cin>>a[i][j];
		
		minn[1]=0;
		for(int i=1; i<=n; i++)	
		{
			int k=0;
			for(int j=1; j<=n; j++)
			{
				if(u[j]&&minn[k]>minn[j])
					k=j;
			}
			u[k]=0;
			
			for(int j=1; j<=n; j++)
			{
				if(u[j]&&a[k][j]<minn[j])
					minn[j]=a[k][j];
			}
			
		}
		
		int sum=0;
		for(int i=1; i<=n; i++)
		{
			sum+=minn[i];	
		}	
		cout<<sum<<endl;
	}
	
}
#endif 












































































