#if 0              // 1.排序算法 
                              //1 sort函数排序 从小到大排序  
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
int a[10];
int i;
for(i=0;i<10;i++)
cin>>a[i];

sort(a+0,a+10);

for(i=0;i<10;i++)
cout<<a[i]<<" ";
	
}


#endif
 
 #if 0                     //1.1sort排序 从大到小 排序 
 #include<iostream>
 #include<algorithm>
 using namespace std
 int  inorderf(const int &a,const int &b)
 {
 	return a>b;
 }
 int main()
 {
 	int x;
 	cin>>x;
 	int *p=new int[x];
 	for(int i=0;i<x;i++)
 	cin>>p[i];
 	sort(p+0,p+x,inorder);
 	for(int i=0;i<x;i++)
 	cout<<p[i]<<'\t';
 	
 }
 
 #endif 
//2.
//字符串         
#if   0
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string a;

	while(getline(cin,a)) 
	{ 
		cout<<a<<endl;
	cout<<"是否为空："<<	a.empty()<<endl;//若为空 为1  反则为0
	cout<<"字串符的大小为 ； "<<	a.size();
		
	} 
	
	
}


#endif  
// 输入 string 还有 一种 更高效的方法  更常用的赋值方法 
#if  0 
#include<bits/stdc++.h>
using namespace std;
int main()

{
	string a;
	char ai[100];
	scanf("%s", & ai);   // scanf 比 cin 更 高效 
	 a=ai;
	 cout<<a<<endl; 
	 
	return 0;
	
}

#endif
//从尾部直接添加 字串符 
#if  0
#include<bits/stdc++.h>
using namespace std;
int main()
{
	string a;
	a+="hello,string.";
	cout<<a<<endl; 
	cout<<"append way:"<<endl;
	a.append("jhon");
	cout<<a<<endl;
	
}

#endif 

//用 erase 删除元素 
#if   0
#include<bits/stdc++.h>
using namespace std;
int main()
{ 
 string s;
 s="0123456789";
 string ::iterator it=s.begin() ;
 s.erase(it+3);   //删除第三个元素，元素是从 位置0 开始计数 
 
 cout<<s<<endl; 
 
 s.erase(it,it+4);
 cout<<s<<endl; 
 //清空 字符串
 s=" ";
 cout<<s<<endl;
 cout<<s.size()<<endl;
 	
	
}
#endif

// 寻找对象的 元素或者是 子串  的下标 
#if 0
#include<bits/stdc++.h>
using namespace std;
int main()

{
string s="cat dog cat";
cout<<"c的下标"<<s.find("c")<<endl;	
cout<<"cat的下标"<<s.find("cat")<<endl;
cout<<"dog的下标"<<s.find("dog")<<endl; 
	
}

#endif

// 比较 字符串的大小  ， 字典 排序， 第一： 如果 开头字母大 则 字符串大 ，第二：如果 开头字母 一样大 ，则size 大的 字符串大 
#if  0
#include<bits/stdc++.h>
using namespace std;
int main()
{
string s="cat dag cat";
cout<<s.compare("cat")<<endl; 

cout<<s.compare("cat dag cat")<<endl;

cout<<s.compare("dag")<<endl;
	
}
#endif 

//reverse string反转 
#if  0
#include<bits/stdc++.h>
using namespace std;
int main()

{
  string s="12345679";
  reverse(s.begin(),s.end())	;
  cout<<s<<endl;
	
}

#endif


//string 对象成为 vector的对象 
#if  0
#include<string>
#include<iostream>
#include<algorithm> 
#include<vector>
using namespace std;
int main()
{
	vector<string> a;
	a.push_back("tom");
	a.push_back("leo");
	a.push_back("jhon");
	cout<<a[0]<<endl<<a[1]<<endl<<a[2]<<endl;
	cout<<a[0]<<" "<<a[0][0]<<endl;
	
}
#endif 

