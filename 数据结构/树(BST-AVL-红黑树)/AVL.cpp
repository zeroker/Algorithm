#include<bits/stdc++.h>
#include"AVL.h"
using namespace std;

int AVL::hight(avltree t)
{
	{
		if(t == NULL)
			return -1;
		return t->h;
	}
}

int AVL::getAvlHight(avltree t)
{
	if(t != NULL)
	{
		return 	1+max(getAvlHight(t->left),getAvlHight(t->right));	
	}	
} 

avltree AVL::right(avltree k1)
{
	avltree k2 = k1->left;
	k1->left = k2->right;
	k2->right = k1;
	k1->h = max(hight(k1->left),hight(k1->right))+1;
	k2->h = max(hight(k2->left),hight(k2->right))+1;
	
	return k2;
} 
avltree AVL::left(avltree k1)
{
	avltree k2 = k1->right;
	k1->right = k2->left;
	k2->left = k1;
	k1->h = max(hight(k1->left),hight(k1->right))+1;
	k2->h = max(hight(k2->left),hight(k2->right))+1;
	return k2;
}

avltree AVL::leftRight(avltree k1)
{
	k1->left = left(k1->left);
	return right(k1);
}


avltree AVL::rightLeft(avltree k1)
{
	k1->right = right(k1->right);
	return left(k1);
}


avltree AVL::insert(int x,avltree t)
{
	if(t == NULL)
	{
		t = new avlnode;
		if(t == NULL)
			cout<<"out of memory"<<endl;
		t->num = x;
		t->left = t->right = NULL; 
		t->h = 0;
	}
	else
	{
		if(x < t->num)
		{
			t->left = insert(x,t->left);
			
			if(hight(t->left)- hight(t->right) == 2)
			{
				if(x < t->left->num)
				{
					t = right(t);
				}
				else
				{
					t = leftRight(t);
				}
			}
		}
		else
		if(x > t->num)
		{
			t->right = insert(x,t->right);
			if(hight(t->right)- hight(t->left) == 2)
			{
				if(x > t->right->num)
					t = left(t);
				else
					t = rightLeft(t);	
			} 
		}
	}
	t->h = max(hight(t->left),hight(t->right))+1;
	return t;    
}

avltree AVL::Delete(int x,avltree t)
{
	if(t == NULL)
	{
		cout<<"tree is null, error"<<endl;	
	}	
	if(x < t->num)
	{
		t->left = Delete(x,t->left);
	}
	else
	if(x > t->num)
	{
		t->right = Delete(x,t->right);	
	} 
	else
	{
		if(t->left && t->right)
		{
			avltree temp = findMinAvl(t->right);
			t->num = temp->num;
			t->right = Delete(t->num,t->right);
		}
		else
		{
			avltree temp = t;
			if(t->right != NULL)
				t = t->right;
			else
				t = t->left;
			free(temp);
		}
	}
	if(t == NULL)
		return t;
	
	t->h = max(hight(t->left),hight(t->right))+1;
	
	int balance = getBalance(t);
	if(balance > 1 && getBalance(t->left) >= 0)
	{
		return right(t);
	}
	
	if(balance >1 && getBalance(t->left) <0)
	{
		return leftRight(t);
	}
	if(balance < -1 && getBalance(t->right) <=0)
	{
		return left(t);
	}
	if(balance < -1 && getBalance(t->right) >0)
	{
		return rightLeft(t);
	}
	
	return t;
} 

avltree AVL::findMinAvl(avltree t)
{
	if(t->left != NULL)
		findMinAvl(t->left);
	else
		return t;
}
int AVL::getBalance(avltree t)
{
	if(t == NULL)
		return 0;
	return hight(t->left) - hight(t->right);
}

void AVL::printAvlTree(avltree t)
{
	if(t != NULL)
	{
		cout<<t->num<<" and hight="<<t->h<<"  --> ";
		printAvlTree(t->left);
		printAvlTree(t->right);
	}
}

