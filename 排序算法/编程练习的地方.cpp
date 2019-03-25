//#if 1
//#include<bits/stdc++.h>
//using namespace std;
//
//int line,value;
//queue<int> q;
//int i;
//void bfs(int a[],int i,int k,int sum)  //下标从1开始 
//{
//	if(sum == k)
//	{
//		cout<<"=="<<endl;
//		return ;
//	}
//	q.push(a[i]);
//	q.push(-a[i]);
//	sum += q.pop();
//}
//
//void dfs(int a[],int n,int k,int sum)
//{
//	if(sum == k)
//	{
//		
//	}
//	
//	
//}
//
//int main()
//{
//	int a[1000];
//	int n,k;
//	for(int i=0; i<n; i++)
//	{
//		cin>>a[i];
//	}
//	
//	
//}
//
//#endif 


//
//#if 1
//#include<bits/stdc++.h>
//using namespace std;
//int main()
//{
//	int j=1;
//	int sum = 0;
//	for(int i=2008; i>=1005; i--)
//	{
//		if(j%2 == 1)
//			sum+=(-1*j*i);
//		else
//			sum+=(i*j); 
//		j++;
//	}
//	cout<<sum<<endl;
//}
//#endif


#if 0
#include<bits/stdc++.h>
#define exp 1e-7 
using namespace std;
unsigned int n,k;
double a[10001],sum;
int fun(double s)        
{       
    int cnt=0;
    for(int i=0; i<n; i++)
    {
        cnt+=(int)(a[i]/s);
    }
    if(cnt>=k) return 1;                     //大于等于
    else return 0;
}
 
int main()
{
    double mid ,l , r;
//    cin>>n>>k;
    scanf("%d,%d",n,k);
     

         sum=0;
         for(int i=0; i<n; i++)
          {
              cin>>a[i];
              sum+=a[i];
         }
         sum/=k;
         l=0;r=sum;
         while(fabs(l-r)>exp)
         {
             mid=(l+r)/2;
             if(fun(mid)) 
                 l=mid;
             else 
                 r=mid;
         }
         printf("%0.2f\n",l);
    
}

#endif






//蓝桥练习 
//3.19 
//十六进制转八进制的 
//1、 
#if 0
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;

	while(n--)
	{
		string s;
		cin>>s;
		
		string str;
		for(int i=0; i<s.size(); i++)
		{
			if(s[i] == '0')
				str += "0000";
			else if(s[i] == '1')
				str += "0001";
			else if(s[i] == '2')
				str += "0010";
			else if(s[i] == '3')
				str += "0011";
			else if(s[i] == '4')
				str += "0100";
			else if(s[i] == '5')
				str += "0101";
			else if(s[i] == '6')
				str += "0110";
			else if(s[i] == '7')
				str += "0111";
			else if(s[i] == '8')
				str += "1000";
			else if(s[i] == '9')
				str += "1001";
			else if(s[i] == 'A')
				str += "1010";
			else if(s[i] == 'B')
				str += "1011";
			else if(s[i] == 'C')
				str += "1100";
			else if(s[i] == 'D')
				str += "1101";
			else if(s[i] == 'E')
				str += "1110";
			else if(s[i] == 'F')
				str += "1111";		
		}	
		if(str.size() % 3 == 1)
			str = "00" + str;
		else if(str.size() % 3 == 2)
			str = "0" + str;										

//		for(int i=0; i<str.size(); i++)
//		{
//			if(i%4 == 0)
//				cout<<" ";
//			cout<<str[i];
//		}
	
	
		int flag = 0;
		for(int i=0; i<str.size(); i+=3)
		{
			int t = 0;
			t = (str[i]-'0')*4 + (str[i+1]-'0')*2 + (str[i+2]-'0')*1;
//			cout<<t<<"----"<<endl;
			if(t == 0 && flag == 0)
				continue;
			else
				flag = 1; 
			if(flag)
				cout<<t;
		}
		cout<<endl;
	}
		
}
#endif 


//2基础练习 闰年判断  
#if 0
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	 
	if(n%400==0 || (n%4==0 && n%100!=0))
		cout<<"yes"<<endl;
	else
		cout<<"no"<<endl; 
}
#endif 


//3.

//2018
//1
#if 0           //125
#include<bits/stdc++.h>
using namespace std;
int a[] = {0,31,29,31,30};
int main()
{
	int count=0;
	for(int i=1; i<=4; i++)
		count+=a[i];
	count+=4;
	cout<<count<<endl;
	
}
#endif 

//2 
//明码