//string 中的数字 相加 不用 int 类型取余 处理了 速度更快
#if 0
#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s="123456789";
	int sum=0;
	 
	 for(int i=0;i<s.length();i++)
	 {
	 	if(s[i]=='0')  sum+=0;
	 	else if(s[i]=='1') sum+=1;         //why ? why 这 的双引 不能用 
		 else if(s[i]=='2') sum+=2;
		 else if(s[i]=='3') sum+=3;
		 else if(s[i]=='4') sum+=4;
		 else if(s[i]=='5') sum+=5;
		 else if(s[i]=='6') sum+=6;
		 else if(s[i]=='7') sum+=7;
		 else if(s[i]=='8') sum+=8;
		 else if(s[i]=='9') sum+=9;
		  	
		 }	
	
	cout<<sum<<endl;
}


#endif 


//string 和char 数组的转换 
#if  0
#include<bits/stdc++h>
using namespace std;
int main()
{
	char a[100];
	string s;
	scanf("%s",&a) ;
	s=a;
	printf(s.c_str) ;
	cout<<endl;
	printf("%s",a);cout<<endl;
	cout<<s<<endl;
	cout<<a<<endl; 
		
}

#endif 
//string and sscanf
#if   0
#include<bits/stdc++.h>
using namespace std;
int main()
{
 string s1,s2,s3;
 char sa[100],sb[100],sc[100];
 sscanf("abc 123 pc","%s %s %s", sa,sb,sc ) ;  //将字符串分割成子串 ， 分隔符为子串 
 s1=sa; s2=sb; s3=sc;
 cout<<s1<<" " << s2 << " " << s3<<endl;
int a,b,c;

sscanf("1 2 3 ","%d %d %d ", &a,&b,&c); //将字符串分割成数字 ， 分隔符为 空格 

cout<< a <<" "<< b <<" " << c <<endl;
	
int x,y,z;                               //将字符串 分割成数字  分隔符为 ￥或者是 ， 
sscanf("4,5$6","%d, %d $ %d",&x,&y,&z);
cout<<x<<" "<<y<<" "<<z<<endl;	
	
}

#endif 





//string 和数值的 转换 
#if   0
#include<iostream>
#include<string>
#include<sstream> 
using namespace std;

string tostring (double x)
{
	//ostringstream对象用来进行格式化的输出，常用于将各种类型转换为string类型
//ostringstream只支持<<操作符

	
	ostringstream o;  //创建一个格式化输出流

	if(o << x )       //把值传递如流中

	return o.str();
	
	return "erro" ;
}

double stringtodouble(string &s)
{
	istringstream i(s);
	double x;
	 if(i >> x)
       return x ;
	   return  0.0 ;	
}

int main()

{
 // double to string c ways
 char b[10];
 string a ;
 sprintf(b,"%d",1975) ;  //转换 
 a=b ;
 cout<< a << endl;	
	
 //double to string c++ ways
 
 string cc=tostring(1976) ;
 
 cout << cc <<endl;
 
 // string to double c++
 
 string dd="2016";
 int p= stringtodouble  ( dd ) ;
  
  cout<< p <<endl;
 	
 	return 0;
}


#endif 

// 直接的 用sstream  将 double 换成 string 型 

#if   0              //如果组数 比较多多的 话,并且 没有用函数   用 a.clear()  清空串流+

 
                
#include<iostream>
#include<string>
#include<sstream>
using namespace std;


string toss(double x)        
{
	stringstream  a;
	
	string s;
	
	a << x ;        //  向流 中 插入 double 数值 
	
	a >> s ;       //    向流中 提取  
	return s; 
	
}

int main()
{
  
  	double x;
  	cin>>x;
  	
  	cout<< toss(x) <<endl;
  	
  	
  	cin>>x; 
  	
  	cout<< toss (x) <<endl;
	
}

#endif



//int 转换成 string 
#if  0

#include<bits/stdc++.h> 

using namespace std;

string s (int x)
{
	string ss;
	
	stringstream a;
	
	a << x ;
	
	a >> ss  ;
	
	return ss;
	
}

int main()
{
	int x;
	
	cin>>x;
	
	cout << s (x) <<endl;
	
}


#endif 




// string 转换成 double 
#if  0

