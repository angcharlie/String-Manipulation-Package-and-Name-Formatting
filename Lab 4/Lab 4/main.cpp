//Charlie Ang
//02/01/16
//CSC 2430
//Prof. Tindall
//Lab #4
//This program obtains a cstring value from the user representing a name
//in the form First Last and then converts it and stores it in another 
//cstring variable in the form Last, First. It finally prints out a messsage
//demonstrating that the converion operation worked. 

#include<iostream>
#include<iomanip>

using namespace std;
#include "stringPkg.h"

const int MAX = 260;	//max number of elements in cstring array 

//Function prototypes
void prompt(char arr[]);
void convert(char firstLast[], char first[], char last[], char lastfirst[], char commaspace[]);
void compare(char first[], char last[]);

int main()
{
	system("cls");

	char firstLast[MAX];	//260 characters max, including room for null character
	char last[MAX];		//vairable to store last name 
	char first[MAX];	//variable to store first name
	char commaspace[MAX] = ", "; //variable to store comma and space 
	char lastfirst[MAX];	//variable to store name in reverse order

	prompt(firstLast);	//call prompt function to prompt user 
	int len = stringLength(firstLast);
	while (len != 0)	//sentinel-stops looping when user enters nothing 
	{
		convert(firstLast, first, last, lastfirst, commaspace);	//calls convert function to do conversions
		compare(first, last);	//calls compare functiont to compare first and last name 
		prompt(firstLast);	//call prompt function to prompt user 
		len = stringLength(firstLast);
	}
}

//This function takes in a character array and prompts user to enter a first and last name.
//It then stores the user input into the cstring array.
void prompt(char arr[])
{
	cout << "Enter a first name and a last name, separated by at least a space: " << endl;
	cin.getline(arr, MAX, '\n');	//store user input into cstring array
}

//This function takes in character arrays firstLast, first, last, lastfirst, and commaspace.
//It then does some manipulation and conversion to re-order the name to the form Last, First.
void convert(char firstLast[], char first[], char last[], char lastfirst[], char commaspace[])
{
	int length = stringLength(firstLast);	//length of firstlast 
	int i = 0;
	while (stringGetchar(firstLast, i) != ' ')	//while not a space
	{
		first[i] = firstLast[i]; //grab first name until space
		i++;
	}
	first[i] = 0;	//append null byte for first name

	while (stringGetchar(firstLast, i) == ' ')	//while space, keep iterating
	{
		i++;
	}

	int j = 0;
	while (i < length) //while not a space
	{
		last[j] = firstLast[i];	//grab
		i++;
		j++;
	}
	last[j] = 0;	//append null byte for last name 

	stringCopy(lastfirst, MAX, last);	//copy last name into string variable
	stringConcatenate(lastfirst, MAX, commaspace);	//concatenate comma and space
	stringConcatenate(lastfirst, MAX, first);	//concatenate first name 

	cout << "Thank you " << lastfirst << " for entering " << firstLast << "." << endl;	//print out message showing conversion
}

//This function takes in a character array for first name and a character array for last name.
//Then it prints out a message indicating which of the two strings is less than the other. 
void compare(char first[], char last[])
{
	int value = stringCompare(first, last);
	if (value < 0)
	{
		cout << "The First Name is less than the Last Name." << endl;
	}
	else if (value == 0)
	{
		cout << "The First Name is equal to the Last name." << endl;
	}
	else //value > 0
	{
		cout << "The Last Name is less than the First Name." << endl;
	}
	cout << endl;	//space
}