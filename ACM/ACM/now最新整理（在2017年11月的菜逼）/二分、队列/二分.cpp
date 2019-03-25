//Strange fuction  三分 求最值的问题 
#if 0
#include<iostream>
#include<cmath> 
#include<iomanip>
using namespace std;
double x,y;
double fun(double x)
{
	double sum=(6.0*pow(x,7)+8.0*(pow(x,6))+7.0*pow(x,3)+5.0*pow(x,2)-y*x);
	return sum;
}

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		cin>>y;
		double mid,midmid,l=0,r=100;
		while(r-l>1.0e-6)
		{
			mid=(l+r)/2;
			midmid=(mid+r)/2;
			if(fun(mid)<fun(midmid)) //
			{
				r=midmid;
			}
			else
			{
				l=mid;
			}
		}
		
		cout<<fixed<<setprecision(4)<<fun(l)<<endl;
	}
		
}
#endif 



//Can you solve this equation?
#if 0
#include<iostream>
#include<cmath> 
#include<iomanip>
using namespace std;
double x,y;
double fun(double x)
{
	double sum=(8.0*pow(x,4)+7.0*(pow(x,3))+2.0*pow(x,2)+3.0*x+6.0);
	return sum;
}

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		cin>>y;
		
		double mid,midmid,l=0,r=100;
		while(r-l>1.0e-6) 
		{
			mid=(l+r)/2; 
			midmid=(mid+r)/2; 
			if(fabs(fun(mid)-y)<fabs(fun(midmid)-y))  //
			{
				r=midmid;  
			}
			else 
			{
				l=mid; 
			}
		}
		
		int x=r;
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




//这个题可以用二分直接求 
#if 0
#include<bits/stdc++.h>
using namespace std;
double x,y;
double fun(double x)
{
	double sum=(8.0*pow(x,4)+7.0*(pow(x,3))+2.0*pow(x,2)+3.0*x+6.0);
	return sum;
}

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		cin>>y;
		
		double mid,midmid,l=0,r=100;
		while(r-l>1.0e-6) 
		{
			mid=(l+r)/2; 
			 
			if(fun(mid)<y)  //
			{
				l=mid; 
			}
			else 
			{
				r=mid; 
			}
		}
		
		int x=r;
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




//扩大10的六次方倍，精准度 
#if 0
#include<iostream>
#include<iomanip>
using namespace std;
long long a[10010];       
int n,p;           
const double pai=3.14159265358979;

bool fun(long long x)              
{
	long long sum=0;
	for(int i=0; i<n; i++)
	{
		sum+=a[i]/x; 
	}
	
	if(sum>=p)
	{
		return 1;
	}
	else
		return 0;
}

int main() 
{
	int T;
	cin>>T;
	
	while(T--)
	{
		
		cin>>n>>p;
		p+=1; 
		long long l=0,r=0,mid,res=0;
		for(int i=0; i<n; i++)
		{
			int x;
			cin>>x;
			a[i]=pai*x*x*1000000; //5 
			r+=a[i]; 
		}
		
	
		while(r>=l)
		{
			mid=(l+r)/2;
			
			if(fun(mid)) //分多了 
			{
				l=mid+1;
				res=mid;
			}
			else
			{
				r=mid-1;	
			} 
		}
		
		cout<<fixed<<setprecision(4)<<res/1000000.0<<endl;
	}
}

#endif


// Aggressive cows
//有n个点，给出每个点的位置，然后没c个点一组，这一组里的距离的最小值为minn,在若干个这样的组合中求出各个minn值中的最大值 

#if 0
#include<iostream>
#include<cmath>  
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
int a[100005];
int n,c;
int fun(int mid)
{
	int cnt=1,sum=0;
	for(int i=1; i<n; i++)
	{
		if(sum+a[i]-a[i-1]<mid)
		{
			sum+=a[i]-a[i-1];
		}
		else
		{
			sum=0;
			cnt++;	
		}	
	}
	
	if(cnt>=c)
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
	
	while(scanf("%d%d",&n,&c)==2)
	{
		memset(a,0,sizeof(a));
		for(int i=0; i<n; i++)
		{
			scanf("%d",&a[i]);
		}
		
		sort(a,a+n);
		int r=a[n-1]-a[0],l=a[n-1]-a[0];
		
		for(int i=1; i<n; i++)
		{
			if(a[i]-a[i-1]<l)
				l=a[i]-a[i-1];
		}
		
		while(r>=l) 
		{
			int mid=(l+r)/2;     
			if(fun(mid))            //多了 
			{
				l=mid+1;
			}
			else
			{
				r=mid-1;
			}
		}
		
		printf("%d\n",r);
	
	}
}
#endif




