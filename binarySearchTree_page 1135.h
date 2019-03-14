//Jaycie Raby
//Programming Challenge #1 "Simple Binary Search Tree Class" Page 1135 -- HEADER FILE


#ifndef DOUBLEBINARYTREE_H
#define DOUBLEBINARYTREE_H
#include <iostream>
#include <vector>
using namespace std;

class DoubleBinaryTree
{
private:
	// The BTreeNode class is used to build the tree
	class BTreeNode
	{
		friend class DoubleBinaryTree;
		double value;
		BTreeNode *left;
		BTreeNode *right;
		BTreeNode(double value1, BTreeNode *left1 = NULL, BTreeNode *right1 = NULL)
		{
			value = value1;
			left = left1;
			right = right1;
		}
	};

	BTreeNode *root;	// Pointer to the root of the tree
	
	//Various helper member functions.
	void insert(BTreeNode *&, double);
	bool search(double, BTreeNode *);
	void displayInOrder(vector <double> & v, BTreeNode *);

public:

	// Constructor
	DoubleBinaryTree() 
	{ 
		root = NULL; 
	}

	//Various member functions
	void insert(double x)
	{
		insert(root, x);
	}
	bool search(double x)
	{
		return search(x, root);
	}
	void inorder(vector <double> & v)
	{
		displayInOrder(v, root);
	}

};
#endif