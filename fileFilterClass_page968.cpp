//Jaycie Raby
//Programming Challenge 5 Page 968 File Filter Class -- Main Method
//
//Project Purpose --
//
//Write an abstract file filter class that defines a pure virtual function for transforming a character.
//Create one subclass of your file filter class that performs encryption, another that transforms a file to
//all uppercase, and another that creates an unchanged copy of the original file.
//The class should have a member function void doFilter(ifstream &in, ofstream &out) that is called to
//perform the actual filtering. The member function for transforming a single character should have the prototype
//char transform(char ch). The encryption class should have a constructor that takes an integer as an argument, and
//uses it as the encryption key.
//19 March 2017

#include"Raby_CPP15.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	//Local Variables, fstream and class objects
	ifstream input;
	ofstream encrypt, upper, original;
	Upper up;
	Original or ;
	int key;
	string inFile, encryptFile, upperFile, originalFile;


	cout << "Please enter the file you'd like to transform: \n";
	cin >> inFile;
	//Open and Read Text File
	input.open(inFile, ios::in);
	while (input.fail())
	{
		cout << "File name " << inFile << " cannot be opened. \n";
		cout << "Re-enter file you'd like to transform: \n";
		cin >> inFile;
		input.open(inFile, ios::in);
	}


	cout << "Please enter the file you'd like the encrypted data to be written to: \n";
	cin >> encryptFile;
	//Open, Read and Write to Text File
	encrypt.open(encryptFile, ios::in | ios::out);
	while (encrypt.fail())
	{
		cout << "File name " << encryptFile << " cannot be opened. \n";
		cout << "Re-enter file you'd like the encrypted data to be written to: \n";
		cin >> encryptFile;
	}


	cout << "Please enter the file you'd like the UPPERCASE data to be written to: \n";
	cin >> upperFile;
	//Open, Read and Write to Text File
	upper.open(upperFile, ios::in | ios::out);
	while (upper.fail())
	{
		cout << "File name " << upperFile << " cannot be opened. \n";
		cout << "Please re-enter the file you'd like the UPPERCASE data to be written to: \n";
		cin >> upperFile;
	}


	cout << "Please enter the file you'd like the original copy to be written to: \n";
	cin >> originalFile;
	//Open, Read and Write to Text File
	original.open(originalFile, ios::in | ios::out);
	while (original.fail())
	{
		cout << "File name " << originalFile << " cannot be opened. \n";
		cout << "Please re-etner the file you'd like the original copy to be written to: \n";
		cin >> originalFile;
	}


	cout << "Please enter the encryption key: \n";
	cin >> key;


	//Calls Encryption Class Object using fstream object as paramaters
	cout << "Performing encryption.....\n";
	Encryption encryptedFile(key);
	encryptedFile.doFilter(input, encrypt);
	up.doFilter(input, upper);
	or.doFilter(input, original);
	cout << "Done. \n";


	//Close Files
	cout << "Closing files...\n";
	input.close();
	encrypt.close();
	upper.close();
	original.close();
	cout << "Done. \n";

	return 0;

}









	


