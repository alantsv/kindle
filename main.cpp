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
	string nameOfBook;
	KindleUnlimeted myKindle;
	cout << "\nPor favor, entre com o nome do livro:" << endl;
	getline( cin, nameOfBook );
	myKindle.setBookName(nameOfBook);

	myKindle.downloadBook(nameOfBook);
	return 0;

}
