//pei
#if 0
#include<bits/stdc++.h>
using namespace std;
const double pai=3.14159265358979;
double n,k,a[50];

int fun(double x)
{
	int num=0;
	for(int i=0; i<n; i++)
	{
		num+=a[i]/x;
	}
	
	if(num>=k)
		return 1;
	return  0;		
}


int main()
{
	while(cin>>n>>k)
	{
		k+=1; 
		memset(a,0,sizeof(a));
		double l=0,r=0,mid=0;
		for(int i=0; i<n; i++)
		{
			cin>>a[i];
			a[i]=pai*a[i]*a[i];	
			r+=a[i];
		} 
			while((r-l)>=1e-6)
			{
				mid=(r+l)/2.0;
				if(fun(mid)) 
				{
					l=mid;
				}
				else
				{
					r=mid;
				}
			}
			cout<<fixed<<setprecision(4)<<l<<endl;
	}	
	
}
#endif
//给Y 求 x 
#if 0
#include<bits/stdc++.h>
using namespace std;
int y;

int fun(double x)
{
	double sum=8*pow(x,4)+7*pow(x,3)+2*pow(x,2)+3*x+6;
	if(sum>=y)            //
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	while(cin>>y)
	{
		double l=0,r=100,mid=0;
		while((r-l)>=1e-6)
		{
			mid=(l+r)/2.0;
			if(fun(mid))
			{
				r=mid;
			}
			else
			{
				l=mid;
			}
		}
		
		int x=l;
		if(x>0&&x<100)
		{
			cout<<fixed<<setprecision(4)<<r<<endl;
		}
		else
		{
			cout<<"No solution!"<<endl;
		}
	}
	
	
}

#endif


//三分
//求最小值的值 

#if 0
#include<bits/stdc++.h>
using namespace std;
int x,y;
double fun(double x)
{
	double sum=6*pow(x,7)+8*pow(x,6)+7*pow(x,3)+5*pow(x,2)-y*x;
	return sum;
}

int main()
{
	while(cin>>y)
	{
		double l=0,r=100,mid=0,midmid=0;
		while((r-l)>=1e-6)
		{
			mid=(l+r)/2;
			midmid=(mid+r)/2;
			
			if(fun(mid)<fun(midmid))
			{
				r=midmid;
			}
			else
			{
				l=mid;
			}
			
		}
		
		cout<<fun(r)<<endl;	
	}	
	
} 

#endif 





//最大化最小值问题 
#if 0
#include<bits/stdc++.h>
using namespace std;
int n,c,a[50];
int fun(int x)
{
	int sum=0,num=1;
	for(int i=1; i<n; i++)
	{
		if(sum+a[i]-a[i-1]<x)
		{
			sum+=a[i]-a[i-1]; 
			
		}
		else
		{
			sum=0;	
			num++;                    //
		}
	}
	
	if(num>=c)
	{
		return 1;
	}
	return 0;
	
	
}
int main()
{
	while(cin>>n>>c)
	{
		memset(a,0,sizeof(a));
		int l=0,r=0,mid=0;
		for(int i=0; i<n; i++)
		{
			cin>>a[i];
		
		}
		sort(a,a+n);
		r=a[n-1]-a[0];
		l=a[n-1]-a[0];
		
		for(int i=1; i<n; i++)
		{
			l=min(l,a[i]-a[i-1]);
		}
		
		while(r>=l)
		{
			mid=(r+l)/2;
			if(fun(mid))
			{
				l=mid+1;
			}
			else
			{
				r=mid-1;
			}
		}
		cout<<r<<endl;
	}
}
#endif 



















































