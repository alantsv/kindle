
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
	Kindle(const string &, const Data & ,const User &, const string &);
	// Copy constructor
	Kindle(const Kindle &);
	// Destructor
	~Kindle();
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
	// Download one book
	void downloadBook(const string &);
	// Show Kindle unlimeted number
	static int showKindleNumber();
	// Show recommended book list
	static void showRecommended();
	// Print (Polymorphism)
	void print() const;
	// Return book name
	string getBookName() const;
	// Set book name
	void setBookName(const string &);
	// Help
	void help() const;
	// Register new account
	void registerNewAccout() const;
private:
	string bookName;
	static string recommendBook[5];
	static int kindleNumber;
};

#endif
