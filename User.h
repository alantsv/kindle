#ifndef USER_H
#define	USER_H

#include <ostream>
#include <string>
using std::string;
using std::ostream;

class User 
{
	friend ostream &operator<<(ostream &, const User &);
public:
	User();
	User(const User &);
	User(const string &, const int, const int);
private:
	string name;
	int age;
	int id;	
};

#endif	/* USER_H */
