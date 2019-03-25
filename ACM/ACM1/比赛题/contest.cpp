#if   0
#include<bits/stdc++.h>
using namespace std;
int main()
{
int i,n,*a,ai=0,bi=0,ci=0,flag=1;
 cin>>n;
 a=new int[n];
 for(i=0;i<n;i++)
 cin>>a[i];
 
 
 if(a[0]==50||a[0]==100)
 {
 cout<<"NO"<<endl;flag=0;
}
 else
 
    {
    	 ai++;
    	 for(i=1;i<n;i++)
    	 {
		 if(a[i]==25)
		    ai++;
		 
		 if(a[i]==50) 
		 {
		 bi++;   ai--;if(ai<0) {
		 cout<<"NO"<<endl; flag=0;break;}
		 
		 }
		 if(a[i]==100)
		{
		  
		 if(bi>0)
		 {
		ci++;ai--;bi--;
		}
		 else 
		 {
		 ci++;ai=ai-3;
		 	}
		 	
		 	if(ai<0||bi<0)
			 {
			   cout<<"NO"<<endl; flag=0;break;
		}
		  } 
    }
    	
	}
 if(flag==1)
 cout<<"YES"<<endl;
 
 
	
	delete []a;
}

#endif 

#if 0                      //contest3      . 1
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,*p,*pp,flag=1;
	cin>>n>>m;
	p=new int [n];
	pp=new int[m];
	for(int i=0;i<n;i++)
	cin>>p[i];
	for(int i=0;i<m;i++)
	cin>>pp[i];
	sort(p,p+n);
	sort(pp,pp+m);
	if(pp[0]>p[n-1])
{ 
	for(int j=p[n-1];j<pp[0];j++)

{
		for(int i=0;i<n;i++)
	if(p[i]*2==j||p[i]*2<j)
	{
		cout<<j<<endl;
		flag=0;
		break;
		
	}
	if(flag==0) break;
}

}
	if(flag==1)
	cout<<"-1"<<endl;
	
	
}

#endif

#if  0                                   // contest 3      .3 
#include<bits/stdc++.h>
using namespace std;
int main()
{
int **a,n,number=0;
cin>>n;
a=new int * [n];
for(int i=0;i<n;i++)
 a[i]=new int [2];
 for(int i=0;i<n;i++)
 for(int j=0;j<2;j++)
 {
  cin>>a[i][j];
  if(a[i][j]!=0) number=number+2;	
 }
	cout<<number+2*n<<endl;
	for(int i=0;i<n;i++)
{
	
	if(a[i][0]>0) cout<<"1 "<<fabs(a[i][0])<<" "<<"R"<<endl;
	if(a[i][0]<0) cout<<"1 "<<fabs(a[i][0])<<" L"<<endl;
	if(a[i][1]>0) cout<<"1 "<<fabs(a[i][1])<<" U"<<endl;
	if(a[i][1]<0) cout<<"1 "<<fabs(a[i][1])<<" D"<<endl;
	cout<<"2"<<endl;
	if(a[i][0]>0) cout<<"1 "<<fabs(a[i][0])<<" "<<"L"<<endl;
	if(a[i][0]<0) cout<<"1 "<<fabs(a[i][0])<<" R"<<endl;
	if(a[i][1]>0) cout<<"1 "<<fabs(a[i][1])<<" D"<<endl;
	if(a[i][1]<0) cout<<"1 "<<fabs(a[i][1])<<" U"<<endl;
	cout<<"3"<<endl;
	
}
	
	
}

#endif



//contest 4 
#if       0              // 1.
#include<bits/stdc++.h>
using namespace std;
int main()
{
int  a[1001];
int ans=0,zero=0,flag1=0;
int n;
cin>>n;
for(int i=1;i<=n;i++)
cin>>a[i];

for(int i=1;i<=n;i++)
{
if(a[i]==5) ans++;	
else 
if(a[i]==0)  zero++;

}

if(zero==0)

cout<<"-1"<<endl;

else
{

for(int i=ans;i>=1;i--)
if(i%9==0) 
{ 
  flag1=1;
	for(int j=1;j<=i;j++)
	cout<<"5";
	for(int jj=1;jj<=zero;jj++)
	cout<<"0";
	cout<<endl;
	break;
}
if(flag1==0)
cout<<"0"<<endl;
}

}

#endif





