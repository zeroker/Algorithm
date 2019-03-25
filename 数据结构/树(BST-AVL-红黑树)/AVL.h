struct avlnode
{
	int num;
	avlnode *left;
	avlnode *right;
	int h;
};

typedef avlnode* avltree;
typedef avlnode* avlposition;

class AVL
{
	public:
		int getAvlHight(avltree t);               //得到树的高度 
		avltree insert(int x,avltree t);
		void printAvlTree(avltree t);
		avltree Delete(int x,avltree t);
		int hight(avltree t);
		avltree right(avltree t);
		avltree left(avltree t);
		avltree rightLeft(avltree t);
		avltree leftRight(avltree t); 
		int getBalance(avltree t);
		avltree findMinAvl(avltree t);
			
		
};
