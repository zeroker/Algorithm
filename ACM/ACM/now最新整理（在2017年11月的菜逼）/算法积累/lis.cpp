//lis 算法   
// 用的是什么思想呢 ？
//维护一个数组，队列 在这里我们用到了二分的思想 
//复杂度n*log(n) 
#if 1 
#include<bits/stdc++.h>
using namespace std;
int binary(int val,int a[],int l,int r)
{
	int m;
	int id;
	while(l<=r)
	{
		m=l+(r-l)/2;
		if(a[m]>val)
		{
			id=m;
			r=m-1;	
		}
		else
			l=m+1;
		
	}
	return id;
}

int main()
{
	int a[1000],l,r,len=0;
	int b[1000];           //维护数组 
	int n;
	cin>>n; 
	for(int i=0; i<n; i++)
	{
		cin>>a[i];
	} 
	
	b[0]=a[0];
	len=1;
	for(int i=1; i<n; i++)
	{ 
		if(a[i]>b[len-1])
		{
			len++;
			b[len-1]=a[i];
		}
		else if(a[i]<b[0]) 
		{
			b[0]=a[i];
		}
		else
		{
			int id=binary(a[i],b,0,len-1); 
			b[id]=a[i];   
		}	
		for(int i=0; i<len; i++)
			cout<<b[i]<<" ";
		cout<<endl;	 
	}
	cout<<len<<endl;	
	for(int i=0; i<len; i++)
		cout<<b[i]<<" ";

}
#endif 




#if 0
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a[1000],l,r,len=0;
	int b[1000];           //维护数组 
	int n;
	cin>>n; 
	for(int i=0; i<n; i++)
	{
		cin>>a[i];
	} 
	
	b[0]=a[0];
	len=1;
	for(int i=1; i<n; i++)
	{ 
		if(a[i]>b[len-1])
		{
			len++;
			b[len-1]=a[i];
		}
		else
		{
			*lower_bound(b,b+len,a[i])=a[i]; 
		  
		}	
		for(int i=0; i<len; i++)
			cout<<b[i]<<" ";
		cout<<endl;	 
	}
	cout<<len<<endl;	
	for(int i=0; i<len; i++)
		cout<<b[i]<<" ";

}
#endif 





//lower_bound 函数的使用 
#if 0
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[100]={1,5,3,9,8};
	int *x=lower_bound(a,a+5,7);
	cout<<x-a<<endl;
	
}
#endif



































