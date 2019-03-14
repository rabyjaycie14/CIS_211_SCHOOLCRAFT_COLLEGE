//Jaycie Raby
//Programming Challenge: Page 835 #12- Check Writer
//Project Purpose: Write a program that displays a simulated check. The program should ask the user to enter
//the date, the payees name, and amount of the check. It should then display a simulated
//check with dollar amount spelled out. Format the numeric value of the check in fixed point
//notation with 2 decimals of precision. Be sure the deimal places always displays,
//even when the number is zero or has no fractional part. Use c-string or string class objects.


#include <iostream>		//display output on the screen and read input from the keyboard.
#include <string>		//allows use of strings
#include <cstring>		//Library function for c-string
#include <iomanip>		//needed to use stream manipulators 
using namespace std;	//allows access to entities (i.e, variables, functions, objects).


class Numbers	//Numbers class declaration
{
private:

	//single integer member variable
	int number;

	//static arrays to hold words
	static const string ones[20];
	static const string tens[9];
	static const string hundreds[10];
	static const string thousands[10];

public:
	//Constructor
	Numbers(int num)
	{
		setNumber(num);
	}
	void setNumber(int num)
	{
		number = num;
	}

	void print();

};

//static member variables must be defined outside of the class
const string Numbers::ones[20] =
{ " zero ", " one ", " two ", " three ", " four ", " five ", " six ", " seven ", " eight ", " nine ", "ten", " eleven ", 
" twelve ", " thirteen ", " fourteen ", " fifteen ", " sixteen ", " seventeen ", " eighteen ", " nineteen " };

const string Numbers::tens[9] =
{ " ten ", " twenty ", " thirty ", " forty ", " fifty ", " sixty ", " seventy ", " eighty ", " ninety " };

const string Numbers::hundreds[10] = { " one hundred ", " two hundred ", " three hundred ", " four hundred ", " five hundred ", 
"six hundred", "seven hundred", "eight hundred", "nine hundred" };

const string Numbers::thousands[10] = { " one thousand ", " two thousand ", " three thousand ", " four thousand ",
" five thousand ", " six thousand ", " seven thousand ", " eight thousand ", " nine thousand " };


void Numbers::print() //print function
{
	if (number == 0)
	{
		cout << ones[(number)];
	}

	if (number >= 1000 && number <= 9999)
	{
		cout << thousands[(number / 1000) - 1];
		number %= 1000;
	}

	if (number >= 100 && number <= 999)
	{
		cout << hundreds[(number / 100) - 1];
		number %= 100;
	}

	if (number >= 20 && number <= 99)
	{
		cout << tens[(number / 10) - 1];
		number %= 10;
	}

	if (number >= 10 && number <= 19)
	{
		cout << ones[(number)-1];
	}

	if (number >= 1 && number <= 9)
	{
		cout << ones[(number)];
	}
	cout << "dollars";
}

int main()
{
	int userinput = 1; //hold userinput //initialize to one so the while loop will work at least once

	cout << "This program takes your first name, last name, date and check amount and simulates a check." << endl;

	while (userinput >= 0 && userinput <= 9999)
	{
		string fname, lname, date;

		cout << "Please enter a check amount between 0 and 9999" << endl;
		cin >> userinput;
		cout << endl;

		cout << "Please enter the date in the following format DD/MM/YYYY: ";
		cin >> date;
		cout << endl;

		cout << "Please enter your first name: ";
		cin >> fname;
		cout << endl;

		cout << "Please enter your last name: ";
		cin >> lname;
		cout << endl;

		cout << "\n--------------------------------------------------\n";
		cout << setw(44) << "DATE: " << date << endl;
		cout << "PAY TO THE ORDER OF: " << fname << " " << lname << "              $" << setprecision(2) << fixed << userinput << endl;
		Numbers engFormat(userinput); //passes userinput to constructor//creates Numbers object
		engFormat.print();
		cout << "\n---------------------------------------------------\n";

		cout << endl;
	}
	
	cout << "Goodbye! [Press enter twice to leave program]" << endl;
	system("pause");
	return 0;

};
