#include<bits/stdc++.h>
#include"List.h"
using namespace std;
int main() 
{
	
	cout<<"hello world"<<endl;
	LinkList l;
	lists head = NULL;
	
	for(int i=0; i<5;i++)
	{
		head = l.add(head,i);
	}

	
	l.print(head);
	cout<<endl;
	head = l.reverse(head);
	l.print(head);
	cout<<"end"<<endl;
}
