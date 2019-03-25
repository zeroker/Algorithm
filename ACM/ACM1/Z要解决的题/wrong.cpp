#if   0          // 20进制         have question 
#include<bits/stdc++.h>
using namespace std;
int main()
{
map<int,char> m;
for(int i=0;i<10;i++)
m[i]=i+48;
for(int i=10;i<20;i++)
m[i]=i+87;	
	string a,b;
	
	while(cin>>a>>b)
	 {
	    int ai[100],bi[100],c[100]; 
	    memset(ai,0,sizeof(ai));
	      memset(bi,0,sizeof(bi));
	        memset(c,0,sizeof(c));
		for(int i=a.size()-1;i>=0;i--)
		{
			if(a[i]>'0'&&a[i]<'9')
			ai[a.size()-i-1]=a[i]-48;
			else ai[i]=a[i]-87;
		 } 
	 for(int i=b.size()-1;i>=0;i--)
		{
			if(b[i]>'0'&&b[i]<'9')
			bi[i]=a[i]-48;
			else bi[b.size()-1-i]=a[i]-87;
		 } 
	
		          int x=0,jin=0;
	
	while(x<a.size()||x<b.size())
	{
		c[x]=ai[x]+bi[x]+jin;
		jin=c[x]/20;
		c[x]%=20;
		
		x++;
	}
	c[x]=jin;
	if(c[x]==0) x--;

	for(int  i=x;i>=0;i--)
	cout<<c[i]<<" ";
	
	 } 
	 	  
	
 } 


#endif















#if    1              /////////////  14. wrong  等着测试  不知道对不对 但是运行 正常    数字反转相加问题 
#include<bits/stdc++.h>
using namespace std;
int main()
{ 
string a,b;
int  ai[100],bi[100],c[100];


	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{ 
	 int sum=0,f=1;
		memset(ai,0,sizeof(ai));
			memset(bi,0,sizeof(bi));
				memset(c,0,sizeof(c));
		
		cin>>a>>b;
		int an=a.size();
		int bn=b.size();
		
		for(int i=0;i<an;i++)
		ai[i]=a[i]-48;
		for(int i=0;i<bn;i++)
		bi[i]=b[i]-48;
	
		int x=0;
		int lenc=0;
		while(lenc<an||lenc<bn)
		{
			c[lenc]=ai[lenc]+bi[lenc]+x;
		     	x=c[lenc]/10;
		    	c[lenc]%=10;
			
			
		 lenc++;	
		}
   c[lenc] =x;
   if(lenc==0)
   lenc--;
    
    for(int i=lenc;i>=0;i--)
    if(c[lenc]==0&&c[lenc-1]!=0)
    {
    	lenc=i;break;
	}
 
 cout<<lenc<<endl;
    
	
for(int i=lenc-1;i>=0;i--)
{
	sum=sum+c[i]*f;
	f=f*10;

}
cout<<sum;


	cout<<endl;
}

	 
	 

			
	}
	

#endif 



#if     0             //////////////         23 草坪问题              需要测试  不知道对不对 结果 
#include<bits/stdc++.h>
using namespace std;
int main()
{
int n,ni;

cin>>n>>ni;

while(n!=0&&ni!=0)
{
    int sum=0,flag=1;
int **a;
a=new int *[n+1];

for(int i=0;i<n+1;i++)
	{
		a[i]=new int[ni];
	}
	
	
	for(int i=0;i<n;i++)
	for(int j=0;j<ni;j++)
	cin>>a[i][j];                       //输入完毕 
	
	for(int i=0;i<ni;i++)
	a[n][i]=1;
	
		for(int i=0;i<n;i++)
	for(int j=0;j<ni;j++)
{
	sum+=a[i][j];
}



if(sum==ni*n)
{
	cout<<"No"<<endl;
	continue;


}
	
else 

{
	for(int i=0;i<n;i++)
{ 
          if(flag==1)
		for(int j=0;j<ni-1;j++)
		
	if((a[i][j]==0&&a[i+1][j]==0)||(a[i][j]==0&&a[i][j+1]==0))
	{
		
		 cout<<"No"<<endl;
	flag=0;
		continue;
		 
		}
		
		 
		 	
					
}
if(flag==1)
 cout<<"Yes"<<endl;
}

cin>>n>>ni;
for(int i=0;i<n;i++)
 delete []a[i];
}
}

#endif


