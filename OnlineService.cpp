#include <iostream>
#include <ostream>
#include <string>
#include "OnlineService.h"
#include "Data.h"
#include "User.h"
using std::cout;
using std::endl;
using std::string;

// Default Constructor
OnlineService::OnlineService()
:registerDate()
{
	this->userCount = 1;
	this->users = new User[this->userCount];
	this->developerCount = 1;
	this->developerList = new string[this->developerCount];
}

// Constructor
OnlineService::OnlineService(const User &user, const string &developer, const Data &date)
:registerDate(date)
{
	this->userCount = 1;
	this->users = new User[this->userCount];
	this->users[0] = user;
	this->developerCount = 1;
	this->developerList = new string[this->developerCount];
	this->developerList[0] = developer;

}

// Copy Constructor
OnlineService::OnlineService(const OnlineService &onlineService)
:registerDate(onlineService.registerDate)
{
	this->userCount = onlineService.userCount;

	this->users = new User[onlineService.userCount];
	for (int i = 0; i < onlineService.userCount; i++)
		this->users[i] = onlineService.users[i];
	this->developerCount = onlineService.developerCount;

	this->developerList = new string[onlineService.developerCount];
	for (int i = 0; i < onlineService.developerCount; i++)
		this->developerList[i] = onlineService.developerList[i];
}

// Destructor
OnlineService::~OnlineService()
{
//	cout << "~OnlineService() called" << endl;
	
	delete [] users;
	delete [] developerList;
}

// Overload opperator <<
ostream &operator<< (ostream &output, const OnlineService &onlineService)
{
	output << "You are registered since " << onlineService.registerDate << "Used for " << onlineService.developerCount << " users"<< endl;
	output << "[Users info]" << endl;
	for (int i = 0; i < onlineService.userCount; i++)
		output << onlineService.users[i] << endl;
	output << "Developed for ";
	for (int i = 0; i < onlineService.developerCount; i++)
		output << onlineService.developerList[i] << "";
	cout << endl;
	return output;
}

// Overload operator ==
bool OnlineService::operator== (const OnlineService &onlineService) const
{
	if (this->userCount == onlineService.userCount)
		return false;
	for(int i = 0; i < onlineService.userCount; i++)
		if (this->users[i] == onlineService.users[i])
			return false;
	if (this->developerCount == onlineService.developerCount)
		return false;
	for(int i = 0; i < onlineService.developerCount; i++)
		if (this->developerList[i] == onlineService.developerList[i])
			return false;
	if (this->registerDate == onlineService.registerDate)
		return false;

	
	return true;
}

// Overload operator =
const OnlineService &OnlineService::operator= (const OnlineService &onlineService)
{
	this->userCount = onlineService.userCount;
	delete [] users;
	this->users = new User[onlineService.userCount];
	for (int i = 0; i < onlineService.userCount; i++)
		this->users[i] = onlineService.users[i];
	this->developerCount = onlineService.developerCount;
	delete [] developerList;
	this->developerList = new string[onlineService.developerCount];
	for (int i = 0; i < onlineService.developerCount; i++)
		this->developerList[i] = onlineService.developerList[i];

	this->registerDate = onlineService.registerDate;

	return *this;
}

void OnlineService::print() const
{}
