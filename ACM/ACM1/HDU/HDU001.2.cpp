//string 操作 

//1.12 reverse  反转
/*
3
olleh !dlrow
m'I morf .udh
I ekil .mca

Sample Output
hello world!
I'm from hdu.
I like acm.
 */ 
 
#if 0 
#include<bits/stdc++.h>
using namespace std;
int main() 
{
	char s[1001], s1[1001];
	int len, i, j, p;
	int n ;
	cin>>n;
	
	getchar();
	
	while(n--)
	{
		gets(s); 
	 len=strlen(s);
	 for(i=0,j=0; i<len; i++)
	 {
	 	if(s[i]!=' ')
	 	s1[j++]=s[i];
	 	else
	 {
	   for(p=j-1; p>=0; p--)
	      cout<<s1[p];
	       cout <<" ";
	       j=0;
	  }
	 }
	 	for(p=j-1; p>=0; p--)
		cout <<s1[p];
		cout << endl; 
	}	
}

#endif










//2.
//题意就是说 ：输入一个n 这个n 个人， 还有m,从1开始 每隔m-1个人开始遍历，看看能不能全部遍历。
//例如 3 2 就可以 。 
//潜在的 规律  要是 m and n 没有 除了1以外 的公约数 就可以了。 
//但是 这个规律 是别人发现的 有木有 ， 自己写的代码 却是runtime  啊 
#if 0
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n , m ;
	
	while(cin>>n>>m && n!=-1 && m!=-1)
	{ 
		int a[1000] ,j ,x;
		bool vis[1000];
memset(vis,false,sizeof(vis)) ;
	
		a[0] = 1;
		for(int i=1; i<n; i++)
		  a[i] = a[i-1] + m; 
		  
		for(int i=0; i<n; i++)
		{
		if(a[i]<=n)
		 vis[a[i]] = 1;
		else
		 
		  {
			 x=a[i]%n;
		   	 vis[x] = 1;
		   }
		   
		}  
		 	 
		for( j=1; j<=n; j++)
		{
			if(vis[j]==0) 
			{
			
				cout << "POOR Haha" <<endl;
					break;
			}
			if(j==n) cout <<"YES" <<endl;
		}
		
	 }
	
	return 0 ;
}

#endif 

#if 0
#include<bits/stdc++.h>
using namespace std;
int main()

{
  int n , m ;
  while(cin>>n>>m && n!=-1 && m!=-1)	
{
  int t;
  while(m!=0)
{
  t = n % m;     	
  n = m ;
  m = t;
      		
 }
if(n==1) cout << "YES" <<endl;
else cout <<"POOR Haha"<<endl;	
	
}
}
#endif

//3. 输出 一串数中 不一样的 那一个  一次成功 excing a     /主要还是找思路 
#if 0
#include<bits/stdc++.h>
using namespace std;
int main()
{
 int n ;
 ios::sync_with_stdio(false) ; //这个 
 while(cin>>n && n)
 {
 	vector<int> v;
 	for(int i=0; i<n; i++)
 	{
 		int x ;
 		cin>>x;
 		v.push_back(x) ;
	 }
 	sort(v.begin(),v.end());
 	
 	int cnt , ans;
 	
 	cnt=v[0];
 	if(v[1]!=v[0])
 	cout << v[0] <<endl;
 	ans=v[n-1];
 	if(v[n-1]!=v[n-2]) 
 	cout << v[n-1] <<endl;
 	
 	for(int i=1; i<n-1; i++)
	 {
 		if(v[i]!=v[i-1] && v[i] !=v[i+1])
 		cout << v[i] <<endl;
	 }
 }
	
	
}


#endif

//4.ACM: 1*1 + 2*3 + 3*13 = 46MID CENTRAL: 1*13 + 2*9 + 3*4 + 4*0 + 5*3 + 6*5 + 7*14 + 8*20 + 9*18 + 10*1 + 11*12 = 650

/
//应该有更简洁的 代码 
#if 0
#include<bits/stdc++.h>
using namespace std;
int main()
{
  map<char,int> m ;
  for(int i=65; i<=90; i++)
  {
   m[char(i)] = i-64;	
  }
m[' '] = 0 ;

string s;
while(getline(cin,s) && s!="#")
{
	int sum=0;
	for(int i=0; i<s.size(); i++)
	{
		sum +=(i+1)*m[s[i]] ;
	}
	cout << sum << endl;
}
return 0;	
}

#endif 

          
#if 0                   //更简洁，更快 ，更完美的代码，初衷~ 
#include<bits/stdc++.h>
using namespace std;
int main()
{ 
    char  s ;
    ios::sync_with_stdio(false) ;
    int sum=0 , i=1;
    while(1)
    {
    s=getchar() ;
    
    if(s=='#') break;
    
    else if(s=='\n')
      {
      	cout << sum <<endl;
      	
      	sum=0; 
		  
		 i=1;
		 
		 //continue; 在这里没有用 
	  
	  }
	  else 
	  {
	  sum +=(s==' ')?0:i*(s-'A'+1);
	  i++;
     }
   }
}

#endif 

