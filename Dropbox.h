#ifndef _DROPBOX_H_
#define _DROPBOX_H_

#include <ostream>
#include <string>
#include "Data.h"
#include "OnlineService.h"
using std::string;
using std::ostream;

class Dropbox : public OnlineService
{
	//Defined operator output
	friend ostream &operator<<(ostream &, const Dropbox &);
public:
	// Default constructor
	Dropbox();
	// Constructor
	Dropbox(const string &, const User &, const string &, const Data &);
	// Copy constructor
	Dropbox(const Dropbox &);
	// Destructor
	~Dropbox();
	// Defined operator ==
	bool operator== (const Dropbox &) const;
	// Defined operator !=
	bool operator!= (const Dropbox &dropbox) const
	{
		return ! (*this == dropbox);
	}
	// Defined assigment operator
	const Dropbox &operator= (const Dropbox &);
	// Store files list
	void storeFile (const string &);
	// Recover exclued files
	void recoverFile () const;
	// Print info
	void print() const;
	// Help
	void help() const;
	// Register new account
	void registerNewAccout() const;
private:
	int filesCount;
	string *fileList;
};
#endif
