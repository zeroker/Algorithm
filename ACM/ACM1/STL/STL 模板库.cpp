#if 0              // 1.�����㷨 
                              //1 sort�������� ��С��������  
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
 
 #if 0                     //1.1sort���� �Ӵ�С ���� 
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
//�ַ���         
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
	cout<<"�Ƿ�Ϊ�գ�"<<	a.empty()<<endl;//��Ϊ�� Ϊ1  ����Ϊ0
	cout<<"�ִ����Ĵ�СΪ �� "<<	a.size();
		
	} 
	
	
}


#endif  
// ���� string ���� һ�� ����Ч�ķ���  �����õĸ�ֵ���� 
#if  0 
#include<bits/stdc++.h>
using namespace std;
int main()

{
	string a;
	char ai[100];
	scanf("%s", & ai);   // scanf �� cin �� ��Ч 
	 a=ai;
	 cout<<a<<endl; 
	 
	return 0;
	
}

#endif
//��β��ֱ����� �ִ��� 
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

//�� erase ɾ��Ԫ�� 
#if   0
#include<bits/stdc++.h>
using namespace std;
int main()
{ 
 string s;
 s="0123456789";
 string ::iterator it=s.begin() ;
 s.erase(it+3);   //ɾ��������Ԫ�أ�Ԫ���Ǵ� λ��0 ��ʼ���� 
 
 cout<<s<<endl; 
 
 s.erase(it,it+4);
 cout<<s<<endl; 
 //��� �ַ���
 s=" ";
 cout<<s<<endl;
 cout<<s.size()<<endl;
 	
	
}
#endif

// Ѱ�Ҷ���� Ԫ�ػ����� �Ӵ�  ���±� 
#if 0
#include<bits/stdc++.h>
using namespace std;
int main()

{
string s="cat dog cat";
cout<<"c���±�"<<s.find("c")<<endl;	
cout<<"cat���±�"<<s.find("cat")<<endl;
cout<<"dog���±�"<<s.find("dog")<<endl; 
	
}

#endif

// �Ƚ� �ַ����Ĵ�С  �� �ֵ� ���� ��һ�� ��� ��ͷ��ĸ�� �� �ַ����� ���ڶ������ ��ͷ��ĸ һ���� ����size ��� �ַ����� 
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

//reverse string��ת 
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


//string �����Ϊ vector�Ķ��� 
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

//string �е����� ��� ���� int ����ȡ�� ������ �ٶȸ���
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
	 	else if(s[i]=='1') sum+=1;         //why ? why �� ��˫�� ������ 
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


//string ��char �����ת�� 
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
 sscanf("abc 123 pc","%s %s %s", sa,sb,sc ) ;  //���ַ����ָ���Ӵ� �� �ָ���Ϊ�Ӵ� 
 s1=sa; s2=sb; s3=sc;
 cout<<s1<<" " << s2 << " " << s3<<endl;
int a,b,c;

sscanf("1 2 3 ","%d %d %d ", &a,&b,&c); //���ַ����ָ������ �� �ָ���Ϊ �ո� 

cout<< a <<" "<< b <<" " << c <<endl;
	
int x,y,z;                               //���ַ��� �ָ������  �ָ���Ϊ �������� �� 
sscanf("4,5$6","%d, %d $ %d",&x,&y,&z);
cout<<x<<" "<<y<<" "<<z<<endl;	
	
}

#endif 





//string ����ֵ�� ת�� 
#if   0
#include<iostream>
#include<string>
#include<sstream> 
using namespace std;

