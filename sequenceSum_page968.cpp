//Jaycie Raby
//Programming Challenge #3 "Sequence Sum" Page 968 - Exam 2 -- main method
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
#include "Raby_CPP-EXAM2-P2.h" //Include header file
using namespace std;


int main()
{

	//Create two instances of the oddSeq and evenSeq
	//to hold each sequence
	oddSeq odd;
	evenSeq ev;
	
	int result = 0;

	//Tell user what program does
	cout << "This program produces two different sequences, and then displays\n"
		 << "the sum of each sequence.\n";
	 
	//Display odd sequence
	cout << "The first 5 numbers of the odd sequence are: \n";
	odd.printSeq(1,5);
	cout << endl;

	//Display sum of odd sequence
	cout << "The sum of the odd sequence is: \n";
	result = odd.sumSeq(1, 5);
	cout << result;
	cout << endl;

	//Display even sequence 
	cout << "The first 5 numbers of the even sequence are: \n";
	ev.printSeq(1, 5);
	cout << endl;

	//Display sum of even sequence
	cout << "The sum of the even sequence is: \n";
	result = ev.sumSeq(1, 5);
	cout << result;
	cout << endl;

	return 0;


};