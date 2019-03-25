// 单调队列  Sliding Window             未ac 但是经典的做法 
#if 0
#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
const int Max=1e6+10;
int a[Max];
int quee[Max];  
int b[Max];  
int n,k;
void minn()
{
		int tail=1,head=1;
	
	for(int i=0; i<k-1; i++)
	{
		while(tail>=head&&a[quee[tail]]>=a[i])  
		{
			tail--;
		}	
		tail++;
		quee[tail]=i; 
	}
	
	for(int i=k-1; i<n; i++)
	{
		while(tail>=head&&a[quee[tail]]>=a[i])
			tail--;
		tail++;
		quee[tail]=i;
			
		while(quee[head]<i-k+1)
		{
			head++;
		}
		
	
		printf("%d ",a[quee[head]]);
	
	}
	
	printf("\n");

}

void maxx()
{
	
	int tail=1,head=1,l=1;  
       
	for(int i=0; i<k-1; i++) 
	{
		while(tail>=head&&a[quee[tail]]<=a[i])
		{
			tail--;
		}
		tail++;
		quee[tail]=i;

	}
	
	for(int i=k-1; i<n; i++)
	{
		while(tail>=head&&a[quee[tail]]<=a[i])
		{
			tail--;
		}
		tail++;
		quee[tail]=i;
		
		while(quee[head]<i-k+1)
		{
			head++;
		}
		
	
		printf("%d ",a[quee[head]]);
		
	}

	printf("\n");
	
	
}


int main()
{
	
	scanf("%d%d",&n,&k);
	for(int i=0; i<n; i++)
		scanf("%d",&a[i]);
	
	minn();
	maxx();
	
}

#endif 


// 空间换时间 多开了两个数组  ac 
#if 0
#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
const int Max=1000005;
int N,M,a[Max],b[Max],c[Max],d[Max];

void maxx()
{
    int i,head,tail,l;
    l=0;tail=-1;head=0;
    
    for(i=1;i<=M;i++)
    {
        while(tail>=0&&a[i]>=b[tail]) 
			tail--;

       b[++tail]=a[i];                                                                                                  
        c[tail]=i;
    }
    
    d[l++]=b[0];
    for(i=M+1;i<=N;i++)
    {
		if(c[head]<i-M+1) 
			head++;
        while(tail>=head&&a[i]>=b[tail]) 
			tail--;
        b[++tail]=a[i];
        c[tail]=i;
        d[l++]=b[head];
    }
    for(i=0;i<l-1;i++)
        cout<<d[i]<<" ";
    cout<<d[l-1]<<endl;
}
void minn()
{
    memset(c,0,sizeof(c));
    memset(b,0,sizeof(b));
    memset(d,0,sizeof(d));
    
    int i,head,tail,l;
    l=0;tail=-1;head=0;
    
    for(i=1;i<=M;i++)
    {
        while(tail>=0&&a[i]<=b[tail])
			tail--;
       b[++tail]=a[i];
        c[tail]=i;
    }
    d[l++]=b[0];
    
    for(i=M+1;i<=N;i++)
    {
        if(c[head]<i-M+1) 
			head++;
        while(tail>=head&&a[i]<=b[tail])
			 tail--;
        b[++tail]=a[i];
        c[tail]=i;
        d[l++]=b[head];
    }
    for(i=0;i<l-1;i++)
        cout<<d[i]<<" ";
    cout<<d[l-1]<<endl;
}
int main()
{
   while(cin>>N>>M)
   {
       for(int i=1;i<=N;i++)								
        scanf("%d",&a[i]);
       minn();
       maxx();
   }
   return 0;
}

#endif



// Largest Rectangle in a Histogram
#if 0
#include<iostream>
#include<stdio.h> 
using namespace std;
const int Max=100000+10;
unsigned long long int a[Max],l[Max],r[Max],q[Max];

