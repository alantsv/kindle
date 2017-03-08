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
}

// Constructor
KindleUnlimited::KindleUnlimited(const string &book, const Data &regist,const Data &date, const User &user, const string &developer, bool sign, const string &genre, int count)
:signatureDate(date), Kindle(book, regist, user, developer, genre, count)
{
	this->signature = true;
}

// Copy Constructor
KindleUnlimited::KindleUnlimited(const KindleUnlimited &kindle)
:signatureDate(kindle.signatureDate), Kindle(static_cast< Kindle >(kindle))
{
	this->signature = kindle.signature;
}

// Destructor
KindleUnlimited::~KindleUnlimited()
{
//	cout << "~KindleUnlimited() called" << endl;
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
