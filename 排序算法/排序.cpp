//排序算法有 冒泡  / 快排/ 选择/堆排序/  归并 / 桶排序 /

//1.冒泡排序
#if 0
#include<bits/stdc++.h>
using namespace std;

void sort(int a[],int n)
{
	for(int i=0; i<n-1; i++)
	{
		for(int j=0; j<n-i-1; j++)          //
		{
			if(a[j] > a[j+1])
				swap(a[j],a[j+1]);
		} 
	} 
}
int  main()
{
	int a[1000];
	int n;
	cin>>n;
	
	for(int i=0; i<n; i++)
		cin>>a[i];
	sort(a,n);
	
	for(int i=0; i<n; i++)
		cout<<a[i]<<" ";
	
}
#endif 


//1.1 快速排序
 #if 0
#include<bits/stdc++.h>
using namespace std;
int a[1000];
int pattern(int l,int r)
{
	int i = l,j = r;
	while(i<j)
	{
		while(i<j && a[i]<=a[j])
			j--;
		if(i<j)
			swap(a[i],a[j]);
		while(i<j && a[i]<=a[j])
			i++;
		if(i<j)
			swap(a[i],a[j]);
	}
	return i;
}

void sort(int i,int j)
{
	if(i<j)
	{
		int mid = pattern(i,j);
		sort(i,mid-1);
		sort(mid+1,j);
	}
}

int  main()
{
	
	int n;
	cin>>n;
	
	for(int i=0; i<n; i++)
		cin>>a[i];
	sort(0,n-1);
	
	for(int i=0; i<n; i++)
		cout<<a[i]<<" ";
	
}
#endif 


//2.选择排序

#if 0
#include<bits/stdc++.h>
using namespace std;

void sort(int a[],int n)
{
	int num;
	for(int i=0; i<n-1; i++)
	{
		num = i;
		for(int j=i+1; j<n; j++)          
		{
			if(a[j] > a[num])
				num = j;
		} 
		if(num != i)
			swap(a[num],a[i]);
	} 
}
int main()
{
		int a[1000];
	int n;
	cin>>n;
	
	for(int i=0; i<n; i++)
		cin>>a[i];
	sort(a,n);
	
	for(int i=0; i<n; i++)
		cout<<a[i]<<" ";
	
}
#endif 


//3. 归并排序
#if 0
#include<bits/stdc++.h>
using namespace std;
int r[1000],r1[1000];
void merge(int s,int m,int t)
{
	int i=s,j=m+1,k=s;   

	while(i<=m && j<=t)
	{
		if(r[i]<=r[j])       	
			r1[k++] = r[i++];
		else
			r1[k++] = r[j++];
	}

	
		while(i<=m)
			r1[k++] = r[i++];
		while(j<=t)
			r1[k++] = r[j++];
				
	for(int z=s; z<=t; z++)
	  	r[z] = r1[z];
		

}
void sort(int s,int t)
{

	if(s>=t)
		return;
		
		int m = (s+t)/2;
		sort(s,m);
		sort(m+1,t);
		merge(s,m,t);
}

int main()
{

	int n;
	cin>>n;
	for(int i=0; i<n; i++)
	{
		cin>>r[i];
	}
	sort(0,n-1);
	
	for(int i=0; i<n; i++)
		cout<<r1[i]<<" "; 
			      
}
#endif 


//4.堆排序

//十万的数字运行了 50s 我了个去？！！！ 

#if 0
#include<bits/stdc++.h>
using namespace std;
int a[100000];
int n;

void sift(int s,int t)
{
	int i=s,j=2*s;
	while(j<=t)
	{
	
		if(a[j+1] > a[j] && j<t)
			j++;
		if(a[i] > a[j])
			break;
		else
		{
			swap(a[i],a[j]);
			i = j;
			j = 2*i;
		}
	
	}

}

void sort(int n)
{
	for(int i=n/2; i>=1; i--)  
	{
		sift(i,n);
	}
	
	for(int i=1; i<n; i++)
	{
		swap(a[1],a[n-i+1]);
		sift(1,n-i); 
		
	}
}


int main()
{

	cin>>n;
	for(int i=1; i<=n; i++)
	{
		a[i] = n-i;
	}
	sort(n);
	
	for(int i=1; i<=n; i++)
		cout<<a[i]<<" ";
			
}
#endif 


//基数排序

#if 0
#include<bits/stdc++.h>
using namespace std;
int head;
struct Node
{
	int key;
	int next;
};
struct QueueNode
{
	int front,rear;
};

void distribute(Node r[],int n,QueueNode q[],int m)
{
	int i = 0;                     							//默认为0   最后的next为 -1 
	while(1)
	{
		int key = r[i].key;
		if(q[key].front==-1)
		{
			q[key].front = i;
		}
		else
		{
			r[q[key].rear].next = i;
		} 
		q[key].rear = i;
		i = r[i].next;
		
		
		if(i == -1)
			break;
	}
	
}

void collection(Node r[],int n,QueueNode q[],int m)
{
	int k = 0;
	while(q[k].front==-1)
		k++;
	int first = q[k].front;
	int last = q[k].rear;
	head = first;
	
	while(k<m)
	{
		k++;
		if(q[k].front!=-1)
		{
			r[last].next = q[k].front;
			last = q[k].rear;
		}
	}
	r[last].next = -1;
}

void bucketSort(Node r[],int n,QueueNode q[],int m)
{
	for(int i=0; i<n; i++)
		r[i].next = i+1;
	r[n-1].next = -1;

	for(int i=0; i<m; i++)
	{
		q[i].front = q[i].rear = -1;	
	}  
	
	
	distribute(r,n,q,m);
	collection(r,n,q,m);
		
		
}

int main()
{
	Node r[1000];
	QueueNode q[1000];
	
	int n;
	cin>>n;
	
	for(int i=0; i<n; i++)
		r[i].key = n-i;
	
	bucketSort(r,n,q,100);	
	
	
	while(head!=-1)
	{
		cout<<r[head].key<<" ";
		head = r[head].next;
	}
	
}
#endif 


//插入排序
#if 0
#include<bits/stdc++.h>
using namespace std;

void sort(int a[],int n)
{
	for(int i=2; i<=n; i++)
	{
		a[0] = a[i];
		int j;
		for(j=i-1; a[j] > a[0]; j--)
		{
			a[j+1] = a[j];
		}
		a[j+1] = a[0];
	}
}


int main()
{
	int a[100];
	int n;
	cin>>n;
	for(int i=1; i<=n; i++)
		cin>>a[i];
	sort(a,n);
	
	for(int i=1; i<=n; i++)
		cout<<a[i]<<" ";
	
}
#endif 



//希尔排序
#if 1
#include<bits/stdc++.h>
using namespace std;

void sort(int a[],int n)
{
	for(int d=n/2; d>=1; d/=2)
	{
		for(int i=d+1; i<=n; i++)
		{
			a[0] = a[i];
			int j;
			for(j=i-d; j>0&&a[0]<a[j]; j-=d)
			{
				a[j+d] = a[j];
			}
			a[j+d] = a[0];
		}
	}
}

int main()
{
	int a[100];
	int n;
	cin>>n;
	for(int i=1; i<=n; i++)
		cin>>a[i];
	sort(a,n);
	
	for(int i=1; i<=n; i++)
		cout<<a[i]<<" ";
}
#endif 








