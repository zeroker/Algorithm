
// peime 算法    最小生成树问题 

// 题目     Truck History 
#if 0
#include<bits/stdc++.h>
using namespace std;
int n,mapp[100][100],minn[100];
bool u[100];
void prime()
{
	memset(minn,0x7f,sizeof(minn));
	minn[1]=0;
	
	for(int i=1; i<=n; i++)
	{
		int k=0;
		for(int j=1; j<=n; j++)
		{
			if(!u[j]&&minn[k]>minn[j])
				k=j;
		}
		u[k]=1;
		
		for(int j=1; j<=n; j++)
		{
			if(!u[j]&&minn[j]>mapp[k][j])
				minn[j]=mapp[k][j];
		}
		
	}
	
	int sum=0;
	for(int i=1; i<=n; i++)
	{
		sum+=minn[i];
	}
	
	cout<<sum<<endl;
}


int main()
{
	while(cin>>n&&n)
	{
		string s[100];
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
					{
						x++;
					}
				}
				mapp[i][j]=x;
			}
		}
		
		prime();
		
	}	
}
#endif

