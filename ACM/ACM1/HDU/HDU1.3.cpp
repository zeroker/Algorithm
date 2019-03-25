//第一章 最好的题基本都在第三节了 



//1.31 今年暑假 不AC     贪心 ，那个东西没有好好看 慢慢来吧 
//这个题就是给出好多时间段，求出互不交叉的时间段最多有多少
// 思路就是选出最先end 来的那个时间段，但是要保证下一次的 begin要 大于上一次的end 
#if 0
#include<bits/stdc++.h>
using namespace std;

struct go
{
	int begin,end;
	
} a[101];

int comp(go &a,go &b)
{
	if(a.end<b.end) return 1 ;
     else return 0;
	
}

int main()
{
	int n;
	while(cin>>n && n)
	{
	 int cnt=1 ,  temp;
	 
	 for(int i=0; i<n; i++)
	 cin>>a[i].begin>>a[i].end;
	 
	 sort(a,a+n,comp);
	 temp=a[0].end;
	 for(int i=1; i<n; i++) 
	 {
	 	if(a[i].begin>=temp) {
	 		cnt++;
	 		temp=a[i].end;
		 }
	 }
	cout << cnt <<endl;	
	}
}


#endif


//1.32
/*
Sample Input
4 5 25             //4是四个人， 五门课，输出 不低于25分 的 同學，按成绩从大到小的排序，成绩一样的话，按名字的 字典排序 
10 10 12 13 15
CS004 3 5 1 3
CS003 5 2 4 1 3 5
CS002 2 1 2
CS001 3 2 3 5
1 2 40
10 30
CS001 1 2
2 3 20
10 10 10
CS000000000000000001 0
CS000000000000000002 2 1 2
0
?

Sample Output
3
CS003 60
CS001 37
CS004 37
0
1
CS000000000000000002 20



*/

#if  0            //cin 要用scanf cout要用printf   要不然超时的 
#include<bits/stdc++.h>
using namespace std;
struct go
{
	char Nu[25];
	int fen;
		
}a[1005];

int comp(go &a, go &b)
{
	if(a.fen>b.fen) return 1 ;
    else
	if(a.fen<b.fen) return 0;
	if(a.Nu<b.Nu) return 1;
}

int main()
{
     ios::sync_with_stdio(false);
	int n,m,flag,t[15];
	
	while(scanf("%d",&n) && n) 
	{
	   scanf("%d%d",&m,&flag); 
		 
		int cnt ,s ,ans=0;
		
	   	for(int i=1; i<=m; i++)
	   	         cin>>t[i];
	   	      
	   	  
	   	  for(int i=0; i<n; i++)
	   	  { 
			 a[i].fen=0;
	    	cin>>a[i].Nu>>cnt;
	   	  
	   	  	
	   	  	for(int j=0; j<cnt; j++)
	   	  	{
	   	  		cin>>s;
	   	  	
	   	  		
	   	  		a[i].fen+=t[s];
			}
			
			if(a[i].fen>=flag) ans++;
		  }
		  
		   sort(a,a+n,comp);
		  	cout<<ans<<endl; 
		  
		  for(int i=0; i<n; i++)
		  {
		  	if(a[i].fen>=flag)
		  
			  cout<<a[i].Nu<<" "<<a[i].fen<<endl;
			  
		  }
	}
}

#endif


//1.33 

//第二小整数 
#if 0 
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,a[11];
	cin>>n;
	while(n--)
	{
		int x;
		cin>>x;
		for(int i=0; i<x; i++)
	     	cin >>a[i] ;
	     	
	     	sort(a,a+x);
	     	cout<<a[1]<<endl;
	}
	
}

#endif 


//1.34
#if  0     //考试排名 艾玛（各种错  ac很蛋疼） 
#include<bits/stdc++.h>
using namespace std;
struct info
{
 string name;
 int cnt , time ;
info()
{
	cnt=time=0;
} 
 	
};

bool comp(info &a,info &b) 
{
 	if(a.cnt>b.cnt) return 1;
 	else if(a.cnt<b.cnt)  return 0;
 	else
 	{
 	 if(a.time<b.time) return 1;
	  else if(a.time>b.time) return 0;
	  else
	  {
	  	if(a.name<b.name) return 1;
	  	else return 0;
	   }	
	}
}

int main() 
{	
//freopen("in.txt","r",stdin) ;
vector<info> v;            

string s;
int n,k;

cin>>n>>k; //8 个题    （20分） 
while(cin>>s) 
{
	info son;
 int  flag=0 ,sum=0;	 //两个变量取整数 
 son.name=s;
 for(int i=0; i<n; i++)
 {
 	int ans=0,temp=0 ;
    cin>>s; 
    if(s[0]=='0'||s[0]=='-') 
    son.cnt+=0; 
    else
	{
	  son.cnt++;
    for(int i=0; i<s.size(); i++)
    {
    	if(s[i]!='(') 
    	temp=temp*10+(s[i]-'0');   
	  else 
	  { 
	  	flag=i;
	  	break;
	  }
	}
	
	if(flag!=0)
	for(int i=flag+1; i<s.size(); i++)
	{
	if(s[i]!=')') 
	ans=ans*10+(s[i]-'0');
	else break;
	}
	                 
 }
 temp=temp+ans*k;
 sum+=temp;
}

 son.time=sum;
v.push_back(son); 	
}
sort(v.begin(),v.end(),comp); 

for(int i=0; i<v.size(); i++)
{
 cout<<setw(10)<<left<<v[i].name<<" "<<setw(2)<<right<<v[i].cnt<<" "<<setw(4)<<right<<v[i].time<<endl;	
}	
	
}
#endif


