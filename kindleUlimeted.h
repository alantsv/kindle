#ifdef _KINDLE_H_
#define _KIDLE_H_

#include <string>
using std::string;

class KindleUnlimeted
{
public:
	//Método para fazer o download de um livro
	void downloadBook(string);
	void setBookName(string);
	string getBookName();

private:
	string bookName;	
};

#endif
