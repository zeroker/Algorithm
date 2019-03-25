//                                                       递归
                       //  1. ！的问题
#if 0 
#include<iostream>
using  namespace std;
int fun(int );
int main()
{
	int m;
	cin>>m;
	cout<<fun(m)<<endl;
	
	
}
int fun(int m)
{
	if(m==1)
	return 1;
	else return fun(m-1)*m;
	
}
#endif 
#if 0            // 2. 欧几里得 算法   求 两个数的最大公约数 
#include<iostream>
using namespace std;
int fun(int ,int); 
int main()
{
	int m,k;
	cin>>m>>k;
	cout<<fun(m,k)<<endl;
	
}
int fun(int m,int k)
{
	if(k==0)
	return m;
	else return fun(k,m%k);
	
}

#endif 


#if 0               // 3. 累加和的问题  
#include<iostream>
using namespace std;
int fun(int); 
int main()
{
 int m;
 cin>>m;
 cout<<fun(m)<< endl;	
}
int fun(int m)
{
	if(m==1) return 1;
	else return fun(m-1)+m;
}

#endif


#if 0            // 4 . 二分查找算法 
#include<iostream>
#include<cstdlib>
using namespace std;
int *a;
int fun (int,int,int); 
int main()
{
	int x,n;
	cin>>n;
	a=new int [n];
     for(int i=0;i<n;i++)
     cin>>a[i];
     cin>>x;
     int max,min;
     min=0;max=n-1;
     fun(x,min,max);
}
fun(int x,int min,int max)
{
	int mid;
	if(min<=max)        // 这个地方需要理解 
   {
	 mid=(max+min)/2;
    if(a[mid]==x) cout<<"yes"<<endl;
       else if(x>a[mid]) fun(x,mid+1,max);
             else if(x<a[mid])  (x,min,mid-1);
   }
   else cout<<"no"<<endl;
   
}
#endif
// 全排列的问题 
#if   0
#include<bits/stdc++.h>
using namespace std;

int ai[4];
int fun(int a[],int k,int n)
{
	if(n==k) 
	 {
	 	
	 
		 	for(int i=0;i<n;i++ )
		 	cout<<a[i];
		 	cout<<endl;
	
	
	}
	else 
	for(int j=k;j<n;j++)
	{
		swap(a[k],a[j]);
		fun(a,k+1,n);
		swap(a[k],a[j]);
		
			}
	
}
int main()
{
	
	for(int i=0;i<4;i++)
	cin>>ai[i];
	fun(ai,0,4);	

}


#endif 


#if  0           //! 数字大了 容易溢出 还没有解决啊        //全错 排列问题  //n个数，将 第一个位置的文件 拿出来 给k 位置，有n-1种情况，k位置对应的文件 分配有两种情况， 
#include<bits/stdc++.h>      // 1. k 给了 第一个位置  2. k 没有给 第一个位置 
using namespace std; // 1.给了 就接着 递归fun(n-1) 2.没给就是 fun(n-1)  所以全错排列公式是 （n-1）（funa(n-1)+fun(n-2))

int fun(int n)
{
	if(n==1) return 0;
	else if(n==2) return 1;
	else if(n==3) return 2;
	else 
	
	return (n-1)*(fun(n-1)+fun(n-2));
		
 } 
int main() 
{
	
int n;
while(cin>>n)	
cout<<fun(n)<<endl;
	
	
}


#endif

// 全错位排列 用数组试试
#if  0                        //这个 也得用 long long int 要不然会溢出的 啊啊 啊啊 
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
long long	int a[21];
	a[1]=0;a[2]=1;a[3]=2;
	for(int i=4;i<21;i++)
	a[i]=(i-1)*(a[i-1]+a[i-2]);
	while(cin>>n)
	cout<<a[n]<<endl;
}


#endif 



 

#if  0         // 汉诺塔 问题 
#include<iostream>
using  namespace std;
void move(int n,char a,char b,char c)
{
	if(n==1) cout<<a<<"-->"<<c<<endl;    //当n只有1个的时候直接从a移动到c
	else{
		 move(n-1,a,c,b);      //第n-1个要从a通过c移动到b
		 cout<<a<<"-->"<<c<<endl;
		 move(n-1,b,a,c);         //n-1个移动过来之后b变开始盘，b通过a移动到c，
	}
}
int main()
{
	 int m;                             
	 cin>>m;
	 move(m,'A','B','C');
}

