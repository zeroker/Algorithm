

///δ֪��Ŀppt 

#if 0 

#include<bits/stdc++.h>
#define exp 1e-8
using namespace std;
int n ,  k , a[100] ;

int ok(double s)

{
	int cnt=0 ; 
	
	for(int i=0 ; i<n ;i++)
	 {
	 	cnt = cnt+ int(a[i] / s );
	 }
	 
	 
	 if(cnt >= k ) return 1;
	 else return 0 ;
	
}

int main()

{
	int sum=0;
	
	for(int i=0 ; i< n ;i++)
	{
		cin>>a[i] ;
		sum = sum+ a[i] ;
		
	}
	
	sum = sum/n ;
	
	int l=0 , r = sum ;
	
	while( fabs(r-l) > exp ) 
	{
		double mid;
		mid = (l+r)/2;
		
		if(ok(mid))
		   r=mid;
		   else l=mid ;
		
	}
	cout << l  <<endl;
}

#endif


//acm����262   1.�ŶӴ�ˮ����
#if   0 
#include<bits/stdc++.h>

using namespace std;

int main()

{
	int n , r, a[100]  , p[100] ,j; 
	
	cin>> n >> r; 
	
		memset(p, 0, sizeof(p) ) ; 
	for(int i = 0 ; i < n ; i++)
	   cin >> a[i] ; 
	   
	   sort(a , a + n ) ;
	   int sum= 0; 
	for(int i=0 ; i< n ; i++)
	{
	if(j == r) j=0 ;            
	p[j] += a[i] ;
	sum += p[j] ;
	
	j++ ;   
	}
	
cout << sum <<endl;	
	
	
}

#endif 


#if 0 // 2.  ����ֽ�� 
#include<bits/stdc++.h>

using namespace std;

int main()

{
	int a[100] , n ,ave=0 ;
	
	cin >> n; 
	
	for(int i=0 ;i < n ;i++) 
	  {
	  	cin >> a[i] ; 
	  	ave += a[i] ; 
	  }
	  ave /= n ;
	  
	  for(int i=0 ;i < n ;i++) 
	    a[i] -= ave;  
	
	int i = 0 , j =n-1 ;
	
	while( a[i] == 0 && j < n-1) i++ ;
	while( a[j] == 0 && i > 0)    j-- ;  
	
	
	int cnt= 0 ;
while( i < j) 
{
 a[i+1] += a[i] ;
 a[i] = 0 ; 
 
 i++ ; 
 cnt ++  ; 
	while( a[i] == 0 && i < j) i++ ;

	
}	

cout << cnt <<endl; 
	
}

#endif 




//             ɾ������  ����һ�����֣� ɾ��n ������ �� ���ɾ�� n λ���� �Ժ���С������ ��
             // ���� 175438  �Ƚ� a[i] > a[i+1] ���� ɾ�� �� ������� �ڴӺ��� ����ɾ�� �� 
#if  1   

#include<bits/stdc++.h>

using namespace std;

int main()

{
  string a ;
  bool flag ;
  int cnt= 0 ;
  cin>> a ; 
  
  int  n ;
  cin >> n ;
 
 for(int  i= 0 ; i< n ;i++)
 {
   int len = a.size() ;
   
   for(int i=0 ; i< len-1; i ++)
   {
   	
   	if(a[i] >a[ i+ 1] ) 
   	{
   	  a.erase(i,1) ;
   	  cnt++ ;
   		break;
	   }
   	
   }
  
}

cnt = n -cnt ;

for(int i=0 ; i< a.size()- cnt ; i++ )
{
	if(a[i]!='0') flag = true ;
	if(flag) cout <<a[i] ;
}
  
  
	
	
	
}


#endif



























































