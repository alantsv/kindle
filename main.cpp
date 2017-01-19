#include <iostream>
#include <string>
#include "kindleUlimeted.h"
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::string;

int main ()
{
	static int bookNumber = 0;
	string autor;
	string bookName;
	KindleUnlimeted myKindle;
	cout << "\nPor favor, entre com o nome do livro:" << endl;
	getline( cin, bookName);
	getline( cin, autor);
	myKindle.setBookName(bookName, autor);
	myKindle.downloadBook();
	return 0;

}
