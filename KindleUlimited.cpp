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
	this->preferenceCount = 0;
	this->genrePreferenceList = new string[1];
}

// Constructor
KindleUnlimited::KindleUnlimited(const string &book, const Data &regist,const Data &date, const User &user, const string &developer, bool sign, int count, const string &genre)
:signatureDate(date), Kindle(book,regist, user,developer)
{
	this->signature = true;
	if (1 > count)
		count = 1;
	this->preferenceCount = count;
	this->genrePreferenceList = new string[preferenceCount];
	this->genrePreferenceList[0] = genre;
	
}

// Copy Constructor
KindleUnlimited::KindleUnlimited(const KindleUnlimited &kindle)
:signatureDate(kindle.signatureDate), Kindle(static_cast< Kindle >(kindle))
{
	this->signature = kindle.signature;
	this->preferenceCount = kindle.preferenceCount;
	this->genrePreferenceList = new string[this->preferenceCount];
	for(int i = 0; i < kindle.preferenceCount; i++)
		this->genrePreferenceList[i] = kindle.genrePreferenceList[i];
}

// Destructor
KindleUnlimited::~KindleUnlimited()
{
//	cout << "~KindleUnlimited() called" << endl;
	delete [] genrePreferenceList;
	
}

// Overload opperator <<
ostream &operator<< (ostream &output, const KindleUnlimited &kindle)
{
	output << "\nSignature Date: " << kindle.signatureDate << endl; 
	output << "\nPreference Count: " << kindle.preferenceCount << endl;
	cout << "\nGenre Preference List: " << endl;
	for(int i = 0; i < kindle.preferenceCount; i++)
		output << kindle.genrePreferenceList[i] << endl;
	output << static_cast< Kindle> (kindle) << endl;
	return output;
}

// Overload operator ==
bool KindleUnlimited::operator== (const KindleUnlimited &kindle) const
{
	if (this->signatureDate != kindle.signatureDate)
		return false;
	if (this->preferenceCount != kindle.preferenceCount)
		return false;
	for(int i = 0; i < kindle.preferenceCount; i++)
		if (this->genrePreferenceList[i] != kindle.genrePreferenceList[i])
			return false;
	if (static_cast< Kindle >(*this) != static_cast<Kindle> (kindle))	
		return false;
	return true;
}

// Overload operator =
const KindleUnlimited &KindleUnlimited::operator= (const KindleUnlimited &kindle)
{
	this->signatureDate = kindle.signatureDate;
	this->preferenceCount = kindle.preferenceCount;
	delete [] this->genrePreferenceList;
	this->genrePreferenceList = new string[this->preferenceCount];
	for(int i = 0; i < kindle.preferenceCount; i++)
		this->genrePreferenceList[i] = kindle.genrePreferenceList[i];
	
	static_cast< Kindle> (*this) = static_cast< Kindle > (kindle);

	return *this;
}

// Choice book to read
void KindleUnlimited::readEBook(const string &ebook) const
{
	cout << "Opening " << ebook << "..." << endl;
}

// Exit all devices
void KindleUnlimited::exitAllDevice() const
{
	cout << "Exit all devices" << endl;
}

// Show max number user shared same account
int KindleUnlimited::showMaxUserShared()
{
	return maxUserShared;
}

// Print cost of assigment for month
double KindleUnlimited::printCostMonth()
{
	return costForMonth;
}

// Add genre to preference list
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