#endif 


//
        //半数集  问题  普通算法 

#if   0 
#include<bits/stdc++.h>
using namespace std;
int ans;
void dfs(int m)
{
	int i;
	ans++;
	for(i=1;i<=m/2;i++)
	dfs(i);
}
int main()
{
	int n;
	cin>>n;
	dfs(n);
	cout<<ans<<endl;
	
	
	
}

#endif

#if   0                          //与上边的 那个半数集 形式不太一样 
#include<bits/stdc++.h>
using namespace std;
int fun(int m)
{ int ans=1;
if(m>1)
	 for(int i=1;i<=m/2;i++)
	  
	  ans=ans+fun(i);
	return ans;
}
int  main()
{
	int n;
	cin>>n;
	cout<<fun(n)<<endl;
	
}
#endif

//记忆式搜索
#if 0               //减少许多不必要的 重复计算        
#include<bits/stdc++.h>
using namespace std;
int h[100];
int fun(int m)
{
	int ans=1;
if(h[m]>0)
return h[m];
	for( int i=1;i<=m/2;i++)
	
	    ans=ans+fun(i);
	  h[m]=ans;
	  return ans;

	
}
int main()
{
	int n;
	cin>>n;
	cout<<fun(n)<<endl;
}

#endif 




//总结 递推的 第一重简单的类型
// 斐波那契数列  也就是 上楼梯的问题 和 放骨牌的 问题 
//楼梯的问题 和骨牌 的问题 就是有点 抽象  但是原理 就是斐波那契 数列


//1 楼梯问题 输入一个N 代表的是N 阶楼梯， 一次性只能 迈一步 或者是 两步，问 都多少种走法？
//n=1台阶 一种情况，n=2 两个台阶 ,两种情况，所以 n=3的时候   是 (x-1)+(x-2)种情况 







#if  0                            // 递推 找到 一条路径，使得 值最大  求出最大的值   
#include<iostream>
using namespace std;
int main()
{
	int a[100][100],n;
	cin>>n;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=i;j++)
	cin>>a[i][j];
	for(int i=n-1;i>=1;i--)
	for(int j=1;j<=i;j++)
{
	if(a[i+1][j]>=a[i+1][j+1]) a[i][j]+=a[i+1][j];
	else 
	a[i][j]+=a[i+1][j+1];
}
	
	cout<<a[1][1]<<endl;
}

#endif

// 动态规划 主要是寻找 状态转移方程  

#if  0                              //动态规划 1 .吃金币问题 就是 从矩形的左上角 走到矩形的右下角 寻求一条路径使得 吃的的 数字最大，并输出这个数字  
#include<bits/stdc++.h> 
using namespace std;
int main()
{
	int a[20][20];
	memset(a,0,sizeof(a));
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	cin>>a[i][j];
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
     if(a[i][j-1]>a[i-1][j]) a[i][j]+=a[i][j-1];
     else a[i][j]+=a[i-1][j];

	cout<<a[n][m]<<endl;
	
	
	
}



#endif 

#if  0                        // 最长上升子序列   输出 最长子序列的 数字 
#include<bits/stdc++.h>
using namespace std;
int main()
{
int a[100],t[100],n;        //t[]存放 状态 
cin>>n;
for(int i=1;i<=n;i++)	
	cin>>a[i];
	t[1]=1;
	for(int i=2;i<=n;i++)
	{  int max=0;
		for(int j=1;j<i;j++)
		if(a[i]>a[j]) 
	     {
	     	if(t[j]>max) max=t[j];
		 }
		 t[i]=max+1;                                                
		}	
	int maxlen=t[1];
	for(int i=2;i<=n;i++)
	if(maxlen<t[i]) maxlen=t[i];
	cout<<maxlen<<endl;
}


#endif 


 
 






#if  0                     
#include<bits/stdc++.h>
using namespace std;

int liu (string &a)
{
	 stringstream o;
	 int aa;
	 o << a ;
	 o >> aa;
	 return aa;
	 
	 
	 
	
}

int main()
{
	string a;
	cin>>a;
	
	cout<< liu (a) <<endl;
	
	
}
#endif





 






 



























