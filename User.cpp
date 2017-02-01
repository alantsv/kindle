#include "User.h"

ostream &operator<<(ostream &output, const User &user)
{
    output << "Name: "<< user.name << " Age: " << user.age << " ID:" << user.id;
    return output;
}

User::User()
{
    this->name = 1; 
    this->age = 1;
    this->id = 1900;
}

User::User(const User &userCopy)
{
    this->name = userCopy.name;
    this->age = userCopy.age;
    this->id = userCopy.id;
}