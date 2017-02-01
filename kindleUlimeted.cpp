#include <iostream>
#include <string>
#include "kindleUlimeted.h"
#include "Date.h"
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::string;

static int bookNumber = 0;
static int userCount = 0;
	// Default Constructor of Kindle
	KindleUnlimeted::KindleUnlimeted()
	{
		this->bookName = "";
		this->bookAutor = "";
		
		bookNumber++;
	}
	// Constructor of Kindle
	KindleUnlimeted::KindleUnlimeted(const string &book, const string &autor)
	{
		this->bookName = book;
        this->bookAutor = autor;

		bookNumber++;
	}
	// Copy Constructor of Kindle
	KindleUnlimeted::KindleUnlimited(const KindleUnlimeted &kindle)
	{
		this->bookName = kindle.bookName;
		this->bookAutor = kindle.bookAutor;

		bookNumber++;
	}
	
    // Add user
    void KindleUnlimeted::addUser (const User &user)
    {
        User *aux = new User[userCount];
        
        for(int i = 0; i < userCount; i++)
            aux[i] = this->users[i];
            
        delete [] this->user;
        
        users = new User[++userCount];
        
        for(int i = 0; i < userCount-1; i++)
            users[i] = aux[i];
            
        users[userCount-1] = user;
        
        delete [] aux;
        
        userCount++;
    }
    
    void KindleUnlimeted::~KindleUnlimeted
    {
        cout << "~KindleUnlimeted() called for" << bookName << '' << bookAutor << endl;
        
        delete
    }
    
	// Download one book
	void KindleUnlimeted::downloadBook() const
	{
		cout << "Downloading " << KidleUnlimeted.getBookName << "..." << endl;
	}
	
    // Set book name
	void KindleUnlimeted::setBookName(string &book, string &autor)
	{
		bookName = book;
		bookAutor = autor;
	}
	
    // Return book name
	string KindleUnlimeted::getBookName() const
	{
		return bookName;
	}

