

//     01背包问题  
// f[i][j]代表了 前i个物品的时候 容量为j的时候的最大的价值量，其中j必须是从v ...0的，因为每一个物品要选一次！！！ 
#if 0 
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
	
	int m,n;                 //m:背包的容量 n:物品的个数 
	cin>>m>>n; 
	int w[n+10];			   //每个物品的重量 
	int c[n+10];				//每个物品的价值 
	int f[m+10];             //f[k]代表 k个物品的时候，能装的最大的价值 
	memset(f,0,sizeof(f));
	for(int i=0; i<n; i++)
	{
		cin>>w[i]>>c[i];
	}
	for(int i=0; i<n; i++)
	{
		for(int v = m; v>=w[i]; v--)
		{
			f[v] = max(f[v],f[v-w[i]] + c[i]);
		}	
	} 
	cout<<f[m]<<endl;	
	
}
#endif

//完全背包问题
#if 0
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int m,n;                 //m:背包的容量 n:物品的个数 
	cin>>m>>n; 
	int w[n+10];			   //每个物品的重量 
	int c[n+10];				//每个物品的价值 
	int f[m+10];             //f[k]代表 k个物品的时候，能装的最大的价值 
	memset(f,0,sizeof(f));
	for(int i=0; i<n; i++)
	{
		cin>>w[i]>>c[i];
	}
	for(int i=0; i<n; i++)
	{
		for(int v = w[i]; v<=m; v++)
		{
			f[v] = max(f[v],f[v-w[i]] + c[i]);
		}	
	} 
	cout<<f[m]<<endl;
}
#endif 




























































