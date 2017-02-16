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
	~OnlineService();
	// Defined operator ==
	bool operator== (const OnlineService &) const;
	// Defined operator !=
	bool operator!= (const OnlineService &onlineServ) const
	{
		return ! (*this == onlineServ);
	}
	// Defined assigment operator
	const OnlineService &operator= (const OnlineService &);
	// Add new user
	void addUser(const User &);
	// Show user
	void showUserCount() const;
	// Setup developer list
	void setupDeveloperList(int);

private:
	int userCount;
	User *users;
	int developerCount;
	string *developerList;
	Data registerDate;

};
#endif
