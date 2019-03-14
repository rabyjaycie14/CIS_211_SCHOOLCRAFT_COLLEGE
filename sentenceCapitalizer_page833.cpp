//Jaycie Raby
//Programming Challenge #3 "Sentence Capitalizer" Page 833 - Exam 1
//
//Write a function that accepts a c-string as as argument and capitalizes the first character
//of each sentence in the string.
//Demonstrate the function in a program that asks the user to input a string and then passes it
//to the function. Display modified string.
//
//7 April 2017


#include <iostream>
using namespace std;

//Function prototype
char *Correction(char *);

int main()
{
	//Create a 200 character array to hold user input, as well as, a pointer object
	char *newUser, user[200];

	//Tell user what program does
	cout << "Program accepts up to 200 characters, then capitalizes\n"
		 << "the first character of each sentence. \n";

	//Get user defined sentence
	cout << "Enter sentence: \n";
	cin.getline(user, 200);
	newUser = Correction(user);

	cout << "\nCorrected sentence: " << newUser << endl;

	return 0;

}

char *Correction(char *sentence)
{
	//initialize variables
	int i = 0, j;

	//Automatically Capitalize First Character
	sentence[i] = toupper(sentence[i]);

	//Parse string 
	for (i = 0; i < strlen(sentence); i++)
	{
		j = i;

		if (sentence[i] == '.' || sentence[i] == '?' || sentence[i] == '!')
		{
			//If found, move to next character
			j++;

			if (sentence[j] == ' ' || sentence == NULL || sentence == '\0')
			{
				//If found, move to next character
				j++;

			}
			
			//found beginning of sentence, now capitalize
			sentence[j] = toupper(sentence[j]);
		}
	}
	
	return sentence;
}
