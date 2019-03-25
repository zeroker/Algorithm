//数学：
//1.高精度乘法 
#if 0 
#include<bits/stdc++.h>
using namespace std;
int main()
{
 string as,bs;
 cin>>as>>bs;
 int a[20],b[20],c[20];
 memset(c,0,sizeof(c));
 memset(a,0,sizeof(a));
 memset(b,0,sizeof(b));
 
 reverse(as.begin(),as.end());
 reverse(bs.begin(),bs.end());
 int lena=as.size();
 int lenb=bs.size();
 
 for(int i=0; i<lena; i++) 
 a[i+1]=as[i]-'0';
 
 for(int i=0; i<lenb; i++)
 b[i+1]=bs[i]-'0'; 
 
 
 for(int i=1; i<=lena; i++) 
 {
 	int x=0;
 	for(int j=1; j<=lenb; j++)
 	{
 	 c[i+j-1]=a[i]*b[j]+c[i+j-1]+x;      
	 x=	c[i+j-1]/10;
	 c[i+j-1]=c[i+j-1]%10;
	}
	c[i+lenb]=x;
 }
 
 int lenc=lena+lenb;
 while(c[lenc]==0 && lenc>1) 
 	lenc--;
 
 
 for(int i=lenc; i>=1; i--)
 cout<<c[i];
 	
}
#endif 

//1.2 高精度除法 低精度 
// 按位相除法 
#if 0                            
#include<bits/stdc++.h>
using namespace std;
int main()
{
	string al;
	int lena;
	int bi;
	int a[100],c[100];
	
	memset(a,0,sizeof(a));
	memset(c,0,sizeof(c));
	
    cin>>al>>bi;
   	lena=al.size();
	
	int x=0;
	for(int i=0; i<lena; i++)                  //这里的问题 
	{
		a[i+1]=al[i]-'0';	
	}

	for(int i=1; i<=lena; i++)
	{
		c[i]=(x*10+a[i])/bi;
		x=(x*10+a[i])%bi;
	}
		
	int lenc=1;
	while(c[lenc]==0 && lenc<lena )
	 lenc++;
	 
	 for(int i=lenc; i<=lena; i++)
	 cout<<c[i];
	    		
}
#endif 


//1.3.高精度加法              //格式啊，蛋碎了一地啊 ， 
#if 0
#include<bits/stdc++.h>
using namespace std;
int main()
{
	
int t,ans=1;
cin>>t;

while(t--)
{
	
string a,b;
cin>>a>>b;

int lena=a.size();
int lenb=b.size();

reverse(a.begin(),a.end());
reverse(b.begin(),b.end()); 
int ax[1001],bx[1001],cx[1001];

memset(cx,0,sizeof(cx));
memset(ax,0,sizeof(ax));
memset(bx,0,sizeof(bx));

for(int i=0; i<lena; i++)
ax[i]=a[i]-'0';
for(int i=0; i<lenb; i++)
bx[i]=b[i]-'0';

int i,k;
for( i=0;i<lena||i<lenb; i++)
{
	int j;

		j=ax[i]+bx[i]+cx[i];
		if( j >= 10) 
		 {
		 	cx[i+1]=j/10;
		 	cx[i]=j%10;
		 }	
		 else
		 cx[i]=j;
}
if(cx[i])
k=i;
else k=i-1;

reverse(a.begin(),a.end());
reverse(b.begin(),b.end());
cout<<"Case "<<ans<<":"<<endl;
cout<<a<<" + "<<b<<" = ";
for(int i=k; k>=0; k--)
{
	cout<<cx[k];
}
if(t>=1)
cout<<endl<<endl;
else cout<<endl;
ans++;
}

}
#endif 

#if 0


#endif 











 

























