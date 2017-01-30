
#include <iostream>
#include <string>
#include "kindleUlimeted.h"
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
    
    Date::Date()
    {
        this->day = 1;
        this->month = 1;
        this->year = 1;
    }
    
     Date::Date(const Date &date)
    {
        this->day = date->day;
        this->month = date->month;
        this->year = date->year;
    }
	
    // Add user
    void User::addUser (const User &user)
    {
        User *aux = new User(userCount);
        
        for(int i = 0; i < userCount; i++)
            aux[i] = userNames[i];
            
        delete [] userNames;
        
        userNames = new string[++userCount];
        
        for(int i = 0; i < userCount-1; i++)
            userNames[i] = aux[i];
            
        userNames[userCount-1] = user;
        
        delete [] aux;
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

