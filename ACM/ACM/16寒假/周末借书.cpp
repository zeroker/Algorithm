#include<iostream> //借书  input 
//100 总页数 
//15 20 20 15 10 30 45 一个周的安排 
//Output
//6 星期几看完 
using namespace std;
int  main()
{
	int x,a[7],i,sum=0;
	cin>>x;
	for(i=0;i<7;i++)
	{
		cin>>a[i];
	}
for(i=0;i<7;i++)
{  sum=sum+a[i];
 if(sum>=x)
 {
 cout<<i+1<<endl;break;}
	
}

}




	















