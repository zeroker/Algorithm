//                                                       �ݹ�
                       //  1. ��������
#if 0 
#include<iostream>
using  namespace std;
int fun(int );
int main()
{
	int m;
	cin>>m;
	cout<<fun(m)<<endl;
	
	
}
int fun(int m)
{
	if(m==1)
	return 1;
	else return fun(m-1)*m;
	
}
#endif 
#if 0            // 2. ŷ����� �㷨   �� �����������Լ�� 
#include<iostream>
using namespace std;
int fun(int ,int); 
int main()
{
	int m,k;
	cin>>m>>k;
	cout<<fun(m,k)<<endl;
	
}
int fun(int m,int k)
{
	if(k==0)
	return m;
	else return fun(k,m%k);
	
}

#endif 


#if 0               // 3. �ۼӺ͵�����  
#include<iostream>
using namespace std;
int fun(int); 
int main()
{
 int m;
 cin>>m;
 cout<<fun(m)<< endl;	
}
int fun(int m)
{
	if(m==1) return 1;
	else return fun(m-1)+m;
}

#endif


#if 0            // 4 . ���ֲ����㷨 
#include<iostream>
#include<cstdlib>
using namespace std;
int *a;
int fun (int,int,int); 
int main()
{
	int x,n;
	cin>>n;
	a=new int [n];
     for(int i=0;i<n;i++)
     cin>>a[i];
     cin>>x;
     int max,min;
     min=0;max=n-1;
     fun(x,min,max);
}
fun(int x,int min,int max)
{
	int mid;
	if(min<=max)        // ����ط���Ҫ��� 
   {
	 mid=(max+min)/2;
    if(a[mid]==x) cout<<"yes"<<endl;
       else if(x>a[mid]) fun(x,mid+1,max);
             else if(x<a[mid])  (x,min,mid-1);
   }
   else cout<<"no"<<endl;
   
}
#endif
// ȫ���е����� 
#if   0
#include<bits/stdc++.h>
using namespace std;

int ai[4];
int fun(int a[],int k,int n)
{
	if(n==k) 
	 {
	 	
	 
		 	for(int i=0;i<n;i++ )
		 	cout<<a[i];
		 	cout<<endl;
	
	
	}
	else 
	for(int j=k;j<n;j++)
	{
		swap(a[k],a[j]);
		fun(a,k+1,n);
		swap(a[k],a[j]);
		
			}
	
}
int main()
{
	
	for(int i=0;i<4;i++)
	cin>>ai[i];
	fun(ai,0,4);	

}


#endif 


#if  0           //! ���ִ��� ������� ��û�н����        //ȫ�� ��������  //n�������� ��һ��λ�õ��ļ� �ó��� ��k λ�ã���n-1�������kλ�ö�Ӧ���ļ� ��������������� 
#include<bits/stdc++.h>      // 1. k ���� ��һ��λ��  2. k û�и� ��һ��λ�� 
using namespace std; // 1.���� �ͽ��� �ݹ�fun(n-1) 2.û������ fun(n-1)  ����ȫ�����й�ʽ�� ��n-1����funa(n-1)+fun(n-2))

int fun(int n)
{
	if(n==1) return 0;
	else if(n==2) return 1;
	else if(n==3) return 2;
	else 
	
	return (n-1)*(fun(n-1)+fun(n-2));
		
 } 
int main() 
{
	
int n;
while(cin>>n)	
cout<<fun(n)<<endl;
	
	
}


#endif

// ȫ��λ���� ����������
#if  0                        //��� Ҳ���� long long int Ҫ��Ȼ������� ���� ���� 
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
long long	int a[21];
	a[1]=0;a[2]=1;a[3]=2;
	for(int i=4;i<21;i++)
	a[i]=(i-1)*(a[i-1]+a[i-2]);
	while(cin>>n)
	cout<<a[n]<<endl;
}


#endif 



 

#if  0         // ��ŵ�� ���� 
#include<iostream>
using  namespace std;
void move(int n,char a,char b,char c)
{
	if(n==1) cout<<a<<"-->"<<c<<endl;    //��nֻ��1����ʱ��ֱ�Ӵ�a�ƶ���c
	else{
		 move(n-1,a,c,b);      //��n-1��Ҫ��aͨ��c�ƶ���b
		 cout<<a<<"-->"<<c<<endl;
		 move(n-1,b,a,c);         //n-1���ƶ�����֮��b�俪ʼ�̣�bͨ��a�ƶ���c��
	}
}
int main()
{
	 int m;                             
	 cin>>m;
	 move(m,'A','B','C');
}

