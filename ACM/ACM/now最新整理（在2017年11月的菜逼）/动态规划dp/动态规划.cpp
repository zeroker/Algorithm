//1. 数塔 求路径   很6 的一个方法   （算法设计） 
#if 0
#include<bits/stdc++.h>
using  namespace std;
int main()
{
	int a[51][51][3]={0};
	
	int n;
	cin>>n;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=i; j++)
		{
			cin>>a[i][j][0];
			a[i][j][1]=a[i][j][0];
		}	
	
	for(int i=n-1; i>=1; i--)
	{
		for(int j=1; j<=i; j++)
		{
		 	if(a[i+1][j][1]>a[i+1][j+1][1])
			{
				a[i][j][1]=a[i][j][1]+a[i+1][j][1];
				a[i][j][2]=0;
		    }	 
			else
			{
				a[i][j][1]=a[i][j][1]+a[i+1][j+1][1];
				a[i][j][2]=1;
			}			
		}
		
	}	
	
	cout<<"max="<<a[1][1][1]<<endl;	 
	int y=1;
	for(int x=1; x<n; x++)
	{
	cout<<a[x][y][0]<<"->";
	y+=a[x][y][2];	
	} 
	cout<<a[n][y][1]<<endl;
	
}
#endif 



//数塔顺推 
#if 0
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[50][50]={0},b[50][50]={0};
	int n;
	cin>>n;
	
	for(int i=1; i<=n; i++)
		for(int j=1; j<=i; j++)
	 	{
	 		cin>>a[i][j];
			b[i][j]=a[i][j];	
		}
		
	for(int i=2; i<=n; i++)
		for(int j=1; j<=i; j++)
		{
			if(b[i-1][j]>b[i-1][j-1])       //必须要b[i-1][j-1] 
				b[i][j]+=b[i-1][j];
			else
				b[i][j]+=b[i-1][j-1];	
		}
		
	int max=0; 
	for(int i=1; i<=n; i++)
		for(int j=1; j<=i; j++)
			if(b[i][j]>max)
				max=b[i][j];
	
	cout<<max<<endl;				
		
		
}
#endif 


 














































