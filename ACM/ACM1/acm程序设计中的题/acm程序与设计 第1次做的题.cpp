#if  0             // 2题 
#include<iostream>
#include<map>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
   map<string,string>a ;
   char s[30],s1[12],s2[12];
   int n,i;
   while(gets(s))
   {
   	 if(strcmp(s,"")==0) break;
   	 else
   	  {
   	    n=strlen(s);       
   	    for(i=0;i<n;i++)
   	    {
   	    	if(s[i]==' ')break;
		   }
		 }
		   strncpy(s1,s,i);
		   s1[i]='\0';
		 
		 strncpy(s2,s+i+1,n-i);
	        s2[n-i]='\0';
	        a[s2]=s1;
		 
   }	
 	while(cin>>s2)
 	{
 		if(a[s2]=="")
 		cout<<"eh"<<endl;
 		else cout<<a[s2]<<endl;
	 }
	
	 }
	
#endif 

#if   0              //孔 2题 
#include<iostream>
#include<string>
using namespace std;
int main()
{
	
	string a[10005];
	string b,c[100];
	int i=0,j=0,k,m;
	while(getline(cin,a[i]))
	{
		if(a[i].size()==0) break;
		i++;
	}
	while(getline(cin,b))
	{
		if(b.size()==0) break;
		for(k=0;k<i;k++)
		{
			if()
			
				m=a[k].find(b);
			   string bi=a[k].substr(0,m);
			   if(bi==b)
			   cout<<
			
			else cout<<"eh"<<endl;
		}
		j++;
	}
	
	
	
	return 0;
}



#endif


//2.
#if  0                     //my 
#include<bits/stdc++.h>
using namespace std;
int main()
{
	map<string,string>m; 
	string a,ai,bi;
	int ii,n;
	
	while(getline(cin,a))
	{
		if(a=="") break;
		n=a.size();
		ii=a.find(" ");
		ai=a.substr(0,ii);
		bi=a.substr(ii+1,n-ii);
		m[bi]=ai;
	
	}
while(getline(cin,ai))
{
	if(m.count(ai))
	cout<<m[ai]<<endl; 
	else cout<<"eh"<<endl;
	
}


}

#endif 



#if    0                    //my 
#include<bits/stdc++.h>
using namespace std;
int main()
{

	string a,ai[100],bi[100],aii;
	int ii,n,i=0;
	
	while(getline(cin,a))
	{
		if(a=="") break;
		n=a.size();
		ii=a.find(" ");
		ai[i]=a.substr(0,ii);
		bi[i]=a.substr(ii+1,n-ii);
	i++;
	
	}
while(getline(cin,aii))
{ 
int ni=0;
	for(int i=0;i<100;i++)
	{
		if(bi[i]==aii)
		{
		cout<<ai[i]<<endl;ni=1;break;
	    }
	   ; 
	}
 if(ni==0)
	     cout<<"eh"<<endl;	
	
}


}

#endif 



#if  0  // 10
#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n,i;
	string aa;

 cin>>n;
 for(i=0;i<n;i++)
 {
 	cin>>aa;
 	int ii=aa.size();
 	cout<<"String #"<<i+1<<endl;
 	for(int j=0;j<ii;j++)
 	{
 		if(aa[j]!='Z')
 		cout<<char(aa[j]+1);
 		else cout<<'A';
	 }
	 
	 cout<<endl<<endl;
	 
 }
 
	
}

#endif 


#if      0      //15 accepd
#include<bits/stdc++.h>
using namespace std;
struct k
{
	string ai;
	int n;
} ;
int main()
{
	string a;

	int ni;
	
	while(cin>>ni&&ni!=0)
	{
	map<string,int>m;
	 k p[100];
	 for(int i=0;i<ni;i++)
	 p[i].n=0;
	 
		for(int i=0;i<ni;i++)
		{
			cin>>a;
			if(m.count(a)==0 ) {	m[a]=i; p[i].n=1 ;p[i].ai=a;
			}
			else if(m.count(a)==1) { p[m[a]].n++;
			}
		}
		int b=0;
		for(int i=1;i<ni;i++)
		{
			if(p[b].n<p[i].n) b=i;
		}
		cout<<p[b].ai<<endl;
		
	}

	
	
}

#endif


