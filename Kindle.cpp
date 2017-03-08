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
	this->preferenceCount = 0;
	this->genrePreferenceList = new string[1];
	
	kindleNumber++;
}

// Constructor
Kindle::Kindle(const string &book, const Data &registe, const User &user, const string &developer,const string &genre, int count)
:OnlineService(user, developer, registe)
{
	this->bookName = book;
	if (1 > count)
		count = 1;
	this->preferenceCount = count;
	this->genrePreferenceList = new string[preferenceCount];
	this->genrePreferenceList[0] = genre;

	kindleNumber++;
}

// Copy Constructor
Kindle::Kindle(const Kindle &kindle)
:OnlineService(static_cast< OnlineService > (kindle))
{
	this->bookName = kindle.bookName;
	this->preferenceCount = kindle.preferenceCount;
	this->genrePreferenceList = new string[this->preferenceCount];
	for(int i = 0; i < kindle.preferenceCount; i++)
		this->genrePreferenceList[i] = kindle.genrePreferenceList[i];
	
	kindleNumber++;
}

// Destructor
Kindle::~Kindle()
{
//	cout << "~Kindle() called" << endl;
	delete [] genrePreferenceList;
	
	kindleNumber--;
}

// Overload opperator <<
ostream &operator<< (ostream &output, const Kindle &kindle)
{


	output << static_cast< OnlineService > (kindle) << endl;
	output << "\nPreference Count: " << kindle.preferenceCount << endl;
	cout << "\nGenre Preference List: " << endl;
	for(int i = 0; i < kindle.preferenceCount; i++)
		output << kindle.genrePreferenceList[i] << endl;
	output << "You are reading the book " << kindle.bookName << endl;
	return output;
}

// Overload operator ==
bool Kindle::operator== (const Kindle &kindle) const
{
	if (this->bookName != kindle.bookName)
		return false;
	if (this->preferenceCount != kindle.preferenceCount)
		return false;
	for(int i = 0; i < kindle.preferenceCount; i++)
		if (this->genrePreferenceList[i] != kindle.genrePreferenceList[i])
			return false;
	if (static_cast< OnlineService >(*this) != static_cast<OnlineService> (kindle))	
		return false;
	return true;
}

// Overload operator =
const Kindle &Kindle::operator= (const Kindle &kindle)
{
	this->bookName = kindle.bookName;
	this->preferenceCount = kindle.preferenceCount;
	delete [] this->genrePreferenceList;
	this->genrePreferenceList = new string[this->preferenceCount];
	for(int i = 0; i < kindle.preferenceCount; i++)
		this->genrePreferenceList[i] = kindle.genrePreferenceList[i];
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
