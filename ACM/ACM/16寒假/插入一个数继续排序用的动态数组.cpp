#include<iostream>
using namespace std;
int app( int *& pa,int n);
int main()

{
	int *ary,n,x,i,a;
cin>>x; 
	cin>>n;
	app(ary,n);
	for(i=0;i<n;i++)
	cin>>ary[i];
	a=n;
	for(i=0;i<a;i++)
	{
		if(x<ary[i])
	{
			cout<<x<<" ";  a=i; }
		 cout<<ary[i]<<" "; 
	}
	for(i=a+1;i<n;i++)
	cout<<ary[i]<<" ";

	
	
}
int app( int *&pa,int len)
{
	pa=new int[len];
	
	
}



	























