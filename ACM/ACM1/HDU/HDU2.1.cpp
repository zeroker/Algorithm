//�򵥵���ѧ���⣨bjd�� 


//2.11
//��С������ 
#if 0
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c;
	
	while(cin>>a>>b)
{
		int x=a*b;
	
	if(a<b)
	{
	a=a^b;
	b=a^b;
	a=a^b;
   }
	while(1)
	{
		c=a%b;
		a=b;
		b=c;
		if(b==0)
	    break;
	}
	cout << x/a<<endl;
}

}

#endif


//2.1 2 
#if 0 
#include<bits/stdc++.h>
using namespace std;
int main()
{
int n;

while(cin>>n)
{
	int cnt=0;
  while(n--)
  {
    int x, q ,i ;
	cin>>x;
	if(x==1)
	continue;
	q=sqrt(x);
	for( i=2; i<=q; i++)
	{
	  if(x%i==0)
	  break;	
	} 	
	if(i==q+1)
	cnt++;
	
  }
  cout << cnt <<endl;
}

	
}
#endif 

// cake      ���� 
#if 0 
#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
	if(!b)
	return a;
	else gcd(b,a%b);
}
int main()
{
 int p,q;
 while(cin>>p>>q)
 {
 	cout<<p+q-gcd(p,q)<<endl;
 }
 
}
#endif


//2.14 Largest prime factor             ��֪��Ϊʲô������ ������ŵ��������ᳬʱ �������˴����ݻ������������ʹ�� 
#if 0
#include<bits/stdc++.h>
using namespace std;
int a[1000000];                  //
	int main()
{
int  ans=1;
	memset(a,0,sizeof(a)) ;
	

	
	for(int i=2; i<=1000000; i++)
	{
		if(!a[i]) 
		{
		a[i]=ans;
		for(int j=i+i; j<=1000000; j+=i)	 
		{
		 a[j]=ans;	
		}	
      	ans++;
	   }
	   	
	}
	
	int x;
    while(~scanf("%d",&x))
    {
        printf("%d\n",a[x]);
    }
}

#endif 



//2.1 5 
//�Ѿ�֪���� ����һ�����Լ�� b ���� ����������һ����������һ���� �����빫ʽ���ԣ� 
//�ּ�GCD
#if  0
#include<bits/stdc++.h>
using namespace std;
int a,b,c; 

int gcd(int a, int b)
{
 int x;
 if(b==0) return a;
 else gcd(b,a%b);	
}

int main()
{
 int n;
 cin>>n;
 while(n--) 
 {
        //���Լ����B 
  cin>>a>>b;
  c=2*b;
 while(1) 
 {
 	if(gcd(a,c)==b)
 	{
 		cout<<c<<endl;
 		break;
	}
	else c+=b;
 }
  

  }
   	
 }
  	

#endif 

//һ���������Ӻ� 
//2.1 6
// ���˸�ȥ ������ѧ�⣬ �� 1 �� ������ n�������ĺͣ����� ��һ�� ����Ϸ���Ҳ��ӡ�

// a * b == n  ������      
#if 0
#include<bits/stdc++.h>
using namespace std;
int main()
{
 int t;
 cin>>t;
 
 while(t--)
 {
 int n,ans=0;
 cin>>n;
 for(int i=1; i*i<=n; i++)
 {
  if(n%i==0)
  {
  ans+=i;
  if(i!=1 && i!=n/i)	
  ans+=n/i;
  }
 } 
 cout<<ans<<endl;
}

}
#endif


// 
//2.17
#if 0     //�������������ģ���ѧ�������  //��Ļ�����ʵһ�� 20���� ����A��������A��һ���� 
#include<bits/stdc++.h>
using namespace std;
int main()
{
	double x1,y1,x2,y2,x3,y3;
	int t1;
	cin>>t1;
	
	while(t1--)
	{
	 double k,a,b,c,sum,t;	
	 cin>>x1>>y1>>x2>>y2>>x3>>y3;
	 	
	 k=(y3-y2)/(x3-x2);
	 a=(y2-y1)/((x1-x2)*(x1-x2));
	 b=-2*a*x1;
	 c=y1-a*x1*x1-b*x1;
	 t=y3-k*x3;

	 double s1= 1.0/3*a*x2*x2*x2+1.0/2*(b-k)*x2*x2+x2*(c-t);
	 double s2=1.0/3*a*x3*x3*x3+1.0/2*(b-k)*x3*x3+x3*(c-t);
	  cout<<fixed<<setprecision(2)<<s2-s1<<endl;
	}
	
}
#endif 

//2.18 
#if 1
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
   {	
	double x,a, n;
	scanf("%lf",&n);
	x=n*log10(n);
	a=pow(10.0,x-(__int64)x);
   	
	int end=int(a);
printf("%d\n",end);
   }
} 
#endif 

















































