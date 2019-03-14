//Jaycie Raby
//Programming Challenge 7 Page 787 -- Exam 1 Part 1
//
//Project Purpose --
//
//Design a DivSales Class that keeps data for a division with
//the following members: 
//1) An array with four quarters of sales figures for the division;
//2) A private static member variable for holding the total corporate sales for all divisions for an entire year; 
//3) A member function that takes four arguments, the value of the arguments is copied into the array that holds
//the sales data, and the total of the four arguments should be added to the static variable that holds yearly corporate sales;
//4) A function that takes an integer w/in the range 0-3, the argument should be used as a subscript into the 
//division quarterly sales array. The function should return the value of the array element with that subscript.
//
//Write a program that creates an array with six DivSales objects. The program should ask the user
//to enter the sales for 4 quarters for each division. Then the program should display a table showing
//the division sales for each quarter. The program should then display the total corporate sales for the year.
//
//26 March 2017

#include <iostream>
#include <iomanip>
using namespace std;


class DivSales 
{
private:

	//Static variable that holds annual corporate asales
	static int yearlySales;

	//Array that holds four quarters of sales figures
	int quarter[4]; 

public:

	//Member function accepts four arguments, assumed
	//to be sales figure data for four quarters
	void salesFigures(int, int, int, int); 

	//Function returns quarterly sales figures
	int qtrlySales(int); 

	//Returns yearly sales
	int getAnnualSales() 
	{ 
		return yearlySales; 
	}

};


//Member function takes four arguments for quarterly sales, copies values 
//into quarter array, and adds the four arguments to the static variable
//yearly sales.
void DivSales::salesFigures(int q1, int q2, int q3, int q4)
{
	quarter[0] = q1;
	quarter[1] = q2;
	quarter[2] = q3;
	quarter[3] = q4;

	yearlySales = yearlySales + q1 + q2 + q3 + q4;

}

//Function argument is used as a subscript
//to access the salesFigures array, and return
//the value of the array element with that subscript
//in main method
int DivSales::qtrlySales(int n)
{
	int value = quarter[n];
	return value;
}


//Definition of static member yearlySales
int DivSales::yearlySales;


int main()
{
	//Creates an array for each of the 6 divisions
	const int DIVS = 6;
	DivSales divisionSales[DIVS];

	//Tell user what program does
	cout << "This program prompts the user to enter quarterly sales figures\n"
		<< "for six divisions in a company. Program then displays the data,\n"
		<< "along with the total corporate sales for the year.\n" << endl;

	cout << "Please enter the data as described: \n";

	for (int div = 0; div < DIVS; div++)
	{

		int qrtr1, qrtr2, qrtr3, qrtr4;

		cout << "Division " << (div + 1) << endl;
		cout << "Quarter 1: ";
		cin >> qrtr1;

		cout << "Quarter 2: ";
		cin >> qrtr2;

		cout << "Quarter 3: ";
		cin >> qrtr3;

		cout << "Quarter 4: ";
		cin >> qrtr4;

		//each div array holds quarterly sales figures
		divisionSales[div].salesFigures(qrtr1, qrtr2, qrtr3, qrtr4);

	}

	//Table showing the division sales for each quarter
	cout << "-------------------------------------------------------\n";
	cout << "\t" << "Qtr 1" << "\t" << "Qtr 2" << "\t" << "Qtr 3" << "\t" <<  "Qtr 4" << "\t" << endl;
	cout << "-------------------------------------------------------\n";
	
	for (int div = 0; div < DIVS; div++)
	{
		cout << "Div " << (div + 1);

		for (int qtr = 0; qtr < 4; qtr++)
		{
			cout << "\t $" << divisionSales[div].qtrlySales(qtr);
		}

		cout << endl;
		cout << "-------------------------------------------------------\n";
	}

	cout << "Annual Corporate Sales: \t $" << divisionSales[0].getAnnualSales() << endl;
	cout << "-------------------------------------------------------\n";

	return 0;

}