string tostring (double x)
{
	//ostringstream�����������и�ʽ��������������ڽ���������ת��Ϊstring����
//ostringstreamֻ֧��<<������

	
	ostringstream o;  //����һ����ʽ�������

	if(o << x )       //��ֵ����������

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
 sprintf(b,"%d",1975) ;  //ת�� 
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

// ֱ�ӵ� ��sstream  �� double ���� string �� 

#if   0              //������� �Ƚ϶��� ��,���� û���ú���   �� a.clear()  ��մ���+

 
                
#include<iostream>
#include<string>
#include<sstream>
using namespace std;


string toss(double x)        
{
	stringstream  a;
	
	string s;
	
	a << x ;        //  ���� �� ���� double ��ֵ 
	
	a >> s ;       //    ������ ��ȡ  
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



//int ת���� string 
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




// string ת���� double 
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





//set ���� ���� 

#if   0             //���Լ� ���е� ����� ��ƽ�� ������ �����ݽṹ �� ��Ԫ�� ����       Ĭ�ϵ��Ǵ�С���� 

#include<iostream> // ������� 
#include<set>
using namespace std;

int main()
{
	set <int> s ;
	s.insert(8) ;
	s.insert( 10) ;
	s.insert(6) ;
	s.insert(89) ;
	
	set<int> :: iterator it ; //����ǰ������� 
	
     for( it= s.begin(); it != s.end() ;it ++ ) 
     cout<< *it <<" "  ;
	   
	
 } 


#endif 


// �������

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
  
  set <int >:: reverse_iterator it ;        // ���巴�������   
   
   for( it = s.rbegin() ; it != s.rend() ; it++   )
   
   {
   	     cout << *it <<" " ; 
   	
		   }    	
  	
	
}



#endif 

// erase ��ʹ��  
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

# if   0            //Ԫ�صļ��� 
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

// �Զ���ȽϺ���  ��С���� ����  

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


// set �� Ԫ���� �ṹ��             ���� �ɼ� �Ӵ�С ���� 

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


//map          Ĭ�ϵ� �ǰ���ֵ       �����Ǵ�С��������� 
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
	cout<<"�������"<<endl;
	
	map<int, string > ::reverse_iterator it1 ;
	
	for(it1=s.rbegin();it1!=s.rend();it1++)                              //ע�����ĸ� Ԫ�ص� rbegin and rend 
	cout<< (*it1) .first <<": " <<(*it1) .second <<endl;
	
	

	
}


#endif 


// ��� �� ǰ�� �� string д�� һ�飬 ������� mapд�Ķ� 
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






//                                    3.����
#if 0  //1.fifo ���� fist in fist out  
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
	cout<<"���е�Ԫ�صĸ�����"<<q.size()<<endl;
	cout<<"������Ԫ����"<<q.front()<<endl;
	cout<<"��������Ԫ����"<<q.back()<<endl;
	cout<<"�����Ƿ�Ϊ�գ�"<<q.empty()<<endl;
	q.pop();//ɾ����Ԫ�� 
	cout<<"ɾ���˶�����Ԫ�ص���һ��Ԫ��Ϊ"<<q.front()<<endl; 
}


#endif 

#if 0 // 3.2 ���ȶ��� 
#include<iostream>  //int ���� 
#include<queue>
using namespace std;
int main()
{
	priority_queue<int> a; //priority n:����Ȩ 
	int n,x;
	cin>>n;
	for(int i=0;i<n;i++)
	{  cin>>x;
	  a.push(x);

		
	 } 
	cout<<"������ ����Ԫ����"<<a.top()<<endl; //��������� ����Ԫ��  intΪ������� 
	cout<<"���� �Ƿ�Ϊ��"<<a.empty()<<endl;
	cout<<"����Ԫ�صĸ�����"<<a.size()<<endl;
	cout<<"ɾ��������Ԫ����һ��Ԫ����";
	a.pop();
	cout<< a.top()<<endl; 
}


#endif 




#if 0    //3.3���ȶ��� ���Ӵ�С ����  ���� ��ɾ�� Ԫ�� 
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


// 4.��̬���麯�� 
              //4.1�򵥵�ʹ�� 
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
	cout<<"ɾ����̬��������Ԫ��Ȼ���������"<<endl;
	for(i=0;i<a.size();i++)
	{
		cout<<a[i]<<" ";
	}
	
 } 



#endif 


#if 0 //  4.2  reservr �� resize��ʹ��  ���� ����̬����Ĵ�С 
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

//5.map ����ʽ���� 
#if 0                //ӳ�� 
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
  cout<<a.size()<<endl; //�����˼��� 
 cout<< a.count(2); // ����С�2���� ���1  
 //cout<<*a.end()<<endl;
 //a.clear(); 
   
 } 

#endif 

// 6.   

#if   0                       //�� sort ����̬��ά��������     wrong 
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
# if    0             //7.  ȫ����  next_permutation(a.begin(),a.end())  ���� ��С�������� Ȼ��  �ı�������Ԫ�ص�˳�򣬲�����һ������           
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

#if 0                    // 7.1     ȫ����  perv_permutation(a.begin(),a.end())  ���� �Ӵ�С���� Ȼ��  �ı�������Ԫ�ص�˳�򣬲���ǰһ������ 
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
           
#if 0                       //8.upper_bound��a,a+5,2)   lower_bound ���ش��ڵ���2�ĵ�һ��λ��   upper_bound(a,a+5,2) ���� >2�ĵ�һ��λ�� 
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







#if   0               // 20���� map ��˹�����Ӧ�� 
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


















































