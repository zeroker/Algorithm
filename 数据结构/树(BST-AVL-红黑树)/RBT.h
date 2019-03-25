typedef enum ColorType{black,red} ColorType;
struct rbttree
{
	int num;
	rbttree *left;
	rbttree *right;
	ColorType color;
};
typedef  rbttree *rbt;

class RBT
{	
	rbt x,p,gp,ggp;
	rbt nullnode = NULL;
	public:
		
		rbt node;
		void hello();
		
		rbt init();
		rbt insertRbt(int item,rbt t);
		rbt rotate(int item,rbt parent);
		void handel(int item,rbt t);
		rbt right(rbt k1);
		rbt left(rbt k1); 
		void doPrint(rbt t);
		void printRbtTree(rbt t);
		
};
