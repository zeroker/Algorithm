#include<iostream>
using  namespace std;
int main()
{
	int n,i,j,k;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		for(j=0;j<n-i;j++)
			cout<<" ";
		for(k=1;k<=(2*i-1);k++)
			cout<<k;
		cout<<endl;

	}
	return 0;
}

