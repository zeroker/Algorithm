//素数环问题 任意相邻的两个数字的和是素数

#if 0
#include<iostream>
#include<cmath>
using namespace std;
int N , toal;

bool pd[21] ;
int ret[21] ;
int prime(int a ,int b) 
{
  int x=a+b ,cnt=2;
  int sqrx=sqrt(x) ;
 
while(cnt<=sqrx&&x%cnt!=0)
 cnt++;
if(cnt>sqrx) return 1;
else return 0 ;

}

int show()
{
	for(int i=1 ; i < N ;i++)
	  cout << ret[i]<<" " ;
	  cout << ret[N]<< endl;	
}

int dfs(int t,int n)
{
	int i  ;
	
	for(i = 1 ; i <= n ; i++)
	{
		if(prime(ret[t-1],i) && !pd[i])
		{
			ret[t]=i;
			pd[i]=1;
		if(t==n)
	{
		if(prime(ret[n],ret[1])&&ret[1]==1) 
		show();
	}
        else    
		 dfs(t+1,n) ;
         pd[i]=0;
		}
	}

      	
	
}

int main()
{
  	while(cin>>N)
  	{
  		toal++ ;
  		cout << "Case "<<toal<<":"<<endl;
		  dfs(1,N) ;
  		cout << endl;
	}

	
 } 


#endif 
 
