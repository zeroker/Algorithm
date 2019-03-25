//二分 快速排序 

#if 1
#include<bits/stdc++.h>
using namespace std; 
int a[100] ={0,9,8,2,1,3,6,4,5,7};
//int a[100] ;

//快速排序 
void fun(int l,int r)
{
	if(l >= r)
		return;
		
	int temp = a[l];
	int i = l;
	int j = r;
	
	
	while(i<j && j>l && i<r)
	{
		while(a[i]<temp && i<r)  i++; 
		
		while(a[j]>temp && j>l)  j--;
		
		if(i<j)
		{
			a[i] ^= a[j];
			a[j] ^= a[i];
			a[i] ^=	a[j];	
		}		
		
	}
	
	int mid = i;
	fun(l,mid);
	fun(mid+1,r);
}
//求第k小的数 
int fun1(int l,int r,int k)
{
//	cout<<"==============================="<<endl;
//	cout<<"l="<<l<<" r="<<r<<endl;
//	cout<<"temp="<<a[l]<<endl;
//	

	if(l>=r)
		return a[l];
		
	int i=l,j=r;
	int temp = a[l];
	
	while(i<j && i<r && j>l)
	{
		while(a[i] < temp && i<r) i++;
		
		while(a[j] > temp && j>l) j--;
		if(i<j)
		{
			a[i]^=a[j];
			a[j]^=a[i];
			a[i]^=a[j];
		}
		
	}
	

	
	int mid = i;
	if(i+1 == k)
	{
		return a[i];
	}
	else if(k > i+1)
	{
		return fun1(i+1,r,k);
	}else if(k < i+1)
	{
		return fun1(l,i,k);
	}
	
}

int main()
{
	int n;
	cin>>n; 
	cout<<fun1(0,9,n);
	
	//快速排序的测试 
//	for(int i=0; i<10; i++)
//		cin>>a[i];
//	fun(0,9);
//	for(int i=0; i<10; i++)
//		cout<<a[i]<<" ";
//	cout<<endl;
	
	
}
#endif 




#if 0
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	int w[1000];
	int c[1000];
	
	int f[1000];
	memset(f,0,sizeof(f));
	for(int i=0; i<n; i++)
	{
		cin>>w[i]>>c[i]; 
	}
	
	for(int i=0; i<n; i++)
	{
		for(int v=m; v>0; v--)
		{
			f[v] = max(f[v],f[v-w[i]]+c[i]);
		}
	}
	
	cout<<f[m-1]<<endl;
	
}
#endif


































