#ifdef _KINDLE_H_
#define _KINDLE_H_

#include <iostream>
#include <string>
#include "kindleUlimeted.h"
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::string;

	//Método para fazer o download de um livro
	void KindleUnlimeted::downloadBook(string bookName)
	{
		cout << "Downloading " << KidleUnlimeted.getBookName << "..." << endl;
	}
	
	void KindleUnlimeted::setBookName(string book)
	{
		bookName = book;
	}
	
	string KindleUnlimeted::getBookName()
	{
		return bookName;
	}

#endif
