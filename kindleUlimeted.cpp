
#include <iostream>
#include <string>
#include "kindleUlimeted.h"
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::string;


	KindleUnlimeted::KindleUnlimeted(){
		this->bookName = "";
        this->bookAutor = "";
	}
	
	KindleUnlimeted::KindleUnlimeted(const string &book, const string &autor){
		this->bookName = book;
        this->bookAutor = autor
	}
    
    KindleUnlimeted::KindleUnlimited(const KindleUnlimeted &kindle){
        this->bookName = kindle.bookName;
        this->bookAutor = kindle.bookAutor;
    }
	
	//Método para fazer o download de um livro
	void KindleUnlimeted::downloadBook(const string bookName)
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

