//Jaycie Raby
//Programming Challenge #1 "Simple Binary Search Tree Class" Page 1135 -- MEMBER FUNCTION DEFINITIONS


#include <iostream>
#include <vector>
#include "Raby_CPP-H.h"
using namespace std;

//This version of insert inserts a number into 
//a given subtree of the main binary search tree
void DoubleBinaryTree::insert(BTreeNode *& tree, double x)
{
	//If the tree is empty, make a new node and make 
	//it the root of the tree
	if (!tree)
	{
		tree = new BTreeNode(x);
		return;
	}

	//If x is already in tree: return
	if (tree->value == x)
		return;

	//The tree is not empty: insert the new node into the
	//left or right subtree
	if (x < tree->value)
		insert(tree->left, x);
	else
		insert(tree->right, x);

}


//search determines if a value is present in the tree. 
//If so, the function returns true. Otherwise,
//returns false
bool DoubleBinaryTree::search(double x, BTreeNode *t)
{
	
	while (t)
	{
		if (t->value == x)
			return true;
		else if (x < t->value)
			t = t->left;
		else
			t = t->right;
	}

	return false;

}

//This function displays the value stored in a tree
//in order using a vector
void DoubleBinaryTree::displayInOrder(vector <double> & v, BTreeNode *tree)
{
	if (tree)
	{
		displayInOrder(v, tree->left);
		v.push_back(tree->value);
		displayInOrder(v, tree->right);
	}
}


