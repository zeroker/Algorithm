#if 0 
#include<bits/stdc++.h>
using namespace std;
#define bitsperword 32
#define shift 5
#define mask 0x1f
#define n 100000000
int a[1 + n/bitsperword]; 

void sets(int i)
{
	a[i>>shift] |= (1<<(i & mask)); 
}
void clr(int i)
{
	a[i>>shift] &= ~(1<<(i & mask));
}
int test(int i)
{
	return a[i>>shift] & (1<<(i & mask));
}

int main() 
{
	int x;
	for(int i=0; i<n; i++)
		clr(i);
	while((cin>>x))
	{
		sets(x);
	}
	for(int i=0; i<n; i++)
	{
		if(test(i))
			printf("%d\n",i);
	}
	
}
#endif






#if 0
#include<bits/stdc++.h>
using namespace std;
int main() 
{
//	int a = (65 & 31);
//	cout<<a<<endl;
	int a = -1;
	int b = a++ + ++a;
	cout<<b<<endl;
	cout<<a<<endl;
}
#endif


 



