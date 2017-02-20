#ifndef _GOOGLEDOCS_H_
#define _GOOGLEDOCS_H_

#include <ostream>
#include <string>
#include "Data.h"
#include "OnlineService.h"
using std::string;
using std::ostream;

class GoogleDocs : public OnlineService
{
	//Defined operator output
	friend ostream &operator<<(ostream &, const GoogleDocs &);
public:
	// Default constructor
	GoogleDocs();
	// Constructor
	GoogleDocs(const string &, bool, const Data &, const User &, const string &, const Data &);
	// Copy constructor
	GoogleDocs(const GoogleDocs &);
	// Destructor
	~GoogleDocs();
	// Defined operator ==
	bool operator== (const GoogleDocs &) const;
	// Defined operator !=
	bool operator!= (const GoogleDocs &googleDocs) const
	{
		return ! (*this == googleDocs);
	}
	// Defined assigment operator
	const GoogleDocs &operator= (const GoogleDocs &);
	// Open document
	void openDocumnet(const string &);
	// Add one document to document list
	void addDocList(const string &);
	// Enable or Disable editing
	void setupEditing()
	{
		this->editing =  !(this->editing);
	}
	// Show last acessa date
	void showDate() const;

private:
	string documentName;
	int docOpenCount;
	bool editing;
	string *listDocumentOpen;
	Data lastAcess;
};
#endif