#if  0   // 2. map
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[100],x,x1,point,point1,point2;
	map<int,int> b;
	memeset(b,0,sizeof(b));
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];	
 
	for(int i=1;i<=n;i++)
	{
		if(b.count(i)) 
		continue;
		else
	{
			b[i]=1;
			
	   for(int j=i;j<=n;j++)
	   {
	  
	   	if(a[j]==a[i]) 
		   {
		   point =j;
		   
		   
	}
	   	x=j-i;
	   	
	   	
	   }
	}
	
 	}
	
	
	
}

#endif






#if  0 
   // 2. 
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[100],x,x1,point,point1,point2;
	
int b[100],ans=1,flag=0;
memset(b,0,sizeof(b));
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];	
		b[1]=a[1];
 for(int i=2;i<=n;i++)
 {   flag=0;
 	for(int j=1;j<=ans;j++)
 	if(a[i]==b[j])
	 {
	   flag=1;break;
}
 
 if(flag==0)		
 	{
 			ans++;
 			    
		 	b[ans]=a[i];
 	
}
 	
 }
 cout<<"ans"<<ans<<endl;
 
 for(int i=1;i<=ans;i++)
 cout<<b[i]<<" ";
 
/*	for(int i=1;i<=n;i++)
	{
		if(b.count(i)) 
		continue;
		else
	{
			b[i]=1;
			
	   for(int j=i;j<=n;j++)
	   {
	  
	   	if(a[j]==a[i]) 
		   {
		   point =j;
		   
		   
	}
	   	x=j-i;
	   	
	   	
	   }
	}
	
 	}
	
	
*/	
}

#endif



#if  0 // 3.
#include<bits/stdc++.h>

using namespace std;
int main()

{
	double a[2000];
double n,sum=0,sum1=0;
cin>>n; 
for(int i=1;i<=2*n;i++)
{
	cin>>a[i];
	sum+=a[i];
	if(a[i]>int(a[i])+0.5) 
	a[i]=int(a[i])+1;
	else a[i]=int(a[i]);
	sum1+=a[i];
	
	}	
	
	cout<<fixed<<setprecision(3)<<fabs(sum-sum1)<<endl;
	
}

#endif



//contst 5
#if  0
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,cha;
	int a[10000];
	int b[1000]={0};
	cin>>n;
for(int i = 0;i < n; i++)
    cin>>a[i];
    sort(a,a+n);
   for(int i=0;i<n;i++)
   cout<<a[i]<<" ";
   cout<<endl;
    for(int i=0;i<n-1;i++)
    { 
    	cha=fabs(a[i]-a[i+1]);
    	b[cha]++;
    	
	}
for(int i=0;i<1000;i++)
if(b[i]!=0)
{
 cout<<i<<" "<<b[i]<<endl;
 break;
}
}

#endif 




#if  0
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
   int *a;
   	cin>>n;
   a=new int[n];
for(int i = 0;i < n; i++)
    cin>>a[i];
    sort(a,a+n);
    
   
    for(int i=0;i<n-1;i++)
    { 
    	a[i]=a[i+1]-a[i];
	}
sort(a,a+n-1);
int ans=1;

for(int i=1;i<n-1;i++)
 if(a[i]==a[0]) ans++;
 else break;
 
 cout<<a[0]<<" "<<ans<<endl;

delete []a;
return 0;
}

#endif 



#if  0
#include<bits/stdc++.h>
using namespace std;
int  main()
{
	vector<int> a; 
	int n;
	cin>>n;
      for(int i=0;i<n;i++)
      a.push_back(i+1);
      
      
      int x;
      cin>>x;
      int *p;
      p=new int [x];
      for(int i=0;i<x;i++)
      cin>>p[i];
      
      int j=0,ans;
      for(int i=0;i<x;i++) 
      { 
                          
        ans=a[i]%a.size();
        j=(ans+j)%a.size();
        
        cout<<a[j]<<" ";
         a.erase(a.begin()+j);                
        
      	
      	
	  }
	
 } 

#endif

//        contest 6


//1 
#if  0
#include<bits/stdc++.h>
using namespace std;
int main()
{
	
	int n;
	while(cin>>n&&n!=0)
	{
		vector<string>a;
		string ai;  
		int flag=1; 
		a.clear();
		
		
		for(int i=0;i<n;i++)
	{
		
		cin>>ai;
		a.push_back(ai);
	}
		
	sort(a.begin(),a.end());
	
	for(int i=0;i<n-1;i++)
{
	if(a[i+1].find(a[i])==0)
	{
		cout<<"NO"<<endl; flag=0;break;
	}
	
		}
				
if(flag) cout<<"YES"<<endl;	
		
}

}
#endif 

