    // 排序算法
#if 1                       // 1.1   经典 冒泡法 
#include<iostream>
using namespace std;
int main()
{
	int i,j,a[5]={6,3,2,5,4},t;
	for(i=1;i<5;i++)
	{
		for(j=0;j<5-i;j++)
		if(a[j]>a[j+1])
		{
			t=a[j];
			a[j]=a[j+1];
			a[j+1]=t;
		}
	}
	for(i=0;i<5;i++)
	cout<<a[i]<<" ";
}
 #endif 
     
#if 0          // 1.1 动态数组写入  泡沫法  排序 
#include<iostream>
using namespace std;
int main()
{
	int *a,x,i,j,t;
	cin>>x;
	a=new int [x];
	 for( i=0;i<x;i++)
	 cin>>a[i];
	
	
	 for(i=0;i<x-1;i++)
	 {
	 	for(j=0;j<x-i-1;j++)
	 
		 	if(a[j]>a[j+1])
	 {
		 	t=a[j];
			 a[j]=a[j+1];
			 a[j+1]=t;
	 }
		 
	 }
	 for(i=0;i<x;i++)
	 cout<<a[i]<<" ";
	delete []a;
}

#endif	

# if 0
#include<iostream>//2.经典 选择排序 
using namespace std;
int main()
{
	int a[5]={1,5,3,4,2},b1,b;
   int i,j;
   for(i=0;i<4;i++)
     { b=i;
   	for(j=i+1;j<5;j++)
   		if(a[b]>a[j]) b=j;
		   if(i!=b)	   
   	{
		   	b1=a[i];
   		a[i]=a[b];
   		a[b]=b1;
	}
		   }
	   

   	for(i=0;i<5;i++)
   	cout<<a[i]<<" ";
   
	
 } 
#endif

#if  0   // 2.1    动态数组写入    简单选择法                    
#include<iostream> 
using namespace std;
int main()
{
  int *a,n,i,j,k,t;
  cin>>n;
  a=new int [n]; 
  for(i=0;i<n;i++)
  cin>>a[i];
  
  
  for(i=0;i<n-1;i++)
  {
  	 k=i;
  	 for(j=i+1;j<n;j++)
  	 	if(a[k]<a[j]) 
		   k=j;
	
  	if(i!=k)
  	{
  		t=a[i];
		  a[i]=a[k];
		  a[k]=t;
	}
  	  	
}


 for(i=0;i<n;i++)
 cout<<a[i]<<" "; 
delete []a;	
}

#endif
          
#if   0  
#include<iostream>        //3.1 vector 写入正常  用 冒泡法排序   
#include<vector>
using namespace std;
int main()
{
 vector <int> a;
 int i,j,t,n;
 cin>>n;
 for(i=0;i<n;i++)
 {
 	int x;
 	cin>>x;
 	a.push_back(x);
 }
 
for(i=1;i<n;i++)
{
	for(j=0;j<n-i;j++)
	
		if(a[j]>a[j+1])
		{ 
		t=a[j];
		a[j]=a[j+1];
		a[j+1]=t;
		}	
}
for(i=0;i<n;i++)
{
	cout<<a[i]<<" ";
}
	
}

#endif         
		  
		  
		  
		  
		    
#if  0            // 3.2 用 vector写入  用简单排序法排序   
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector <int> a;
	int  n,i,j,k,t;
	cin>>n;
	for(i=0;i<n;i++)
	{
		int x;
		cin>>x;
		a.push_back(x);
	}
	for(i=0;i<n-1;i++)
	{
		k=i;
		for(j=i+1;j<n;j++)
		if(a[k]<a[j]) k=j;
		if(i!=k)
		{
			t=a[i];
			a[i]=a[k];
			a[k]=t;
		}
		
	}
for(i=0;i<n;i++)
cout<<a[i]<<" ";
	
}

#endif

#if 0                  // 4.1 用  模板库的 排序算法  但是 是从小到大  
#include<iostream>
#include<vector>
#include<algorithm> //从小到大 
using namespace std;
int main()
{
	vector<int> a;
	int i,n;
	cin>>n;
	for(i=0;i<n;i++)
	{
		int x;
		cin>>x;
		a.push_back(x);
	 } 
	sort(a.begin(),a.end());
	for(i=0;i<n;i++)
	cout<<a[i]<<" ";
	
}

#endif 


#if 0                 //  4.2  用模板库的排序算法 动态数组 和 排序 从大到小  
#include<iostream>
#include<algorithm>           //注意了解  compare 用法 以及意义 
#include<vector>
using namespace std;
int compare (const int & a,const int & b)
{
	return a>b ;
}
int main()
{
	vector<int> a;
	int i,n;
	cin>>n;
	for(i=0;i<n;i++)
	{
		int x;
		cin>>x;
		a.push_back(x);
	}
	sort(a.begin(),a.end(), compare);
	for(i=0;i<n;i++)
	cout<<a[i]<<" ";
}

#endif 


























