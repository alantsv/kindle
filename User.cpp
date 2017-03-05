#include "User.h"

#include <iostream>
using std::cout;
using std::endl;

// Overload output operator
ostream &operator<<(ostream &output, const User &user)
{
	output << "Name: "<< user.name << "\nAge: " << user.age << "\nID: " << user.idUser  << endl;
	return output;
}

// Overload operator ==
bool User::operator== (const User &user) const
{
	if (this->name == user.name)
		return false;
	if (this->age == user.age)
		return false;
	if (this->idUser == user.idUser)
		return false;
	
	return true;
}


// Overload operator =
const User &User::operator= (const User &user)
{
	this->name = user.name;
	this->age = user.age;
	this->idUser = user.idUser;
	
	return *this;
}

//Default constructor
User::User()
{
	this->name = ""; 
	this->age = 0;
	this->idUser = 0;
}

//Copy constructor
User::User(const User &userCopy)
{
	this->name = userCopy.name;
	this->age = userCopy.age;
	this->idUser = userCopy.idUser;
}

//Constructor
User::User(const string &nameUser, const int ageUser, const int idUser)
{
	this->name = nameUser;
	this->age = ageUser;
	this->idUser = idUser;
}

//Destructor
User::~User()
{
//	cout << "~User() called" << endl;
}
