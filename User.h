#ifndef USER_H
#define	USER_H

#include <string>
using std::string

class User 
{
public:
    User();
    User(const User &);
private:
    string name;
    int age;
    int id;    
};

#endif	/* USER_H */