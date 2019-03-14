//Jaycie Raby
//Programming Challenge #1 "Static Stack Template" Page 1106 -- header file
//
//Project Purpose--
//Write a template that will create a static stack of any data type.
//Demonstrate the class with a driver program.
//
//1 April 2017
#include <iostream>
using namespace std;

class DoubleStack
{
private:
	double *stackArray;
	int capacity;
	int top;
public:
	DoubleStack(double capacity); //constructor
	~DoubleStack()
	{
		delete[] stackArray;
	}
	void push(double value);
	void pop(double &value);
	bool isEmpty() const;

	//Stack Exceptions
	class Overflow {};
	class Underflow {};
};
