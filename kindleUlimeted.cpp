#include <iostream>
#include <string>
#include "kindleUlimeted.h"
#include "Date.h"
#include "User.h"
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::string;

static int bookNumber = 0;
static int userCount = 0;

// Overload opperator <<
ostream &operator<< (ostream &output, const KindleUnlimeted &kindle)
{
    output << "Book: "<< kindle.bookName << " Autor: " << kindle.bookAutor;
    return output;
}

// Overload operator =
const KindleUnlimeted &operator= (const KindleUnlimeted &kindle)
{
    this->bookName = kindle.bookName;
    this->bookAutor = kindle.bookAutor;
    this->bookName = kindle.bookName;
    this->signatureDate = kindle.signatureDate;
    delete [] users;
    this->users= new User[kindle.userCount];
    
    for(int i = 0; i < kindle.userCount; i++)
        this->users[i] = kindle.users[i];
    
    return *this;
}

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
    this->bookAutor = autor;

    bookNumber++;
}
// Copy Constructor
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

// Destructor
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

