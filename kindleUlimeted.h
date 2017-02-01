#ifndef _KINDLE_H_
#define _KINDLE_H_

#include <string>
using std::string;

class KindleUnlimeted
{
public:
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
 	string bookAutor;
    int userCount;
	static int bookNumber;
    const static int bookMaxNumber;
    const Date signatureDate;
    User users[5];
};

#endif
