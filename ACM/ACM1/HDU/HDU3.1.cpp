//�򵥵ĵ��Ƶݹ� 

//3.11         //�����쳲��������� �� 3-6 �������൱���� a[6-3] 
#if 0
#include<bits/stdc++.h>
using namespace std;
int main()
{
	__int64 a[51],xi,yi,n;
	a[1]=1;a[2]=2;
	for(int i=3; i<51; i++)
	a[i]=a[i-1]+a[i-2];
	cin>>n;
	while(n--)
	{
		cin>>xi>>yi;
		cout<<a[yi-xi]<<endl;
	}
	return 0;
}
#endif
//3.12
 //�����̷���  
#if 0 
#include<bits/stdc++.h>
using namespace std;
int main()
{
	__int64 a[51];
	a[1]=1;
	a[2]=2;
	for(int i=3; i<51; i++)
	a[i]=a[i-1]+a[i-2];
	
	int x;
	while(cin>>x)
	cout<<a[x]<<endl;
}
#endif

//3.13 ĸţ�Ĺ��� 
#if 0 
#include<bits/stdc++.h>
using namespace std;
int main()
{
 int a[56];
 a[1]=1;
 a[2]=2;
 a[3]=3;
 a[4]=4;
 
 for(int i=5; i<55; i++)
 a[i]=a[i-1]+a[i-3];
 
 int x;
 while(cin>>x && x)
 cout<<a[x]<<endl;
	
}
#endif
//3.14
#if  1
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[10001],x,n;
	a[1]=1;
	a[2]=7;
	for(int i=3; i<10001; i++)
	a[i]=a[i-1]+4*(i-1)+1;
	
	cin>>n;
	while(n--)
	{
		cin>>x;
		cout<<a[x]<<endl;
	}
}
#endif



//3.15  �̵���ש���µ��̷�   
//�п��λ3 �������� n �� �أ��� �߳�Ϊ��2���� 1 �������Σ����� n �׳���ʱ���ж����ַ��� 
#if 0
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,a[31];
	a[1]=1;
	a[2]=3;
	
	for(int i=3; i<31; i++)
	a[i]=a[i-1]+a[i-2]*2; 
	cin>>n;
	while(n--)
	{
		int x;
		cin>>x;
		cout<<a[x]<<endl;
	}
	
}
#endif 


//3.16 ͬ 3.15 
#if 0 
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[31];
	a[1]=1;a[2]=3;
	for(int i=3; i<31; i++)
	a[i]=a[i-1]+a[i-2]*2;
	
	int n;
	cin>>n;
	while(n--)
	{
		int x;
		cin>>x;
		cout<<a[x]<<endl;
	}
}
#endif 



//3.17
//���ų�һ�еģ�������ú�(Red)����(Pink)����(Green)��ɫͿÿ�����ӣ�
//ÿ��Ϳһɫ��Ҫ���κ����ڵķ�����ͬɫ������β����Ҳ��ͬɫ����ȫ��������Ҫ���Ϳ��.

#if 0
#include<bits/stdc++.h>
using namespace std;
int main()
{
	__int64 a[51],n;
	a[1]=3;a[2]=6;a[3]=6;
	for(int i=4; i<51; i++)
	a[i]=a[i-1]+a[i-2]*2;
	
	int x;
	while(cin>>x)
	cout<<a[x]<<endl;
}
#endif 





//3.18
#if 0
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[1001][200],x;
	a[1]=1;a[2]=2;
	for(int i=3; i<50; i++)
	a[i]=a[i-1]+a[i-2]*2;
	
	while(cin>>x)
	cout<<a[x]<<endl;
}
#endif




































