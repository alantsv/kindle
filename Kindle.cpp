#include <iostream>
#include <string>
#include "Kindle.h"
#include "Data.h"
#include "OnlineService.h"
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::string;

int Kindle::kindleNumber = 0;
const int bookMaxNumberMonth = 50;
string Kindle::recommendBook[5] = {"Eragon", "The Godfather", "UML", "Linux é vida", "Think Python"};

// Default Constructor
Kindle::Kindle()
:OnlineService()
{
	this->bookName = "";
	this->bookAuthor = "";
	
	kindleNumber++;
}

// Constructor
Kindle::Kindle(const string &book, const string &author, const Data &registe, const User &user, const string &developer)
:OnlineService(user, developer, registe)
{
	this->bookName = book;
	this->bookAuthor = author;

	kindleNumber++;

}

// Copy Constructor
Kindle::Kindle(const Kindle &kindle)
:OnlineService(static_cast< OnlineService > (kindle))
{
	this->bookName = kindle.bookName;
	this->bookAuthor = kindle.bookAuthor;
	
	kindleNumber++;
}

// Destructor
Kindle::~Kindle()
{
	cout << "~Kindle() called" << endl;
	
	kindleNumber--;
}

// Overload opperator <<
ostream &operator<< (ostream &output, const Kindle &kindle)
{
	output << "Book: " << kindle.bookName << "\nAuthor: " << kindle.bookAuthor << endl;
	cout << endl;
	output << static_cast< OnlineService > (kindle) << endl;

	return output;
}

// Overload operator ==
bool Kindle::operator== (const Kindle &kindle) const
{
	if (this->bookName != kindle.bookName)
		return false;
	if (this->bookAuthor != kindle.bookAuthor)
		return false;
	if (static_cast< OnlineService >(*this) != static_cast<OnlineService> (kindle))	
		return false;
	return true;
}

// Overload operator =
const Kindle &Kindle::operator= (const Kindle &kindle)
{
	this->bookName = kindle.bookName;
	this->bookAuthor = kindle.bookAuthor;
	
	static_cast< OnlineService> (*this) = static_cast< OnlineService > (kindle);
		
	return *this;
}

// Set book name
void Kindle::setBookName(string &book)
{
	bookName = book;
}

// Set author name
void Kindle::setAuthorName(string &author)
{
	bookAuthor = author;
}

// Return book name
string Kindle::getBookName() const
{
	return bookName;
}

// Rerturn author name
string Kindle::getAuthorName() const
{
	return bookAuthor;
}

// Download one book
void Kindle::downloadBook() const
{
	cout << "Downloading " << this->bookName << "..." << endl;
}

// Show the Kindle number
int Kindle::showKindleNumber()
{
	return kindleNumber;
}

// Show 5 recommended books
void Kindle::showRecommended()
{
	cout << "<<<< Recommended >>>>" << endl;
	for(int i = 0; i < 5; i++)
		cout << recommendBook[i] << endl;
}
