#include <iostream>
using namespace std;

struct node{
	int data;
	node *left, *right;
}root;

void insert(node *&root, int data)
{
	if(root == NULL)
	{
		root = new node;
		root->data = data;
		root->left = root->right = NULL;
		cout << "Inserting data = " << data << endl;
	}
	else if(data <= root->data)
		insert(root->left, data);
	else if(data > root->data)
		insert(root->right, data);
}	

void print(node *root)
{
	cout << root->data << endl;
	cout << root->left->data <<"  "<< root->right->data << endl;
}

void search(node *root, int n)
{
	if(root == NULL)
		cout << "Empty BST....!" <<endl;
	else if( root->data == n)
		cout << "Found "<< n << " at addr = " << root << endl;
	else if (n < root->data && root->left != NULL)
		search(root->left, n);
	else if (n > root->data && root->right != NULL)
		search(root->right, n);
	else 
		cout << "Not found...!" << endl;
}

int main()
{	
	node *root = NULL;
	insert(root, 3);
	insert(root, 2);
	insert(root, 5);
	print(root);
	search(root,2);
	search(root, 6);

	return 0;
}


/*
OUTPUT:

Inserting data = 3
Inserting data = 2
Inserting data = 5
3
2  5
Found 2 at addr = 0x2143030
Not found...!

*/