#ifndef _KINDLEULI_H_
#define _KINDLEULI_H_

#include <ostream>
#include <string>
#include "Data.h"
#include "Kindle.h"
#include "User.h"
using std::string;
using std::ostream;

class KindleUnlimited : public Kindle
{
	//Defined operator output
	friend ostream &operator<<(ostream &, const KindleUnlimited &);
public:
	// Default constructor
	KindleUnlimited();
	// Constructor
	KindleUnlimited(const string &, const Data &, const Data & ,const User &, const string &, bool, int count, const string &);
	// Copy constructor
	KindleUnlimited(const KindleUnlimited &);
	// Destructor
	~KindleUnlimited();
	// Defined operator ==
	bool operator== (const KindleUnlimited &) const;
	// Defined operator !=
	bool operator!= (const KindleUnlimited &kindle) const
	{
		return ! (*this == kindle);
	}
	// Defined assigment operator
	const KindleUnlimited &operator= (const KindleUnlimited &);
	// Choice eBook for read
	void readEBook(const string &) const;
	// Setup account enable ou disable
	void setupSignature()
	{
		this->signature = !signature;
	}
	// Setup preference genre list
	void setupPreferenceList(const string &);
	// Force exit all device
	void exitAllDevice() const;
	// Show max number user shared same account
	static int showMaxUserShared();
	// Print o cost for month
	static double printCostMonth();
private:
	const static int maxUserShared = 5;
	const Data signatureDate;
	const static double costForMonth = 19.90;
	bool signature;
	int preferenceCount;
	string *genrePreferenceList;
};

#endif