//4
#if 0
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while(cin>>n&&n!=0)
	{
		vector<int>a;
		int x;
		for(int i=0;i<n;i++)
		{
			cin>>x;
			a.push_back(x);
		}
		
		sort(a.begin(),a.end());
		int sum=0;
		for(int i=1;i<n;i++)
		{
		    sum=a[i]-a[i-1]+sum;	
		}
		sum=sum+a[n-1]-a[0];
		cout<<sum<<endl;
		
	}
	
	
}

#endif



//选拔 one   17.4.2
//1.
#if  0
#include<bits/stdc++.h>
using namespace std;
int main()
{
 int n;
 cin>>n;
 for(int ii=0;ii<n;ii++)
 {
 	 int a[1000],b[1000]={0};
 	int ni;
 	cin>>ni;
 	for(int j=0;j<ni;j++)
 	{
 	      cin>>a[j];
	 }
	 
	 sort(a,a+ni);
	 
	 for(int i=0;i<ni;i++)
	 {
	    b[a[i]]++;	
	 }
	 
	
	 int ans=0,cnt,cnt1;
	 
	 for(int i=0;i<1000;i++)
	{
	    if(ans<b[i])
		 {
		 cnt=i;       
		  ans=b[i];    
		  } 
		 else
	    if(ans==b[i])  cnt1=cnt; 

 }
 
 
 if(cnt==cnt1) cout<<"Nobody"<<endl;
	    else cout<<cnt<<endl;

	
	 	  	
 }
 	
	

}

#endif 



//选拔 one  
// H 水题 

#if  0
#include<bits/stdc++.h>
using namespace std;
int main()
{
		int n;
		cin>>n;
		vector<int> a;
	for(int i = 0;i < n ; i++)
	{
		
		int cnt=0;
		
		int ni;
		cin>>ni;
		
		for(int j=0;j<ni;j++)
		{
			int x;
			cin>>x;
			a.push_back(x);
		}
		
		for(int ii=0;ii<ni;ii++)
		{
			if(a[ii]>6000) cnt++;
		}
		
		cout<<cnt<<endl;
		a.clear();
	}
	
	
}
#endif

// 选拔 one  d     题意去找上acm 
 
#if  0
#include<bits/stdc++.h>
using namespace std;
int main()
{
int n;
cin>>n;

for(int ii=0;ii<n;ii++)
{  

map<int,string> a; 
map<int,string> b;
map<int,string> c;

	int s,m,d;
	cin>>s>>m>>d;
	int ss[105],mm[105],dd[105];
	string sl[105],ml[105],dl[105];
	
	for(int i=1;i<=s;i++)
	{
	   cin>>sl[i];
		cin>>ss[i];	
		a[ss[i]]=sl[i];
	}
	
	for(int i=1;i<=m;i++)
	{
	    cin>>ml[i];
		cin>>mm[i];	
		b[mm[i]]=ml[i];
	}
	
	for(int i=1;i<=d;i++)
	{
	    cin>>dl[i];
		cin>>dd[i];	
		c[dd[i]]=dl[i];
	}
	
	sort(ss+1,ss+s+1);
	sort(mm+1,mm+m+1);
	sort(dd+1,dd+d+1);
	
	int anss,ansd,ansm,si,mi,di;
	
	if(s==1)
	anss=1;
	else
	if(s%2!=0) 
	anss=(s+1)/2;
	else 
	{
		if(ss[s/2]>ss[(s/2)+1]) 
		{
			si=s/2;
		anss=si; ;
		
	}
		else {
			si=(s/2)+1;
			anss=si;
			
		}
	}
	
	
	if(m==1)
	ansm=1;
		if(m%2!=0) 
	ansm=(m+1)/2;
	else 
	{
		if(mm[m/2]>mm[(m/2)+1]) 
		{
				mi=m/2;
		ansm=mi ;
	
	}
		else 
		{
				mi=(m/2)+1;
			ansm=mi;
		
		}
	}
	
	
	if(d==1)
	ansd=1;
	else
		if(d%2!=0) 
	ansd=(d+1)/2;
	else 
	{
		if(dd[d/2]>dd[(d/2)+1]) 
		{
			di=d/2;
		ansd=di ;
		
	}
		else
		{
			di=(d/2)+1;
			ansd=di;
		 } 
	}
	
	int sum=ss[anss]+mm[ansm]+dd[ansd]; 
	cout<<a[ss[anss]]<<" "<<b[mm[ansm]]<<" "<<c[dd[ansd]]<<" "<<sum<<endl;
	
	}	
	
	
}

