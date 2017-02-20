
#ifndef _KINDLE_H_
#define _KINDLE_H_

#include <ostream>
#include <string>
#include "Data.h"
#include "OnlineService.h"
using std::string;
using std::ostream;

class Kindle : public OnlineService
{
	//Defined operator output
	friend ostream &operator<<(ostream &, const Kindle &);
public:
	// Default constructor
	Kindle();
	// Constructor
	Kindle(const string &, const string &, const Data & ,const User &, const string &);
	// Copy constructor
	Kindle(const Kindle &);
	// Destructor
	virtual ~Kindle();
	// Defined operator ==
	bool operator== (const Kindle &) const;
	// Defined operator !=
	bool operator!= (const Kindle &kindle) const
	{
		return ! (*this == kindle);
	}
	// Defined assigment operator
	const Kindle &operator= (const Kindle &);
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
	// Show Kindle unlimeted number
	static int showKindleNumber();
	// Show recommended book list
	static void showRecommended();

private:
	string bookName;
 	string bookAuthor;
	static string recommendBook[5];
	static int kindleNumber;
};

#endif
