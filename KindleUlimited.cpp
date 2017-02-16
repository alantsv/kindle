#include <iostream>
#include <string>
#include "KindleUlimited.h"
#include "Data.h"
#include "Kindle.h"
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::string;



// Default Constructor
KindleUnlimited::KindleUnlimited()
:signatureDate(), Kindle()
{
	this->signature = true;
	this->preferenceCount = 1;
	this->genrePreferenceList = new string[preferenceCount];
}

// Constructor
KindleUnlimited::KindleUnlimited(const string &book, const string &author, const Data &regist,const Data &date, const User &user, const string &developer)
:signatureDate(date), Kindle(book, author,regist, user,developer)
{
	this->signature = true;
	this->preferenceCount = 1;
	this->genrePreferenceList = new string[preferenceCount];
}

// Copy Constructor
KindleUnlimited::KindleUnlimited(const KindleUnlimited &kindle)
:signatureDate(kindle.signatureDate), Kindle(static_cast< Kindle >(kindle))
{
	this->signature = kindle.signature;
	this->preferenceCount = kindle.preferenceCount;
	delete [] this->genrePreferenceList;
	for(int i = 0; i < kindle.preferenceCount; i++)
		this->genrePreferenceList[i] = kindle.genrePreferenceList[i];
}

// Destructor
KindleUnlimited::~KindleUnlimited()
{
	cout << "~KindleUnlimited() called" << endl;
	
}

// Overload opperator <<
ostream &operator<< (ostream &output, const KindleUnlimited &kindle)
{
	output << "\nSignature Date: " << kindle.signatureDate << endl;
	output << static_cast< Kindle> (kindle) << endl;
	return output;
}

// Overload operator ==
bool KindleUnlimited::operator== (const KindleUnlimited &kindle) const
{
	if (this->signatureDate != kindle.signatureDate)
		return false;
	if (static_cast< Kindle >(*this) != static_cast<Kindle> (kindle))	
		return false;
	return true;
}

// Overload operator =
const KindleUnlimited &KindleUnlimited::operator= (const KindleUnlimited &kindle)
{
	this->signatureDate = kindle.signatureDate;
	
	static_cast< Kindle> (*this) = static_cast< Kindle > (kindle);
}

// Choice book to read
void KindleUnlimited::readEBook(const string &ebook) const
{
	cout << "Opening " << ebook << "..." << endl;
}

void KindleUnlimited::setupPreferenceList(const string &newGenre)
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

void KindleUnlimited::exitAllDevice() const
{
	cout << "Exit all devices" << endl;
}

int KindleUnlimited::showMaxUserShared()
{
	return maxUserShared;
}

double KindleUnlimited::printCostMonth()
{
	return costForMonth;
}
