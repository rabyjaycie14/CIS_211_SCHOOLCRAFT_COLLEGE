//Jaycie Raby
//Programming Challenge #1 "Static Stack Template" Page 1106
//
//Project Purpose--
//Write a template that will create a static stack of any data type.
//Demonstrate the class with a driver program (My program stacks doubles).
//
//1 April 2017

#include <iostream>
#include "Raby_CP18.h"
using namespace std;

//Constructor
DoubleStack::DoubleStack(double capacity)
{
	this->capacity = capacity;
	stackArray = new double[capacity];
	top = 0;
}

//Adds a value to the stack
void DoubleStack::push(double value)
{
	if (top == capacity) throw DoubleStack::Overflow();
	stackArray[top] = value;
	top++;
}

//Determines whether the stack is empty
bool DoubleStack::isEmpty() const
{
	if (top == 0)
		return true;
	else return false;
}

//Removes a value from the stack and returns it
void DoubleStack::pop(double &value)
{
	if (isEmpty()) throw DoubleStack::Underflow();
	top--;
	value = stackArray[top];
}

int main()
{
	DoubleStack stack(5);
	double values[] = { 1.1,2.2,3.3,4.4,5.5 };
	double value;

	//Tell user what program does
	cout << "This program creates a static stack out of double values.\n";

	cout << "Pushing...\n";
	for (int k = 0; k < 5; k++)
	{
		cout << values[k] << "   ";
		stack.push(values[k]);
	}

	cout << "\nPopping...\n";
	while (!stack.isEmpty())
	{
		stack.pop(value);
		cout << value << "  ";
	}

	cout << endl;
	return 0;
};
