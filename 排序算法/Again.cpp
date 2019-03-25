//Again And Again
//一切都是在于不断的练习！！！！  相信一万小时定理！！ 

//1.快排 
#if 0
#include<bits/stdc++.h>
using namespace std;
int a[100];
int per(int l,int r)
{
	int i = l,j = r;
	while(i < j)
	{
		while(a[i]<=a[j] && i<j) 
			j--;
		if(i < j)
			swap(a[i],a[j]);
		while(a[i]<=a[j] && i<j) 
			i++;
		if(i < j)
			swap(a[i],a[j]);	
	}
	return i;
}
void binary_sort(int l,int r)
{
	if(l < r)
	{
		int mid = per(l,r);
		binary_sort(l,mid-1);
		binary_sort(mid+1,r);
	}
	
}

int main()
{
	
	int n;
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>a[i];
	binary_sort(0,n-1);
	for(int i=0; i<n; i++)
		cout<<a[i]<<" ";
}

#endif


#if 0
#include<bits/stdc++.h>
using namespace std;
int pattern(int a[],int i,int j)
{
	while(i<j)
	{
		while(i<j && a[i]<=a[j]) j--;
		if(i<j)
			swap(a[i],a[j]);
		while(i<j && a[i]<=a[j]) i++;
		if(i<j)
			swap(a[i],a[j]);
	}
	return i;
}

void sort(int a[],int i,int j)
{
	if(i<j)
	{
		int mid = pattern(a,i,j);
		sort(a,i,mid-1);
		sort(a,mid+1,j);
	}
}
int main()
{
	int a[100];
	int n;
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>a[i];
	sort(a,0,n-1);
	for(int i=0; i<n; i++)
		cout<<a[i]<<" ";
}
#endif


//2 堆排序
#if 0
#include<bits/stdc++.h>
using namespace std;

void sife(int a[],int k,int m)
{
	int i = k;
	int j = 2*i;
	while(j<=m)
	{
		if(a[j+1]>a[j] && j<m)
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

void sort(int a[],int n)
{
	int mid = n/2;
	for(int i=mid; i>=1; i--)
	{
		sife(a,i,n);
	}
	
	for(int i=0; i<n-1; i++)
	{
		swap(a[1],a[n-i]);
		sife(a,1,n-i-1);
	}
}

int main()
{
	
	int n;
	cin>>n;
	int a[100];
	for(int i=1; i<=n; i++)
		cin>>a[i];
	sort(a,n);
	for(int i=1; i<=n; i++)
		cout<<a[i]<<" ";
}
#endif 


//堆 
#if 0
#include<bits/stdc++.h>
using namespace std;
void sife(int a[],int k,int m)
{
	int i = k,j = 2*k;
	while(j <= m )
	{
		if(a[j+1]>a[j] && j<m)
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
void sort(int a[],int n)
{
	for(int i=n/2; i>=1; i--)
		sife(a,i,n);
	for(int i=0; i<n-1; i++)
	{
		swap(a[1],a[n-i]);
		sife(a,1,n-i-1);
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



//快排
#if 0
#include<bits/stdc++.h>
using namespace std;
int pattern(int a[],int l,int r)
{
	int i=l,j=r;
	while(i < j)
	{
		while(a[i]<a[j] && i<j)
			j--;
		if(i<j)
			swap(a[i],a[j]);
		while(a[i]<a[j] && i<j)
			i++;
		if(i<j)
			swap(a[i],a[j]);
	}
	return i;
}
void sort(int a[],int i,int j)
{
	if(i<j)
	{
		int mid = pattern(a,i,j);
		sort(a,i,mid-1);
		sort(a,mid+1,j);
	}
}
int main()
{
	int n;
	int a[100];
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>a[i];
	sort(a,0,n-1);
	for(int i=0; i<n; i++)
		cout<<a[i]<<" ";
}
#endif 



//基数排序 

/*
 5 100 5 9 8 6 0
*/

#if 0
#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int x;
	int next;
};
struct QueueNode
{
	int head;
	int tear;
};
int first;
void distribute(Node node[],int n,QueueNode queue[],int m) 
{
	for(int i=0; i<n; i++)
	{
		int x = node[i].x;
		if(queue[x].head == -1)
		{
			queue[x].head = i;
		}
		else
		{
			node[queue[x].tear].next = i;
		}
		queue[x].tear = i;
	}
}

int collection(Node node[],int n,QueueNode queue[],int m)
{
	int i=0;
	while(queue[i].head == -1)                                     
	{
		i++;
	}
	int head = queue[i].head;
	int tear = queue[i].tear;
	for(int j=i+1; j<m; j++)
	{
		if(queue[j].head != -1)
		{
			node[tear].next = queue[j].head;
			tear = queue[j].tear;
		}
		
	}
	node[tear].next = -1;
	
	return head;
}
void sort(Node node[],int n,QueueNode queue[],int m)
{
	for(int i=0; i<m; i++)
		queue[i].head = queue[i].tear = -1;
	for(int i=0; i<n; i++)
		node[i].next = i;
		
	distribute(node,n,queue,m);
	int h =collection(node,n,queue,m);
	int i = h;
	while(i!=-1)
	{
		cout<<node[i].x<<" ";
		i = node[i].next;
	}
}
int main()
{
	int n,m;
	cin>>n>>m;
	Node node[n];
	QueueNode queue[m];
	
	for(int i=0; i<n; i++)
		cin>>node[i].x;
	
	sort(node,n,queue,m);
	
}

#endif


//

//归并 
#if 1
#include<bits/stdc++.h>
using namespace std;
void merge(int a[],int l,int k,int r)
{
	
	int s[r];
	int i=l,j=k+1;
	int id = 0;
	while(i<=k && j<=r)
	{
		if(a[i] < a[j])     
			s[id++] = a[i++];
		else
			s[id++] = a[j++];
	}
	while(i<=k)
		s[id++] = a[i++];
	while(j<=r)
		s[id++] = a[j++];
	
	for(int i=l; i<r; i++)
		a[i] = s[i];
} 
void sort(int a[],int l,int r)
{
	if(l>=r)
		return;
	int mid = (l+r)/2;
	sort(a,l,mid);
	sort(a,mid+1,r);
	merge(a,l,mid,r);
}
int main()
{
	int n;
	int a[100];
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>a[i];
	sort(a,0,n-1);
	for(int i=0; i<n; i++)
		cout<<a[i]<<" ";
}
#endif 






























