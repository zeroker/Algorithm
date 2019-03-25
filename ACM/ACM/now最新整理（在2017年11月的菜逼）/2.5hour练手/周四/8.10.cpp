


//1.
#if 0
#include<iostream>
using namespace std;
int sumd;
int a[]={0,31,28,31,30,31,30,31,31,30,31,30,31};

bool ok(int x)
{
	if((x%4==0&&x%100!=0)||(x%400==0))
		return 1;
	else
		return 0;	
}


int main()
{
	int y,m,d;
	while(cin>>y>>m>>d && y+m+d)
	{
		sumd=0;
	for(int i=1800; i<y; i++)
	{
		if(ok(i)) 
		{
			sumd+=366;
		}
		else
		{
			sumd+=365;
		}
		
		if(sumd>=7)
		{
			sumd%=7;
		}
	}
	
	for(int i=1; i<m; i++) 
	{
		if(i==2)  
		{
			if(ok(y)) 
			{
				sumd+=29; 
			}
			else 
			{
				sumd+=28;  
			}
		}
		else
		{
			sumd+=a[i]; 
		}
		if(sumd>=7)
		{
			sumd%=7;
		}
	}
	
	sumd+=d;
	
	if(sumd>=7)
	{
		sumd%=7;
	}
	

	if(sumd==6)   
	{
		cout<<"monday"<<endl;
	}
	else 
	if(sumd==0) 
	{
		cout<<"tuesday"<<endl; 
	}
	else				
	if(sumd==1)
	{
		cout<<"wednesday"<<endl;
	}
	else
	if(sumd==2)
	{
		cout<<"thursday"<<endl;
	}
	else
	if(sumd==3)																				
	{
		cout<<"friday"<<endl;										
	}		
	else														
	if(sumd==4)
	{
		cout<<"saturday"<<endl;
	}
	else
	if(sumd==5) 													
	{
		cout<<"sunday"<<endl; 
	}
	
	
	}
	
	
	
}
#endif







//2.
#if 0
#include<iostream>
#include<cstring>
using namespace std;
int a[400][400];
int t[400][400];
int main()
{
	int n;
	while(cin>>n)
	{
		memset(a,0,sizeof(a));
		memset(t,0,sizeof(t));
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=i; j++)
			{
				cin>>a[i][j];
				t[i][j]=a[i][j];
			}
		}
		
		
		for(int i=n-1; i>=1; i--)
		{
			for(int j=1; j<=i; j++)
			{
				t[i][j]=max(t[i][j]+t[i+1][j],t[i][j]+t[i+1][j+1]);
			}
		}
		cout<<t[1][1]<<endl;
	}
	
	
}
#endif




//3.

#if 0
#include<iostream>
#include<cstring>
using namespace std;
int n,m,maxx,cnt;
char a[1010][1010];
bool vis[1010][1010];
int f[4][2]={{1,0},{-1,0},{0,1},{0,-1}}; 

bool ok(int i,int j)
{
	if(i>=1&&i<=n&&j>=1&&j<=m) 
	{
		
			return 1; 
	}
	
	return 0; 
}


void dfs(int x,int y) 
{
	
		
		if(ok(x,y)==0) 
		{
			return;
		}
		
		if(a[x][y]=='*'&&vis[x][y]==0)
		{
			vis[x][y]=1;
			cnt++;
			
			for(int i=0; i<4; i++)
			{
				int xi=x+f[i][0];
				int yi=y+f[i][1];
				dfs(xi,yi);				
			}
		}
	
	
	
}
	
int main()
{
	while(cin>>m>>n)
	{
		memset(a,0,sizeof(a));
		memset(vis,0,sizeof(vis));
		cnt=0;
		
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=m; j++)
			{
				cin>>a[i][j];	
			}
		}
		
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=n; j++)
			{
				cnt=0;
				if(!vis[i][j]&&ok(i,j)) 
				{
					dfs(i,j);	
		
					if(cnt>maxx)
					{
						maxx=cnt; 
					}
				}	
			}	
		} 
		cout<<maxx<<endl;
	}
	
}
#endif





#if 1
#include<iostream>
#include<cstring>
using namespace std;
int prime[20010];

void fun() 
{
	for(int i=0; i<=20010; i++)
		prime[i]=1;
	
	for(int i=2; i<=20010; i++) 
	{
		if(prime[i]==1)   
		{
			prime[i]=i;
			for(int j=2; i*j<=20010; j++)
			{
				prime[i*j]=i; 
			}                                                                                     
		}     
	}    
}

int main()
{
	int n; 
	fun();
	
	//cout<<prime[38]<<endl;
	while(cin>>n)
	{
		
		int endx=-1,endy=-1;
		
		for(int i=0; i<n; i++)
		{
			int x;
			cin>>x;
			if(prime[x]>endx)
			{
				endx=prime[x];
				endy=x;
			}
		}
		
		cout<<endy<<endl;
	}
	
}

#endif




























































































