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
	// Defined operator ==
	bool operator== (const KindleUnlimeted &) const;
	// Defined operator !=
	bool operator!= (const KindleUnlimeted &kindle) const
	{
		return ! (*this == kindle);
	}
	// Defined assigment operator
	const KindleUnlimeted &operator= (const KindleUnlimeted &);
	// Default constructor
	KindleUnlimeted();
	// Constructor
	KindleUnlimeted(const string &, const string &, const Data &, const User &);
	// Copy constructor
	KindleUnlimeted(const KindleUnlimeted &);
	// Destructor
	~KindleUnlimeted();
	// Add new user
	void addUser(const User &);
	// Buy one new book
	void buyBook(const string &);
	// Set book name
	void setBookName(string &);
	// Set author name
	void setAuthorName(string &);
	// Return book name
	string getBookName() const;
	// Return author name
	string getAuthorName() const;
	// Download one book
	void downloadBook() const;
	// Show user
	void showUserCount() const;
	// Show kindle unlimeted number
	static int showKindleNumber();
	// Show recommended book list
	static void showRecommended();
	// Setup developer list
	void setupDeveloperList(int);


private:
	string bookName;
 	string bookAuthor;
	const static int bookMaxNumberMonth;
	int userCount;
	static int kindleNumber;
	const Data signatureDate;
	User *users;
	static string recommendBook[5];
	string *developerList;
	int developerCout;
};

#endif
