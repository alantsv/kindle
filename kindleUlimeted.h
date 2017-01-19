#ifndef _KINDLE_H_
#define _KINDLE_H_

#include <string>
using std::string;

class KindleUnlimeted
{
public:
	KindleUnlimeted();
	KindleUnlimeted(const string &, const string &);
    	KindleUnlimeted(const KindleUnlimeted &);
	//Método para fazer o download de um livro
	void downloadBook() const;
	void setBookName(string &, string &);
	string getBookName() const;

private:
	string bookName;
 	string bookAutor;
	static int bookNumber;
};

#endif
