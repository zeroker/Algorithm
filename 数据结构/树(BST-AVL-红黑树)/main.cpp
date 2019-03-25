#include<bits/stdc++.h>
#include"BST.h"
//#include"AVL.h"
//#include"RBT.h" 
using namespace std;
int main()
{
	//查找二叉树的 测试 
	//------------------------------------------------------------------------------
	Bst b;
	tree t = NULL;
	int n;
	cin>>n;
	for(int i=0; i<n; i++)
	{
		int x;
		cin>>x;
		t = b.insert(x,t);                			//建树 
	}
	
	b.printTree(t);                      			//遍历 
	 cout<<endl;
	t = b.reverse(t);
	b.printTree(t);
	 
	 
//	t = b.Delete(8,t);
//	t = b.makeEmpty(t);
//	b.printTree(t); 

//	position p = b.find(10,t);
//	
//	cout<<p->num<<endl;
//
//	cout<<"ok"<<endl;
	 
	 
//	 7
//5 2 8 1 3 7 10
	 
	cout<<"hight:"<<b.getHight(t)<<endl;            //高度 
//	
//	position minn = b.findMin(t);					//最小值 
//	cout<<minn->num<<endl;				 
//	
//	position maxx = b.findMax(t); 					//最大值
//	cout<<maxx->num<<endl;


//------------------------------------------------------------------------------------

//AV平衡二叉树的测试 
/*
	avltree t = NULL;
	AVL b ;
	for(int i=1; i<=5; i++)
	{
		t = b.insert(i,t);
	}
	b.printAvlTree(t);
	cout<<endl;
//	int minn = b.findMinAvl(t)->num;
//	cout<<minn<<endl;
	t = b.Delete(1,t);
	b.printAvlTree(t);
	cout<<"end"<<endl;
*/

//红黑树 测试 
//14
//10 85 15 70 20 60 30 50 65 80 90 40 5 55
//	RBT b;
//		
//	b.hello();
//	cout<<b.node->num<<endl;
//	rbt t = b.init(); 
//	
//	int n;
//	cin>>n;
//	for(int i=0; i<n; i++)
//	{
//		int x;
//		cin>>x;
//		t = b.insertRbt(x,t);
//	}
//	b.printRbtTree(t);
//
//	
//	b.init();
//	cout<<"end"<<endl;
}
