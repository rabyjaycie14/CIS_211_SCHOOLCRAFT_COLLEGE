//Jaycie Raby
//Programming Challenge 5 Page 968 File Filter Class -- Header File
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

#include <iostream>
#include <fstream>
using namespace std;

class Filter
{
public:
	Filter();
	~Filter();
	virtual char transform(char ch) = 0;
	void doFilter(ifstream &in, ofstream &out);
};

//Default Constsructor
Filter::Filter()
{

}


//Default Destructor
Filter::~Filter()
{

}

//Member Function that performs the actual filtering
void Filter::doFilter(ifstream &in, ofstream &out)
{
	//Local Variables
	char ch;
	char transCh;

	//Get Data from File
	in.get(ch);

	//Flags to set the input|output files to beginning of file
	in.clear();
	out.clear();
	in.seekg(0L, ios::beg);


	while (!in.fail())
	{
		//Set transCh as the returned value of the virtual function
		transCh = transform(ch);

		//Writes data stored in transCh to the output file
		out.put(transCh);

		//Gets next character in the inputfile
		in.get(ch);
	}

}

//Subclass Encryption Encrypts Data
class Encryption : public Filter
{
private:
	int key;
public:
	Encryption(int k);
	~Encryption();
	char transform(char ch);
};

Encryption::Encryption(int k)
{
	key = k;
}

Encryption::~Encryption()
{

}


//Subclass of Encryption -- Virtual Function Transform Definition
char Encryption::transform(char ch)
{
	return ch + key;
}

//Subclass Upper that transforms a file to all uppercase
class Upper : public Filter
{
public:
	Upper();
	~Upper();
	char transform(char ch);
};

Upper::Upper()
{

}
Upper::~Upper()
{

}

//Subclass of Upper -- Virtual Function Transform Definition
char Upper::transform(char ch)
{
	//Returns uppercase value
	return toupper(ch);

}

//Subclass Original that creates an unchanged copy of the original file
class Original : public Filter
{
public:
	Original();
	~Original();
	char transform(char ch);
};

Original::Original()
{

}

Original::~Original()
{

}

//Subclass of Original -- Virtual Function Transform Definition
char Original::transform(char ch)
{
	return ch;
}
