#include<iostream> //����  input 
//100 ��ҳ�� 
//15 20 20 15 10 30 45 һ���ܵİ��� 
//Output
//6 ���ڼ����� 
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




	















