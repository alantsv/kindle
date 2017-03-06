#include <iostream>
#include <ostream>
#include <string>
#include "Dropbox.h"
#include "Data.h"
using std::cout;
using std::endl;
using std::string;

// Default Constructor
Dropbox::Dropbox()
:OnlineService()
{
	this->filesCount = 0;
	this->fileList = new string[1];
	this->fileList[0] = "";
}

// Constructor
Dropbox::Dropbox(const string &document, const User &user, const string &developer, const Data &date)
:OnlineService(user, developer, date)
{
	this->filesCount = 1;
	this->fileList = new string[this->filesCount];
	this->fileList[0] = document;

}

// Copy Constructor
Dropbox::Dropbox(const Dropbox &dropbox)
:OnlineService(static_cast<OnlineService> (dropbox))
{
	this->filesCount = dropbox.filesCount;
	this->fileList = new string[dropbox.filesCount];
	for (int i = 0; i < dropbox.filesCount; i++)
		this->fileList[i] = dropbox.fileList[i];
}

// Destructor
Dropbox::~Dropbox()
{
//	cout << "~Dropbox() called" << endl;
	
	delete [] fileList;
}

// Overload opperator <<
ostream &operator<< (ostream &output, const Dropbox &dropbox)
{
	output << static_cast< OnlineService> (dropbox) << endl;
	cout << endl;
	output << "You have " << dropbox.filesCount << " files" <<endl;

	output << "[Your files]" << endl;
	for (int i = 0; i < dropbox.filesCount; i++)
		output << "> "<< dropbox.fileList[i] << endl;


	return output;
}

// Overload operator ==
bool Dropbox::operator== (const Dropbox &dropbox) const
{
	if (this->filesCount == dropbox.filesCount)
		return false;
	for(int i = 0; i < dropbox.filesCount; i++)
		if (this->fileList[i] == dropbox.fileList[i])
			return false;
	if (static_cast< OnlineService >(*this) != static_cast<OnlineService> (dropbox))	
	return false;

	return true;
}

// Overload operator =
const Dropbox &Dropbox::operator= (const Dropbox &dropbox)
{
	this->filesCount = dropbox.filesCount;
	delete [] this->fileList;
	this->fileList = new string[this->filesCount];
	for (int i = 0; i < dropbox.filesCount; i++)
		this->fileList[i] = dropbox.fileList[i];
	static_cast< OnlineService> (*this) = static_cast< OnlineService > (dropbox);
	return *this;
}

// Store your Files
void Dropbox::storeFile(const string &document)
{
	string *aux = new string[filesCount];
	
	for(int i = 0; i < filesCount; i++)
		aux[i] = this->fileList[i];
		
	delete [] this->fileList;
	
	this->fileList = new string[++filesCount];
	
	for(int i = 0; i < filesCount-1; i++)
		this->fileList[i] = aux[i];
		
	this->fileList[filesCount-1] = document;
	
	delete [] aux;
	
	this->filesCount++;

}


// Recover exclued files
void Dropbox::recoverFile() const
{
	cout << "You don't any files for recover";
}

// Print (Polymorphism)
void Dropbox::print() const
{
	cout << *this << endl;
}

// Virtual help
void Dropbox::help() const
{
	cout << "How can we help you?" << endl;
	cout << "Choose a category to find the help you need" << endl;
	cout << "Sharing files and folders\nPayments and billing\nSecurity and privacy\nDropbox Business" << endl;
}

// Virtual register
void Dropbox::registerNewAccout() const
{
	cout << "[Full name]\n[Email]\n[Password]\n[ ] I agree to Dropbox terms" << endl;
	cout << "Sing up for free" << endl;
	cout << "Sing up free with Google" << endl;
}
