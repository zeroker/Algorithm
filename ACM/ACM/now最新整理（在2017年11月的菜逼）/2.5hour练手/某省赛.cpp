
#if 0
#include<iostream>
#include<cstring>
using namespace std;
const int MAXN=1e9+10; 

int main()
{
	
    int t,n,m;
	int ki[25];
	int c[25][MAXN];
	int w[25][MAXN];
	int f[MAXN];
	int cas=0;
	cin>>t;
	while(t--) 
	{
		memset(ki,0,sizeof(ki));
		memset(c,0,sizeof(c));
		memset(f,0,sizeof(f));
		memset(w,0,sizeof(w));
		cin>>n>>m;	
		for(int i=1; i<=n; i++)
		{
			cin>>ki[i];
			for(int j=1; j<=ki[i]; j++)
			{
				cin>>w[i][j]>>c[i][j];
			}		
		}	
		
		for(int i=1; i<=n; i++)
		{
			for(int j=m; j>=0; j--)
			{
				int cc=0,ww=0;
				for(int k=0; k<=ki[i]; k++)
				{
					cc+=c[i][k];
					ww+=w[i][k];
					if(j-cc<0) break;
					f[j]=max(f[j],f[j-cc]+ww);
				}
			}
		}
		cout<<f[m]<<endl;	
	}
	
}

#endif





































































