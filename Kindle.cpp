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
	
	kindleNumber++;
}

// Constructor
Kindle::Kindle(const string &book, const Data &registe, const User &user, const string &developer)
:OnlineService(user, developer, registe)
{
	this->bookName = book;

	kindleNumber++;
}

// Copy Constructor
Kindle::Kindle(const Kindle &kindle)
:OnlineService(static_cast< OnlineService > (kindle))
{
	this->bookName = kindle.bookName;
	
	kindleNumber++;
}

// Destructor
Kindle::~Kindle()
{
//	cout << "~Kindle() called" << endl;
	
	kindleNumber--;
}

// Overload opperator <<
ostream &operator<< (ostream &output, const Kindle &kindle)
{

	output << static_cast< OnlineService > (kindle) << endl;
	cout << endl;
	output << "You are reading the book " << kindle.bookName << endl;
	return output;
}

// Overload operator ==
bool Kindle::operator== (const Kindle &kindle) const
{
	if (this->bookName != kindle.bookName)
		return false;
	if (static_cast< OnlineService >(*this) != static_cast<OnlineService> (kindle))	
		return false;
	return true;
}

// Overload operator =
const Kindle &Kindle::operator= (const Kindle &kindle)
{
	this->bookName = kindle.bookName;
	
	static_cast< OnlineService> (*this) = static_cast< OnlineService > (kindle);
		
	return *this;
}

// Download one book
void Kindle::downloadBook(const string &book) 
{
	cout << "Downloading " << this->bookName << "..." << endl;
	this->bookName = book;
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

// Print (Polymorphism)
void Kindle::print() const
{
	cout << *this;
}

// Set book name
void Kindle::setBookName(const string &book)
{
    bookName = book;
}

// Return book name
string Kindle::getBookName() const
{
    return bookName;
}

// Virtual help
void Kindle::help() const
{
	cout << "Hello. What can we help you with?" << endl;
	cout << "Amazon Device Support\tReturns & Refunds\tAccount Settings" << endl;
}

// Virtual register
void Kindle::registerNewAccout() const
{
	cout << "[Amazon]\nHello. Sign in\nAccount & Lists" << endl;
	cout << "Sing in\nEmail (phone for mobile accounts)\n\nPassword\tForgot your password?" << endl;
}

// Add genre to preference list
void Kindle::setupPreferenceList(const string &newGenre)
{
	string *aux = new string[preferenceCount];
	
	for(int i = 0; i < preferenceCount; i++)
		aux[i] = this->genrePreferenceList[i];
		
	delete [] this->genrePreferenceList;
	
	this->genrePreferenceList = new string[++preferenceCount];
	
	for(int i = 0; i < preferenceCount-1; i++)
		this->genrePreferenceList[i] = aux[i];
		
	this->genrePreferenceList[preferenceCount-1] = newGenre;
	
	delete [] aux;
	
	this->preferenceCount++;
}
