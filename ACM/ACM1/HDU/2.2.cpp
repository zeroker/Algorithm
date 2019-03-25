
//没有接触过的额数学问题 


//2.11 斐波那契额数列           斐波那契数列的公式 f(n)=  1/sqrt(5)*(  (1+sqrt(5)/2)^n -  (1-sqrt(5)/2)^n   ) 然后取对数，科学计数法的 a 

// 但是 取对数的时候 取不出来  数学是硬伤啊 
#if 0
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int f[21] = {0, 1, 1};

int main()
{
	int n;
	for(int i = 2; i < 21; ++i)
		f[i] = f[i - 1] + f[i - 2];
	while(scanf("%d", &n) != EOF)
	{
		if(n <= 20)
		{
			printf("%d\n", f[n]);
			continue;
		}
		else
		{
			double temp = -0.5 * log(5.0) / log(10.0) + ((double)n) * log((sqrt(5.0)+1.0)/2.0) / log(10.0);
			temp -= floor(temp);
			temp = pow(10.0, temp);
			while(temp < 1000)
				temp *= 10;
			printf("%d\n", (int)temp);
		}
	}
	return 0;
}
#endif


// 2.2 2  绕环问题， 给你一个n , m .
////题意就是说 ：输入一个n 这个n 个人， 还有m,从1开始 每隔m-1个人开始遍历，看看能不能全部遍历。
//例如 3 2 就可以 。 
//潜在的 规律  要是 m and n 没有 除了1以外 的公约数 就可以了。 
//但是 这个规律 是别人发现的 有木有 ， 自己写的代码 却是runtime  啊  
#if 0
#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
 
   if(a<b)
   {
   	 a=a^b;
   	 b=a^b;
   	 a=a^b;
   }
   while(b)
   {
   	int x=a%b;
   	a=b;
   	b=x;
   	gcd(a,b);
   }
 return a;
 	
}

int main()

{
  int n , m ,x;
  cin>>x; 
  while(x--)	
{
  int t;
  cin>>m>>n;

if(gcd(m,n)==1) cout << "NO" <<endl;
else cout <<"YES"<<endl;	
	
}
}
#endif



//2.25 
// 3n+1
#if 0            //为什么会 wa 呢 上网查了查 ，是因为 a 的输入有可能 比 b 大 
#include<bits/stdc++.h>
using namespace std;
long long int cnt;
int go(int n)
{
	if(n==1)
	{
		cnt++;
		return cnt;
	}
	else
	 if(n%2)
	 {
	 	cnt++;
	 	go(3*n+1);
	 }
	 else
	 {
	 	cnt++;
	 	go(n/2);
	 }
	
}

int main()
{
	int a,b;
	while(cin>>a>>b)
	{ 
	cnt=0;
   int maxi=0;
   int ai=min(a,b);
   int bi=max(a,b);
	for(int i=ai; i<=bi; i++)
	{
		cnt=0;
		int x=go(i);
         if(x>maxi) 
		 maxi=x;		
	}
  cout<<a<<" "<<b<<" "<<maxi<<endl;     
 }
}
#endif

 // 	a[i]=(x*a[i-1] + y*a[i-2])%7; 有蛋疼的循环规律        //要写博客的 
//2.26
#if 0 
#include<bits/stdc++.h>
using namespace std;
int a[50];
int main()
{
	int x,y,n;

while(cin>>x>>y>>n && x+y+n)
{
	
	a[1]=1;
    a[2]=1; 
	for(int i=3; i<=50; i++)
	{
		a[i]=(x*a[i-1] + y*a[i-2])%7;
	}
	cout<<a[n%49]<<endl;            
	
}
	
}
#endif 








//2.28 求位数的方法     ~~~ 哈哈哈今天看的东西用到了 
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
		double sum=0;
		for(int i=1; i<=n; i++)
		{
			sum+=log10(i);
		}
		cout<<(int)sum+1<<endl;
	}
}
#endif 







//2.27 
//大数之间的乘除         ~~ 没大看 还有引入 卡特兰  这个概念                   //等啥时候自己切一遍 

#if 0
#include <iostream>
#include <cstdio>
#include <memory.h>

using namespace std;

#define MAX 101
#define BASE 10000

void multiply(int a[], int len, int b) {
    for(int i=len-1, carry=0; i>=0; i--) {
        carry += b * a[i];
        a[i] = carry % BASE;
        carry /= BASE;
    }
}

void divide(int a[], int len, int b) {
    for(int i=0, div=0; i<len; i++) {
        div = div * BASE + a[i];
        a[i] = div / b;
        div %= b;
    }
}

int main()
{
    int i, j, h[101][MAX];
    memset(h[1], 0, MAX*sizeof(int));
    for(i=2, h[1][MAX-1]=1; i<=100; i++) {
        memcpy(h[i], h[i-1], MAX*sizeof(int));
        multiply(h[i], MAX, 4*i-2);
        divide(h[i], MAX, i+1);
    }

    while(cin >> i && i>=1 && i <= 100) {
        for(j=0; j<MAX && h[i][j]==0; j++);
        printf("%d", h[i][j++]);                                               
        for(; j<MAX; j++)
            printf("%04d", h[i][j]);
        cout << endl;
    }
    return 0;
}
#endif 








//汉诺塔问题           //http://blog.csdn.net/yongnuzhibu/article/details/74422    
 
//2.23           //不对 
#if 0 
#include<bits/stdc++.h>
using namespace std;
bool go(int n, int a[], int b[], int c[]) //a 借 b 到 c 
{
 if(b[0]==n)
 return 0;
 else if(a[0]==n)
  return go(n-1,a+1,c,b);
 else if(c[0]==n)
 return go(n-1,b,a,c+1);
 	
 return 1;	
}

int main()
{
	int a[70],b[70],c[70];
	int ai,bi,ci;
	int t;
    int x;
	cin>>t;
	while(t--)
	{

	cin>>x;
	
	cin>>ai;
	for(int i=0; i<ai; i++)
	 cin>>a[i];
	 
	 cin>>bi;
	 for(int i=0; i<bi; i++)
	   cin>>b[i];
	   
	   cin>>ci;
	   for(int i=0; i<ci; i++)
	     cin>>c[i];
	     
	     if(go(x,a,b,c))
	     cout<<"true"<<endl;
	     else cout<<"false"<<endl;
	     
	}
	
}
#endif


//2.22 约瑟夫环 问题
#if 1
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int f[30],a[30];
	for(int i=1; i<14; i++)
	{
		int min=1;
		int n=2*i;
		memset(a,0,sizeof(a));
		
		for(int j=1; j<=i; j++)
		{
		   a[j]=(a[j-1]+min-1)%(n-j+1);//);//(a[j-1]+MIN-1)计算的是从现在这个人的位置开始数能到达的人的位置，
	    // (n-j+1)是出局人后一个人的位置，因为要由他开始数，得到的是下个出局的人的位置，注意这个位置是从0开始的
                                         
		   if(a[j]<i)
		   {
		   	j=0;
		   	min++;   ////好人出局了，j重置，min增加进行枚举
		   }	
		}
		f[i]=min;
		
	}
	
	int x;
	while(cin>>x && x)
	cout<<f[x]<<endl;
	return 0;
	
}
#endif 