//1.35 Wooden Sticks   用动态数组   删除~ 
#if 0 
#include<bits/stdc++.h>
using namespace std;
struct go
{
	int l,w;
}; 

bool comp(go &a ,go &b) 
{
 if(a.l!=b.l) 
 return a.l<b.l;
 else 
 {
  return  a.w<b.w;	
 }	
}

int main()
{
  int n;
  cin>>n;
 while(n--)   
 { 
    vector<go> v;
 	int x,len,wid,cnt=0;
 	go g;
 	
 	cin>>x;
 
 	for(int j=0; j<x; j++)
   {
   
   	cin>>g.l>>g.w;
   	v.push_back(g);
	} 
    
   sort(v.begin(),v.end(),comp);
   
   vector<go>::iterator it;
  
   while(v.size()) 
  {
  	len=v[0].l;
    wid=v[0].w;	
    
    for(it=v.begin();it!=v.end();)
   {
    if(it->w>=wid)  
     {
     	wid=it->w;                                   //思维得多不缜密，这种逻辑 漏了 
     	v.erase(it);
	 }
     else it++;
   } 
   
   cnt++;
 }
 cout << cnt <<endl;
 
 }
 	
}

#endif 

//1.35 ~2         用 flag 标记 
#if 0 
#include<bits/stdc++.h>
using namespace std;
struct go
{
int l,w;
bool flag;	
}a[5001];

int comp(go &a, go &b)
{
	if(a.l!=b.l)
	return a.l<b.l;
	else return a.w<b.w;
}

int main()
{
	int t,n;
	cin>>t;
	
	while(t--)
	{
		int ans=0,x;
		cin>>n;
		
		for(int i=0; i<n ;i++)
	{
	   cin>>a[i].l>>a[i].w;
	   a[i].flag=1;
	}	
		sort(a,a+n,comp);
		
		for(int i=0; i<n; i++)
		{
			if(a[i].flag)
			 {
			 	x=a[i].w;
			 	a[i].flag=0;                                                  
			}
			else continue;
			for(int k=0; k<n; k++)
			{
				if(a[k].w>=x && a[k].flag)
				{
					a[k].flag=0;
					x=a[i].w;                   // 
				}
			}
			ans++;
		}
		cout << ans <<endl;
	}
	
}

#endif



//1.36 排列2 主要是格式问题 输出选择 do while很重要，以后如果多提前多一次输出，要记住用do while(还有里面if语句的使用) 
#if 0
#include<bits/stdc++.h>
using namespace std;

int main()
{

int a[5] ;
int cnt=0;

while(cin>>a[0]>>a[1]>>a[2]>>a[3] && a[0]+a[1]+a[2]+a[3])
{
	if(cnt)
	cout << endl; 
	cnt=1;
	sort(a,a+4);
	
	int flag=1,k;
	do
	{
	  if(a[0]==0)
	  continue; 
	  else 
	  if(flag)
	  {
	  	cout<<a[0]<<a[1]<<a[2]<<a[3];
	  	k=a[0];
	  	flag=0;
	  }
	  else
	  if(k==a[0])
	  cout<<" "<<a[0]<<a[1]<<a[2]<<a[3];
	  else if(k!=a[0])
	  {
	  	cout<<endl<<a[0]<<a[1]<<a[2]<<a[3];
	  	k=a[0];
	  }
	  	
	} while(next_permutation(a,a+4));
 cout << endl;
}

} 

#endif 

// RANK	1.37 
#if 0
#include<bits/stdc++.h>
using namespace std;
struct go
{
 int nur, mark;	
}a[1001];

bool comp (go &a, go &b)
{
	if(a.mark!=b.mark)
	return a.mark>b.mark ;
}

int main()
{
int n ; 
while(cin>>n)
{
int i=0;
while(cin>>a[i].nur>>a[i].mark && a[i].nur+a[i].mark)
{
  i++;	
}	

sort(a,a+i,comp);
int m;
for(int j=0; j<i; j++)
{
 if(a[j].nur==n)
{
 m=a[j].mark;
 
for(int k=0; k<i; k++)
{
 if(m==a[k].mark)
 {
 	cout <<k+1 <<endl;
	 break;	 }	
} 

}

}

	
 }
}
#endif



//1.38 
// 简单的求中间大小的 值 
#if 0
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n , a[1000000];
	while(cin>>n)
	{
	
	for(int i=0; i<n; i++)
	cin>>a[i];
	
	sort(a,a+n);
	
	cout<<a[(n-1)/2]<<endl;
   }
}

#endif





















