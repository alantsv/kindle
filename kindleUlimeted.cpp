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

int KindleUnlimeted::kindleNumber = 0;
const int bookMaxNumberMonth = 50;

// Overload opperator <<
ostream &operator<< (ostream &output, const KindleUnlimeted &kindle)
{
	output << "Book: "<< kindle.bookName << "\nAuthor: " << kindle.bookAuthor << "\nSignature Date: " << kindle.signatureDate << "User count:" << kindle.userCount << endl;
	for(int i = 0; i < kindle.userCount; i++)
		output << kindle.users[i] << endl;
	return output;
}


// Overload operator ==
bool KindleUnlimeted::operator== (const KindleUnlimeted &kindle) const
{
	if (this->bookName == kindle.bookName)
		return false;
	if (this->bookAuthor == kindle.bookAuthor)
		return false;
	if (this->userCount == kindle.userCount)
		return false;
	if (this->signatureDate == kindle.signatureDate)
		return false;
	for(int i = 0; i < kindle.userCount; i++)
		if (this->users[i] == kindle.users[i])
			return false;
	
	return true;
}

// Overload operator =
const KindleUnlimeted &KindleUnlimeted::operator= (const KindleUnlimeted &kindle)
{
	this->bookName = kindle.bookName;
	this->bookAuthor = kindle.bookAuthor;
	this->userCount = kindle.userCount;
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
	this->userCount = 1;
	this->users;
	this->signatureDate;
	
	kindleNumber++;
}

// Constructor
KindleUnlimeted::KindleUnlimeted(const string &book, const string &author, const Data &date, const User &user)
:signatureDate(date)
{
	this->bookName = book;
	this->bookAuthor = author;
	this->userCount = 1;
	this->users[0] = user;

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
	cout << "~KindleUnlimeted() called" << endl;
	
	delete [] users;
	
	kindleNumber--;

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


int KindleUnlimeted::showKindleNumber()
{
	return kindleNumber;
}