#if    0              // 21.
#include<iostream>
using namespace std;
int main()
{
	
	
	int n=0,i=3,di;
	 
	 while(cin>>di) 
	 {   
	 	while(n!=di)
	 	{
	 		
	 	 if(i%3==0||i%5==0)
	 			n++;
			 
	 		i++;
	 		
		 }
		 cout<<i-1<<endl;	
	 }
return 0;	
}

#endif





#if 0                   // 21.第二条思路 
#include<iostream>
using namespace std;
int main()
{
int a[100000],i,j=0;
for(i=0;i<100000;i++)
{
	if(i%3==0||i%5==0)
	a[j++]=i;
}
while(cin>>i)
{
	cout<<a[i]<<endl;
	}	
	
}

#endif


#if 0
#include<bits/stdc++.h>
using namespace std;
int main()
{
int n;
cin>>n;
string a[2];
for(int i=0;i<2;i++)
cin>>a[i];
for(int i=0;i<2;i++)
cout<<a[i]<<endl;

 
	
}

#endif 


#if    0                     //13
#include<bits/stdc++.h>
using namespace std;
int main()
{
vector <int> v;
int n;
cin>>n;
while(n!=-1)
{
	v.push_back(n);
	int x,sum=0;

	while(	cin>>x&&x!=0)
	{
		
		v.push_back(x);
	
	}
	for(int j=0;j<v.size();j++)
	{     
		for(int jj=0;jj<v.size();jj++)
		if(v[jj]==2*v[j]) sum++;
	}
	cout<<sum<<endl;
	cin>>n;
	v.clear();
	}	
	
	
}

#endif



#if 0                    //11.
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n,j=1;
	cin>>n;
	while(n!=0)
	{
	vector<int> a;
		int ni=0,sum=0;
	
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		a.push_back(x);
		sum=sum+x;
		}	
		int ver=sum/n;
		for(int i=0;i<n;i++)
		{
		if(a[i]<ver) ni=ni+(ver-a[i]);
			
		}
		cout<<"Set #"<<j<<endl;
		cout<<"The minimum number of moves is "<<ni<<"."<<endl<<endl;
		j++;
		cin>>n;
	}
	
	return 0;
	
}

#endif



#if   0                  // 12.
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	cin.get();
	string s;
	  for(int j=1;j<=n;j++)
	{
			getline(cin,s);
		
			reverse (s.begin(),s.end());
			cout<<s<<endl;
		
	}
	return 0;	
}

#endif











#if  0    // 20
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int b,n;
	cin>>b>>n;
	while(b!=0&&n!=0)
	{
		for(int i=1;;i++)
		{
		   	if(fabs(pow(i,n)-b)<fabs(pow(i-1,n)-b)&&fabs(pow(i,n)-b)<fabs(pow(i+1,n)-b))
		   {
			   	cout<<i<<endl; break;
				    }
		}
	cin>>b>>n;	
	}
	
	
	
}


#endif



#if   0                         // 25
#include<bits/stdc++.h>
using namespace std;
int main()
{
int n,p=1,ni;
cin>>n;


for(int i=0;i<n;i++)
{
	
	string a;
	cin>>a;
	 ni=a.size();
	 

for(int j=0;j<ni;j++)
{
	if(a[j]==a[j+1])
	p++;
	else
{
	cout<<p<<a[j]; p=1;
}
	
}
cout<<endl;

}
return 0;		
}
	
#endif


#if     0           // 26        
#include<bits/stdc++.h>
using namespace std;
int main()

{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int a,b;
		string ai,bi;
		cin>>a;
		char p[10];
		for(int j=0;j<a;j++)
		{
		 cin>>p;
		 
			 ai=ai+p[0];
			
	}
	
	cin>>b;
	
	char pi[10];
	for(int jj=0;jj<b;jj++)
	{
		cin>>pi;
		bi=bi+pi[0];
	
	}
	

	if (ai==bi) cout<<"SAME"<<endl;
	else cout<<"DIFFERENT"<<endl;
		
	


}
}


#endif

