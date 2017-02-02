#include <iostream>
#include <string>
#include "kindleUlimeted.h"
#include "Date.h"
#include "User.h"
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::string;

static int kindleNumber = 0;

// Overload opperator <<
ostream &operator<< (ostream &output, const KindleUnlimeted &kindle)
{
	output << "Book: "<< kindle.bookName << " Author: " << kindle.bookAuthor;
	return output;
}

// Overload operator =
const KindleUnlimeted &operator= (const KindleUnlimeted &kindle)
{
	this->bookName = kindle.bookName;
	this->bookAuthor = kindle.bookAuthor;
	this->bookName = kindle.bookName;
	this->signatureDate = kindle.signatureDate;
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
	this->userCount = "";
	this->signatureDate;
	this->users = 0;
	
	kindleNumber++;
}

// Constructor
KindleUnlimeted::KindleUnlimeted(const string &book, const string &author, int cout)
{
	this->bookName = book;
	this->bookAuthor = author;
	this->userCount = cout;
	this->signatureDate;

	kindleNumber++;
}

// Copy Constructor
KindleUnlimeted::KindleUnlimited(const KindleUnlimeted &kindle)
{
	this->bookName = kindle.bookName;
	this->bookAuthor = kindle.bookAuthor;
	this->userCount = kindle.userCount;
	this->signatureDate = kindle.signatureDate;
	delete [] users;
	this->users = new User[kindle.userCout];
	
	for (int i = 0; i < kindle.userCount; i++)
		this->user[i] = kindle.users[i];

	return *this

	kindleNumber++;
}

// Destructor
void KindleUnlimeted::~KindleUnlimeted
{
	cout << "~KindleUnlimeted() called for" << bookName << '' << bookAuthor << endl;
	
	delete [] bookName;
	delete [] bookAuthor;
	delete [] userCout;
	delete [] signatureDate;
	delete [] users;
	
	kindleNumber--;

}

// Download one book
void KindleUnlimeted::downloadBook() const
{
	cout << "Downloading " << KidleUnlimeted.getBookName << "..." << endl;
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

