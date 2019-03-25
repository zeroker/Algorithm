// hdu 1.1

#if 0
#include<iostream>

using namespace std;

int main()

{
	 
int a , b , sum ;

while(cin>>a>>b)
{

 sum = a + b ;
 
 cout << sum <<endl;
	
 }	 
	
	
}

#endif
//1.2
#if 0

#include<iostream>
using namespace std;

int main()

{
	int n ,a , b ; 
	cin >> n ;
	
  while(n--)
  {
  	cin >> a >> b ;
  	
  	cout << a + b  <<endl;
  	
  }
	
	
	
}


#endif

//1.13 
#if 0
#include<iostream>
using namespace std;

int main()

{
   int a , b ;
  
   while(  	cin >> a >> b)
   {
   	if(a==0 && b==0 ) break;
   	else 
   	cout << a + b << endl ;
   	
   	
 
    }	
	
	
	
}

#endif

//1.14

#if 0

#include<iostream>

using namespace std;

int main()

{
	int n ; 
	
	while(cin >> n && n!=0)
	
	{ 
	    int sum = 0 , a ;
		for(int i=0 ; i< n ;i++)
		{
			cin >>  a; 
			sum += a ;
		}
		
		cout <<  sum <<endl;
	}
	
	
	
}


#endif


//1.15
#if 0

#include<iostream>

using namespace std;

int main()
{
	int m ,n; 
 cin>> m ; 
 
 while(m--)
 {
    int n ; 
    cin >> n ;
    
    
int sum = 0 ,  a;     
while(n--)
{
	cin >> a ;
	sum+= a ;
	
}	
	cout <<  sum <<endl; 	
 	
 }	
	
	
	
}


#endif


//1.16
#if 0

#include<iostream>

using namespace std;

int main()
{
   int n ;
   while(cin >> n && n> 0 )
   
   { 
     int x , sum = 0 ; 
   	while(n--)
   	{
   		cin >> x ;
   		
   		sum += x ;
	}
   	cout << sum <<endl;
   	
   	
   }	
	
	
	
}

#endif



//1.17
#if 0
#include<iostream>

using namespace std;

int main()

{
	 
int a , b , sum ;

while(cin>>a>>b)
{

 sum = a + b ;
 
 cout << sum <<endl << endl;
	
 }	 
	
	
}

#endif

//1.18



#if 0

#include<iostream>

using namespace std;

int main()
{
	int m ,n; 
 cin>> m ; 
 
 while(m--)
 {
    int n ; 
    cin >> n ;
    
    
int sum = 0 ,  a;     
while(n--)
{
	cin >> a ;
	sum+= a ;
	
}	

if(m>0)	cout <<  sum <<endl <<endl; 	
 	else
	   if(m==0) cout << sum <<endl;
 }	
	
	
	
}


#endif






















































