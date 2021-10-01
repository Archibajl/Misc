//Justin Archibald   CSC 160   C++  CH 10 Program

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class  bookType {
public:
	// variables declaired
	string title;
	string ISBN;
	string Publisher;
	int PublishYear;
	string auth[4];
	double cost;
	int copies;
	int authorCount;
//	int bookCount;
	// set book info to retrive from the main program
	void setBookInfo(string a, string b, string c,
		int x, string y, double d, int e, int z) {
		title = a; ISBN = b; Publisher = c; PublishYear = x; auth[1] = y[1]; auth[2] = y[2]; auth[3] = y[3]; auth[4] = y[4]; cost = d; copies = e;
		authorCount = z;
	}
	// boolian functions for the if statments in the main program.
	bool isISBN(string ISBN) {
			return true;  if (ISBN.empty())
		{		return false;
	}
	}
	bool isTitle(string title) {
		 return true;
 		if (title.empty())
		{			return false;	}
	}
	// prints the saved variables for print info function.
	void printInfo(){
		cout << "Title: " << title << " ISBN: " << ISBN << endl;
		cout << "Author: " << auth[1] << " " << auth[2] << " " << auth[3] << " " << auth[4] << endl;
		cout << "Publisher: " << Publisher << " PublishYear: " << PublishYear << endl;
		cout << "Cost: " << cost << " Number of copies available: " << copies << endl;
	}

	//this function prints the book titles it loops in the main program.
	void printbookTitle() {
		cout << title << " " << ISBN << endl;
	}
	// this function prints the titles and isbn for a selection in the main program.
	void printbookTitleAndISBN() {
		cout << title << " " << ISBN << endl;
	}
	// this function updates the quantity in bookType.
	void updateQuantity(int x)
	{
		copies = x;
	}
};

// this function prototype is for a function in the main program.
void printData();

bookType  books[100];

