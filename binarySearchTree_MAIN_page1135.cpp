//Jaycie Raby
//Programming Challenge #1 "Simple Binary Search Tree Class" Page 1135	-- MAIN METHOD
//
//Project Purpose--
//Write a class for implementing a simple binary search tree capable of storing numbers. 
//The class should have three member functions:
//void insert(double x)
//	[The insert function should not use recursion directly, or indirectly by calling a recursive function.]
//bool search(double x)
//	[The search function should work by calling a private recursive member function --> bool search(double x, BBTreeNode *t)]
//void inorder(vector <double> &v )
//	[The inorder function is passed initially empty vector v: it fills v with the inorder list of numbers stored in the binary
//	search tree.]
//Demonstrate the operation of the class using a suitable driver program.

#include <iostream>
#include <vector>
#include "Raby_CPP-H.h"
using namespace std;

int main()
{
	DoubleBinaryTree tree;
	vector<double> values;

	//Tell user what program does
	cout << "This program demonstrates a class used for implementing a simple\n"
		<< "binary search tree, capable of storing members.\n";

	cout << "Inserting the numbers 5.5, 8.8, 3.3, 12.12, 9.9...\n";
	tree.insert(5.5);
	tree.insert(8.8);
	tree.insert(3.3);
	tree.insert(12.12);
	tree.insert(9.9);
	cout << endl;

	tree.inorder(values);
	cout << "Here are the values stored in the tree:\n";
	for (int i = 0; i < values.size(); i++)
	{
		cout << values[i] << " ";
	}

	cout << endl;

	if (tree.search(5.5))
		cout << "5.5 is found in the tree.\n";
	else
		cout << "5.5 was not found in the tree\n";

	cout << "Done.\n";
};
