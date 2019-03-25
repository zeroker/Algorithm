//http://acm.hdu.edu.cn/webcontest/contest_login.php?cid=11793         


// 跳马问题  符合条件走到最后的 
#if 0
#include<bits/stdc++.h>
using namespace std;
int f[8][2]{{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}},p,q,ax[65],ay[65];
bool flag,vis[9][9];

int ok(int x,int y)
{
	if(x>=0 && x<p && y>=0 && y<q) //  
		return 1;
	else
		return 0;	
} 

void dfs(int x,int y, int t)
{
	vis[x][y]=1; 
	ax[t]=x;                    //放的位置有点纠结刚刚 
	ay[t]=y;                    //
	
	if(p*q-1==t)
	{
		flag=1;
		return;
	}
	
	for(int i=0; i<8; i++)
	{
		int dx=x+f[i][0];
		int dy=y+f[i][1];
		
		
		if(ok(dx,dy) && !vis[dx][dy])
		{
			vis[dx][dy]=1;
			dfs(dx,dy,t+1);
			
			if(flag)
				return ;
			vis[dx][dy]=0;	
				
		}
	}
	
}

int main()
{
 
	while(cin>>p>>q)
	{
		memset(ax,0,sizeof(ax));
		memset(ay,0,sizeof(ay));
		memset(vis,0,sizeof(vis));
		flag=0;
		
		for(int i=0; i<p; i++)
		{
			for(int j=0; j<q; j++)
			{
				dfs(i,j,0);
				if(flag)
					break;
			}
			
			if(flag)
				break;
	    }
	    
	    if(flag)
	    {
			for(int i=0; i<q*p; i++)
	    		cout<<char(ay[i]+'A')<<ax[i]+1;
	    	cout<<endl<<endl;	
	    }		
	    else
	    	cout<<"NO"<<endl<<endl; 
			
	}


}

#endif 


//广搜跳马题  求步数问题 
 
#if 0 
#include<bits/stdc++.h>
using namespace std;
int starx,stary,endx,endy,step[8][8];
int f[8][2]={{1,-2},{1,2},{2,1},{2,-1},{-1,2},{-1,-2},{-2,1},{-2,-1}};

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
	int x,x1,y,y1;
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
		{
			return step[x][y];
		}
		else
			for(int i=0; i<8; i++)
			{
				x1=x+f[i][0];
				y1=y+f[i][1];
				if(ok(x1,y1))
				{
					q.push(x1);
			    	q.push(y1);
			    	step[x1][y1]=step[x][y]+1;
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
	 	cout<<bfs()<<endl;
		
	}
}
#endif 

// 农民追牛问题 
#if 0
#include<bits/stdc++.h>
using namespace std;
queue<int> q;
int n,k;
int cnt[5000]={0};
bool vis[5000]={0};

int  bfs()
{
	q.push(n);
	vis[n]=1;
	while(!q.empty())
	{
		int now=q.front();
		q.pop();
		int ans=cnt[now];
		
		if(now==k)
  		{
			return cnt[k];
		}
		else
		{
			if(!vis[now+1])
			{
				cnt[now+1]=ans+1;
				q.push(now+1);
				vis[now+1]=1;
			}
			if(!vis[now-1])
			{
				cnt[now-1]=ans+1;
				q.push(now-1);
				vis[now-1]=1;
			}
			if(!vis[now*2]) 
			{
				cnt[now*2]=ans+1;
				q.push(now*2);
				vis[now*2]=1;
			}
			
		}
		
	}

}

int main()
{
	cin>>n>>k;
	cout<<bfs()<<endl;	
	
}
#endif 


//0 1 问题
//最简单的深搜 必须要标记回溯，否则无限深搜，会爆炸啊 
#if 0
#include<bits/stdc++.h>
using namespace std;
bool flag=0;
void dfs(int k,long long int n,int i)
{
	if(i==19)
		return;
	if(flag==0)
	{
		if(n%k==0)
		{
			cout<<n<<endl;
			flag=1;
			return;
		}
		else
		{
			dfs(k,n*10,i+1);
			dfs(k,n*10+1,i+1);
		}
	}
	else
	{
		return;
	}

}


int main()
{
	long long int n;
	while(cin>>n)
	{
		flag=0;
		dfs(n,1,0);
	}
	
}

#endif 
 
 


//01问题深搜问题 
#if 0
#include<bits/stdc++.h>
using namespace std;
queue<int> q;
int k;
int bfs()
{
	q.push(1);
	while(!q.empty())
	{
		int now=q.front();
		q.pop();
		if(now%k==0)
		{
			return now;
		}
		q.push(now*10);
		q.push(now*10+1);
	}
	
}
int main()
{
	
	while(cin>>k)
	{
		cout<<bfs()<<endl;
	}
}


#endif 


//素数环问题 

































