//ĸţ����
//1.-A

#if  0
#include<bits/stdc++.h>
using namespace std;
int main()
{
int n;
 cin>>n;
 	int a[55];
 while(n!=0)
 {
 
 	
 
 	int i;
 	a[1]=1;
 	a[2]=2;
 	a[3]=3;

 	for(i=4;i<=n;i++)
 	{
 	 
 		a[i]=a[i-1]+a[i-3];
		 	 }
 	cout<<a[n]<<endl;
 	
 	cin>>n;
 }
 

	
}

#endif 

//�б�����     b 2. 
#if 0 
#include<iostream>
using namespace std;
int main()
{
	int n,a[101],x;
	
	cin>>n;
	a[1]=2;
	a[2]=4;
	x=3;
		for(int i=3;i<=n;i++)
	{
		a[i]=a[i-1]+x;
		x++;
	}
	
	cout<<a[n]<<endl;
}

#endif 


#if 0                    //  e 5. ���ӷ�ֳ���� 
#include<iostream>
using namespace std;

int main()
{
long long	int a[100];
	
	int n;
	while(cin>>n&&n!=0)
{
				
	a[1]=1;
	a[2]=2;
	
	for(int i=3;i<=n;i++)
	a[i]=a[i-1]+a[i-2];
	
	cout<<a[n]<<endl;
}
	return 0;
}

#endif

#if  0   // f 6      �������������  û���� �������� 
#include<bits/stdc++.h>
using namespace std;
int fun(int n,int m)
{
 if(n==m) return 1;
 else
 if(m==0) return 1;
 else 
 if(n==1) return 1;
 else return   fun(n-1,m-1)+fun(n-1,m);
 	
	
}
int main()
{
	int x,n,m;
	cin>>x;
	for(int i=1;i<=x;i++)
{
	cin>>n>>m;
	cout<<fun(n,m)<<endl;
	
}
	
}
#endif

#if  0// f 6.2     �������������   ����  ����������  �Ľ� 
#include<bits/stdc++.h>
using namespace std;
int a[21][21]={0}; 
int fun(int n,int m)
{
 if(n==m) return 1;
 else
 if(m==0) return 1;
 else 
 if(n==1) return 1;
 if(a[n][m]) return a[n][m];
 else {
 	a[n][m]=fun(n-1,m-1)+fun(n-1,m);
 	return a[n][m];
    
}
	
}
int main()
{
	int x,n,m;
	cin>>x;
	for(int i=1;i<=x;i++)
{
	cin>>n>>m;
	cout<<fun(n,m)<<endl;
	
}
	
}
#endif






#if 0           // G 7 .�ļ�Ӣ�￼�ԣ���λ ���� 
#include<bits/stdc++.h>
using namespace std;
int fun(int n)
{
	if(n==1) return 1;
	else
	if(n==2) return 2;
	else if(n==3) 
	return 3;
	else 
	return fun(n-1)+fun(n-3)+1;
}
int main()
{
	int n;
	while(cin>>n)
	cout<<fun(n)<<endl;
	
	
}


#endif






//p. ���ֲ���           
#if             0
#include<bits/stdc++.h>
using namespace std;
int *a;  
int fun(int ,int ,int );  
int main()
{
	
 int n,i,x,mid,lower,top;
 
    scanf("%d",&n);
 
 a= new int[n];
 for(i=0;i<n;i++)
            scanf("%d",&a[i]);
 	lower=0;
 	top=n-1;
 	int ni;
 	
         scanf("%d\n",&ni);
 
 	for(int i=0;i<ni;i++)
  {
  	
          	scanf("%d",& x);
          	int k=fun(x,lower,top);
                     	printf("%d\n",k);
 		
}
}
int fun(int x,int min,int max)
{
	int mid;
	mid=(max+min)/2;
	if(max>=min)
	{
		if(x==a[mid]) return   mid+1;
		else
		if(x>a[mid])   fun(x,mid+1,max);   
		else 

	 fun(x,min,mid-1);	
	}
	else return -1;
	
}
#endif 




#if  0                  //��֪��Ϊ�� ����� �ݹ鲻�� �����ĸ�ʽ 
#include<bits/stdc++.h>
using namespace std;
int a[3000001];
int f(int m,int x,int y);
int main()
{ int n,i,m,N;
 scanf("%d",&n);
 for(i=1;i<=n;++i)
 { scanf("%d",&a[i]);
 }
 cin>>N;
 while(N--)                   //�������ѧһ�� 
 {  scanf("%d",&m);
  printf("%d\n",f(m,1,n));
 }
}
int f(int m,int x,int y)
{ int z;
 while(x<=y)
 { z=(x+y)/2;
   if(m==a[z])return z;
else if(m<a[z]) y=z-1;       //�������� 
 else x=z+1;                  //���������� 
  }
  return -1;
}

#endif






// C 3          �ݹ�ĺ���         ������ ����������           
#if   0                      
#include<bits/stdc++.h>                 
using namespace std;                    
	int aii[31][31][31]={0};                
int fun(int ai,int bi,int ci)
{
	
	if(ai<=0||bi<=0||ci<=0) return 1; 
		else if(aii[ai][bi][ci]) return aii[ai][bi][ci];
	else 
	if(ai>20||bi>20||ci>20)	    
	{ 
	
		aii[ai][bi][ci]=fun(20,20,20);
		return aii[ai][bi][ci];
	}

	else
	 if(ai<bi&&bi<ci) 
	   {  
			    aii[ai][bi][ci]=fun(ai,bi,ci-1)+fun(ai,bi-1,ci-1)-fun(ai,bi-1,ci-1); 
			    return aii[ai][bi][ci];
			   
		
	   }
	    
	else 
	{
	  aii[ai][bi][ci]=fun(ai-1,bi,ci)+fun(ai-1,bi-1,ci)+fun(ai-1,bi,ci-1)-fun(ai-1,bi-1,ci-1); 
	 return  aii[ai][bi][ci];
	
}
	
}
int main()
{
	int a,b,c;

	while(cin>>a>>b>>c)
{
	cout<<fun(a,b,c)<<endl;
}
	
}

