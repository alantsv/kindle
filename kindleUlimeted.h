#ifndef _KINDLE_H_
#define _KIDLE_H_

#include <string>
using std::string;

class KindleUnlimeted
{
public:
	KindleUnlimeted();
	KindleUnlimeted(const string &, const string &);
    	kindleUnlimeted(const KindleUnlimeted &)
	//Método para fazer o download de um livro
	void downloadBook(const string &, const string &);
	void setBookName(string &);
	string getBookName();

private:
	string bookName;
    string bookAutor
};

#endif
