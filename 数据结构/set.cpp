//顺序实现 集合的并 运算 
#if 0
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	char a[n];
	char b[m];
	vector<char> c;
	for(int i=0; i<n; i++)
		cin>>a[i];
	for(int i=0; i<m; i++)
		cin>>b[i];
	set_union(a,a+n,b,b+n,inserter(c,c.begin()));
	for(int i=0; i<c.size(); i++)
		cout<<c[i]<<" ";
}
#endif 

#if 0 
#include<bits/stdc++.h>
using namespace std;
const int M = -0x7fffffff;
struct node
{
	int value;
	node* next;
}head1,head2,head3;

void setLink(node *head,int n)         //建链表 
{
	head->next = NULL;
	node * first = head;
	int x;
	for(int i=0; i<n; i++)
	{
		cin>>x;
		node *s = new node;
		s->value = x;
		s->next = first->next;
		first->next = s;
	}

}

void print(node *head0)                  //打印集合 
{
	node *head = head0;
	while(head->next != NULL)
	{
		head = head->next;
		cout<<head->value<<endl;
	}

}

void getInterSection(node *first1,node *first2,node* first3)                       //求交集 
{
	first3->next = NULL;
	node *head1 = first1;
	node *head3 = first3;
	while(head1->next!=NULL)
	{
		head1 = head1->next;
		int x = head1->value;
		
		node *head2 = first2;
		while(head2->next !=NULL)
		{
			head2 =  head2->next;
			int x2 = head2->value;
			if(x == x2)
			{
				node *s =new node;
				s->value = x;
				s->next = head3->next;
				head3->next = s;
				
				head2->value = M;
			}
		
		}
	}

}
int main()
{
	int n,m;

	cin>>n;
	cin>>m; 
	setLink(&head1,n);
	setLink(&head2,m);
	if(n>m)
		getInterSection(&head1,&head2,&head3);
	else
			getInterSection(&head2,&head1,&head3);
	print(&head3);                                            //集合1 交集合2 的结果 打印  

	print(&head1);                                             //集合1 

	print(&head2);											//集合2 

}
#endif




#if 01
#include <iostream>
using namespace std;
const int MaxSize = 200;
template<class T>
class SeqList
{
	public:
		SeqList();
		SeqList(T a[], int n);
		SeqList(const SeqList&A);
		int Length();
		T Get(int i);
		int Locate(T item);
		void Insert(int i, T item);
		T Delete(int i);
		void display();
		int empty();
		void clear();
	private:
		T data[MaxSize];
		int length;
};

template<class T>
SeqList<T>::SeqList()
{
	length = 0;
}

template<class T>
SeqList<T>::SeqList(T a[], int n)
{
	if (n > MaxSize) throw"数组元素个数不合法";
	for (int i = 0; i < n; i++)
		data[i] = a[i];
	length = n;
}

template<class T>                                      //复制 
SeqList<T>::SeqList(const SeqList&A)
{
	for (int i = 0; i < A.length; i++)
		data[i] = A.data[i];
	length = A.length;
}

template<class T>
int SeqList<T>::Length()
{
	return length;
}

template<class T>
T SeqList<T>::Get(int i)
{
	return data[i];
}

template<class T>
int SeqList<T>::Locate(T item)              //返回它是 第几个元素 
{
	for (int i = 0; i < length; i++)
		if (data[i] == item)
			return i + 1;
	return -1;
}

template<class T>
void SeqList<T>::Insert(int i, T item)
{
	int j;
	if (length >= MaxSize)throw"溢出";
	if (i<1 || i>length + 1)throw"i不合法！";
	for (j = length; j >= i; j--)
		data[j] = data[j - 1];
	data[i - 1] = item;
	length++;
}

template<class T>
T SeqList<T>::Delete(int i)
{
	int item,j;
	if (length == 0)throw"表为空，无法删除元素 ！";
	if (i<1 || i>length)throw"i不合法！";
    item = data[i - 1];
	for (j = i; j < length; j++)
		data[j - 1] = data[j];
	length--;
	return item;
}

template<class T>
void SeqList<T>::display()
{
	for (int i = 0; i < length; i++)
		cout << data[i]<<" ";
}

template<class T>
int SeqList<T>::empty()
{
	if (length == 0)
		return 1;
	return 0;
}

template<class T>
SeqList<T> bin(SeqList<T>A, SeqList<T>B)
{
	SeqList<T>C;
	int m = 1;
	int a = A.Length();
	for (int b = 0; b <= B.Length(); b++)
	{
		A.Insert(a + b + 1, B.Get(b));
	}
	for (char i = 'a'; i <= 'z'; i++)                                 //毛病 
	{
		for (int d = 0; d <= A.Length(); d++)
		{
			if (A.Get(d) == i)
			{
				C.Insert(m, i);
				m++;
				break;
			}
		}
	}
	return C;
}
int main()
{
    char a[50];
    char b[50];
    cout<<"Set1";
    cin.getline(b,'/0');
    cout<<endl;
    cout<<"Set2:";
    cin.getline(a,'/0');
    cout<<endl;
    SeqList<char>A(a,50),B(b,50),C;
    C=bin(A,B);
    cout<<"Set1USet2="
//    C.display();
//    cout<<endl;
}

#endif 




