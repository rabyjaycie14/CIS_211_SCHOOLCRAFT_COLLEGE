//Jaycie Raby
//Jaycie Raby
//Programming Challenge 2 "Dynamic Stack Template" Page 1106
//
//Project Purpose--
//Write a template that will create a dynamic stack of any data type.
//Demonstrate the class with a driver program.
//
//1 April 2017

#include <iostream>
#include "Raby_CPP18B.h"
using namespace std;


int main()
{
	DynDoubleStack stack;
	double catchVar;

	//Tell user what program does
	cout << "This program dynamically stacks double values\n";
	cout << endl;

	cout << "Pushing 5.5\n";
	stack.push(5.5);
	cout << "Pushing 10.5\n";
	stack.push(10.5);
	cout << "Pushing 15.5\n";
	stack.push(15.5);

	cout << endl;

	cout << "Popping...\n";
	stack.pop(catchVar);
	cout << catchVar << endl;
	stack.pop(catchVar);
	cout << catchVar << endl;
	stack.pop(catchVar);
	cout << catchVar << endl;

	cout << "\nAttempting to pop again....\n";
	stack.pop(catchVar);
	return 0;

}


//Member function push pushes 
//the argument onto the stack
void DynDoubleStack::push(double num)
{
	top = new StackNode(num, top);
}

//Member function pop removes the value at the top
//of the stack and copies it into the variable passed
//as an argument
void DynDoubleStack::pop(double &num)
{
	StackNode *temp;

	if (isEmpty())
	{
		cout << "The stack is now empty\n";
		exit(1);
	}
	
	else //Pop value off top of stack
	{
		num = top->value;
		temp = top;
		top = top->next;
		delete temp;
	}

}

//Member function isEmpty returns true if the stack
//is empty or false otherwise
bool DynDoubleStack::isEmpty() const
{
	if (!top)
		return true;
	else
		return false;
}

