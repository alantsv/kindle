#ifndef _KINDLE_H_
#define _KINDLE_H_

#include <ostream>
#include <string>
#include "User.h"
#include "Data.h"
using std::string;
using std::ostream;

class KindleUnlimeted
{
	//Defined operator output
	friend ostream &operator<<(ostream &, const KindleUnlimeted &);
public:
	// Defined operator assigment
	const KindleUnlimeted &operator= (const KindleUnlimeted &);
	// Default constructor
	KindleUnlimeted();
	// Constructor
	KindleUnlimeted(const string &, const string &, const int, const Data &);
	// Copy constructor
	KindleUnlimeted(const KindleUnlimeted &);
	// Destructor
	~KindleUnlimeted();
	// Add new user
	void addUser(const User &);
	// Buy one new book
	void buyBook(const string &);
	// Set book name
	void setBookName(string &, string &);
	// Return book name
	string getBookName() const;
	// Download one book
	void downloadBook() const;


private:
	string bookName;
 	string bookAuthor;
	int userCount;
	static int kindleNumber;
	const static int bookMaxNumber;
	const Data signatureDate;
	User *users;
};

#endif
