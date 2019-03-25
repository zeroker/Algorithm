//4.1 1       单调函数 求一次导数就可以  看看斜率 
#if 0
#include<bits/stdc++.h>
using namespace std;
int pre=0,end=100,min=50;
int y;
double f(double x)
{
	return (8*x*x*x*x + 7*x*x*x +2*x*x +3*x +6) ;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		 
	     cin>>y;
	    if(f(0)>y || f(100)<y)
	    {
	    	cout<<"No solution!"<<endl;
	    	continue;
		}
	 
	 double l=0.0,r=100.0,mid=50.0;
	 
	 while(fabs(f(mid)-y)>1e-5)
	 {
	   if(f(mid)>y)
	   {
	     r=mid;
	     mid=(r+l)/2; 	
	   }	
	    else
	   if(f(mid)<y) 
	   {
	   	l=mid;
	   	mid=(r+l)/2;
	   }
	   		
	 }	
	cout<<fixed<<setprecision(4)<<mid<<endl;	
	     
	}
	
}
#endif

//4.12 二次函数求最小值  开口上的 二次函数 ， 先找出导数的零点， 然后带入x  
#if 0
#include<bits/stdc++.h>
double f(double x, double y)
{
	return(42*pow(x,6) + 48*pow(x,5) + 21*pow(x,2) + 10*x -y);
}
double fun(double x,double y)
{
	return (6*pow(x,7) + 8*pow(x,6) + 7*pow(x,3) + 5*x*x -y*x );
}
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	  double l=0.0,r=100.0,mid;
	  double y;
	  cin>>y;	
	    while(fabs(l-r)>1e-6)
		{
			mid=(r+l)/2;
			
			if(f(mid,y)>0)
			r=mid;
			else
			l=mid;
		}
		cout<<fixed<<setprecision(4)<<fun(mid,y)<<endl;
	} 
	
}
#endif 


//4.13
#if 0              //WA 三个数组 分别找一个数，看看这三个数的和是不是 x      有没有 wa? ~~~  
#include<bits/stdc++.h>
int li[501],ni[501],mi[501],ln[250005];
using namespace std;
bool fun(int r,int x)
{
  	int l=0,mid;
  	
  	while(l<=r)
  	{
  	 mid=(r+l)/2;
  	 
	 if(ln[mid]==x)
	  return 1;
	  else
	 if(ln[mid]>x)
	  r=mid-1;
	  else 
	  l=mid+1;
	 	
	}
  	return 0;
}

int main()
{
	int l,n,m,ans=1;
	while(cin>>l>>n>>m )
	{ 
		for(int i=0; i<l; i++)
		 cin>>li[i];
		for(int i=0; i<n; i++)
		  cin>>ni[i];
		for(int i=0; i<m; i++)
		  cin>>mi[i]; 
		  sort(mi,mi+m);  
		
		int k=0; 
		
		for(int i=0; i<l; i++)
		 for(int j=0; j<n; j++)
		   ln[k++]=li[i]+ni[j];
		 sort(ln,ln+k)  ;
		 k=unique(ln,ln+k)-ln;
		   
		 int t,flag;
		 cin>>t;
		 cout<<"Case "<<ans++<<":"<<endl;
		 while(t--)
		 {
		   int x;
		   cin>>x;
		   flag=0;
		   
		   if(x>ln[k-1]+mi[m-1] || x<ln[0]+mi[0])
		   {
		   	cout<<"NO"<<endl;
		   	continue;
		   }
		   
		   for(int i=0; i<m; i++)
		   {
		   	if(fun(k-1,x-mi[i])) 
		   	{
			   
			   flag=1;
			   break;
		    }
		   }
		   
		   if(flag==1)
		   cout<<"YES"<<endl;
		   else
		   cout<<"NO"<<endl;
		  	
		 }  
		
	}
	
}
#endif

//tie          重要的是思路啊 
#if 0
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

__int64 a[505],b[505],c[505],la,lb,lc;
__int64 sum[505*505],len;

