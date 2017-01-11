
#include <iostream>
#include <string>
#include "kindleUlimeted.h"
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::string;


	void KindleUnlimeted::KindleUnlimeted(){
		this->bookName = "";
	}
	
	void KindleUnlimeted::KindleUnlimeted(const string &book){
		this->bookName = book;
	}
	
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