int main()
{
	int n;
	while(scanf("%d",&n))
	{
		if(n==0)
			break; 
		for(int i=1; i<=n; i++)
		{
			scanf("%I64d",&a[i]);
			l[i]=r[i]=i;	
		}
		
		int t=0;
		for(int i=1; i<=n; i++)
		{
			
			while(t&&a[i]<=a[q[t]])    //shangsheng 
				t--;
			if(t==0)
				l[i]=1;	
			else	
				l[i]=q[t]+1;
					
			q[++t]=i;
		}
		
		t=0;
		for(int i=n; i>=1; i--)
		{
			while(t&&a[i]<=a[q[t]])
				t--;	
		
			if(t==0)
			{
				r[i]=n;	
			}		
			else
			{
				r[i]=q[t]-1;	
			}
			
			q[++t]=i;
		}
		
		unsigned long long int maxx=0;
		for(int i=1; i<=n; i++)
		{
			unsigned long long int temp=(r[i]-l[i]+1)*a[i];
			if(maxx<temp)
				maxx=temp;	
		}	
		printf("%I64d\n",maxx);    
	     
	}	
	
}


#endif 






//   Feel Good
#if 0
#include<iostream>
#include<stdio.h> 
using namespace std;
const int Max=100000+10;
unsigned long long int a[Max],l[Max],r[Max],q[Max],man[Max];

int main()
{
		int n;
	
		while(cin>>n&&n) 
		{
		bool flagg=0;
		             
		for(int i=1; i<=n; i++)
		{
			scanf("%I64d",&a[i]);
			l[i]=r[i]=i;
			man[i]=man[i-1]+a[i];
			if(flagg==0)
			{
				if(man[i]>0)	
					flagg=1;
			}	
		}
		
		int t=0;
		for(int i=1; i<=n; i++)
		{
			
			while(t&&a[i]<=a[q[t]])    //下降 
				t--;
			if(t==0)                       
				l[i]=1;	
			else	
				l[i]=q[t]+1;
					
			q[++t]=i;
		}
		
		t=0;
		for(int i=n; i>=1; i--)
		{
			while(t&&a[i]<=a[q[t]])   
				t--;	
		
			if(t==0)
			{
				r[i]=n;	
			}		
			else
			{
				r[i]=q[t]-1;	
			}
			
			q[++t]=i;
		}
		
		if(flagg==0)
		{
			printf("0\n1 %d\n",n);
			continue;
		}
		
		unsigned long long int maxx=0;
		int flag=0;
		for(int i=1; i<=n; i++) 
		{
			unsigned long long int sum=0; 
			sum=man[r[i]]-man[l[i]]+a[l[i]];
			
			unsigned long long int temp=sum*a[i];
			//cout<<temp<<endl;
			if(maxx<temp)
			{
				maxx=temp;
				flag=i;
			}
		}	
		printf("%I64d\n",maxx);  
		printf("%I64d %I64d\n",l[flag],r[flag]);    
		
		
	
		    
		}
	
}


#endif 




//1011	Terrible Sets				                                                      
#if 0
#include<iostream>
#include<stdio.h> 
using namespace std;
const int Max=100000+10;
unsigned long long int a[Max],l[Max],r[Max],q[Max],w[Max];                       

int main() 
{
		int n;  
	
		while(cin>>n&&n!=-1)                      
		{ 
	
		             
		for(int i=1; i<=n; i++)   
		{	
			
			scanf("%I64d",&w[i]);         
			scanf("%I64d",&a[i]);      
			    
			l[i]=r[i]=i;      
			   
			
		}
		
	
		int t=0;
		for(int i=1; i<=n; i++)
		{
			
			while(t&&a[i]<=a[q[t]])    //下降 
				t--;
			if(t==0)                       
				l[i]=1;	
			else	
				l[i]=q[t]+1;
					
			q[++t]=i;
		}
		
		t=0;
		for(int i=n; i>=1; i--)
		{
			while(t&&a[i]<=a[q[t]])   
				t--;	
		
			if(t==0)
			{
				r[i]=n;	
			}		
			else
			{
				r[i]=q[t]-1;	
			}
			
			q[++t]=i;
		}
		
	
		
		unsigned long long int maxx=0;
		
		for(int i=1; i<=n; i++) 
		{
			unsigned long long int sum=0; 
			
			for(int j=l[i]; j<=r[i]; j++)
				sum+=w[j];
				
			unsigned long long int temp=0;
			temp=sum*a[i];
	
			if(maxx<temp)
			{
				maxx=temp;
				
			}
		
		}	
		
	
			
		printf("%I64d\n",maxx);  
	   	
		
		
		
		    
		}
	
}