#if   0           /// 23 //////////////////////
#include<bits/stdc++.h>
using namespace std;
int main()
{
int n,ni,t=0;

cin>>n>>ni;

while(n!=0&&ni!=0)
{
    int sum=0;
int **a;
a=new int *[n];

for(int i=0;i<n;i++)
	{
		a[i]=new int[ni];
	}
	
	
	for(int i=0;i<n;i++)
	for(int j=0;j<ni;j++)
	cin>>a[i][j];
	
		for(int i=0;i<n;i++)
	for(int j=0;j<ni;j++)
{
	sum+=a[i][j];
}
if(sum==ni*n)
{
	cout<<"No"<<endl;
	t=1;
	cin>>n>>ni;
	for(int i=0;i<n;i++)
           delete []a[i];

}
	
else 
for(int i=0;i<ni-1;i++)
{
	if(a[n-1][i]==0&&a[n-1][i+1]==0 )
	{
		cout<<"No"<<endl;
		 t=1;
		for(int i=0;i<n;i++)
           delete []a[i];
           cin>>n>>ni;
	}
}
	
	if(t)
	 continue ;
	for(int i=0;i<n-1;i++)
	for(int j=0;j<ni-1;j++)
	{
		
	if((a[i][j]==0&&a[i+1][j]==0)||(a[i][j]==0&&a[i][j+1]==0))
	{
		 cout<<"No"<<endl;
		 break;	}
		 else 
		 {
		 cout<<"Yse"<<endl;
		 break;
	} 
		
	
	}
cin>>n>>ni;
for(int i=0;i<n;i++)
 delete []a[i];
}
}

#endif


#if   0                      //////////////         23
#include<bits/stdc++.h>
using namespace std;
int main()
{
int n,ni;

cin>>n>>ni;

while(n!=0&&ni!=0)
{
    int sum=0;
int **a;
a=new int *[n+1];

for(int i=0;i<n+1;i++)
	{
		a[i]=new int[ni];
	}
	
	
	for(int i=0;i<n;i++)
	for(int j=0;j<ni;j++)
	cin>>a[i][j];
	
	for(int i=0;i<ni;i++)
	a[n][i]=1;
	
		for(int i=0;i<n;i++)
	for(int j=0;j<ni;j++)
{
	sum+=a[i][j];
}
if(sum==ni*n)
{
	cout<<"No"<<endl;


}
	
else 

{
	for(int i=0;i<n;i++)
	for(int j=0;j<ni-1;j++)
	{
		
	if((a[i][j]==0&&a[i+1][j]==0)||(a[i][j]==0&&a[i][j+1]==0))
	{
		 break;
		 cout<<"No"<<endl;
		
		}
		 else 
		 {
		 	 break;
		 cout<<"Yse"<<endl;
		
	} 
		
	
	}
	
}
cin>>n>>ni;
for(int i=0;i<n;i++)
 delete []a[i];
}
}

#endif

                           //  18 .
#if    0
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int q[100],j=0;
	memset(q,0,sizeof(a));
	for(int i=2;;i++)
	{
		if(q[99]!=0) break;
		int k=sqrt(i);
		jj=2;
		while(i%jj&&i<=k)
		
	
		
	}
	
	
}
#endif



#if 0                              // 20 进制 的题 srong
#include<bits/stdc++.h>
using namespace std;
int main()
{
 string a,ai;
char b[100],bi[100],c[100];
cin>>a>>ai;	
int an,ain;
an=a.size();
ain=ai.size();
while(an!=0&&ain!=0)

{

for(int i=0;i<an;i++)
{
	b[i]=a[an-i-1];
}

for(int i=0;i<ai.size();i++)
  {
  	bi[i]=ai[ain-i-1];
  }
  
  
  for(int i=0;i<an||i<ain;i++)
  {
     if(m[b[i]]+m[bi[i]]>10)
     c[i]=
  	
  	
  }
  	
}


}
#endif

#if    0                      /////////////  14. wrong 
#include<bits/stdc++.h>
using namespace std;
int main()
{ 
string a,b;
int  ai[100],bi[100],c[100];


	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{ 
	 int aj,bj; 
		memset(ai,0,sizeof(ai));
			memset(bi,0,sizeof(bi));
				memset(c,0,sizeof(c));
		int x=0;
		int lenc=0;
		cin>>a>>b;
		int an=a.size();
		int bn=b.size();
		
		for(int i=0;i<an;i++)
		ai[i]=a[i]-48;
		for(int i=0;i<bn;i++)
		bi[i]=b[i]-48;
	
		
		while(lenc<=an||lenc<=bn)
		{
			c[lenc]=ai[lenc]+bi[lenc]+x;
		     	x=c[lenc]/10;
		    	c[lenc]%=10;
			
		 lenc++;	
		}

for(int i=0;i<lenc-1;i++)
cout<<c[i];



	cout<<endl;
}

	 
	 

			
	}
	

#endif 
























