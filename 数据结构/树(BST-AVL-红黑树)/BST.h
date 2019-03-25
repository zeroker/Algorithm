struct node
{
	int num;
	node* right;
	node* left;

};
typedef node *tree;
typedef node *position;   
class Bst{
	
	public:
	void hello();
	tree insert(int x,tree t);
	position findMin(tree t);
	position findMax(tree t);
	void printTree(tree t);
	int getHight(tree t);
	tree Delete(int x,tree t); 
	tree makeEmpty(tree t);
	position find(int x,tree t);
	tree reverse(tree t); 
	
	
};