#endif


//   选拔 one    E   1928年的 1.1 是星期1，输入一个 年号，问你 这一年的 五一假期 放几天？ 须看原题稍加理解 
#if  0 
#include<bits/stdc++.h>
using namespace std;
int main()
{ 
	int n,ni;
	cin>>ni;
	for(int j=0;j<ni;j++) 
	{
		int cnt=0;
	
	cin>>n;
	
	for(int i=1928;i<n;i++)
	{
		if(((i%4)==0&&(i%100!=0))||(i%400==0))
		cnt+=366;
		else 
		cnt+=365;	
	} 
	if(((n%4==0)&&(n%100!=0))||(n%400==0))
	   cnt=cnt+121;
	   else cnt+=120;
	   
	int x=cnt%7;
	
	if(x==1) cout<<9<<endl;
	else 
	if(x==2||x==0) cout<<6<<endl;
	else 
	if(x==6||x==3||x==4||x==5) cout<<5<<endl;

}

}

#endif

 



//选拔 two
//1. 

#if 0
#include<bits/stdc++.h>
using namespace std;
int a[102];

int main()
{
	int n,i;;
	cin>>n;

	for(int j=0;j<n;j++)
	{
	memset(a,0,sizeof(a));	
	
	int x,num;
	
	cin>>x>>num;

	for(int i=0;i<x;i++)
{
	int xi;
	cin>>xi;
	a[i]=100-xi;
}
	
	
	sort(a,a+x);
	

	
	int cnt=0;

	for( i=0;i<x;i++)
	{
	cnt+=a[i];
	if(cnt>num) 
	break;
	}
		
cout<<i<<endl;	

	}

return 0;	
	
}

#endif 







//2
#if         0
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
 int n;
 cin>>n;
 while(n--)
 {
 	double xi,yi,xii,yii,ri,rii,sumr,cha;
 	double disp;
 	
 	cin>>xi>>yi>>ri>>xii>>yii>>rii;
 	
 	sumr=ri+rii; 
 	cha=fabs(ri-rii);
 	
 	disp=sqrt(1.0*(xi-xii)*(xi-xii)+1.0*(yi-yii)*(yi-yii));
 	
 	if(disp==1.0*sumr) cout<<"3"<<endl;
 	else 
	 if(disp>1.0*sumr) cout<<"4"<<endl;
 	else 
	 if(disp>1.0*cha&&cha<disp) cout<<"2"<<endl;                    //相交 
 	else 
 	  if( disp<1.0*cha&&cha>disp) cout<<"0"<<endl;    
	   else 
	    if( disp==1.0*cha&&cha==disp )cout<<"1"<<endl;
	                               
 	  else if(disp==0.0&&ri==rii)
 	  cout<<"-1"<<endl;
 	
	 }	
	
	
 } 
 
#endif







#if  0 // e
#include<bits/stdc++.h>
using namespace std;
int com(int &a,int &b)
{
	return a>b;
}
int main()
{

int n;
cin>>n;
vector<int> a;
int x;
for(int i=0;i<n;i++)
{
	cin>>x;
	a.push_back(x);
}

sort(a.begin(),a.end(),com);	
	
	cout<<a[0]<<endl;
	
	
}
#endif


//contest three

#if  0
#include<bits/stdc++.h>
using namespace std;
int main()
{

	int ni;
	cin>>ni;
    while(ni--)
	{
			int a[102]={0};
		int n;
		cin>>n;
		
		for(int i=0;i<n;i++)
	         cin>>a[i];
	         
 sort(a,a+n);
 if(a[0]==a[1]) cout<<a[n-1]<<endl;
 else cout<<a[0]<<endl;
		
	}
	return 0;
	
}

#endif








#if  0                     // h
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int  ai,hi,aii,hii;
		cin>>ai>>hi>>aii>>hii;
		
		if(ai==0) cout<<"Invalid"<<endl;
		
		else  if(aii<hi&&ai<hii) cout<<ai<<" "<<hi-aii<<" "<<aii<<" "<<hii-ai<<endl;
		
		else if(aii>=hi&&ai>=hii) cout<<"Discard"<<" Discard"<<endl;
		
		else if(hi>aii&&hii<=ai) cout<<ai<<" "<<hi-aii<<" "<<"Discard"<<endl;
		
		else if(aii>=hi&&ai<hii) cout<<"Discard "<<aii<<" "<<hii-ai<<endl;	
		
	}
	
	
	
}