#endif 


//Bad Hair Day
#if 0
#include<iostream>
#include<stdio.h>
using namespace std;
#define  MAX 80000+10
#define LL long long
LL  q[MAX];

int main()
{
		int n;		
		scanf("%d",&n);
		
		LL  sum=0,x;
		int head=0,tail=-1;
		
		for(int i=1; i<=n ;i++)
		{
			scanf("%I64d",&x);
			
			while(tail>=head&&x>=q[tail]) 
				tail--;
			
			q[++tail]=x;	
			sum+=tail;
		}
		
		
	printf("%I64d\n",sum);

	
}

#endif


//1005	Sticks Problem       

#if 0
#include<iostream>
#include<cstdio>
using namespace std;
int a[50010],q[50010],lminn[50010],l[50010];
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int t=0,maxx=0;
	for(int i=1; i<=n; i++)
		{
			scanf("%d",&a[i]);
		}
		
		for(int i=1; i<=n; i++)
		{
			l[i]=i;
			while(t>0&&a[i]>a[q[i]]) 
				t--;

			if(t==0)
			{
				l[i]=1;
			}
			else
				l[i]=q[t];

			q[++t]=i;
		}


		 for(int i=1; i<=n; i++)
		 {
			int minn=0x7fffffff;
			for(int j=l[i]; j<=i; j++)
			{
				if(a[j]<minn)
				{
					minn=a[j];
					lminn[i]=j;
				}
			} 
		 }
                             
		for(int i=1; i<=n; i++)
		{             
			int cha=i-lminn[i];
			if(maxx<cha)
				maxx=cha;                  
		}

		if(maxx==0)
			
			printf("-1\n");
		else
			printf("%d\n",maxx);
			
			
			/*for(int i=1; i<=n; i++)
			{
				cout<<l[i]<<"-->"<<i<<endl;
			}*/
			
		}

}
#endif





#if 1
#include<iostream>
#include<cstdio>
using namespace std;
#define long long int ll
int n;
int a[50005],q[50005],r[50005];
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1; i<=n; i++)
            scanf("%d",&a[i]);
            
        int t=1; q[1]=n+1;
        for(int i=n;i>=1;i--)  
        {
            while(t>=1&&a[q[t]]>a[i]) 
				t--;
			 r[i]=q[t]-1-i;
			q[++t]=i;	
        }
        int maxn,p,cha=0;
        for(int i=1; i<=n; i+=p+1)
        {
            maxn=p=-1;
            
            for(int j=0; j<=r[i]; j++) 
            {
                if(a[i+j]>maxn) 
                {
                	 p=j; 
                    maxn=a[i+j]; 
                }
            }
            
            if(cha<p)
				cha=p;
        }
        if(cha!=0) 
			printf("%d\n",cha);
        else
			 printf("-1\n");
    }
    
}
#endif







#if 0
#include<iostream>
#include<stdio.h> 
using namespace std;
const int Max=100000+10;
unsigned long long int a[Max],l[Max],r[Max],q[Max],cha[Max];

int main()
{
	int n;
	while(scanf("%d",&n))
	{
		if(n==0)
			break; 
		for(int i=1; i<=n; i++)
		{
			scanf("%I64d",&a[i]);
			l[i]=r[i]=i;	
		}
		
		int t=0;
		for(int i=1; i<=n; i++)
		{
			
			while(t&&a[i]>=a[q[t]])    //下降 
				t--;
			if(t==0)
				l[i]=1;	
			else	
				l[i]=q[t]+1;
					
			q[++t]=i;
		}
		
		t=0;
		for(int i=n; i>=1; i--)
		{
			while(t&&a[i]<=a[q[t]])
				t--;	
		
			if(t==0)
			{
				r[i]=n;	
			}		
			else
			{
				r[i]=q[t]-1;	
			}
			
			q[++t]=i;
		}
		
		for(int i=1; i<=n; i++)
		{             
			cha[i]=r[i]-l[i]; 
			cout<<cha[i]<<endl;                
		}
		
		unsigned long long int abc=0,flago=0;
		for(int i=1; i<=n; i++)
	     {
	     	if(l[i]!=i&&r[i]!=i)
			 {
			 	abc=max(cha[i],abc);		
			 }
			
			if(abc>0)
				flago=1; 
		 }
		 
		 if(flago)
		 {
		 	cout<<abc<<endl;
		 }
		 else
		 	cout<<"-1"<<endl;
	}	
	
}


