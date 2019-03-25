#include<bits/stdc++.h>
#include"RBT.h"
using namespace std;

void RBT::hello()
{
	node = new rbttree;
	node->num = 55;
}

rbt RBT::init()
{
	rbt t = NULL;
	
	if(nullnode == NULL)
	{
		nullnode = new rbttree;
		if(nullnode == NULL)
			cout<<"out of space"<<endl;
		
		nullnode->left = nullnode->right = nullnode;
		nullnode->color = black;
		nullnode->num = 0;                       						//	
	}	
	t = new rbttree;
	if(t == NULL)
		cout<<"out of space"<<endl;
	t->num = -0x7fffffff;                                               //头结点 
	t->left = t->right = nullnode;
	t->color = black;
	
	return t;
}

void RBT::doPrint(rbt t)
{
	if(t != nullnode)
	{
		doPrint(t->left);
		if(t->color == red)
		{
			cout<<"num:"<<t->num<<" color:red"<<"   -->"<<endl; 
		}
		else
		{
			cout<<"num:"<<t->num<<" color:black"<<"   -->"<<endl; 
		}
		doPrint(t->right);	
	}	
} 
void RBT::printRbtTree(rbt t)
{
	doPrint(t->right);
}

rbt RBT::right(rbt k1)
{
	rbt k2 = k1->left;
	k1->left = k2->right;
	k2->right = k1;
	
	return k2;	
} 
 
rbt RBT::left(rbt k1)
{
	rbt k2 = k1->right;
	k1->right = k2->left;
	k2->left = k1;
	return k2;
}
rbt RBT::rotate(int item,rbt parent)
{
	
	if(item < parent->num)
	{
		if(item > parent->left->num)
			return parent->left = left(parent->left);
		else
			return parent->left = right(parent->left);
	}
	else
	{
		if(item < parent->right->num)
			return parent->right = right(parent->right);
		else
			return parent->right = left(parent->right);
	}
} 


void RBT::handel(int item,rbt t)                                     //调整 红黑树   
{
	x->color = red;
	x->left->color = x->right->color = black;
	if(p->color == red)
	{
		gp->color = red;
		if((item<gp->num) != (item<p->num))
		{
			p = rotate(item,gp);
		}
		 
		x = rotate(item,ggp);
	}
	
	t->right->color = black;
	
}

rbt RBT::insertRbt(int item,rbt t)
{
	x = p = gp = t;
	nullnode->num = item;
	while(x->num != item)
	{
		ggp = gp; gp = p; p = x;
		if(item < x->num)
			x = x->left;
		else
			x = x->right;
		if(x->left->color == red && x->right->color == red)
		{
			handel(item,t);
		}
	}
	
	if(x != nullnode)
		return nullnode;
		
	x = new rbttree;
	x->num = item;
	x->left = x->right = nullnode;
	if(item<p->num)
		p->left = x;
	else
		p->right = x;
	
	handel(item,t); 
	return t;
}


 
