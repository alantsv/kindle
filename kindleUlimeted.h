#ifndef _KINDLE_H_
#define _KINDLE_H_

#include <string>
using std::string;

class KindleUnlimeted
{
public:
	// Default constructor
	KindleUnlimeted();
	// Constructot
	KindleUnlimeted(const string &, const string &);
	// Copy constructor
    	KindleUnlimeted(const KindleUnlimeted &);
	// Faz o download de um livro
	void downloadBook() const;
	// Seleciona o nome do livro
	void setBookName(string &, string &);
	// Retorna o nome do livro
	string getBookName() const;

private:
	string bookName;
 	string bookAutor;
	static int bookNumber;
};

#endif
