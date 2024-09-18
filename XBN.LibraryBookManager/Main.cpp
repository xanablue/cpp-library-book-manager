// Xana Navoichick - Assignment 3: Library Book Manager

#include <iostream>
#include <conio.h>

using namespace std;

struct Book
{
	string title;
	string author;
	int yearPublished;
	int numPages;
};

struct TempBookData
{
	string title;
	string author;
	int yearPublished;
	int numPages;
};

int main()
{
	const int NUM_BOOKS = 4;
	Book books[NUM_BOOKS] =
	{
		{ "Alice's Adventures in Wonderland", "Lewis Carroll", 1865, 1 },
		{ "Wuthering Heights", "Unknown", 1847, 416 },
		{ "Lord of the Flies", "Unknown", 1954, 224 },
		{ "The Shining", "Stephen King", 10, 447 }
	};

	TempBookData userInput[NUM_BOOKS] =
	{
		{ "Alice's Adventures in Wonderland", "Lewis Carroll", 1865, 1 },
		{ "Wuthering Heights", "Unknown", 1847, 416 },
		{ "Lord of the Flies", "Unknown", 1954, 224 },
		{ "The Shining", "Stephen King", 10, 447 }
	};

	for (int i = 0; i < NUM_BOOKS; i++)
	{
		cout << (i + 1) << ". " << books[i].title << "\n";
		cout << "Author: " << books[i].author << "\n";
		cout << "Year Published: " << books[i].yearPublished << "\n";
		cout << "Number of Pages: " << books[i].numPages << "\n\n";
	}

	cout << "Enter the ID of the book you would like to update (1-4): ";
	int bookIndex;
	cin >> bookIndex;
	if (bookIndex == 1 || bookIndex == 2 || bookIndex == 3 || bookIndex == 4)
	{
		cout << bookIndex << ". " << books[bookIndex - 1].title << "\n";
		cout << "Enter the Author (" << books[bookIndex - 1].author << "): \n";
		cin >> userInput[bookIndex - 1].author;
		cout << "Enter the Year Published (" << books[bookIndex - 1].yearPublished << "): \n";
		cin >> userInput[bookIndex - 1].yearPublished;
		cout << "Enter the Number of Pages (" << books[bookIndex - 1].numPages << "): \n";
		cin >> userInput[bookIndex - 1].numPages;
		cout << "Save these changes? (Y/N): ";
		char confirmation;
		cin >> confirmation;
		if (confirmation == 'Y' || confirmation == 'y')
		{
			books[bookIndex - 1].author = userInput[bookIndex - 1].author;
			books[bookIndex - 1].yearPublished = userInput[bookIndex - 1].yearPublished;
			books[bookIndex - 1].numPages = userInput[bookIndex - 1].numPages;
			
			cout << "\n" << bookIndex << ". " << books[bookIndex - 1].title << "\n";
			cout << "Author: " << books[bookIndex - 1].author << "\n";
			cout << "Year Published: " << books[bookIndex - 1].yearPublished << "\n";
			cout << "Number of Pages: " << books[bookIndex - 1].numPages;
		}
		else if (confirmation == 'N' || confirmation == 'n')
		{
			cout << "\nChanges to book information not saved.\n";
			cout << "Press any key to exit the application.";
		}
		else
		{
			cout << "\nInvalid character. Changes will not be saved.\n";
			cout << "Press any key to exit the application.";
		}
	}
	else
	{
		cout << "Error: Book ID is invalid. Book is not found in the library.\nPress any key to exit the application.";
	}

	(void)_getch();
	return 0;
}