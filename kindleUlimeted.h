#ifndef _KINDLE_H_
#define _KIDLE_H_

#include <string>
using std::string;

class KindleUnlimeted
{
public:
	KindleUnlimeted();
	KindleUnlimeted(string const);
	//Método para fazer o download de um livro
	void downloadBook(string const);
	void setBookName(string const);
	string getBookName();

private:
	string bookName;
    string bookAutor
};

#endif