#include<string>
#include<sstream>
#include<iostream>
using namespace std;
double a (string x)
{
	stringstream o ;
	double n ;
	o << x ;
	
	o >> n ;            
	
	return n ;
	
}


int main()

{
	string x ;
	getline(cin,x) ;
	cout << a (x) <<endl;
	
}

#endif 





//set 集合 容器 

#if   0             //用自己 特有的 红黑树 的平衡 二叉树 的数据结构 来 给元素 排序       默认的是从小到大 

#include<iostream> // 中序遍历 
#include<set>
using namespace std;

int main()
{
	set <int> s ;
	s.insert(8) ;
	s.insert( 10) ;
	s.insert(6) ;
	s.insert(89) ;
	
	set<int> :: iterator it ; //定义前向迭代器 
	
     for( it= s.begin(); it != s.end() ;it ++ ) 
     cout<< *it <<" "  ;
	   
	
 } 


#endif 


// 反序遍历

#if  0 
#include<iostream>
#include<set>
using namespace std;
int main()

{
  set <int > s ;
  
  s.insert(10);
  s.insert(5);
  s.insert(6); 
  s.insert(100);
  
  set <int >:: reverse_iterator it ;        // 定义反向迭代器   
   
   for( it = s.rbegin() ; it != s.rend() ; it++   )
   
   {
   	     cout << *it <<" " ; 
   	
		   }    	
  	
	
}



#endif 

// erase 的使用  
# if  0
#include<iostream>
#include<set>
using namespace std;
int main()

 {
 	 set <int > s ;
 	 s.insert(50); s.insert(5) ;s.insert(12) ; s.insert(6) ;
	  
	 s.erase(5) ;
	 
	 set<int> ::reverse_iterator it ;
	 
	 for( it = s.rbegin(); it!= s.rend() ; it ++ ) 
	 cout<< *it << " " ;     
 	 
 	
  } 

#endif

# if   0            //元素的检索 
#include<iostream>
#include<set> 
using namespace std;
int main()
{
   set <int > s;
   s.insert (1) ;
   s.insert (12) ;
   s.insert (6) ;
   
   set <int > :: iterator it ;
   
   it= s.find(6) ;
   if(it!=s.end()) cout<<*it <<endl; 
     else cout << " no " <<endl;
	 
	 it =s.find (100) ;
	 if(it!=s.end()) cout<< *it <<endl;
	  else cout<< "no" <<endl;	
	
	s.clear () ;
	cout<< s .size () <<endl;
	
 } 

#endif 

// 自定义比较函数  从小到大 排序  

#if  0
#include<iostream>  
#include<set>
using namespace std;

struct com 
{
  bool operator () ( const int &a ,const int & b ) 
  
  {
  	if (a!= b) return a  > b ; 
  	else return a > b ;
  	 
  	
  } 	
} ;

int main() 
{
  set <int, com  > s;
  s.insert(5); 
  s.insert(6) ;
  s.insert(60) ;
  s.insert( 8)  ;
  s.insert(2) ;
  s.insert(7) ;
  
  set <int ,com> ::iterator it ;
  for (it=s.begin();it!=s.end(); it++) 
  cout<< *it << "\t" ;
       	
	
	
}

#endif


// set 的 元素是 结构体             按照 成绩 从大到小 排序 

#if  0
#include<iostream>
#include<set>
using namespace std;

struct com
{
	string name ;
     double 	score ;
	 bool operator < (const com & a) const 
	 {
	 	return a.score < score ;
	 }
	  
	
} ;

int  main()

{
	set <com > s;  
	com c ;
	 c.name ="jhon" ;
	 c.score =100 ;
	 s.insert(c) ;
	 
	 c.name ="tom" ;
	 c.score=120 ;
	 s.insert(c) ;
	 
	 c.name ="q" ;
	 c.score=95 ;
	 s.insert(c) ;
	 
	 set <com> ::iterator it ;
	 for( it=s.begin() ;it!= s.end() ;it++ ) 
	 cout<< (*it) .name << " " <<(*it) .score <<endl; 
	
	
}


