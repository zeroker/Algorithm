

#if 0
#include<bits/stdc++.h>
using namespace std;
#define MAX 2000+50
int w,h;

int f[4][2]={{1,0},{-1,0},{0,1},{0,-1}}; 

int a[MAX][MAX],sx,sy,ex,ey;
bool ok(int i,int j)
{
	if(i>=0&&i<h&&j>=0&&j<w)
	{
			return 1;		
	}	
	return 0;	
}

struct node
{
	int x,y,step;
	int thing;	
};


void bfs()
{
	queue<node> q;
	node now;
	now.step=0;
	now.x=sx;
	now.y=sy;
	now.thing=0;
	
	q.push(now);
	
	while(!q.empty()) 
	{
		now=q.front(); 
		q.pop();
		
		if(now.x==ex&&now.y==ey)   
		{
			if(now.thing==1)
			{
				cout<<now.step<<endl;
				return;
			}
		}
		else
		for(int i=0; i<4; i++)
		{
			node next;
			next.x=now.x+f[i][0];
			next.y=now.y+f[i][1];
			
			if(ok(next.x,next.y)) 
			{
				if(a[next.x][next.y]!=1) 
				{
					if(a[next.x][next.y]==4)
					{
						next.thing=1;
						next.step=now.step+1;
						q.push(next);	
					}
					else 
					{
						next.step=now.step+1;
						q.push(next);
					}
					
				}
			}
		}
	}
}

int main()
{
	while(cin>>w>>h)
	{
		memset(a,0,sizeof(a));
		//memset(b,0,sizeof(b));
		for(int i=0; i<h; i++)
		{
			for(int j=0; j<w; j++)
			{
				cin>>a[i][j];
				if(a[i][j]==2)
				{
					sx=i;
					sy=j;	
				}
				else if(a[i][j]==3)
				{
					ex=i;
					ey=j;
				}	
			}	
		}
		
		bfs();	
	}		
	
}

#endif




#if 0
#include<bits/stdc++.h>
using namespace std;
#define MAX 2000+50
int w,h;

int f[4][2]={{1,0},{-1,0},{0,1},{0,-1}}; 
//bool flag[MAX][MAX];
int a[MAX][MAX],sx,sy,ex,ey;
bool ok(int i,int j)
{
	if(i>=0&&i<h&&j>=0&&j<w)
	{
			return 1;		
	}	
	return 0;	
}

struct node
{
	int x,y,step;
	bool  thing;	
};


void bfs()
{
	queue<node> q;
	node now;
	
	now.step=0;
	now.x=sx;
	now.y=sy;
	now.thing=0;
	
	q.push(now);
	
	while(!q.empty()) 
	{
		now=q.front(); 
		q.pop();
		
		if(now.x==ex&&now.y==ey)   
		{
			if(now.thing==1)
			{
				cout<<now.step<<endl;
				return;
			}
		}
		else
		for(int i=0; i<4; i++)
		{
			node next;
			next.x=now.x+f[i][0];
			next.y=now.y+f[i][1];
			
			if(ok(next.x,next.y)) 
			{
				if(a[next.x][next.y]!=1) 
				{
					if(a[next.x][next.y]==4)
					{
						next.thing=1;      
						next.step=now.step+1;
						q.push(next);	
					}
					else 
					{
						next.step=now.step+1;
						q.push(next);
					}
					
				}
			}
		}
	}
}

int main()
{
	while(cin>>w>>h)
	{
		memset(a,0,sizeof(a));
		//memset(b,0,sizeof(b));
		for(int i=0; i<h; i++)
		{
			for(int j=0; j<w; j++)
			{
				cin>>a[i][j];
				if(a[i][j]==2)
				{
					sx=i;
					sy=j;	
				}
				else if(a[i][j]==3)
				{
					ex=i;
					ey=j;
				}	
			}	
		}
		
		bfs();	
		
	
	}		
	
}

#endif














#if 0
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int n,cnt;
const int MAX=1000000+50;
int a[MAX],b[MAX],k; 

void dfs(int s,int t)
{
	
	for(int i=a[t-1]; i<=s; i++)
	{
		bool flag=0;
		for(int j=0; j<k; j++)
		{
			if(i==b[j])
			{
				flag=1;
			}
		}
		
		if(flag==0)
		{
			continue;
		}
		
		if(i<n) 
		{
			
			{
				a[t]=i;
				s-=i;
				if(s==0)
				{
					cnt++;
				//	for(int i=1; i<=t; i++)
				//		cout<<a[i]<<"  ";
				//	cout<<endl;	
					return;
				}
				else
					dfs(s,t+1);
				s+=i;
			}
		}
	}
}

int main()
{
		cin>>n;
		k=0;
		a[0]=1;
		memset(b,0,sizeof(b));
		
			while(pow(2,k)<n)
			{
					int x=pow(2,k);
					b[k++]=x;
			}
		
			/*while(b[k]<1000010)
			{
				k++;
				b[k]=b[k-1]*2;
			}*/
		
		
		cnt=0;
		
		dfs(n,1);
		cout<<cnt<<endl;
	 
}
#endif












#if 0
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int n,cnt;
const int MAX=1000000+50;
int a[MAX],b[MAX],k; 

void dfs(int s,int t)
{
	
	for(int i=a[t-1]; i<=s; i*=2)
	{
		if(i<n) 
		{
			
			{ 
				a[t]=i; 
				s-=i;
				if(s==0)
				{
					cnt++;
				//	for(int i=1; i<=t; i++)
				//		cout<<a[i]<<"  ";
				//	cout<<endl;	
					return;
				}
				else
					dfs(s,t+1);
				s+=i;
			}
		}
	}
}

int main()
{
		cin>>n;
		k=0;
		a[0]=1;
	//	memset(b,0,sizeof(b));
		
		/*	while(pow(2,k)<n)
			{
					int x=pow(2,k);
					b[k++]=x;
			}
		
			/*while(b[k]<1000010)
			{
				k++;
				b[k]=b[k-1]*2;
			}*/
		
		
		cnt=0;
		
		dfs(n,1);
		cout<<cnt<<endl;
	 
}
#endif    




#if 1
#include<iostream>
#include<cstdio>
 using namespace std;
 int n,a[1000001];
 int main()
 {
      int i;
      while(cin>>n)
      {
           a[1]=1;
           a[2]=2;
           for (i=3;i<=n;i++)
           {
                if(i%2==1)  
					a[i]=a[i-1];
                if(i%2==0)  
					a[i]=(a[i-1]+a[i/2])%1000000000;
            }
          	cout<<a[n]<<endl;
      }
      return 0;
}
#endif



















