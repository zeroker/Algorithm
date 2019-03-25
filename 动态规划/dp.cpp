
//全排列 
#if 0
#include<bits/stdc++.h>
using namespace std;

void fun(int a[],int k,int m)
{
	if(k == m)
	{
		for(int i=0; i<=m; i++)
			cout<<a[i]<<" ";
		cout<<endl;
	}
	for(int i=k; i<=m; i++)
	{
		swap(a[k],a[i]);
		fun(a,k+1,m);
		swap(a[k],a[i]);
	}
}


int main()
{
	int n;
	int a[100];
	cin>>n; 
	for(int i=0; i<n; i++)
	{	
		cin>>a[i];
	}
	fun(a,0,n-1);
	
}
#endif 




// 最大上升 子序列 
/*给出 [4,2,4,5,3,7]，LIS 是 [2,4,5,7]，返回 4

*/
#if 0
#include<bits/stdc++.h>
using namespace std;
int fun(int a[],int n)
{
	int b[n];                    //截至到i 最大的上升子序列 的个数 
	for(int i=0; i<n; i++)
		b[i] = 1;
	for(int i=1; i<n; i++)
	{
		int max = -1;
		for(int j=0; j<i; j++)                        //找出前面比  此时的x 小的，并且 连续数最 大的   ~！！！ 
		{
			if(a[j] < a[i] && b[j] > max)
			{
				max = b[j];		
			}
		}
		if(max != -1)
			b[i] = max +1;
	}
	int maxx = 0;
	for(int i=0; i<n; i++)
		maxx = max(b[i],maxx);
	return maxx;
}
int main()
{
	int n = 5;
//	int a[] ={4,2,4,5,3,7};                                                                                                                                   
//5,4,1,2,3
	int a[] ={5,4,1,2,3};
	cout<<fun(a,n)<<endl;

}
#endif 



//n皇后问题
#if 0
#include<bits/stdc++.h>
using namespace std;

int total;
int n;
int a[100]; //a[i] = x 表示第i列第x行 

bool place(int k)
{
	for(int i=1; i<k; i++)
	{
		if(a[i] == a[k] || fabs(i-k) == fabs(a[i]-a[k]))	
			return false;
	} 
	return true;
}

void fun(int k)
{
	if(k > n)
	{
		total++;
		for(int i=1; i<=n; i++)
			cout<<a[i]<<" ";
		cout<<endl;
		return;
	}
	for(int i=1; i<=n; i++)
	{
		a[k] = i;
		if(place(k))
			fun(k+1);
	}
	
}
int main()
{
	cin>>n;
	fun(1);
	cout<<total<<"==="<<endl;
}

#endif 








































