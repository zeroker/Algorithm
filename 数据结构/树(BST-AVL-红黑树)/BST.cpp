#include<bits/stdc++.h>
#include"BST.H"
using namespace std;


void Bst::hello(){
	cout<<"hello world"<<endl;
	
	tree p = new node;
	p->num = 88;
	
	cout<<p->num<<endl;
	
	free(p);
	

}

tree Bst::insert(int x,tree t)
{
	if(t == NULL)
	{
		t = new node;
		if(t == NULL)
		{
			cout<<"error! out of memory"<<endl;
		}
		t->num = x;
		t->left = t->right = NULL; 
	}
	else
	{
		if(x > t->num)
		{
			t->right = insert(x,t->right);
		}
		else
		if(x < t->num)
		{
			t->left = insert(x,t->left);
		}
	}
	return t;
}

//void Bst::printTree(tree t)
//{
//	if(t != NULL)
//	{
//		
//		printTree(t->left);
//		cout<<t->num<<" --";
//		printTree(t->right);
//			
//	}
//}


void Bst::printTree(tree t)                            //≤„–Ú±È¿˙ 
{
	queue<tree> q;
	q.push(t);
	while(!q.empty())
	{
		tree temp = q.front();  
		q.pop();
		cout<<temp->num<<" ";
		if(temp->left != NULL)
			q.push(temp->left);
		if(temp->right != NULL)
			q.push(temp->right);	
	} 
}

int Bst::getHight(tree t)
{
	if(t != NULL)
	{
		return 1+max(getHight(t->right),getHight(t->left));	
	}
}

position Bst::findMin(tree t)
{
	if(t== NULL)
		return NULL;
	if(t->left == NULL)
		return t;
	else
		findMin(t->left);
}

position Bst::findMax(tree t)
{
	if(t == NULL)
		return NULL;
	if(t->right == NULL)
		return t;
	else
		findMax(t->right);
	
}
position Bst::find(int x,tree t)
{
	if(x < t->num)
		find(x,t->left);
	else
	if(x > t->num)
		find(x,t->right);
	else
		return t;
}

tree Bst::Delete(int x,tree t)
{
	position temp;
	if(t == NULL)
		cout<<" ˜ «ø’µƒ£¨…æ≥˝ ß∞‹"<<endl;
	if(x > t->num)
	{
		t->right = Delete(x,t->right);
	}
	else
	if(x < t->num)
	{
		t->left = Delete(x,t->left);
	}
	else
	{
		if(t->left && t->right)
		{
			temp = findMin(t->right);
			t->num = temp->num;
			t->right = Delete(temp->num,t->right);
		}
		else
		{
			temp = t;
			if(t->left == NULL)
				t = t->right;
			else
				t = t->left;
			free(temp);
		}
	}
	return t;
}

tree Bst::makeEmpty(tree t)
{
	if(t != NULL)
	{
		makeEmpty(t->left);
		makeEmpty(t->right);
		free(t); 
	} 
	return NULL;
}

tree Bst::reverse(tree t)
{
	queue<tree> q;
	q.push(t);
	
	while(!q.empty())
	{
		tree left = NULL,right=NULL;
		tree now = q.front();
		q.pop();
		if(now->left != NULL)
		{
			left = now->left;
			q.push(left);
		}
		
		if(now->right != NULL)
		{
			right = now->right;
			q.push(right);
		}
		now->left = right;
		now->right = left;
		
	}
	return t;
}

