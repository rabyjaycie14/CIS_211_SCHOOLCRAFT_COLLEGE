//Jaycie Raby
//Jaycie Raby
//Programming Challenge 2 "Dynamic Stack Template" Page 1106 -- header file
//
//Project Purpose--
//Write a template that will create a dynamic stack of any data type.
//Demonstrate the class with a driver program.
//
//1 April 2017

#ifndef DYNDOUBLESTACK_H
#define DYDOUBLETSACK_H

class DynDoubleStack
{
private:
	class StackNode
	{
		friend class DynDoubleStack;
		double value;
		StackNode *next;
		//Constructor
		StackNode(double value1, StackNode *next1 = NULL)
		{
			value = value1;
			next = next1;
		}
	};

	StackNode *top;

public:
	DynDoubleStack() 
	{ 
		top = NULL; 
	}

	void push(double);
	void pop(double &);
	bool isEmpty() const;
};
#endif

