//Jaycie Raby
//Programming Challenge: Page 896 #13- Corporate Sales Data Ouput
//Project Purpose:
//Write a program that uses a struture to store the following information on a company division:
//Division Name [N,S,E,W], Quarters [1,2,3,4], and Quarterly Sales. 
//The user should be asked for the four quarters sales figures for all four divisions. The information
//for each division should be written to a file.

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int SIZE = 4; //Holds four quarters

struct Info
{
	static string division[SIZE];
	double qtr[SIZE];
	double qtrlySales;
	
};

string Info::division[SIZE] = { "North ", "East ", "South ", "West " }; //Holds four divisions

int main()
{
	Info salesFigures; //Store sales figures

	//Create file object and open file
	fstream file("salesFigures.txt", ios::out | ios::binary);
	if (!file)
	{
		cout << "Error opening file. Program aborting. \n";
		return 0;
	}

	//Ask for the sales figures for each quarter
	//for each division
	cout << "Please enter the sales figures for each quarter, for each division: \n";
	for (int i = 0; i < SIZE; i++)
	{
		cout << salesFigures.division[i] << "Division: ";
		for (int k = 0; k < SIZE; k++)
		{
			cout << "Quarter " << (k + 1) << ": $";
			cin >> salesFigures.qtrlySales;

			if (salesFigures.qtrlySales < 0)
				cout << "Please enter a number greater than zero.";
		}

		//Write sales figures to the file
		cout << "Writing data to the file.\n";
		file.write(reinterpret_cast<char *>(&salesFigures), sizeof(salesFigures));
	}

	cout << "Closing the file...\n";
	file.close();
	cout << "Done.\n";
	return 0;

}