#if 0
#include<bits/stdc++.h>
using namespace std;
void fun(int x)                   						//转二进制 
{
	string s = "";
	if(x > 0)
	{
		while(x != 0)
		{
			int temp = x%2;
			s = char(temp+'0') + s;                    //			
			x /= 2;
		}
		if(s.size() < 8)
		{
			int sub = 8-s.size();
			for(int i=0; i<sub; i++)
				s = '0' + s;
		}
	}
	else if(x < 0)
	{
		int j;
		x = -x;
		while(x != 0)
		{
			int temp = x%2;
			s = char(temp + '0') + s;                       //
			x /= 2;
		}
		if(s.size() < 8)
		{
			int sub = 8-s.size();
			for(int i=0; i<sub; i++)
				s = '0' + s;
		}
		for(int i=s.size()-1; i>=0; i--)
		{
			if(s[i] == '1')
			{
				j = i;
				break;
			}
		}
		for(int i=0; i<j; i++)
		{
			if(s[i] == '0')
				s[i] = '1';
			else 
				s[i] = '0';
		}
	}	
	else if(x == 0)
	{
		s = "00000000";
	}
//
	for(int i=0; i<s.size(); i++)
		if(s[i] == '1')
			cout<<"1";
		else if(s[i] == '0')
			cout<<" ";
}
int main()
{
	int k = 0;
	int a[30][1000];
	for(int i=1; i<=10; i++)
		for(int j=1; j<=32; j++)
			cin>>a[i][j];
	
	for(int i=1; i<=10; i++)
	{
		for(int j=1; j<=32; j++)
		{
			fun(a[i][j]);
			if(j%2 == 0)
				cout<<endl;
		}
		cout<<endl;
	}
}
#endif



//3
#if 0             //26     错误                 //31 
#include<bits/stdc++.h>
using namespace std;
int a[11][11];

int main()
{
	int count = 0;
	int sum = 1;
	for(int i=0; i<10; i++)
		for(int j=0; j<10; j++)
			cin>>a[i][j];
	
	for(int i=0; i<10; i++)
	{
		for(int j=0; j<10; j++)
		{
			if(sum == 0)
				sum = 1;
			sum *= a[i][j];
			while(sum%10 == 0 && sum != 0)
			{
				sum /= 10;
				count++;
//				cout<<"==="<<endl;
			}
//			cout<<"++1"<<endl;
		}	
	
	}
	
	cout<<count<<endl;
}

#endif
// 4  10次 
//5
#if 0
#include<bits/stdc++.h>
using namespace std;
int MAX = 100000+2;
int main()
{
	int n;
	cin>>n;
	
	int a[MAX],b[MAX],c[MAX];
	for(int i=0; i<n; i++)
		cin>>a[i];
	for(int i=0; i<n; i++)
		cin>>b[i];
	for(int i=0; i<n; i++)
		cin>>c[i];
		
	sort(a,a+n);
	sort(b,b+n);
	sort(c,c+n);
	int na,nb,nc;
	if(a[n-1] <= n)
		na = n;
	else
	{
		for(int i=0; i<n; i++)
		{
			if(a[i] > n)
			{
				na = i;
				break;
			}
		}
	}
	
	if(b[n-1] <= n)
		nb = n;
	else
	{
		for(int i=0; i<n; i++)
		{
			if(b[i] > n)
			{
				nb = i;
				break;
			}
		}
	}
	
	if(c[n-1] <= n)
		nc = n;
	for(int i=0; i<n; i++)
	{
		if(c[i] > n)
		{
			nc = i;
			break;
		}
	}
	
	int t[MAX];
	int t2[MAX];
	for(int i=0; i<nb; i++)
	{
		int x = b[i];
		int *k = lower_bound(a,a+na,x);
		t[i] = k-a;                                //比他小的数的 个数 
//		cout<<t[i]<<"  ";
	}
	
	int sum = 0;
	for(int i=0; i<nc; i++)
	{
		int x = c[i];
		int *k = lower_bound(b,b+nb,x);
		for(int j=0; j<k-b; j++)
		{
			t2[i] += t[j];
		}
//		cout<<t2[i]<<"  ";
		sum += t2[i];
	}
//	
//	for(int i=0; i<nc; i++)
//		cout<<t2[i]<<" ";
	cout<<sum<<endl; 
	
}
#endif

//
//6

#if 0
#include<bits/stdc++.h>
using namespace std;
int x[4] = {-1,0,1,0};    //左上 右下 
int y[4] = {0,1,0,-1};
int main()
{
	int sum = 0;
	int step = 1;
	int func_id = 0;                     //方向 
	int count = 1;                    //转 2 次 ，加 1 个step  (记录局部 内 转的 次数)
	int nx,ny;
	scanf("%d %d",&nx,&ny);
	int i=0,j=0;
	int flag = 0;
	while(1)
	{
		if(i==nx && j==ny)
			break;
		if(count == 3)
		{
			count = 1;
			step++;	
		} 
		if(func_id == 4)
			func_id = 0;
		for(int k=0; k<step; k++)
		{
			if(i==nx && j==ny)
			{
				flag = 1;
				break;
			}
			i += x[func_id];
			j += y[func_id];
			sum++;
		}
		if(flag)
			break;
		func_id++;
		count++;                        //换方向的次数 
	}
	 
	cout<<sum<<endl;
	
}
#endif


#if 1
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int s[4];
	for(int i=1; i<9; i++)
	{
		s[0] = i;
		s[3] = i;
		for(int j=0; j<9; j++)
		{
			s[1] = j;
			s[2] = j;
			for(int i=0; i<4; i++)
				cout<<s[i];
			cout<<endl;
		}
	}	
}
#endif




