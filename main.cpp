#include <iostream>
#include <string>
#include "kindleUlimeted.h"
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::string;
/*
   *Uma nova classe relacionada ao seu projeto
    Duas alocações dinâmicas de memória - uma similar ao do exemplo do livro - slide 85
    *Uso explicito do ponteiro this
    *Uso do destrutor
    *Sobrecarga dos operadores em todas as classes
        *= (atribuição)
        *==
        *!=
        *operator <<
    *3 construtores - incluindo um de cópia
    *2 métodos - não pode ser get ou set
    *1 método extra que precisa ser const
    *1 atributo static - inicializar no cpp
    *1 atributo static const - inicializar no cpp
    *1 método static - mostrar o seu uso no main
    *Composição com classe Data
    *1 array  - precisa ser realmente usado
*/

int main ()
{
	string author;
	string bookName;
	KindleUnlimeted myKindle;
	KindleUnlimeted::showRecommended();
	cout << endl;
	cout << "Plase, book name: ";
	getline( cin, bookName);
	cout << "Plase, author name: ";
	getline( cin, author);
	cout << endl;
	myKindle.setBookName(bookName);
	cout << endl;
	myKindle.setAuthorName(author);
	myKindle.downloadBook();
	cout << endl;
	cout << myKindle << endl;
	cout << "Kindle number: " << KindleUnlimeted::showKindleNumber << endl;
	cout << endl;
	cout << endl;
	return 0;

}
