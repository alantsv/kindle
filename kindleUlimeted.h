#ifdef _KINDLE_H_
#define _KIDLE_H_

#include <string>
using std::string;

class KindleUnlimeted
{
public:
	KindleUnlimeted();
	KindleUnlimeted(string);
	void downloadBook(string);
	void setBookName(string);
	string getBookName();

private:
	string bookName;	
};

#endif
