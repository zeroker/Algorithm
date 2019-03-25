
//1  //A. Vladik and Courtesy 
#if 0
#include<bits/stdc++.h>
using namespace std;
int main()
{
	
	int a,b;
	cin>>a>>b;
	
	for(int i=1; ; i++)
	{
		if(i%2==1)
		{
			a-=i;
		}
		else
		{
			b-=i;
		}
		if(a<0)
		{
			cout<<"Vladik"<<endl;
			break;
		}
		
		if(b<0)
		{
			cout<<"Valera"<<endl;
			break;
		}
		
	}
	
}

#endif


//2.
#if 0
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,t,a[10000];
	
while(cin>>n>>t)
{
	
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];	
	}
	
	while(t--)
	{
		
		int l,r,p;
		cin>>l>>r>>p;
		
		
		if(p<l&&p>r)
		{
			cout<<"Yes"<<endl;
		}
		else
		{
			
		int c[10000]={0},d[10000]={0},num=0;
		for(int i=l; i<=r; i++) 
		{
			if(a[i]<a[p])
				num++; 
		}
		
		if(a[p]==a[l+num]) 
		{
			cout<<"Yes"<<endl;
		}
		else
		{
			cout<<"No"<<endl;
		}
	
		
	//	sort(c,c+(r-l+1));
		
	/*	for(int i=0; i<l-1; i++)
		{
			d[i]=a[i];
		}
		
		for(int i=l-1; i<=r-1; i++)
		{
			d[i]=c[i-l+1];
		}
		for(int i=r; i<n; i++)
		{
			d[i]=a[i];
		}
		
	/*	for(int i=0; i<n; i++)
		{
			cout<<d[i];
		}
		cout<<endl;
	*/
	
		
		
		}
	
	}
}
}
#endif