#endif 


//map          默认的 是按键值       排序是从小到大的排序 
#if  0

#include<iostream>
#include<map>
using namespace std;
int main()

{
	map <int , string > s ; 
	
	string ss[3] ;
	
	for(int i=0;i<3;i++)
     cin>>ss[i];
     
     	for(int i=0;i<3;i++)
              s[i]=ss[i]; 
	
	map<int ,string > ::iterator it ;
	
	for(it=s.begin();it!=s.end();it++) 
	cout<<(*it).first <<":"<<(*it).second <<endl; 
	cout<<"反向遍历"<<endl;
	
	map<int, string > ::reverse_iterator it1 ;
	
	for(it1=s.rbegin();it1!=s.rend();it1++)                              //注意是哪个 元素的 rbegin and rend 
	cout<< (*it1) .first <<": " <<(*it1) .second <<endl;
	
	

	
}


#endif 


// 这个 在 前面 用 string 写了 一遍， 这次是用 map写的额 
#if    0 
#include<iostream>
#include<map>
#include<string>
using namespace std;
int main() 

{
 map< char ,int> a;
 for(int i=0;i<10;i++)
 a['0'+i]=i;
 
 string s;
 cin>>s;
 
 int sum=0;
 for(int i=0;i<s.size();i++)
 {
 	sum+=a[s[i]] ;
 }
	cout<<sum<<endl;
	
}



#endif






//                                    3.队列
#if 0  //1.fifo 队列 fist in fist out  
#include<iostream>
#include<queue>
using namespace std;
int main()
{  
 int x;
	queue<int> q;
	for(int i=0;i<5;i++)
	{ 
	cin>>x;
		q.push(x);
	}
	cout<<"队列的元素的个数是"<<q.size()<<endl;
	cout<<"队列首元素是"<<q.front()<<endl;
	cout<<"队列最后的元素是"<<q.back()<<endl;
	cout<<"队列是否为空："<<q.empty()<<endl;
	q.pop();//删除首元素 
	cout<<"删除了队列首元素的下一个元素为"<<q.front()<<endl; 
}


#endif 

#if 0 // 3.2 优先队列 
#include<iostream>  //int 类型 
#include<queue>
using namespace std;
int main()
{
	priority_queue<int> a; //priority n:优先权 
	int n,x;
	cin>>n;
	for(int i=0;i<n;i++)
	{  cin>>x;
	  a.push(x);

		
	 } 
	cout<<"队列中 优先元素是"<<a.top()<<endl; //输出队列中 优先元素  int为最大类型 
	cout<<"队列 是否为空"<<a.empty()<<endl;
	cout<<"队列元素的个数是"<<a.size()<<endl;
	cout<<"删除队列首元素下一个元素是";
	a.pop();
	cout<< a.top()<<endl; 
}


#endif 




#if 0    //3.3优先队列 来从大到小 排列  不过 会删除 元素 
#include<iostream>
using namespace std;
#include<queue>
 using namespace std;
 int main()
 {
 	priority_queue <int> a;
 	int n;
 	int i,x;
 	cin>>n;
 	for(i=0;i<n;i++)
 	{
 	    cin>>x;
		 a.push(x);	
	 }
	 for(i=0;i<n;i++)
	 {  cout<<a.top()<<'\t';
	 	a.pop();
	 	
	 }
	 cout<<endl;
	 cout<<a.empty()<<endl;
	 cout<<a.top()<<endl;
	 cout<<a.size()<<endl;
 }


#endif


// 4.动态数组函数 
              //4.1简单的使用 
#if 0 
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	vector<int> a;
	int n ,x,i;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>x;
		a.push_back(x);
	}
	sort(a.begin(),a.end());
	for(i=0;i<a.size();i++)
	{
		cout<<a[i]<<" ";
	}
	a.pop_back();
	cout<<"删除动态数组最后的元素然后输出数组"<<endl;
	for(i=0;i<a.size();i++)
	{
		cout<<a[i]<<" ";
	}
	
 } 



#endif 


