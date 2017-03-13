#ifndef _ONLINESERVICE_H_
#define _ONLINESERVICE_H_

#include <ostream>
#include <string>
#include "User.h"
#include "Data.h"
using std::string;
using std::ostream;

class OnlineService
{
	//Defined operator output
	friend ostream &operator<<(ostream &, const OnlineService &);
public:
	// Default constructor
	OnlineService();
	// Constructor
	OnlineService(const User &, const string  &, const Data &);
	// Copy constructor
	OnlineService(const OnlineService &);
	// Destructor
	virtual ~OnlineService();
	// Defined operator ==
	bool operator== (const OnlineService &) const;
	// Defined operator !=
	bool operator!= (const OnlineService &onlineServ) const
	{
		return ! (*this == onlineServ);
	}
	// Defined assigment operator
	const OnlineService &operator= (const OnlineService &);
	// Virtual print
	virtual void print() const = 0;
	// Virtual help
	virtual void help() const = 0;
	// Virtual register
	virtual void registerNewAccout() const = 0;
private:
	int userCount;
	User *users;
	int developerCount;
	string *developerList;
	Data registerDate;
};
#endif
