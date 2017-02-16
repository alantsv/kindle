#include <iostream>
#include <string>
#include "kindleUlimeted.h"
#include "Data.h"
#include "OnlineService.h"
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::string;

int KindleUnlimeted::kindleNumber = 0;
const int bookMaxNumberMonth = 50;
string KindleUnlimeted::recommendBook[5] = {"Eragon", "The Godfather", "UML", "Linux é vida", "Think Python"};

// Default Constructor
KindleUnlimeted::KindleUnlimeted()
:signatureDate(), OnlineService()
{
	this->bookName = "";
	this->bookAuthor = "";
	
	kindleNumber++;
}

// Constructor
KindleUnlimeted::KindleUnlimeted(const string &book, const string &author, const Data &regist,const Data &date, const User &user, const string &developer)
:signatureDate(date), OnlineService(user, developer, regist)
{
	this->bookName = book;
	this->bookAuthor = author;

	kindleNumber++;

}

// Copy Constructor
KindleUnlimeted::KindleUnlimeted(const KindleUnlimeted &kindle)
:signatureDate(kindle.signatureDate), OnlineService(static_cast< OnlineService > (kindle))
{
	this->bookName = kindle.bookName;
	this->bookAuthor = kindle.bookAuthor;
	
	kindleNumber++;
}

// Destructor
KindleUnlimeted::~KindleUnlimeted()
{
	cout << "~KindleUnlimeted() called" << endl;
	
	kindleNumber--;
}

// Overload opperator <<
ostream &operator<< (ostream &output, const KindleUnlimeted &kindle)
{
	output << "\nSignature Date: " << kindle.signatureDate << endl;
	output << "Book: " << kindle.bookName << "\nAuthor: " << kindle.bookAuthor << endl;
	cout << endl;
	output << static_cast< OnlineService > (kindle) << endl;

	return output;
}

// Overload operator ==
bool KindleUnlimeted::operator== (const KindleUnlimeted &kindle) const
{
	if (this->bookName != kindle.bookName)
		return false;
	if (this->bookAuthor != kindle.bookAuthor)
		return false;
	if (this->signatureDate != kindle.signatureDate)
		return false;
	if (static_cast< OnlineService >(*this) != static_cast<OnlineService> (kindle))	
		return false;
	return true;
}

// Overload operator =
const KindleUnlimeted &KindleUnlimeted::operator= (const KindleUnlimeted &kindle)
{
	this->bookName = kindle.bookName;
	this->bookAuthor = kindle.bookAuthor;
	this->signatureDate = kindle.signatureDate;
	
	static_cast< OnlineService> (*this) = static_cast< OnlineService > (kindle);
		
	return *this;
}

// Set book name
void KindleUnlimeted::setBookName(string &book)
{
	bookName = book;
}

// Set author name
void KindleUnlimeted::setAuthorName(string &author)
{
	bookAuthor = author;
}

// Return book name
string KindleUnlimeted::getBookName() const
{
	return bookName;
}

// Rerturn author name
string KindleUnlimeted::getAuthorName() const
{
	return bookAuthor;
}

// Download one book
void KindleUnlimeted::downloadBook() const
{
	cout << "Downloading " << this->bookName << "..." << endl;
}

// Show the KindleUnlimeted number
int KindleUnlimeted::showKindleNumber()
{
	return kindleNumber;
}

// Show 5 recommended books
void KindleUnlimeted::showRecommended()
{
	cout << "<<<< Recommended >>>>" << endl;
	for(int i = 0; i < 5; i++)
		cout << recommendBook[i] << endl;
}
