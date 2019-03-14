//Jaycie Raby
//Programming Challenge #3 "Sequence Sum" Page 968 - Exam 2 -- header file
//
//Program Purpose: 
//Write an abstract class AbstractSeq that has a pure virtual member function [virtual int fun(int k) = 0;
//as well as, a stand-in for an actual sequence, and two member functions.
//Demonstrate your AbstractSeq by creating subclasses that you use to sum the terms of at least two different sequences.
//Determine what kind of ouput best shows off the operation of these classes, and then
//implement such outputs.
//
//7 April 2017

#include <iostream>
#include <fstream>
using namespace std;

class AbstractSeq
{
public:

	//Pure Virtual Member Function
	virtual int fun(int k) = 0;

	//Member Function
	void printSeq(int k, int m);

	//Member Function
	int sumSeq(int k, int m);
};

//Member function printSeq prints all terms fun(k)
//through fun(m) of the sequence
void AbstractSeq::printSeq(int k, int m)
{
	for (int i = k; i <= m; i++)
		cout << fun(i) << " ";
};

//Member function sumSeq returns the sum of 
//the terms in sequence fun(k) through fun(m)
int AbstractSeq::sumSeq(int k, int m)
{
	int sum = 0;
	
		for (int i = k; i <= m; i++)
			sum += fun(i);
	
	return sum;
}


//Subclass evenSeq produces
//an even integer sequence
class evenSeq : public AbstractSeq
{
	int fun(int k)
	{
		return 2 * k;
	}

};

//Subclass oddSeq produces
//an odd integer sequence
class oddSeq : public AbstractSeq
{
	int fun(int k)
	{
		return 2 * k - 1;
	}

};

