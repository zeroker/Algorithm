#if 1
#include<iostream>
using namespace std;
int lowbit(int x)
{
	return ((x)&(-x));
}
int main()
{
	int x;
	while(cin>>x) 
	cout<<x<<" lowbit:-->   "<<lowbit(x)<<endl;
}
#endif