#endif 


//
        //������  ����  ��ͨ�㷨 

#if   0 
#include<bits/stdc++.h>
using namespace std;
int ans;
void dfs(int m)
{
	int i;
	ans++;
	for(i=1;i<=m/2;i++)
	dfs(i);
}
int main()
{
	int n;
	cin>>n;
	dfs(n);
	cout<<ans<<endl;
	
	
	
}

#endif

#if   0                          //���ϱߵ� �Ǹ������� ��ʽ��̫һ�� 
#include<bits/stdc++.h>
using namespace std;
int fun(int m)
{ int ans=1;
if(m>1)
	 for(int i=1;i<=m/2;i++)
	  
	  ans=ans+fun(i);
	return ans;
}
int  main()
{
	int n;
	cin>>n;
	cout<<fun(n)<<endl;
	
}
#endif

//����ʽ����
#if 0               //������಻��Ҫ�� �ظ�����        
#include<bits/stdc++.h>
using namespace std;
int h[100];
int fun(int m)
{
	int ans=1;
if(h[m]>0)
return h[m];
	for( int i=1;i<=m/2;i++)
	
	    ans=ans+fun(i);
	  h[m]=ans;
	  return ans;

	
}
int main()
{
	int n;
	cin>>n;
	cout<<fun(n)<<endl;
}

#endif 




//�ܽ� ���Ƶ� ��һ�ؼ򵥵�����
// 쳲���������  Ҳ���� ��¥�ݵ����� �� �Ź��Ƶ� ���� 
//¥�ݵ����� �͹��� ������ �����е� ����  ����ԭ�� ����쳲����� ����


//1 ¥������ ����һ��N �������N ��¥�ݣ� һ����ֻ�� ��һ�� ������ �������� ���������߷���
//n=1̨�� һ�������n=2 ����̨�� ,������������� n=3��ʱ��   �� (x-1)+(x-2)����� 







#if  0                            // ���� �ҵ� һ��·����ʹ�� ֵ���  �������ֵ   
#include<iostream>
using namespace std;
int main()
{
	int a[100][100],n;
	cin>>n;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=i;j++)
	cin>>a[i][j];
	for(int i=n-1;i>=1;i--)
	for(int j=1;j<=i;j++)
{
	if(a[i+1][j]>=a[i+1][j+1]) a[i][j]+=a[i+1][j];
	else 
	a[i][j]+=a[i+1][j+1];
}
	
	cout<<a[1][1]<<endl;
}

#endif

// ��̬�滮 ��Ҫ��Ѱ�� ״̬ת�Ʒ���  

#if  0                              //��̬�滮 1 .�Խ������ ���� �Ӿ��ε����Ͻ� �ߵ����ε����½� Ѱ��һ��·��ʹ�� �Եĵ� ������󣬲�����������  
#include<bits/stdc++.h> 
using namespace std;
int main()
{
	int a[20][20];
	memset(a,0,sizeof(a));
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	cin>>a[i][j];
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
     if(a[i][j-1]>a[i-1][j]) a[i][j]+=a[i][j-1];
     else a[i][j]+=a[i-1][j];

	cout<<a[n][m]<<endl;
	
	
	
}



#endif 

#if  0                        // �����������   ��� ������е� ���� 
#include<bits/stdc++.h>
using namespace std;
int main()
{
int a[100],t[100],n;        //t[]��� ״̬ 
cin>>n;
for(int i=1;i<=n;i++)	
	cin>>a[i];
	t[1]=1;
	for(int i=2;i<=n;i++)
	{  int max=0;
		for(int j=1;j<i;j++)
		if(a[i]>a[j]) 
	     {
	     	if(t[j]>max) max=t[j];
		 }
		 t[i]=max+1;                                                
		}	
	int maxlen=t[1];
	for(int i=2;i<=n;i++)
	if(maxlen<t[i]) maxlen=t[i];
	cout<<maxlen<<endl;
}


#endif 


 
 






#if  0                     
#include<bits/stdc++.h>
using namespace std;

int liu (string &a)
{
	 stringstream o;
	 int aa;
	 o << a ;
	 o >> aa;
	 return aa;
	 
	 
	 
	
}

int main()
{
	string a;
	cin>>a;
	
	cout<< liu (a) <<endl;
	
	
}
#endif





 






 



























