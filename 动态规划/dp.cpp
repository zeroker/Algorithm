
//ȫ���� 
#if 0
#include<bits/stdc++.h>
using namespace std;

void fun(int a[],int k,int m)
{
	if(k == m)
	{
		for(int i=0; i<=m; i++)
			cout<<a[i]<<" ";
		cout<<endl;
	}
	for(int i=k; i<=m; i++)
	{
		swap(a[k],a[i]);
		fun(a,k+1,m);
		swap(a[k],a[i]);
	}
}


int main()
{
	int n;
	int a[100];
	cin>>n; 
	for(int i=0; i<n; i++)
	{	
		cin>>a[i];
	}
	fun(a,0,n-1);
	
}
#endif 




// ������� ������ 
/*���� [4,2,4,5,3,7]��LIS �� [2,4,5,7]������ 4

*/
#if 0
#include<bits/stdc++.h>
using namespace std;
int fun(int a[],int n)
{
	int b[n];                    //������i �������������� �ĸ��� 
	for(int i=0; i<n; i++)
		b[i] = 1;
	for(int i=1; i<n; i++)
	{
		int max = -1;
		for(int j=0; j<i; j++)                        //�ҳ�ǰ���  ��ʱ��x С�ģ����� �������� ���   ~������ 
		{
			if(a[j] < a[i] && b[j] > max)
			{
				max = b[j];		
			}
		}
		if(max != -1)
			b[i] = max +1;
	}
	int maxx = 0;
	for(int i=0; i<n; i++)
		maxx = max(b[i],maxx);
	return maxx;
}
int main()
{
	int n = 5;
//	int a[] ={4,2,4,5,3,7};                                                                                                                                   
//5,4,1,2,3
	int a[] ={5,4,1,2,3};
	cout<<fun(a,n)<<endl;

}
#endif 



//n�ʺ�����
#if 0
#include<bits/stdc++.h>
using namespace std;

int total;
int n;
int a[100]; //a[i] = x ��ʾ��i�е�x�� 

bool place(int k)
{
	for(int i=1; i<k; i++)
	{
		if(a[i] == a[k] || fabs(i-k) == fabs(a[i]-a[k]))	
			return false;
	} 
	return true;
}

void fun(int k)
{
	if(k > n)
	{
		total++;
		for(int i=1; i<=n; i++)
			cout<<a[i]<<" ";
		cout<<endl;
		return;
	}
	for(int i=1; i<=n; i++)
	{
		a[k] = i;
		if(place(k))
			fun(k+1);
	}
	
}
int main()
{
	cin>>n;
	fun(1);
	cout<<total<<"==="<<endl;
}

#endif 








































