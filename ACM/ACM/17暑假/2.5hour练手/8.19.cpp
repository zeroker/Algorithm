

#if 0
#include<iostream>
#include<string>
using namespace std;
const int MAXX=1e9+7;
const int MAXN=1e6+5;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		char c1[MAXN],c2[MAXN];
		string s1,s2;
		
		scanf("%s",&c1);
		scanf("%s",&c2);
		
		s1=c1;
		s2=c2;
		
		int sum=0;
		int len2=s2.size();
		for(int i=0; i<len2; i++)
		{
			 int ni=len2-i,li=0; 	       
		
			string s=s2.substr(i,ni);

			int x=s1.find(s,0);    
			
			while(x!=-1)
			{
				li++;
				x=s1.find(s,x+1);						
			}
			
			sum+=ni*li;
			if(sum>=1e9+7);
				sum=sum%(MAXX);
		}
		
		printf("%d\n",sum);
	}
	
}
#endif


#if 0
#include<iostream>
using namespace std;
int main()
const int MAXN=3005;
int a[MAXN][MAXN];
{
	int n,T;	
	scanf("%d",&T);
	while(T--)
	{
		cin>>n;
		for(int i=1; i<n; i++)
		{
			for(int )
			
		}
	}
	
}

#endif 


#if 1
#include<iostream>
using namespace std;
int main()


{
	int sum=0;	
	for(int i=2; i<=36; i++)
		sum+=i;
	cout<<sum<<endl;
}

#endif 










