#endif




//训练赛 7

//1
#if  0
#include<bits/stdc++.h>
using namespace std;
int main()

{
int n;
cin>>n;

long long int sum=n;

for(int i=0;i<n-1;i++)
   sum=sum*n;
	
	cout<<sum<<endl;
}

#endif 

// 3cifang
#if  0
#include<bits/stdc++.h>
using namespace std;
int main()

{
int n;
cin>>n;

long long int sum=n;

for(int i=0;i<2;i++)
   sum=sum*n;
	
	cout<<sum<<endl;
}

#endif 

//cheng 9
#if 0

#include<bits/stdc++.h>
using namespace std;
int main()

{
int n;
    cin>>n;
  
      int sum= n*9;
	
	cout<<sum<<endl;
}

#endif


// 斐波那契数列  错了 
#if 0
#include<bits/stdc++.h>
using namespace std;
int main()

{
int a[31] ;
a[1]=1; a[2]=26;
for(int i=3;i<31;i++)	
	
	a[i]=a[i-1]+a[i-2];
	
	int n;
	cin>>n;
	cout<<a[n]<<endl; 
}


#endif








//f 最后一个题 
#if 0
#include<bits/stdc++.h>
using namespace std;
int main()

{
	int n;
	cin>>n;
	int a[12]={0};
	for(int i=0;i<n;i++)
	cin>>a[i];
	
	sort(a,a+n) ;
	
	for(int i=0;i<n;i++)
	cout<<a[i]<<" "; 
	
}


#endif

// D 

#if 0
#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int sum=0;
	 
	 for(int i=0;i<s.length();i++)
	 {
	 	if(s[i]=='0')  sum+=0;
	 	else if(s[i]=='1') sum+=1;       
		 else if(s[i]=='2') sum+=2;
		 else if(s[i]=='3') sum+=3;
		 else if(s[i]=='4') sum+=4;
		 else if(s[i]=='5') sum+=5;
		 else if(s[i]=='6') sum+=6;
		 else if(s[i]=='7') sum+=7;
		 else if(s[i]=='8') sum+=8;
		 else if(s[i]=='9') sum+=9;
		  	
		 }	
	
 if(sum>10) cout<<"Yes"<<endl;
 else cout<<"No"<<endl;
}


#endif 


#if  0 

#include<bits/stdc++.h>
using namespace std;
int main()

{
   int  a[100005],b[100005],t[100005];
   	int n;
   	cin>>n;
   	
   	for(int i=0;i<n;i++)
          cin>>a[i];
             
             
            b[0]=(fabs(a[0]-a[1])) ;
             int cha,end;
             for(int i=1;i<n-1;i++)
             {
             	cha=fabs(a[i]-a[i+1]);
             	end=cha*(-1);
               b[i]=end;
             
			 }
			 
		
t[0]=b[0];
       int max=t[0];
       for(int i=1;i<n-1;i++)
       {
       	 if(b[i]+t[i-1]<0) t[i]=0;
       	 else t[i]=t[i-1]+b[i];
       	if(max<t[i]) max=t[i];
       	
	   }

	cout<<max<<endl;
}


#endif

// contest 8
#if  0      // 1.
#include<iostream>
using namespace std;
int main()

{
	int n;
	cin>>n;
	while(n--)
	{
		int ni,mi;
		cin>>ni>>mi;
		int a[10],b[10];
		
		int sun=0,sum=0;
		for(int i=0;i<ni;i++)
	{
			cin>>a[i];
			sun+=a[i];
	}
		for(int i=0;i<mi;i++)
	{
		cin>>b[i];
		sum+=b[i];
	}
	if(sun>sum) cout<<"Calem"<<endl;
	else if(sun<sum) cout<<"Serena"<<endl;
	else cout<<"Draw"<<endl;
	
		
		
	}
	
	
}


#endif 


//3.

#if  0
#include<iostream>
using namespace std;
int main()

{
	int n;
	cin>>n;
	while(n--)
	
{
	int  n,m;
	cin>>n>>m;
     int sum=0;
	int max=0;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
	      sum+=x;
	      if(max<x) max=x;
	}
	
	    if(n<=m) cout<<max<<endl;
	    else 
	    {
	    	int ans;
	    	ans=sum/m;
	    	if(sum%m!=0)  ans++;  
	    	if(ans<max) ans=max; 
			cout<<ans<<endl;
					}
	 
		
	}
	
	
}



