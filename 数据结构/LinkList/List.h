struct node
{
	int val;
	node* next;
};
typedef node* lists;

class LinkList
{
	
	public:
		lists add(lists head,int x);
		void print(lists head);
		lists reverse(lists head);
	
}; 
