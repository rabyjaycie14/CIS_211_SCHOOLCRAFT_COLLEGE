// Jaycie Raby
//Programming Challenge #7 "List Search" Page 1067
//Project Purpose--
//Modify the list class (below) to include a member function (int search double x) that returns
//the position of a number x on the list. The first node in the list is at position 0, the second node is at position 1,
// and so on. If x is not found on the list, the search should return -1. Test the new member function
//using an appropriate driver program.
//
//[Professor Provided Skeleton for Program Definition below]
//**Chapter 17 - Assignment 1, Simple Linked List Class
// This program creates and uses a simple linked list 
// class with member functions for adding items to the list
// and checking items for membership.**

#include <iostream>
#include <fstream>
#include <list>
using namespace std;

// The Node for the list items
class ListNode
{
public:
	ListNode(double v, ListNode *p)
	{
		value = v; next = p;
	}
private:
	double value;
	ListNode *next;
	friend class LinkedList;    // LinkedList  has friend status	
};

// The linked list class itself
class LinkedList
{
public:
	void add(double x);
	bool isMember(double x);
	void displayList() const;
	LinkedList() { head = NULL; }
	~LinkedList();

	//Member function the returns the position of
	//a number x on the list
	int search(double x);

private:
	ListNode * head;
};

//*************************************
//        LinkedList::add             *
//  Adds a given value to the list.   *
//*************************************
void LinkedList::add(double x)
{
	head = new ListNode(x, head);
	
}

//*************************************
//        LinkedList::displayList     *
//  displayList outputs a sequence of * 
//	all values currently stored in the* 
//					list	          *
//*************************************
void LinkedList::displayList() const
{
	ListNode *nodePtr = head; // start at head of list
	while (nodePtr)
	{
		//Print the value in the current node
		cout << nodePtr->value << "   ";
		//Move on to the next node
		nodePtr = nodePtr->next;
	}

}


//***********************************************************
//                LinkedList::search                        *
//     Returns the position of a number x on the list	    *
//***********************************************************
int LinkedList::search(double x)
{
	ListNode *p = head;     // Use p to walk through list

	for (int k = 0; k <= 4; k++)
	{
		if (p->value == x)
			return k;
		else
			p = p->next;
	}
	// List is exhausted without finding x
	return -1;

}

//***********************************************************
//          LinkedList::isMember                            *
// Checks to see if a given value is a member of the list.  *
//***********************************************************
bool LinkedList::isMember(double x)
{
	ListNode *p = head;     // Use p to walk through list
	while (p != NULL)
	{
		if (p->value == x)
			return true;
		else
			p = p->next;
	}
	// List is exhausted without finding x
	return false;
}

//******************************************
//         Destructor                      *
// Deallocates memory for the list.        *
//******************************************
LinkedList::~LinkedList()
{
	while (head != 0)
	{
		ListNode * p = head;
		head = head->next;
		delete p;
	}
}

int main()
{
	// Explain program to user
	cout << "This program allows the user to enter five numbers, and puts them in a linkedList."
		 << "Program then allows user to search for the index of the elements in the array."
		 << "-1 Is returned if the number \n being searched for is not in the list\n";

	// Create empty list
	LinkedList list1;

	// Get input from user and add them to list
	cout << "Enter 5 numbers: \n";
	for (int k = 1; k <= 5; k++)
	{
		double x;
		cin >> x;
		list1.add(x);

	}
	
	cout << "Here is the list you entered: ";
	list1.displayList();
	cout << endl;

	// Allow user to test membership
	for (int k = 0; k <= 4; k++)
	{
		double x;
		cout << "Enter a number to test membership for: ";
		cin >> x;


		if (list1.isMember(x))
		{
			cout << "\n" << x << " is on the list in position " << list1.search(x) <<  "\n" << endl;
		}

		else
		{
			cout << "\n" << x << " is not on the list [" << list1.search(x) << "]"<< endl;
		}

	}



}
