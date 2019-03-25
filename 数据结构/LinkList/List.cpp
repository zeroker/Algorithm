#include"List.h"
#include<bits/stdc++.h>
using namespace std;

lists LinkList::add(lists head,int x)              //Î²²å 
{
	lists r = head;
	if(head == NULL)
	{
		head = new node;
		head->val = x;
		head->next = NULL;											
		return head;
	}
	
	while(r->next != NULL)
	{
		r = r->next;
	}
	
	lists tail = new node;
	tail->val = x;
	tail->next = NULL;
	r->next = tail;
	
	return head;
	
}

void LinkList::print(lists head)
{ 
	
	if(head == NULL)
	{
		cout<<"list is NULL"<<endl;
	}
	
	while(head != NULL)
	{
		cout<<head->val<<" ";
		head = head->next; 
	}
	
}

lists LinkList::reverse(lists head)
{
	if(head == NULL)
		return head;
	
	lists new_head = NULL;
	lists cur = head;
	lists next = cur->next;
	
	new_head = cur;
	cur = next;
	new_head->next = NULL;
	
	while(cur != NULL)
	{
		next = cur->next;
		cur->next = new_head;
		new_head = cur;
		cur = next;
	}
	
	return new_head;
}
