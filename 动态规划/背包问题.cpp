

//     01��������  
// f[i][j]������ ǰi����Ʒ��ʱ�� ����Ϊj��ʱ������ļ�ֵ��������j�����Ǵ�v ...0�ģ���Ϊÿһ����ƷҪѡһ�Σ����� 
#if 0 
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
	
	int m,n;                 //m:���������� n:��Ʒ�ĸ��� 
	cin>>m>>n; 
	int w[n+10];			   //ÿ����Ʒ������ 
	int c[n+10];				//ÿ����Ʒ�ļ�ֵ 
	int f[m+10];             //f[k]���� k����Ʒ��ʱ����װ�����ļ�ֵ 
	memset(f,0,sizeof(f));
	for(int i=0; i<n; i++)
	{
		cin>>w[i]>>c[i];
	}
	for(int i=0; i<n; i++)
	{
		for(int v = m; v>=w[i]; v--)
		{
			f[v] = max(f[v],f[v-w[i]] + c[i]);
		}	
	} 
	cout<<f[m]<<endl;	
	
}
#endif

//��ȫ��������
#if 0
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int m,n;                 //m:���������� n:��Ʒ�ĸ��� 
	cin>>m>>n; 
	int w[n+10];			   //ÿ����Ʒ������ 
	int c[n+10];				//ÿ����Ʒ�ļ�ֵ 
	int f[m+10];             //f[k]���� k����Ʒ��ʱ����װ�����ļ�ֵ 
	memset(f,0,sizeof(f));
	for(int i=0; i<n; i++)
	{
		cin>>w[i]>>c[i];
	}
	for(int i=0; i<n; i++)
	{
		for(int v = w[i]; v<=m; v++)
		{
			f[v] = max(f[v],f[v-w[i]] + c[i]);
		}	
	} 
	cout<<f[m]<<endl;
}
#endif 




























































