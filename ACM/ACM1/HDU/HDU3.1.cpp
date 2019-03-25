//简单的递推递归 

//3.11         //变相的斐波那契数列 从 3-6 ，又是相当于求 a[6-3] 
#if 0
#include<bits/stdc++.h>
using namespace std;
int main()
{
	__int64 a[51],xi,yi,n;
	a[1]=1;a[2]=2;
	for(int i=3; i<51; i++)
	a[i]=a[i-1]+a[i-2];
	cin>>n;
	while(n--)
	{
		cin>>xi>>yi;
		cout<<a[yi-xi]<<endl;
	}
	return 0;
}
#endif
//3.12
 //骨牌铺方格  
#if 0 
#include<bits/stdc++.h>
using namespace std;
int main()
{
	__int64 a[51];
	a[1]=1;
	a[2]=2;
	for(int i=3; i<51; i++)
	a[i]=a[i-1]+a[i-2];
	
	int x;
	while(cin>>x)
	cout<<a[x]<<endl;
}
#endif

//3.13 母牛的故事 
#if 0 
#include<bits/stdc++.h>
using namespace std;
int main()
{
 int a[56];
 a[1]=1;
 a[2]=2;
 a[3]=3;
 a[4]=4;
 
 for(int i=5; i<55; i++)
 a[i]=a[i-1]+a[i-3];
 
 int x;
 while(cin>>x && x)
 cout<<a[x]<<endl;
	
}
#endif
//3.14
#if  1
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[10001],x,n;
	a[1]=1;
	a[2]=7;
	for(int i=3; i<10001; i++)
	a[i]=a[i-1]+4*(i-1)+1;
	
	cin>>n;
	while(n--)
	{
		cin>>x;
		cout<<a[x]<<endl;
	}
}
#endif



//3.15  铺地面砖的新的铺法   
//有宽度位3 ，长度是 n 的 地，有 边长为，2，和 1 的正方形，问你 n 米长的时候有多少种方案 
#if 0
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,a[31];
	a[1]=1;
	a[2]=3;
	
	for(int i=3; i<31; i++)
	a[i]=a[i-1]+a[i-2]*2; 
	cin>>n;
	while(n--)
	{
		int x;
		cin>>x;
		cout<<a[x]<<endl;
	}
	
}
#endif 


//3.16 同 3.15 
#if 0 
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[31];
	a[1]=1;a[2]=3;
	for(int i=3; i<31; i++)
	a[i]=a[i-1]+a[i-2]*2;
	
	int n;
	cin>>n;
	while(n--)
	{
		int x;
		cin>>x;
		cout<<a[x]<<endl;
	}
}
#endif 



//3.17
//有排成一行的ｎ个方格，用红(Red)、粉(Pink)、绿(Green)三色涂每个格子，
//每格涂一色，要求任何相邻的方格不能同色，且首尾两格也不同色．求全部的满足要求的涂法.

#if 0
#include<bits/stdc++.h>
using namespace std;
int main()
{
	__int64 a[51],n;
	a[1]=3;a[2]=6;a[3]=6;
	for(int i=4; i<51; i++)
	a[i]=a[i-1]+a[i-2]*2;
	
	int x;
	while(cin>>x)
	cout<<a[x]<<endl;
}
#endif 





//3.18
#if 0
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[1001][200],x;
	a[1]=1;a[2]=2;
	for(int i=3; i<50; i++)
	a[i]=a[i-1]+a[i-2]*2;
	
	while(cin>>x)
	cout<<a[x]<<endl;
}
#endif




































