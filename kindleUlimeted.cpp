#include <iostream>
#include <string>
#include "kindleUlimeted.h"
#include "Data.h"
#include "User.h"
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::string;

static int kindleNumber = 0;
const int bookMaxNumber = 0;

// Overload opperator <<
ostream &operator<< (ostream &output, const KindleUnlimeted &kindle)
{
	output << "Book: "<< kindle.bookName << " Author: " << kindle.bookAuthor;
	return output;
}

// Overload operator =
const KindleUnlimeted &KindleUnlimeted::operator= (const KindleUnlimeted &kindle)
{
	this->bookName = kindle.bookName;
	this->bookAuthor = kindle.bookAuthor;
	this->bookName = kindle.bookName;
	delete [] users;
	this->users= new User[kindle.userCount];
	
	for(int i = 0; i < kindle.userCount; i++)
		this->users[i] = kindle.users[i];
	
	return *this;
}

// Default Constructor
KindleUnlimeted::KindleUnlimeted()
{
	this->bookName = "";
	this->bookAuthor = "";
	this->userCount = 0;
	this->users = 0;
	
	kindleNumber++;
}

// Constructor
KindleUnlimeted::KindleUnlimeted(const string &book, const string &author, int cout, const Data &date)
:signatureDate(date)
{
	this->bookName = book;
	this->bookAuthor = author;
	this->userCount = cout;
	this->signatureDate;

	kindleNumber++;
}

// Copy Constructor
KindleUnlimeted::KindleUnlimeted(const KindleUnlimeted &kindle)
:signatureDate(kindle.signatureDate)
{
	this->bookName = kindle.bookName;
	this->bookAuthor = kindle.bookAuthor;
	this->userCount = kindle.userCount;
	delete [] users;
	this->users = new User[kindle.userCount];
	
	for (int i = 0; i < kindle.userCount; i++)
		this->users[i] = kindle.users[i];
	kindleNumber++;
}

// Destructor
KindleUnlimeted::~KindleUnlimeted()
{
	cout << "~KindleUnlimeted() called for" << bookName << "" << bookAuthor << endl;
	
	delete []  users;
	
	kindleNumber--;

}

// Set book name
void KindleUnlimeted::setBookName(string &book, string &author)
{
	bookName = book;
	bookAuthor = author;
}

// Return book name
string KindleUnlimeted::getBookName() const
{
	return bookName;
}

// Download one book
void KindleUnlimeted::downloadBook() const
{
	cout << "Downloading " << bookName << "..." << endl;
}

// Add user
void KindleUnlimeted::addUser (const User &newUser)
{
	User *aux = new User[userCount];
	
	for(int i = 0; i < userCount; i++)
		aux[i] = this->users[i];
		
	delete [] this->users;
	
	users = new User[++userCount];
	
	for(int i = 0; i < userCount-1; i++)
		users[i] = aux[i];
		
	users[userCount-1] = newUser;
	
	delete [] aux;
	
	userCount++;
}



