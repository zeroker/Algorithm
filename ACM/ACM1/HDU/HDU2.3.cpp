//主要是大数之间的加减乘除 主要代表
//卡斯兰特数 

 
//2.31高精度加法              //格式啊，蛋碎了一地啊 ， 
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


//2.33  题意就是让你求出 n！ 的位数 
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
 double x=0;
 cin>>n;
 
 for(int i=1; i<=n; i++)
 {
  x+=log10(i);	
 }	
  cout<<int(x)+1<<endl;
}
	
}
#endif
 
//2.37 
//动态规划 小dp 
// 下沙的沙子有几粒？ 这个题意就是说 给你一个n,m，有n个1，和m个0， 从左到右，1的个数总是比0 多，看最后一个数，
//   如果是 1 的话就是 a[i-1][j] 如果是 0 的话，就是 a[i][j-1].   
#if 0
#include<bits/stdc++.h>
using namespace std;
int main()
{
	__int64 a[21][21]={0};
	 
	for(int i=0; i<21; i++)
	a[i][0]=1;
	
	for(int i=1; i<21; i++)
	{
		for(int j=1; j<=i; j++)
		{
			
			a[i][j]=a[i-1][j]+a[i][j-1];
		}
	}
	
	int x,y;
	while(cin>>x>>y)
	cout<<a[x][y]<<endl;
}

#endif 






//2.38
#if 1
#include<bits/stdc++.h>
using namespace std;
int main()
{
 long long int a[36]={0};
 a[0]=1;
 a[1]=2;
 
 for(int i=2; i<=35; i++)
 a[i]=a[i-1]*(4*i-2)/(i+1);
 
 long long int x,ans=1;
 while(cin>>x && x!=-1)
 {
 	cout<<ans<<" "<<x<<" "<<a[x]<<endl;
    ans++; 	
 }	
	 
	
}
#endif 




#if 0
#include<stdio.h>
__int64 map[36][36]={};
int main(void)
{
    __int64 n,ans,i,j,t=0;
    for(i=0;i<36;i++)
        map[i][0]=1;        
    for(i=1;i<=35;i++)    
        for(j=1;j<=i;j++)
            map[i][j]=map[i-1][j]+map[i][j-1];            
    while(~scanf("%I64d",&n)&&n!=-1)
    {
        t++;
        printf("%I64d %I64d %I64d\n",t,n,2*map[n][n]);
    }
    return 0;
}
#endif






