#endif

//g

#if 0
#include<string>
#include<iostream>
using namespace std;
int main()

{
	int n;
	 cin>>n;
	 
	 while(n--)
	 {
	   int x1,x2,x3;
	    char y1,y2;
	    cin>>x1>>y1>>x2>>y2>>x3;
	    int n1,n2,sum;
	    
	    if(y1!='%'&&y1!='*'&&y1!='/'&&y2!='%'&&y2!='*'&&y2!='/')
	    {
	    	if(y1=='+') n1=x1+x2; 
	    	else if (y1=='-') n1=x1-x2;
	    	
	    	if(y2=='+') n2=n1+x3;
	    	else  if(y2=='-') n2=n1-x3;
	    	
	    	sum=n2;
		}
	     else if ((y1=='%'||y1=='*'||y1=='/')&&(y2=='+'||y2=='-')) 
		 {
		 	if(y1=='%') n1=x1%x2; 
		 	else if(y1=='*') n1=x1*x2;
		 	else if(y1=='/') n1=x1/x2;
		 	
		 	if(y2=='+') n2=n1+x3;
		 	else if(y2=='-') n2=n1-x3;
		 	sum=n2;
		  }
		  
		  else if((y2=='%'||y2=='*'||y2=='/')&&(y1=='+'||y1=='-')) 
		  {
		  	if(y2=='%') n2=x2%x3; 
		 	else if(y2=='*') n2=x2*x3;
		 	else if(y2=='/') n2=x2/x3;
		 	
		 	if(y1=='+') n1=n2+x1;
		 	else if(y1=='-') n1=x1-n2;
		 	
		 	sum=n1;
		  	
		  }
		   else if((y1=='*'||y1=='/'||y1=='%')&&(y2=='*'||y2=='%'||y2=='/'))
		   
		   {
		   	 if(y1=='*') n1=x1*x2;
		   	 else if(y1=='/') n1=x1/x2;
		   	 else if(y1=='%') n1=x1%x2;
		   	 
		   	 if(y2=='*') n2=n1*x3;
		   	 else if(y2=='/') n2=n1/x3;
		   	 else if(y2=='%') n2=n1%x3;
		   	 
		   	 sum=n2;
		   	
		   }
		   
		   cout<<sum<<endl;
	 
	 }
	
	
}


#endif 










// j

#if 0                       //chaoshi
#include<iostream>
using namespace std;
int main()

{
	int n;
	cin>>n;
	int a[100] ={0};
	while(n--)
	{                  
		int x;
		cin>>x;
	 int tall=0;
		for(int i=1;i<=x;i++)
		{ 
		if(a[i]) tall+=a[i] ;
		else
		   {
		   int sum=i;
		   for(int j=1;j<i;j++) 
			 sum=sum*i;
			 a[i]=sum;
			 	tall+=sum;
	}
		   
		   
	
		}
		
		if(tall%7==0) cout<<"Saturday"<<endl;
		else if(tall%7==1) cout<<"Sunday"<<endl;
		else if(tall%7==2) cout<<"Monday"<<endl;
		else if(tall%7==3) cout<<"Tuesday"<<endl;
		else if(tall%7==4) cout<<"Wednesday"<<endl;
		else if(tall%7==5) cout<<"Thursday"<<endl;
		else if(tall%7==6) cout<<"Friday"<<endl;
		
	}
	
	
}

#endif


// j 2 

#if   0
#include<iostream>                                   
using namespace std;
int main()
{
	int n;
	cin>>n;
	while(n--)
	{                  
		int x;
		cin>>x; 
		int tall=0;
		int ans=1;      
		for(int i=1;i<=x;i++)
		{     ans=i%7;
			for(int j=1;j<i;j++)
			{
				ans=ans*ans;
				if(ans>=7) ans%=7;
			}
			tall+=ans;
			if(tall>=7) tall%=7;
		}
		
		  	
		if(tall==0) cout<<"Saturday"<<endl;
		else if(tall==1) cout<<"Sunday"<<endl;
		else if(tall==2) cout<<"Monday"<<endl;
		else if(tall==3) cout<<"Tuesday"<<endl;
		else if(tall==4) cout<<"Wednesday"<<endl;
		else if(tall==5) cout<<"Thursday"<<endl;
		else if(tall==6) cout<<"Friday"<<endl;
		
	}
	
	
}

#endif

// l
#if  0
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
	 string a[20005] ;
	 int x;
	 cin>>x;
	 

	
}



}
#endif















