#include <iostream>
using namespace std;

struct node{
	int data ;
	node *next = NULL;
};

int main()
{
	int a[5] = {1,2,3,4,5};
	int i = 0;

	node *root;
	node *p, *q;

	root = NULL;

	while(i<5)
	{
		if(root == NULL)
		{	
			// if you forget this you'll get segmentation fault
			root = new node;

			root->data = a[i];
			root->next = NULL;
			p=root;			
		}

		else
		{
			// if you forget this you'll get segmentation fault
			q = new node;
			
			q->data = a[i];
			q->next = NULL;	
			p->next = q;
			p = p->next;
		}
		++i;
	}

	for(int i=0; i<5; ++i)
	{
		cout << root->data <<" " << root->next << endl;
		root = root->next;
	}

}