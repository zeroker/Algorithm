//1002
#if 0
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int MAXN=1000+50;
int a[MAXN][MAXN];
int disa[MAXN];
int n,m,x;

int main()
{
	while(~scanf("%d%d%d",&n,&m,&x)&&n&&m&&x)
	{
		int xi,yi,vi;
		memset(a,0x7f,sizeof(a));
		memset(disa,0x7f,sizeof(disa));
		
		
		for(int i=1; i<=m; i++)
		{
			scanf("%d%d%d",&xi,&yi,&vi);
			a[xi][yi]=vi;  
			  
			if(yi==x)
			{
				disa[xi]=vi;                      
			}
			
		}
			
		for(int k=1; k<=n; k++)
		{
			for(int it=1; it<=n; it++)
			{
				for(int jt=1; jt<=n; jt++)
				{
					if((k!=it&&k!=jt&&it!=jt)&&a[it][k]+a[k][jt]<a[it][jt])
						a[it][jt]=a[it][k]+a[k][jt];	
				}	
			}	
		}		
		
	
		int end=0;	
		
		for(int i=1; i<=n; i++)
		{
			if(i==x)
				continue;
			else
			{
				int s=a[x][i]+disa[i];	 
				if(s>end&&s<0x7f)
					end=s;
			}
			
		}
		

		cout<<end<<endl;
	}

}

#endif




//1002
#if 0                                 
#include<iostream>                                                            
#include<cstring>
#include<cstdio>
using namespace std;
const int MAXN=1000+50;
int a[MAXN][MAXN];
int n,m,x;

int main()
{
	while(~scanf("%d%d%d",&n,&m,&x)&&n&&m&&x)
	{
		int xi,yi,vi;
		memset(a,0x7f,sizeof(a));
		
		for(int i=1; i<=m; i++)
		{
			scanf("%d%d%d",&xi,&yi,&vi);
			a[xi][yi]=vi;  
	
		}
			
		for(int k=1; k<=n; k++)
		{
			for(int it=1; it<=n; it++)
			{
				for(int jt=1; jt<=n; jt++)
				{
					if((k!=it&&k!=jt&&it!=jt)&&a[it][k]+a[k][jt]<a[it][jt])
						a[it][jt]=a[it][k]+a[k][jt];	
				}	
			}	
		}		
		
	
		int end=0;	
		
		for(int i=1; i<=n; i++)
		{
			if(i==x)
				continue;
			else
			{
				int s=a[x][i]+a[i][x];	 
				if(s>end&&s<0x7f)
					end=s;
			}
			
		}
		cout<<end<<endl;
	}

}

#endif


//
#if 0
#include<iostream>
using namespace std;
int main()
{
	
	
}
#endif                   

























































