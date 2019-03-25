//https://cn.vjudge.net/contest/175955


#if 0
#include<bits/stdc++.h>
using namespace std;
int a[205],b[205],n,k;

int main()
{
	
	cin>>n>>k;
	for(int i=0; i<n; i++)
		cin>>a[i];

		
	for(int i=0; i<k; i++)
		cin>>b[i];
		
	
	
	if(k==1)
	{
		for(int i=0; i<n; i++)
		{
			if(a[i]==0)
			{
				a[i]=b[0];
				break;	
			}	
		}
		bool flag=0;
		int ai[205];
		for(int i=0; i<n; i++)
			ai[i]=a[i];
		sort(a,a+n);
		
		for(int i=0; i<n; i++)
		{
			if(a[i]!=ai[i])
			{
				flag=1;
				break;
			}	
		}
		
		if(flag)
		{
			cout<<"Yes"<<endl;	
		}	
		else
			cout<<"No"<<endl;
	}
	else
		cout<<"Yes"<<endl;
	
}
#endif




#if 1
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[1005],b[1005],a12[5],n,cnt=0;
    cin>>n;
    
    for(int i=0; i<n; i++)
    {
    	cin>>a[i];
	}
	for(int i=0; i<n; i++)
	{
		cin>>b[i];
	}
	
	for(int i=0; i<n; i++)
	{
		if(a[i]!=b[i])
		{
			a12[cnt]=i;
			cnt++;
		}
	}
	
	if(cnt==1)
	{
		for(int i=1; i<n; i++)
		{
			bool flag=0;
			if(i!=a[a12[0]] && i!=b[a12[0]])
			{
				for(int j=1; j<n; j++)
				{
					if(i==a[j])
					{
						flag=1;
						break;
					}
				}
				if(flag==0)
			    {
			    	a[a12[0]]=i;
			   		break;
				}
			}
		}
		for(int i=0; i<n; i++)
			cout<<a[i]<<" ";
		cout<<endl;	 
	}
	else
	{
		int x=a12[0],y=a12[1];
		if(a[x]==a[y] && b[x]==b[y])
		{
			a[x]=b[x];
			for(int i=0; i<n; i++)
			{
				cout<<a[i]<<" "; 
			}
		    cout<<endl;
		}
		else
		if((a[x]==a[y]&&b[x]!=b[y])||(a[x]!=a[y]&&b[x]==b[y]))
		{
			if(a[x]==a[y]&&b[x]!=b[y])
			{
				bool flag=0;
				for(int i=0; i<n; i++)
				{
					if(b[x]==a[i])
					{
						flag=1;
						break;
					}
				}
				if(flag==0)
				{
					a[x]=b[x];
				}
				else
				{
					a[y]=b[y];
				}	
				for(int i=0; i<n; i++)
					cout<<a[i]<<" ";
				cout<<endl;
			}
			else
			if(a[x]!=a[y]&&b[x]==b[y])
			{
				bool flag=0;
				for(int i=0; i<n; i++)
				{
					if(a[x]==b[i])
					{
						flag=1;
						break;
					}
				}
				if(flag==0)
				{
					b[x]=a[x];
				}
				else
				{
					b[y]=a[y];
				}
				
				for(int i=0; i<n; i++)
					cout<<b[i]<<" ";
				cout<<endl;	
			}
			
		}
	
#endif
















