#include <iostream>
using namespace std;

class linkedList{

struct node{
	int data ;
	node *next = NULL;
};

node *head, *tail;

public:
	linkedList();
	bool isEmpty();
	void add(int );
	void addInBetween(int, int);
	void sort();
	void display( );
};

// constructor
linkedList::linkedList()
{
	head = NULL;
	tail = NULL;
} 	

// check if list is empty 
bool linkedList::isEmpty()
{
	if(head == NULL)
		return true;
	else
		return false;
}

// add element to the list
void linkedList::add(int n) 
	{
		if(isEmpty())
		{
			head = new node;
			head->data = n;
			head->next = NULL;
			tail = head;
		}
		else
		{
			// if you forget this you'll get segmentation fault
			node *temp = new node;
			temp->data = n;
			temp->next = NULL;

			tail->next = temp;
			tail = temp;
		}
	}

//add a number at kth position
void linkedList::addInBetween(int n, int k)
{
	node *left = head;
	for (int i=0; i<k-1; ++i)
		left = left->next;

	node *right = left->next;

	node *temp = new node;
	temp->data = n;
	
	// now we need to insert temp, left->temp->right 
	left->next = temp;
	temp->next = right;
}

// sort the linkedlist
// need to implement merge sort
void linkedList::sort()
{
	node *pivot, *current;
	pivot = head;
	current = head->next;	

	while(pivot->next != NULL)
	{
		
	}	
}


// display the elements from head
void linkedList::display()
{
	if(isEmpty())
		cout <<" Empty list. Nothing to display!!";
	else
	{
		node *temp = head;
		while(temp->next != NULL)
		{	
			cout << temp->data <<" ";
			temp = temp->next;
			
		}
		cout << temp->data <<  endl;
	}
}

int main()
{
	linkedList l;
	l.add(81);
	l.add(25);
	l.add(53);
	l.add(14);
	l.addInBetween(11,1);
	l.display();

	return 0;
}
