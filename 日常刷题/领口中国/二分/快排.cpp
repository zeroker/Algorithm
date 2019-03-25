//快排 

#if 1
#include<bits/stdc++.h>
using namespace std;
void fun(int a[],int l,int r) 
{
	cout<<"============================="<<endl;
	cout<<"left="<<l<<"  right="<<r<<endl;
	if(l>=r) 
		return;
	int i = l, j = r;
	int temp = a[l];	
	cout<<"temp="<<temp<<endl;
	i++;
	while(i <= j && i <= r && j >= l)
	{
		while(a[i] < temp && i <= r)
		{
				cout<<"i= "<<i<<endl;
			i++;
		
		}
		
		while(a[j] > temp && j >= l)
		{
			cout<<"j= "<<j<<endl;
			j--;
		
		}
		if(i <= j && i <= r && j >= l) 
		{
			cout<<a[i]<<" swap "<<a[j]<<endl;
			swap(a[i],a[j]);
		}
		
	}
	cout<<"----------"<<endl;
	cout<<"i= "<<i<<"  j="<<j<<endl;	
	a[l] = a[j];
	a[j] = temp;
	
	cout<<"flagj = "<<j<<endl;
	for(int i=0; i<5; i++)
		cout<<a[i]<<" ";
	cout<<endl;

	fun(a,l,j-1);
	fun(a,j+1,r);
}

int main()
{
	int a[100];
	int n;
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>a[i];
	fun(a,0,n-1);
	
	for(int i=0; i<n; i++)
		cout<<a[i]<<" ";
		
}

#endif 

#if 0
#include<bits/stdc++.h>
using namespace std;

void fastsort(int a[],int l,int r)
{
	if(l>=r)
		return;
	int i=l,j=r;
	int temp = a[l];
	
	i++;
	while(i<=j && i<=r && j>=l)
	{
		while(a[i]<temp && i<=r) i++;
		while(a[j]>temp && j>=l) j--;
		if(i<=j)
		{
			a[i]^=a[j];
			a[j]^=a[i];
			a[i]^=a[j];
		}
	}
	a[l] = a[j];
	a[j] = temp;
	fastsort(a,l,j-1);
	fastsort(a,j+1,r);
}

int main()
{
	int a[1000];
	int n;
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>a[i];
	 
	 
	 fastsort(a,0,n-1);
	 
	 
	 for(int i=0; i<n; i++)
	 	cout<<a[i]<<" ";
	
}




//搜索第k小的数字             快速排序的变形 
#if 0
#include<bits/stdc++.h>
using namespace std;
void fun(int a[],int l,int r) 
{
	if(l>=r) 
		return;
	int i = l, j = r;
	int temp = a[l];	
	i++;
	
	while(i <= j && i <= r && j >= l) 
	{
		while(a[i] < temp && i <= r) i++;
		
		while(a[j] > temp && j >= l) j--;
		
		if(i <= j && i <= r && j >= l) 
			swap(a[i],a[j]);
		
	}
	
	a[l] = a[j];
	a[j] = temp;

	fun(a,l,j-1);
	fun(a,j+1,r);
}

int main()
{
	int a[100];
	int n;
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>a[i];
	fun(a,0,n-1);
	
	for(int i=0; i<n; i++)
		cout<<a[i]<<" ";
		
}

#endif 























#endif 
