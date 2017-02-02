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
	friend ostream &operator<<(ostream &, const KindleUnlimeted &);
public:
	// Assingement
	const KindleUnlimeted &operator= (const KindleUnlimeted &);
	// Default constructor
	KindleUnlimeted();
	// Constructot
	KindleUnlimeted(const string &, const string &);
	// Copy constructor
	KindleUnlimeted(const KindleUnlimeted &);
	// Add new user
	void addUser(const User &);
	// Buy one new book
	void buyBook(const string &);
	// Download one book
	void downloadBook() const;
	// Set book name
	void setBookName(string &, string &);
	// Return book name
	string getBookName() const;

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
