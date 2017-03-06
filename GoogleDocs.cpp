#include <iostream>
#include <ostream>
#include <string>
#include "GoogleDocs.h"
using std::cout;
using std::endl;
using std::string;

// Default Constructor
GoogleDocs::GoogleDocs()
:OnlineService()
{
	this->documentName = "";
	this->editing = false;
	this->docOpenCount = 0;
	this->openDocumentList = new string[1];
	this->openDocumentList[0] = this->documentName;
}

// Constructor
GoogleDocs::GoogleDocs(const string &document, bool edit, const User &user, const string &developer, const Data &date)
:OnlineService(user, developer, date)
{
	this->documentName = document;
	this->editing = edit;
	this->docOpenCount = 1;
	this->openDocumentList = new string[this->docOpenCount];
	this->openDocumentList[0] = document;

}

// Copy Constructor
GoogleDocs::GoogleDocs(const GoogleDocs &googleDocs)
:OnlineService(static_cast<OnlineService> (googleDocs))
{
	this->documentName = googleDocs.documentName;
	this->editing = googleDocs.editing;
	this->docOpenCount = googleDocs.docOpenCount;
	this->openDocumentList = new string[googleDocs.docOpenCount];
	for (int i = 0; i < googleDocs.docOpenCount; i++)
		this->openDocumentList[i] = googleDocs.openDocumentList[i];
}

// Destructor
GoogleDocs::~GoogleDocs()
{
//	cout << "~GoogleDocs() called" << endl;
	
	delete [] openDocumentList;
}

// Overload opperator <<
ostream &operator<< (ostream &output, const GoogleDocs &googleDocs)
{

	output << static_cast< OnlineService> (googleDocs) << endl;
	cout << endl;
	output << "Open document: " << googleDocs.documentName <<endl;
	output << "Document number: " << googleDocs.docOpenCount << endl;
	output << "Documents open recently ";
	for (int i = 0; i < googleDocs.docOpenCount; i++)
	{
		output << googleDocs.openDocumentList[i];
	if (i < googleDocs.docOpenCount-1)
			cout << ", ";
	}
	cout << endl;

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
		if (this->openDocumentList[i] == googleDocs.openDocumentList[i])
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
	delete [] this->openDocumentList;
	this->openDocumentList = new string[this->docOpenCount];
	for (int i = 0; i < googleDocs.docOpenCount; i++)
		this->openDocumentList[i] = googleDocs.openDocumentList[i];
	static_cast< OnlineService> (*this) = static_cast< OnlineService > (googleDocs);
	return *this;
}

void GoogleDocs::addDocList(const string &document)
{
	string *aux = new string[docOpenCount];
	
	for(int i = 0; i < docOpenCount; i++)
		aux[i] = this->openDocumentList[i];
		
	delete [] this->openDocumentList;
	
	this->openDocumentList = new string[++docOpenCount];
	
	for(int i = 0; i < docOpenCount-1; i++)
		this->openDocumentList[i] = aux[i];
		
	this->openDocumentList[docOpenCount-1] = document;
	
	delete [] aux;
	
	this->docOpenCount++;

}

void GoogleDocs::openDocument(const string &document)
{
	cout << "Openning " << document << "..." << endl;
	this->documentName = document;
	this->addDocList(document);
	this->setupEditing();
}

// Print (Polymorphism)
void GoogleDocs::print() const
{
	cout << *this << endl;
}

// Virtual help
void GoogleDocs::help() const
{
	cout << "Help & Feedback" << endl;
	cout << "Help" << endl;
	cout << "Find or recover a file\nInsert and arrange text, shapes, and lines\nAdd a title, heading, or table of contents in a document\nCreate a survey using Google Forms" << endl;
}

// Virtual register
void GoogleDocs::registerNewAccout() const
{
	cout << "Redirecting for Google Drive\n[Acess the Google Drive]\nRedirecting for Google" << endl;
	cout << "One account. All of Google.\nSign in to continue to Google Drive" << endl;
	cout << "Enter your email" << endl;
	cout << "Next" << endl;
}
