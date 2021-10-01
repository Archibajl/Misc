#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
#include "bookHead.h"


// this is the included file from the directions and is included as directed.

using namespace std;

void getBookData(bookType books[], int& noOfBooks);
void printBookData(bookType books[], int noOfBooks);
void searchBookData(bookType books[], int bookCount);
void searchBookDataByISBN(bookType books[], int bookCount, string ISBN,
	int& loc);
void searchBookDataByTitle(bookType books[], int bookCount, string title,
	int& loc);
void updateCopiesInStock(bookType books[], int bookCount);
void showMenu();
void subMenu();



int main()
{
	

	int numberOfBooks = 0;

	int choice;

	int i;

	getBookData(books, numberOfBooks);

	showMenu();
	cin >> choice;

	while (choice != 9)
	{
		switch (choice)
		{
		case 1:
			for (i = 0; i <numberOfBooks; i++)
				books[i].printbookTitle();
			cout << endl;
			break;
		case 2:
			for (i = 0; i <numberOfBooks; i++)
				books[i].printbookTitleAndISBN();
			cout << endl;
			break;
		case 3:
			searchBookData(books, numberOfBooks);
			break;
		case 4:
			updateCopiesInStock(books, numberOfBooks);
			break;
		case 5:
			printBookData(books, numberOfBooks);
			break;
		default:
			cout << "Invalid selection." << endl;
		}

		showMenu();
		cin >> choice;
	}

	return 0;
}

void getBookData(bookType books[], int& noOfBooks)
{
	string title;
	string ISBN;
	string Publisher;
	int PublishYear;
	string auth[4];
	double cost;
	int copies;
	int authorCount;

	int i, j;

	ifstream infile;
	char ch;
	// for some reason the program will not read this text file i tried reloading it multiple times the syntax is correct
	// i tried everything i could think of or look up nothing works sorry.
	infile.open("bookData2.txt");

	if (!infile)
	{
		cout << "Cannot open Input file" << endl;
		cout << "Exit the program" << endl;
		return;
	}

	infile >> noOfBooks;
	infile.get(ch);

	for (i = 0; i < noOfBooks; i++)
	{
		getline(infile, title);
		getline(infile, ISBN);
		getline(infile, Publisher);
		infile >> PublishYear >> cost >> copies >> authorCount;
		infile.get(ch);

		for (j = 0; j < authorCount; j++)
			getline(infile, auth[j]);

		books[i].setBookInfo(title, ISBN, Publisher,
			PublishYear, auth[j], cost, copies,
			authorCount);
	}
	infile.close();
}



void printBookData(bookType books[], int noOfBooks)
{
	int i;

	for (i = 0; i < noOfBooks; i++)
	{
		books[i].printInfo();
		cout << endl << "---------------------------------" << endl;
	}
}

// these functions needed boolian  functions to operate and that got it to work.
void searchBookDataByISBN(bookType books[], int bookCount, string ISBN,
	int& loc)
{
	int i;
	loc = -1;

	for (i = 0; i < bookCount; i++)
	{

		if (books[i].isISBN(ISBN))
		{
			loc = i;
			break;
		} }
}

void searchBookDataByTitle(bookType books[], int bookCount, string title,
	int& loc)
{
	int i;
	loc = -1;

	for (i = 0; i < bookCount; i++) {

		if (books[i].isTitle(title))
		{
			loc = i;
			break;
		}
	}
}

void searchBookData(bookType books[], int bookCount)
{
	int choice;
	char ch;

	int loc;

	string str;

	subMenu();

	cin >> choice;
	cin.get(ch);

	switch (choice)
	{
	case 1:
		cout << "Enter the ISBN of the book." << endl;
		getline(cin, str);
		searchBookDataByISBN(books, bookCount, str, loc);
		if (loc != -1)
			cout << "The store sells this book." << endl;
		else
			cout << "The store does not sell this book" << endl;
		break;
	case 2:
		cout << "Enter the title of the book." << endl;
		getline(cin, str);
		searchBookDataByTitle(books, bookCount, str, loc);
		if (loc != -1)
			cout << "The store sells this book." << endl;
		else
			cout << "The store does not sell this book" << endl;
		break;
	default:
		cout << "Invalid choice" << endl;
	}
}

void updateCopiesInStock(bookType books[], int bookCount)
{
	int choice;

	int loc;

	int count;
	char ch;

	string str;

	subMenu();
	cin >> choice;
	cin.get(ch);

	switch (choice)
	{
	case 1:
		cout << "Enter the ISBN of the book." << endl;
		getline(cin, str);
		searchBookDataByISBN(books, bookCount, str, loc);
		if (loc != -1)
		{
			cout << "Enter the number of books: ";
			cin >> count;
			cout << endl;

			books[loc].updateQuantity(count);
		}
		else
			cout << "The store does not sell this book: " << endl;
		break;
	case 2:
		cout << "Enter the title of the book." << endl;
		getline(cin, str);
		searchBookDataByTitle(books, bookCount, str, loc);
		if (loc != -1)
		{
			cout << "Enter the number of books";
			cin >> count;
			cout << endl;

			books[loc].updateQuantity(count);
		}
		else
			cout << "The store does not sell this book" << endl;
		break;
	default:
		cout << "Invalid choice" << endl;
	}
}

void showMenu()
{
	cout << "Welcome to Rock's Book Store" << endl;
	cout << "To make a selection enter the number and press enter"
		<< endl;
	cout << "1: Print a list of books" << endl;
	cout << "2: Print a list of books and ISBN numbers" << endl;
	cout << "3: To see if a book in store" << endl;
	cout << "4: To update the number of copies of a book" << endl;
	cout << "5: To print books data" << endl;
	cout << "9: Exit the program." << endl;
}

void subMenu()
{
	cout << "Enter" << endl;
	cout << "1: To search the book by ISBN" << endl;
	cout << "2: To search the book by title" << endl;
}

