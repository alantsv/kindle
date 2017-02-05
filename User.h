#ifndef _USER_H_
#define	_USER_H_

#include <ostream>
#include <string>
using std::string;
using std::ostream;

class User 
{
	friend ostream &operator<<(ostream &, const User &);
public:
	bool operator== (const User &) const;
	bool operator!= (const User &user) const
	{
		return ! (*this == user);
	}
	const User &operator= (const User &);
	User(const User &);
	User();
	User(const string &, const int, const int);
	~User();
private:
	string name;
	int age;
	int idUser;	
};

#endif	/* USER_H */
