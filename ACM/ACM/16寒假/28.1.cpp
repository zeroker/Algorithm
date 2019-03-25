#include<iostream>
using namespace std;
int main()
{
	int n,*a,i,m=0;
	cin>>n;
	a=new int[n];
	for(i=0;i<n;i++)
	cin>>a[i];
	for(i=1;i<n-1;i++)
	{
		if(a[i]>a[i-1]&&a[i]>a[i+1])
	{	cout<<a[i]<<" "; m++;if(m%5==0)cout<<endl;}
		
	}
	return 0;
}