// 
/*
4
+ 1 2
- 1 2
* 1 2
/ 1 2
简单的 加减乘除 
*/ 

#if 0
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n , a, b;
	char f ;
	cin>>n;
	
	while(n--)
	{
		cin>>f>>a>>b;
		if(f=='+') cout << a+b <<endl;
		if(f=='-') cout << a-b <<endl;
		if(f=='*') cout << a*b <<endl;
		if(f=='/') 
		{
			if(a%b==0) cout << a/b <<endl;
			else cout<<fixed<<setprecision(2)<<double(a)/b<<endl;
			
		}	
	}
	
	
}


#endif 

//5
/*

Input
The input file will contain data for one or more test cases, one test case per line. On each line there will be one or more upper case letters, separated by blank spaces.


Output
Each line of input will result in exactly one line of output. 
If all upper case letters on a particular line of input came from the set {A, B, C, D, F} then the output will consist of the GPA, 
displayed with a precision of two decimal places. 
Otherwise, the message "Unknown letter grade in input" will be printed.


*/
///水
#if  0
#include<bits/stdc++.h>
using namespace std;
int main()
{
	char ch ;
	
	int sum=0,i=0;
	bool flag=0;
	while(ch=getchar())
	{
		
		
		
	
		if(ch=='A'||ch=='B'||ch=='C'||ch=='D'||ch=='F'||ch==' ') 
		{
			if(ch=='A') { sum+=4;i++;
			}
			else
			  if(ch=='B') {sum+=3;i++;
			  }
			else
			   if(ch=='C') {sum+=2;i++;
			   }
			else
			    if(ch=='D') {sum+=2;i++;
				}
			else 
			    if(ch=='F') {sum+=0;i++;
				}
		}
		else 
		{
			flag=1;
		cout << "Unknown letter grade in input"<<endl;  
		
	}

	if(ch=='\n' && flag==0)
	{
		
			cout << fixed << setprecision(2)<< double(sum)/i <<endl;       
			sum=0;
			i=0;
	
	
	}
	 
	
	
	
	}
	
}

#endif 
// 虽然水  但是在用什么输入的时候 没有选择 好， 还是有坑 还是有弯的 
#if 0 
#include<bits/stdc++.h>
using namespace std;
int main()
{
  char s[100];
  int len,sum;
  bool flag=0;

while(gets(s))
{ 
	 flag=0;
	 int sum=0;
   len=strlen(s);
   
 for(int i=0; i<len; i++)
 {
 
 if(s[i]==' ')
  sum+=0;
  else
  if(s[i]=='A')
   sum+=4;
   else
   if(s[i]=='B')
   sum+=3;
   else
   if(s[i]=='C')
   sum+=2;
   else
   if(s[i]=='D')
   sum+=1;
   else
   if(s[i]=='F')
   sum+=0;
	else 
	{
		cout << "Unknown letter grade in input" <<endl;
		flag=1;
		break;
	}
 	
 }
 if(flag==0)
 cout << fixed << setprecision(2) << double(sum)/((len+1)/2)<<endl;	

}	
		
}

#endif

//1.2.8
//不知道为什么不对啊  啊  
/*
input
1
330000198910120036


Sample Output
He/She is from Zhejiang,and his/her birthday is on 10,12,1989 based on the table.



*/
#if 0
#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	map<string,string> m;
	m["330000"]="Zhejiang";
	m["110000"]="Beijing";
	m["710000"]="Taiwan";
	m["810000"]="Hong Kong";
	m["820000"]="Macao";
	m["540000"]="Tibet";
	m["210000"]="Liaoning";
	m["310000"]="Shanghai";
 int n;
 cin>>n;
 
 while(n--)
 {
 	cin>>s;
 	string Num ,year, month, day;
 	Num=s.substr(0,6);
    year=s.substr(6,4);
    month=s.substr(10,2);
    day=s.substr(12,2);
    
    cout <<"He/She is from "<<m[Num] <<",and his/her birthday is on "<<month<<","<<day<<","<<year<<" based on the table."<<endl;

Num="";
year="";
month="";
day="";
s="";
 }
 return 0;
}
#endif 

///人家写的 却对了  差距~ 
#if 0 
#include <stdio.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<map>
using namespace std;
char a[20],mp[88][15];
int main()
{
    int n,y,m,d,dd;
    strcpy(mp[33],"Zhejiang");
    strcpy(mp[82],"Macao");
    strcpy(mp[11],"Beijing");
    strcpy(mp[54],"Tibet");
    strcpy(mp[71],"Taiwan");
    strcpy(mp[21],"Liaoning");
    strcpy(mp[81],"Hong Kong");
    strcpy(mp[31],"Shanghai");
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s",a);
        dd=0; y=0;
        for(int i=0;i<2;i++) dd=dd*10+a[i]-'0';
        for(int i=6;i<=9;i++) y=y*10+a[i]-'0';
        printf("He/She is from %s,and his/her birthday is on ",mp[dd]);
        printf("%c%c,%c%c,%d",a[10],a[11],a[12],a[13],y);
        printf(" based on the table.\n");
    }
}


#endif























































