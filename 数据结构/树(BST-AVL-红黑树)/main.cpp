#include<bits/stdc++.h>
#include"BST.h"
//#include"AVL.h"
//#include"RBT.h" 
using namespace std;
int main()
{
	//���Ҷ������� ���� 
	//------------------------------------------------------------------------------
	Bst b;
	tree t = NULL;
	int n;
	cin>>n;
	for(int i=0; i<n; i++)
	{
		int x;
		cin>>x;
		t = b.insert(x,t);                			//���� 
	}
	
	b.printTree(t);                      			//���� 
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
	 
	cout<<"hight:"<<b.getHight(t)<<endl;            //�߶� 
//	
//	position minn = b.findMin(t);					//��Сֵ 
//	cout<<minn->num<<endl;				 
//	
//	position maxx = b.findMax(t); 					//���ֵ
//	cout<<maxx->num<<endl;


//------------------------------------------------------------------------------------

//AVƽ��������Ĳ��� 
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

//����� ���� 
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
