//Jaycie Raby
//Programming Challenge #5 "Recursive Multiplication" Page 931
//
//Project Purpose-- 
//Write a recursive boolean named isMember. The function should accept three parameters:
//an array of integers, an integer indicating the # of elements in the array, and an integer
//value to be searched for. The function should return true if the value is found in the array,
//or falseif the value is not found.
//Demonstrate the use of the function in a program that asks the user to enter an rray of #'s to
//be searched for.
//
//7 April 2017

#include <iostream>
using namespace std;

const int SIZE = 100;

// Function prototype
bool isMember(int[], int, int);

int main()
{
	int numArray[100], numCount, searchValue;

	//Tell user what program does
	cout << "This program accepts user input for an array of up to 100 integers,\n"
		<< "as well as, a value to be searched for within that array.\n";

	//Ask for number of elements in array
	cout << "Please enter number of elements you'd like in the array: \n";
	cin >> numCount;

	//Collect array integers
	for (int i = 0; i < numCount; i++)
	{
		cout << "Please enter integer #" << (i + 1) << ": ";
		cin >> numArray[i];
	}

	//Ask for search value
	cout << "Please enter a value to be searched for: \n";
	cin >> searchValue;

	// Display the result of function isMember
	if (isMember(numArray, SIZE, searchValue))
	{
		cout << searchValue << " is a member of the array.\n";
	}
	else
		cout << searchValue << " is not a member of the array.\n";

	return 0;
}

//Define isMember function
bool isMember(int array[], int size, int num)
{
	if (*array == array[size])
		return false;

	if (*array == num)
	{
		return true;
	}

	else
	{
		return isMember(array + 1, size, num);
	}
}