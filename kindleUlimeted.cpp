
#include <iostream>
#include <string>
#include "kindleUlimeted.h"
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::string;

	// Default Constructor
	KindleUnlimeted::KindleUnlimeted()
	{
		this->bookName = "";
		this->bookAutor = "";
		
		bookNumber++;
	}
	// Constructor
	KindleUnlimeted::KindleUnlimeted(const string &book, const string &autor)
	{
		this->bookName = book;
        	this->bookAutor = autor

		bookNumber++;
	}
	// Copy Constructor
	KindleUnlimeted::KindleUnlimited(const KindleUnlimeted &kindle)
	{
		this->bookName = kindle.bookName;
		this->bookAutor = kindle.bookAutor;

		bookNumber++;
	}
	
	// Método para fazer o download de um livro
	void KindleUnlimeted::downloadBook(const string &bookName)
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