int bin(__int64 x)
{
    __int64 l = 0,r = len-1;
    while(l<=r)
    {
        __int64 mid = (l+r)>>1;
        if(sum[mid] == x)
            return 1;
        else if(sum[mid]>x)
            r = mid-1;
        else
            l = mid+1;
    }
    return 0;
}

int main()
{
    __int64 m,s,cas = 1,i,j,k;
    while(~scanf("%I64d%I64d%I64d",&la,&lb,&lc))
    {
        for(i = 0; i<la; i++)
            scanf("%I64d",&a[i]);
        for(i = 0; i<lb; i++)
            scanf("%I64d",&b[i]);
        for(i = 0; i<lc; i++)
            scanf("%I64d",&c[i]);
        sort(c,c+lc);
        len = 0;
        for(i = 0; i<la; i++)
        {
            for(j = 0; j<lb; j++)
            {
               sum[len++] = a[i]+b[j];
            }
        }
        sort(sum,sum+len);
        len = unique(sum,sum+len)-sum;
        scanf("%I64d",&m);
        printf("Case %I64d:\n",cas++);
        while(m--)
        {
            scanf("%I64d",&s);
            if(s>sum[len-1]+c[lc-1] || s<sum[0]+c[0])
            {
                printf("NO\n");
                continue;
            }
            __int64 flag = 0;
            for(i = 0;i<lc;i++)
            {
                int kk = s-c[i];
                if(bin(kk))
                {
                    flag = 1;
                    break;
                }
            }
            if(flag)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }

    return 0;
}

#endif

//4.14 Cup
#if 0     //求 圆台的 高度              qiu的公式参照 百度~~~ 数学啊，代码实现能力~！ 
#include<bits/stdc++.h>
#define pi acos(-1.0)
using namespace std;
double r,R,H,V,mid;
double fun(double x)
{
	double u=x/H*(R-r)+r;
	return pi/3*(r*r+r*u+u*u)*x;
}
int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
	
	 cin>>r>>R>>H>>V;
	 
	 double l=100,f=0;
	 	while(l-f>1e-9)
		{
			mid=(l+f)/2;
			 if(fabs(fun(mid)-V) <= 1e-9)
			break;
		    else 
			 if(fun(mid) > V)
			l=mid-1e-9;
			else 
			f=mid+1e-9; 	
			
		}
		cout<<fixed<<setprecision(6)<<mid<<endl;
	}
	
	
}
#endif 

//4.15 我只能说这是一个特好的 题 和一个 很nice的代码 
#if 0
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	 int n;
	 cin>>n;
	 int i=1;
	 while(n>i)
	 {
	 	n-=i;
	 	i++;
	 }
	 
	 n%=9;
	 if(n==0)
	 n=9;
	 
	 cout<<n<<endl;
	 	
	} 
	
}
#endif 



//4.16
#if 1
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int ax,ay,bx,by,cx,cy,dx,dy;
		cin>>ax>>ay>>bx>>by>>cx>>cy>>dx>>dy;
		
		int p,q,r;
		cin>>p>>q>>r;
		double ab,bc,cd;
		ab=sqrt(pow(ax-bx,2)+pow(ay-by,2));
		bc=sqrt(pow(cx-bx,2)+pow(cy-by,2));
		cd=sqrt(pow(cx-dx,2)+pow(cy-dy,2));
		
		
		double sum=ab/p+bc/r+cd/q ;
	    double min=sum;                          //abcd
	    
	    double ad;
	    ad=sqrt(pow(ax-dx,2)+pow(ay-dy,2));     //ad
	    sum=ad/r;
	    if(sum<min)
	    min=sum;
	    
	    double ac;
	    ac=sqrt(pow(ax-cx,2)+pow(ay-cy,2));  //acd
	    sum=ac/r+cd/q;
	    if(sum<min)
	    min=sum;
	    
	    
	    double bd;
	    bd=sqrt(pow(bx-dx,2)+pow(by-dy,2));
	    sum=(ac+bd)/r;                       //acbd
	     if(sum<min)
	    min=sum;
	    
	     sum=(ab/q)+bd/r;
		  if(sum<min)
	      min=sum;                                     //abd
	    
	    
	    
	    
	    
	    cout<<min<<endl;
	    
	}
}
#endif 























