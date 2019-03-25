//3.21 最大连续子序列   max sum   但是啊  这个是要求开始和终止的下标的 
#if 0  
#include<bits/stdc++.h>
using namespace std;
int a[100001],dp[100001]; 
int main()
{
	int t,cas=1; 
	cin>>t;
	while(t--)
	{
	
	int max,pre,end;
	int n;
	bool flag=0;
	cin>>n;
	for(int i=1; i<=n ;i++)
	cin>>a[i];
  
	if(a[1]<0) dp[1]=0;
	else dp[1]=a[1]; 
	
	max=dp[1];
   for(int i=1; i<=n; i++)
   {
   	if(dp[i-1]+a[i]>0) 
   	dp[i]=dp[i-1]+a[i];
   	else {
   		dp[i]=0;
   		pre=i;
	   }
   	
   	if(max<dp[i]) {
   		max=dp[i];
   		end=i;
	   }
   }
   

   
   if(!flag) 
   pre=1;
   
   
cout<<"Case "<<cas<<":"<<endl<<max<<" "<<pre<<" "<<end<<endl;
if(t>=1) cout<<endl;
	
}
}
#endif



//2.commend 字符串                               //http://blog.csdn.net/a_eagle/article/details/7213236
//F[i][j]=F[i-1][j-1]+1；（a[i]==b[j]）
//F[i][j]=max(F[i-1][j],F[i][j-1])(a[i]!=b[j]);
#if 0
#include<bits/stdc++.h>
using namespace std;
int f[1001][1001];
int main()
{
	char a[1001],b[1001];
	
	while(cin>>a>>b)
	{
		int lena,lenb;
		lena=strlen(a);
		lenb=strlen(b);
		
		for(int i=0; i<=lena; i++)
		f[i][0]=0;
		for(int i=0; i<=lenb; i++)
		f[0][i]=0;
		
		for(int i=1; i<=lena; i++)
		 for(int j=1; j<=lenb; j++)
		 {
		 	if(a[i-1]==b[j-1])
		 	f[i][j]=f[i-1][j-1]+1;
		 	 else
		 	
			{
			  f[i][j]=f[i-1][j]>f[i][j-1]?f[i-1][j]:f[i][j-1];	
			}  
		 	
		 }
		 
		 cout<<f[lena][lenb]<<endl;
	}
	return 0;
}
#endif 




#if 0  // 最大连续子序列和 
#include<bits/stdc++.h>
using namespace std;
int a[1001],t[1001];
int main()

{
	int n;
	while(cin>>n && n)
	{
		int maxlen=0;
		memset(a,0,sizeof(a));
		memset(t,0,sizeof(t));
		
		for(int i=0; i<n; i++)
		cin>>a[i];
		
		t[0]=a[0]; maxlen=t[0];
		
		for(int i=1; i<n; i++)
		{ 
		    int max=0;
			for(int j=0; j<i; j++)
			{
				if(a[i]>a[j] && t[j]>max) 
				max=t[j];
			}
			t[i]=max+a[i];
			
			if(t[i]>maxlen)
			maxlen=t[i];
			
		}
		
		cout<<maxlen<<endl;
	}
	
}

#endif

//3.25
//丑数 需要手动计算到a[15]加强理解 
// 1, 3,5,7
#if 0
#include<bits/stdc++.h>
#define min(a,b) (a<b?a:b)
#define min4(a,b,c,d) min(min(a,b),min(c,d))
using namespace std;
int main()
{
  int a[5850];
  a[1]=1;
  int p1,p2,p3,p4;
  p1=p2=p3=p4=1;	
  
  for(int i=2; i<5845; i++)
  {
  	a[i]=min4(2*a[p1],3*a[p2],5*a[p3],7*a[p4]);
  	
  	if(a[i]==2*a[p1])
  	p1++;
  	 if(a[i]==3*a[p2])
  	p2++; 
	 if(a[i]==5*a[p3])
	p3++;
	 if(a[i]==7*a[p4])
	p4++;    
  }
  
  int n;
 
  while(scanf("%d",&n) && n)
  {
  	 if(n%10==1 && n%100!=11)
  	printf("The %dst humble number is ",n);
  	else
     if(n%10==2 && n%100!=12)
	printf("The %dnd humble number is ",n);
	else
	 if(n%10==3 && n%100!=13)
	printf("The %drd humble number is ",n);
	else
	printf("The %dth humble number is ",n);
    printf("%d.\n",a[n]);
  }
	
}
#endif

//3.24


#if 0
#include<bits/stdc++.h>
using namespace std;

struct mas
{
int weigt;
int sped;
int key;
};

bool cmp(mas x,mas y)
 {
if(x.weigt!=y.weigt)
return x.weigt<y.weigt;
else
return x.sped>y.sped;
 }

mas g[1100];
int f[1100];

int main()
{      
int x,y;
int i=1;
while(scanf("%d%d",&x,&y)!=EOF)
{
g[i].weigt=x;
g[i].sped=y;
g[i].key=i;
i++;
}
memset(f,0,sizeof(f));
sort(g+1,g+i,cmp);// 先对数据处理下，排序。


f[i-1]=1;
for(int j=i-2;j>=0;j--)
{
int max=0;
for(int k=j+1;k<i;k++)
{
if(g[k].sped<g[j].sped&&g[k].weigt>g[j].weigt&&max<f[k])
{
max=f[k];
}
}
f[j]=max+1;
}
int max1=0;
int pi;
for(int j=1;j<i;j++)
{
if(f[j]>max1)  
{
pi=j;  
max1=f[j];
}
}
printf("%d\n",max1);
for(int j=pi;j<i;j++)
{
if(f[j]==max1)
{
printf("%d\n",g[j].key);
max1--;
}
if(max1==0)
break;
}
return 0;
}
#endif



//3.27
//数塔问题
#if 0
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,a[102][102]={0};
		cin>>n;
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=i; j++)
			cin>>a[i][j];
		}
		
		for(int i=n-1; i>=1; i--)
		 for(int j=1; j<=i; j++)
		 {
		   if(a[i+1][j]>a[i+1][j+1])
		   a[i][j]+=a[i+1][j];
		   else a[i][j]+=a[i+1][j+1];
		 }
		cout<<a[1][1]<<endl;
	}
}
#endif 

//3.28 
//二维数组 稍有改变 
#if 0 
#include<bits/stdc++.h>
using namespace std;
int a[25][1005],dp[25][1005];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		
		for(int i=1; i<=n; i++)
		 for(int j=1; j<=m; j++)
		  cin>>a[i][j];
		  
		  for(int i=0; i<=n ;i++)
		    dp[i][0]=-99999999;
		  for(int i=0; i<=m; i++)
		    dp[0][i]=-99999999;  
		  
		  dp[1][0]=dp[0][1]=0;
		  
		int max=0;
		for(int i=1; i<=n; i++)
		{
		
		 for(int j=1; j<=m; j++)
		 {
	        
			if(dp[i-1][j]>dp[i][j-1]) 
			 dp[i][j]=dp[i-1][j];
			else 
			 dp[i][j]=dp[i][j-1];  	 	
		 	for(int k=2; k<=m; k++)
		 	{
		 		if(j/k==double(j/k))
		        if(dp[i][j/k]>dp[i][j])
				 dp[i][j]=dp[i][j/k];	
		    }
		 	dp[i][j]+=a[i][j];
		 	
		 }
		
	   }
	   cout<<dp[n][m]<<endl;
	}
	
}
#endif 



