//Monthly Expense
#if 0
#include<iostream>
#include<cmath>  
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
int a[100005];
//int b[50],k;
int n,c;
int fun(int mid) 
{
	//cout<<"*************************"<<endl;
	int cnt=0,sum=0;
	for(int i=0; i<n; i++)
	{
		if(sum+a[i]<=mid)
		{
			sum+=a[i];
	//		b[k]=a[i];
	//		k++;
		}
		else
		{
	//		for(int i=0; i<k; i++)
	//			cout<<b[i]<<"  ";
	//		cout<<endl<<"&&&&&&&&&&"<<endl;
	//		k=0;
	//		memset(b,0,sizeof(b));	
			sum=a[i];
			cnt++;	
		}	
	}
	
	if(cnt>=c)                   
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
	
	while(scanf("%d%d",&n,&c)==2) 
	{ 
		int r=0,l=0,mid=0; 
		memset(a,0,sizeof(a));
		for(int i=0; i<n; i++) 
		{
			scanf("%d",&a[i]);
			r+=a[i];
			l=max(l,a[i]);
		}
		
		
		while((r>=l))
		{
			mid=(l+r)/2;     
			if(fun(mid))            //多了 
			{
				l=mid+1;
			}
			else
			{
				r=mid-1;
			}
		}
		
	cout<<l<<endl;
	}
}

#endif 





//Copying Books

#if 0
#include<iostream>
#include<cmath>  
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
int a[100005];
int b[100005],ans[100005],k;
int n,c;
int fun(int mid) 
{
	memset(b,0,sizeof(b));
	
	int cnt=0,sum=0;
	
	for(int i=n; i>=1; i--)
	{
		if(sum+a[i]<=mid&&i>=c-cnt)
		{
			sum+=a[i];

		}
		else
		{	
				
			sum=a[i];
			cnt++;	
			b[i]=1;
		}	
	}
	
	if(cnt+1==c)                   
	{
		for(int i=1; i<=n; i++)
		{
			ans[i]=b[i];
		}
		return 1;	
	}
	else
	{
		return 0;	
	}	
}

int main()
{
	int T;
	cin>>T;
	while(T--) 
	{ 
		scanf("%d%d",&n,&c);
		int r=0,l=0,mid=0; 
		memset(a,0,sizeof(a));
		
		for(int i=1; i<=n; i++) 
		{
			scanf("%d",&a[i]);
			r+=a[i];
			l=max(l,a[i]);
		}
		
		 memset(ans,0,sizeof(ans));
		
		while(r>=l)
		{

			mid=(l+r)/2;     
			if(fun(mid)==1)            //多了 
			{
				r=mid-1;
			}
			else
			{
				l=mid+1;
			}
		}

		for(int i=1; i<n; i++)
		{
			if(ans[i]==1)
			{
				cout<<"/ "<<a[i]<<" ";
			}
			else
			{
				cout<<a[i]<<" ";
			}
		}
		cout<<a[n]<<endl;
				
	}
				
		
}

#endif 





// ac 代码   Copying Books
#if 0
#include<cstdio>
#include<cstring>

int  T,n,c,a[510],b[510],ans[510],left,right,mid;
int check(int max)
{
    int j,num=0,tot=0;
    memset(b,0,sizeof(b));
    for(j=n;j>=1;j--)
    {
        if(tot+a[j]<=max&&j>=c-num)
            tot+=a[j];
        else
        {
            ++num;
            tot=a[j];
            b[j]=1;
        }
    }
    if(num+1==c)
    {
        for(j=1;j<=n;j++)
            ans[j]=b[j];
        return 1;
    }
    else return 0;
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        left=0;
        right=0;
        scanf("%d%d",&n,&c);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            right+=a[i];
            if(a[i]>left) 
				left=a[i];
        }
        memset(ans,0,sizeof(ans));
        
        while(left<=right)
        {                        
            mid=(left+right)/2;
            
            if(check(mid)==1)
                right=mid-1;
            else 
				left=mid+1;
        }
        for(int i=1;i<n;i++)
        {
            if(ans[i]==1)
                printf("%d / ",a[i]);
            else 
				printf("%d ",a[i]);
        }
        printf("%d\n",a[n]);
    }
    return 0;
}

#endif