#endif 


	

// c 3                  �ݹ�ĺ���      ����İٶ� 
#if 0  //baidu

#include <bits/stdc++.h>
 using namespace std; 
 int x[31][31][31]={0}; 
 int f( int a, int b, int c) 
 {
  if(a<=0||b<=0||c<=0) return 1; 
  else if(a>20||b>20||c>20)
   return f(20,20,20); 
   else if (x[a][b][c]) return x[a][b][c]; 
   else if(a<b&&b<c) return x[a][b][c]=f(a,b,c-1)+f(a,b-1,c-1)-f(a,b-1,c-1); 
   else return x[a][b][c]=f(a-1,b,c)+f(a-1,b-1,c)+f(a-1,b,c-1)-f(a-1,b-1,c-1); } 
   int main() 
   { 
   int a,b,c;
    while (cin>>a>>b>>c)
	 { 
	 cout<<f(a,b,c)<<endl;
	  }
	   return 0;
	   } 

#endif



       // h ��������                                                                     
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


#if  0         //i ��Ҽ� 
#include<bits/stdc++.h>
using namespace std;
int main()
{
	
	int a[31],n;
	
	a[1]=1;
	while(cin>>n&&n!=0)
	{
	    for(int i=2;i<=n;i++)
	    a[i]=(a[i-1] +1)*2;	
	    	cout<<a[n]<<endl;
	}

	
}


#endif


#if  0                   //��ǿ�� 쳲��������� 
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[31],n;
	a[1]=1;
	a[2]=2;
	a[3]=3;
		while(cin>>n)
	{
		for(int i=4;i<=n;i++)
		a[i]=a[i-1]+a[i-2]+a[i-3];
		
		cout<<a[n]<<endl;
	}
	
	
	
}


#endif 





#if   0                // m   ��ֵ�ֽ� 
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		int ans=0,x=0;
		if(n==1)
		cout<<"1 "<<endl<<"1 1"<<endl;
		else
		 if(n==2)cout<<"2 "<<endl<<"1 2"<<endl;
	
		
	else	
		if(n%3==0) 
		{
		x=n/3;
		
		for(int i=0;i<x;i++)
		cout<<"3 ";
		cout<<endl<<x<<" "<<(long long int)pow(3,x)<<endl;
	}
	else
	if((n-4)%3==0) 
	{
		x=(n-4)/3;
		
		for(int i=0;i<x;i++)
		cout<<"3 ";
		cout<<"4 "<<endl;
		cout<<x+1<<" "<<(long long int)pow(3,x)*4<<endl;
	}
		else
	{
		x=n/3;
		ans=n%3;
		for(int i=0;i<x;i++)
		cout<<"3 ";
		cout<<ans;
		cout<<endl<<x+1<<" "<<(long long int)pow(3,x)*ans<<endl;
	}
		
	}
	
}
#endif 

// ��ŵ��  d 4.      //ע�� �����ʽ�� ʹ�� 3��29 �η� ��û�� ʹ��setprecision ��ʱ�� �ǿ�ѧ���� ��ʾ�� 
#if  0                        //�õ� long long int ���� ͨ���� 
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,x;
	cin>>n;
	for(int i=0;i<n;i++)
	{ 
		cin>>x;
		
	cout<<(long long int)pow(3,x)<<endl;
		
		
	}
	
	
	
}

#endif


//��ѧ�ڶ�
#if  0
#include<bits/stdc++.h>
using namespace std;
int ki;
int fun(int n)
{
	if(n==6174) cout<<endl<<ki<<endl;
	else
	{ 
  ki++;
   int a[6]={0};
	int i=0,t=n,k;
		
 while(t>0)
 {
 
 	int x=t%10;
 	t/=10;
 	a[i]=x;
 	i++;
  } 
  
  sort(a,a+4);
  
  int min,max; 
  min=a[0]*1000+a[1]*100+a[2]*10+a[3];
  max=a[3]*1000+a[2]*100+a[1]*10+a[0];
  cout<<max-min<<" ";
  fun(max-min);
}

}


int main()
{
	
	
int n;

while(cin>>n)
{
		ki=0;
		fun(n);
}
}

#endif

//��������
#if 1

#include<bits/stdc++.h>

using namespace std;

int main()

{
	int m , a[20][20] ;
	cin>> m ;
int	ax[]={0,1,0,-1} ,ay[] ={1,0,-1,0 } ; 
	
	
	
	while (m--)
	{
		int n;
		cin>>n; 
		
		
      memset(a,0,sizeof(a)) ;
		 
		 int nx=0 , ny=0 ,x=0,y=0,k=0;
		 
		 for(int i=0 ;i<n*n ;i++) 
		 {
		 	a[x][y] =i+1 ;
		 	nx = x+ ax[k] ;
		 	ny= y+ay[k] ;
		 	
		 	if(nx==n||nx<0||ny==n||ny<0||a[nx][ny]!=0)
		 	 {
		 	 	   k=(k+1)%4 ;
					 nx= x+ ax[k] ;
					 ny =y +ay[k] ; 
			  }
		 	x= nx ; y=ny ;
		 	
		 }
		
		
		for (int i=0 ;i< n ;i++) 
		{
		    for(int j=0 ;j< n ;j++) 
		  cout<< a[i][j] <<" \t" ;
		  cout<<endl;
	}
	 } 
	
	
	
 } 



 #endif 






