#if 0 //  4.2  reservr 和 resize的使用  重新 定动态数组的大小 
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	vector<int> a;
	int n;
	cin>>n;
	a.reserve(n);
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		a.push_back(x);
	 } 
	sort(a.begin(),a.end());
	for(int i=0;i<a.size();i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	a.resize(5);
a[3]=5;
a[4]=4;
for(int i=0;i<a.size();i++)
cout<<a[i]<<"\t";
}


#endif 

//5.map 关联式容器 
#if 0                //映射 
#include<iostream>
#include<map>
#include<string> 

using namespace std;
 map<int,string> a;
int main()
{
	
	a[5]="you are my shine";
	cout<<a[5]<<endl; 
  a[1]="love";
  cout<<a[1]<<endl; 
  cout<<a.size()<<endl; //关联了几对 
 cout<< a.count(2); // 如果有“2”则 输出1  
 //cout<<*a.end()<<endl;
 //a.clear(); 
   
 } 

#endif 

// 6.   

#if   0                       //用 sort 给动态二维数组排序     wrong 
#include<bits/stdc++.h>
using namespace std;
int main()
{
  int **a,i,j,x,y, *ai;
  cin>>x>>y;
  a=new int *[x];
  for(i=0;i<x;i++)
    a[i]=new int [y];
	for(i=0;i<x;i++)
	for(j=0;j<y;j++)
	cin>>a[i][j];
	 
	 for(i=0;i<x;i++)
	 {  
	        ai=a[i];
	 	sort(ai.begin(),ai.end());
	 }
	 
	 
 	for(i=0;i<x;i++)
 	for(j=0;j<y;j++)
 	cout<<a[i][j]<<" ";
	
}

#endif 

//7.
# if    0             //7.  全排列  next_permutation(a.begin(),a.end())  先是 从小到大排序 然后  改变区间内元素的顺序，产生下一个排列           
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
  int a[3];
  int i;
  for(i=0;i<3;i++)
  cin>>a[i];
sort(a,a+3);
for(i=0;i<3;i++)
cout<<a[i]<<" ";
cout<<endl;
while (next_permutation(a,a+3) )
{
	for(i=0;i<3;i++)
	cout<<a[i]<<" ";
	cout<<endl;
	
}
  


 } 
#endif  

#if 0                    // 7.1     全排列  perv_permutation(a.begin(),a.end())  先是 从大到小排序 然后  改变区间内元素的顺序，产生前一个排列 
#include<iostream>
#include<algorithm>
using namespace std;
int  com(int &a,int &b)
{
	return a>b;
}
int main()
{
  int a[3];
  int i;
  for(i=0;i<3;i++)
  cin>>a[i];
sort(a,a+3,com);
for(i=0;i<3;i++)
cout<<a[i]<<" ";
cout<<endl;
while (prev_permutation(a,a+3) )
{
	for(i=0;i<3;i++)
	cout<<a[i]<<" ";
	cout<<endl;
	
}
  


 } 
#endif 
           
#if 0                       //8.upper_bound（a,a+5,2)   lower_bound 返回大于等于2的第一个位置   upper_bound(a,a+5,2) 返回 >2的第一个位置 
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[5],i;
	for(i=0;i<5;i++)
	cin>>a[i];
	sort(a,a+5);
	for(i=0;i<5;i++)
	cout<<a[i]<<" ";
	cout<<endl;
	int *ai,*aii;
	ai=lower_bound(a,a+5,2);
	aii=upper_bound(a,a+5,2);
	 cout<<ai-a<<"  "<<aii-a<<endl;
	 while(ai!=aii)
	 {
	 	cout<<*ai<<" ";
	 	ai++;
	 }
	
}

#endif







#if   0               // 20进制 map 阿斯克码的应用 
#include<bits/stdc++.h>
using namespace std;
int main()
{
map<int,char> m;
for(int i=0;i<10;i++)
m[i]=i+48;
for(int i=10;i<20;i++)
m[i]=i+87;	
	for(int i=0;i<20;i++)
	cout<<m[i]<<" ";
	
	
 } 


#endif


















































