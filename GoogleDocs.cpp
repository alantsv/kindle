#include <iostream>
#include <ostream>
#include <string>
#include "GoogleDocs.h"
#include "Data.h"
using std::cout;
using std::endl;
using std::string;

// Default Constructor
GoogleDocs::GoogleDocs()
:lastAcess(), OnlineService()
{
	this->documentName = "";
	this->editing = false;
	this->docOpenCount = 0;
	this->listDocumentOpen = new string[1];
	this->listDocumentOpen[0] = this->documentName;
}

// Constructor
GoogleDocs::GoogleDocs(const string &document, bool edit, const Data &lastDate, const User &user, const string &developer, const Data &date)
:lastAcess(lastDate), OnlineService(user, developer, date)
{
	this->documentName = document;
	this->editing = edit;
	this->docOpenCount = 1;
	this->listDocumentOpen = new string[this->docOpenCount];
	this->listDocumentOpen[0] = document;

}

// Copy Constructor
GoogleDocs::GoogleDocs(const GoogleDocs &googleDocs)
:lastAcess(googleDocs.lastAcess), OnlineService(static_cast<OnlineService> (googleDocs))
{
	this->documentName = googleDocs.documentName;
	this->editing = googleDocs.editing;
	this->docOpenCount = googleDocs.docOpenCount;
	this->listDocumentOpen = new string[googleDocs.docOpenCount];
	for (int i = 0; i < googleDocs.docOpenCount; i++)
		this->listDocumentOpen[i] = googleDocs.listDocumentOpen[i];
	this->lastAcess = googleDocs.lastAcess;
}

// Destructor
GoogleDocs::~GoogleDocs()
{
	cout << "~GoogleDocs() called" << endl;
	
	delete [] listDocumentOpen;
}

// Overload opperator <<
ostream &operator<< (ostream &output, const GoogleDocs &googleDocs)
{
	output << "Last acess: " << googleDocs.lastAcess << "Document count: " << googleDocs.docOpenCount << endl;
	output << "Document:" << googleDocs.documentName <<endl;

	output << "Documents open recently:" << endl;
	for (int i = 0; i < googleDocs.docOpenCount; i++)
		output << "[" << i+1 << "] " << googleDocs.listDocumentOpen[i] << endl;
	output << static_cast< OnlineService> (googleDocs) << endl;

	return output;
}

// Overload operator ==
bool GoogleDocs::operator== (const GoogleDocs &googleDocs) const
{
	if (this->documentName == googleDocs.documentName)
		return false;
	if (this->editing == googleDocs.editing)
		return false;
	if (this->docOpenCount == googleDocs.docOpenCount)
		return false;
	for(int i = 0; i < googleDocs.docOpenCount; i++)
		if (this->listDocumentOpen[i] == googleDocs.listDocumentOpen[i])
			return false;
	if (this->lastAcess == googleDocs.lastAcess)
		return false;
	if (static_cast< OnlineService >(*this) != static_cast<OnlineService> (googleDocs))	
	return false;

	return true;
}

// Overload operator =
const GoogleDocs &GoogleDocs::operator= (const GoogleDocs &googleDocs)
{
	this->documentName = googleDocs.documentName;
	this->editing = googleDocs.editing;
	this->docOpenCount = googleDocs.docOpenCount;
	delete [] this->listDocumentOpen;
	this->listDocumentOpen = new string[this->docOpenCount];
	for (int i = 0; i < googleDocs.docOpenCount; i++)
		this->listDocumentOpen[i] = googleDocs.listDocumentOpen[i];
	this->lastAcess = googleDocs.lastAcess;
	static_cast< OnlineService> (*this) = static_cast< OnlineService > (googleDocs);
	return *this;
}

// Show last acess date
void GoogleDocs::showDate() const
{
	cout << "Last acess date: "<< endl;
	cout << this->lastAcess << endl;
}
