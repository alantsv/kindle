#include <iostream>
#include <string>
#include "kindleUlimeted.h"
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::string;

/*
class KindleUnlimeted
{
public:
	//Método para fazer o download de um livro
	void downloadBook()
	{
		cout << "Downloading " << bookName << "..." << endl;
	}
	//Método para definir o nome do livro
	void setBookName(string book)
	{
		bookName = book;
	}
	//Método para retornar o nome do livro
	string getBookName()
	{
		return bookName;
	}

private:
		string bookName;	
};
*/

int main ()
{
	string nameOfBook;
	KindleUnlimeted myKindle;
	cout << "\nPor favor, entre com o nome do livro:" << endl;
	getline( cin, nameOfBook );
	myKindle.setBookName(nameOfBook);

	myKindle.downloadBook(nameOfBook);
	return 0;

}