#endif 


// TLE  Largest Submatrix of All 1’s              为AC 
#if 0
#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
int a[2005][2005],t[2005][2005];
int n,m;

int main()
{
	
	while(scanf("%d%d",&n,&m))
	{
		bool flag=0;
		int cnt=0;
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=m; j++)
			{
				scanf("%d",&a[i][j]);
				t[i][j]=a[i][j];
				if(a[i][j]==0)
				{
					cnt++;
				}
			}
		}
		
		if(cnt==n*m)
		{
			cout<<"-1"<<endl;
			continue;
		}
		else
		{
			/*for(int i=2; i<=n; i++)
			{
				for(int j=1; j<=m; j++)
				{
					if(t[i][j]==1)
					{
						t[i][j]+=t[i-1][j];
					}
				}
	  		} */
			
			int maxxx=0;
			int tail=0; int q[2005]={0},l[2005],r[2005],s[2005]={0};
			
			for(int i=1; i<=m; i++)
				r[i]=l[i]=i;
				
			for(int i=1; i<=n; i++)
			{
				int maxx=0;
				tail=0;
				memset(r,0,sizeof(r));
				memset(l,0,sizeof(l));
				
				for(int j=1; j<=m; j++)
				{
					while(tail&&t[i][j]<=t[i][q[tail]])
						tail--;
						
					if(tail==0)
					{
						l[j]=1;	
					}	
					else
						l[j]=q[tail]+1;
						
					q[++tail]=j;	
				}
				
				tail=0;
				for(int j=m; j>0; j--)
				{
					while(tail&&t[i][j]<=t[i][q[tail]])
						tail--;
				
				
					if(tail==0)
						r[j]=m;
					else
						r[j]=q[tail]-1;
					q[++tail]=j;
				
				}
				
				for(int j=1; j<=m; j++) 
				{
					int temp=(r[j]-l[j]+1)*t[i][j];
					if(maxx<temp)
						maxx=temp;		
				}	
		
				if(maxx>maxxx)
					maxxx=maxx;
			}
			printf("%d",maxxx);
		
			
		}
		
	}
}

#endif 






//  Largest Submatrix of All 1’s           AC代码 
#if 0
#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
int main()
{
    int a[2010], t[2010],l[2010],r[2010],q[2010];
    
    int N,M;
    int Max;
    while(~scanf("%d%d",&N,&M) && N && M)
    {
        Max=0;
        memset(a,0,sizeof(a));
        memset(t,0,sizeof(t));
        memset(q,0,sizeof(q));
        for(int k=1;k<=M;k++)
        {
            for(int j=1;j<=N;j++)
            {
                scanf("%d",&a[j]);
                if(a[j]==0)
                    t[j]=0;
                else
                    t[j]+=a[j];
                l[j]=j;
                r[j]=j;
            }
		int top=0;
		for(int i=1;i<=N;i++)   //向左找
		{
			while(top && t[i]<=t[q[top]])
                top--;
            if(top==0)
                l[i]=1;
            else
                l[i]=q[top]+1;//s[top]存的数的值肯定是比a[i]小的，所以地s[top]+1个位置即为所求
            q[++top]=i;
		}
		top=0;
		for(int i=N;i>=1;i--)
		{
			while(top && t[i]<=t[q[top]])
                top--;
            if(top==0)
                r[i]=N;
            else
                r[i]=q[top]-1;
            q[++top]=i;
		}
		int maxn=0;
		int area;
		for(int i=1;i<=N;i++)
		{
			area=t[i]*(r[i]-l[i]+1);
			if(maxn<area)
				maxn=area;
		}
		if(Max<maxn)
            Max=maxn;
        }
        printf("%d\n",Max);
    }

    return 0;
} 
#endif























 