// 1002  未ac    Expanding Rods
#if 0
#include<iostream>
#include<iomanip>
#include<cmath>
#include<algorithm>
using namespace std;
const double pai=3.1415926535897; 
double x,x1,n,c;
int fun(double a)
{
	double R=x/(2*sin(a)) ;          
	double xx=2.0*a*R;                    
	
	if(xx<=x1)
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
	while(cin>>x>>n>>c)
	{
		if(x==-1&&n==-1&&c==-1)
		{
			break;
		}
		
		x1=(1.0+n*c)*x;                //加热后的长度 
		
		double l=0.00000000001,r=pai/2.0;  //二分角的度数  
		
		         
		if(x==x1)
		{
			cout<<"0.000"<<endl;
			continue;
		}	
		else
		if(x*pai-2*x1<=1e-6)
		{
			cout<<fixed<<setprecision(3)<<x/2<<endl;
			continue;	
		} 
	
		while((r-l)>=1e-8)
		{
			double mid=(r+l)/2.0;  
			if(fun(mid)==1)              //小了 
			{
				l=mid;                 
			}
			else
			{
				r=mid;
			}
		}
		
		
		double R=x/(2*sin(l)); 
		double H=x/(2*tan(l)); 
	
			cout<<fixed<<setprecision(3)<<(R-H)<<endl; 
		
	}                          
	
}
#endif 

//......................................................................................................................
#if 0        //xpanding Rods
#include<iostream>
#include<iomanip>
#include<cmath>
#include<algorithm>
using namespace std;
const double pai=3.1415926535897; 
double x,x1,n,c;
int fun(double h)
{
	
	double R=(pow(x,2)+4*pow(h,2))/(8*h); 
	double O=asin(x/(2*R));               
	double xx=2*O*R;
	if(xx<=x1)
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
	while(cin>>x>>n>>c)
	{
		if(x==-1&&n==-1&&c==-1)
		{
			break;
		}
		
		x1=(1.0+n*c)*x;                //加热后的长度 
		
		double l=0.0,r=x/2;  //二分 高度 的度数  
		
		while((r-l)>=1e-6)
		{
			double mid=(r+l)/2.0;  
			if(fun(mid)==1)              //小了 
			{
				l=mid;                 
			}
			else
			{
				r=mid;
			}
		}
		
		cout<<fixed<<setprecision(3)<<l<<endl;
		
	}                          
	
}
#endif 









//Prime Gap

#if 0
#include<iostream>
#include<cstring>
using namespace std;
const int MAX=1299999;
int a[MAX],k;
bool vis[MAX];

void fun()
{
	memset(vis,1,sizeof(vis));
	for(int i=2; i<=1299709; i++)
	{
		if(vis[i]==1)
		{
			for(int j=2; j*i<=1299709; j++)
			{
				vis[i*j]=0;
			}
		}
	}

	for(int i=1; i<=1299709; i++)
	{
		if(vis[i]==1)
		{
			a[k]=i;
			k++;
		}
	}
	
}


int main()
{
	int n;
	fun();
	

	
	while(cin>>n&&n)
	{
		if(vis[n]==1) 
		{
			cout<<"0"<<endl;	
		}
		else
		{
			for(int i=1; i<k; i++)
			{
				if(a[i]>n&&a[i-1]<n)
				{
					cout<<a[i]-a[i-1]<<endl;
					break;	
				}	
			}	
		}	
	}	
}
#endif


//Drying
#if 0
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;
int a[100010],k,n;

int fun(int mid)
{
	int sum=0;
	
	for(int i=0; i<n; i++)
	{
		if(a[i]<=mid)
		{
			continue;
		}
		else
		{
			sum+=ceil((double)(a[i]-mid)/(k-1));
		}

		if(sum>mid) 
		{
			return 0;	
		}	
	}
		
	return sum<=mid; 
	
}

int main()
{
                                                                           
		cin>>n;
		int l=0,r=0,mid=0,maxx=0;
		for(int i=0; i<n; i++)
		{
			scanf("%d",&a[i]);
			maxx=max(maxx,a[i]);
		} 
		
		scanf("%d",&k);
		
		
		if(k==1)
		{
			printf("%d\n",maxx);
			
		}
		else
		{
		
		r=maxx;
		
		while(r>=l)
		{
			mid=(r+l)/2;
			
			if(fun(mid))   				   //shao
			{
				r=mid-1;
			}
			else
			{
				l=mid+1;
			}
		}
		
		printf("%d\n",l);
		}
}
#endif








































